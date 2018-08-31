/* Program: alphabetWar.cpp
 * Description: Write a function that accepts fight string consists of only small letters and * which means a bomb drop place. Return who wins the fight after bombs are exploded. When the left side wins return Left side wins!, when the right side wins return Right side wins!, in other case return Let's fight again!.

The left side letters and their power:

 w - 4
 p - 3
 b - 2
 s - 1
The right side letters and their power:

 m - 4
 q - 3
 d - 2
 z - 1

The other letters don't have power and are only victims.
The * bombs kills the adjacent letters ( i.e. aa*aa => a___a, **aa** => ______ );

 * Kata: 6
 * Date: 8/31/2018
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int getPower(int temp)
{
        vector<char>letter = {'w', 'p', 'b', 's', 'm', 'q', 'd', 'z'};
        vector<int>value = {4,3,2,1,4,3,2,1};

        for (int i=0; i<letter.size(); i++)
        {
                if (temp == letter[i])
                        return value[i];
        }
}

char findTeam(char temp)
{
        if (temp == 'w' || temp == 'p' || temp == 'b' || temp == 's')
                return 'l';
        else if (temp == 'm' || temp == 'q' || temp == 'd' || temp == 'z')
                return 'r';
        else
                return '*';
}

string alphabetWar(string fight)
{
        int rightScore=0;
        int leftScore=0;

        //apply the "bombs"
        for (int i=0; i<fight.size(); i++)
        {
                if (fight[i] == '*')
                {
                        fight[i-1] = '_';
                        fight[i+1]='_';
                }
        }

        // record the numberical scores
        for (int i=0; i<fight.size(); i++)
        {
                //cout << "letter: " << fight[i] << endl;
                if (findTeam(fight[i]) == 'l') //left letter
                {
                        //cout << "add to left" << endl;
                        leftScore += getPower(fight[i]);
                }
                else if (findTeam(fight[i]) == 'r') ///right letter
                {
                        //cout << "add to right" << endl;
                        rightScore += getPower(fight[i]);
                }

        }

        //determine winner
        string r = "Right side wins!";
        string l = "Left side wins!";
        string n = "Let's fight again!";
        if (rightScore > leftScore)
                return r;
        else if (leftScore> rightScore)
                return l;
        else
                return n;
}

int main()
{
        /*test case*/

        string s;
        s="z"; //expected "Right side wins!"
        //s="****"; //expected "Let's fight again!"
        //s="z*dq*mw*pb*s"; //expected "Let's fight again!"
        //s="zdqmwpbs"; //expected "Let's fight again!"
        //s="zz*zzs";  //expected "Right side wins!"
        //s="*wwwwww*z*"; //expected "Left side wins!"
        //s="*ww*ww*w*wz"; //expected "Right side wins!"

        cout << alphabetWar(s) << endl;

        return 0;
}
