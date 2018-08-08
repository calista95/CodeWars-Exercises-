/*Program: Mexican Wave
 *Kata: 6
 *Date: 8/6/2018
 *Description: In this simple Kata your task is to create a function that turns a string into a Mexican Wave. You will be passed a string and you must return that string in an array where an uppercase letter is a person standing up.
 *Rules:
        1.  The input string will always be lower case but maybe empty.
        2.  If the character in the string is whitespace then pass over it as if it was an empty seat
 *Example: wave("hello") => {"Hello", "hEllo", "heLlo", "helLo", "hellO"}
*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <wctype.h>
using namespace std;


vector<string> wave(string y)
{
        vector<string> myVector; //to store results
        for (int i=0; i<y.size(); i++) //run loop equal to how many letters are in the string
                {
                        string tempString = y;
                        if (!iswspace(tempString[i]))
                        {
                                tempString[i] = toupper(tempString[i]); //make i'th letter uppercase
                                myVector.push_back(tempString); //store in vector
                        }
                }
        return myVector;
}


int main()
{
        string myString;
        cout << "Please enter your string (you may include spaces)." << endl;
        cin.ignore();
        getline(cin, myString);
        while (!cin)
                {
                        cout << "Bad input. Enter again." << endl;
                        cin.clear();
                        cin.ignore();
                        getline(cin, myString);
                }
        cout << "Result: " << endl;
        vector<string> myVector = wave(myString);
        for (int i=0; i<myVector.size(); i++)
  		{
                        cout << myVector[i] << " ";
                }
        return 0;
}

