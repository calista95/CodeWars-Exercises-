/*Program: playingWithDigits.cpp
 * Date: 8/7/2018
 * Kata: 6
 * Description: Some numbers have funny properties. For example:

89 --> 8¹ + 9² = 89 * 1

695 --> 6² + 9³ + 54= 1390 = 695 * 2

46288 --> 4³ + 64+ 25 + 86 + 87 = 2360688 = 46288 * 51

Given a positive integer n written as abcd... (a, b, c, d... being digits) and a positive integer p we want to find a positive integer k, if it exists, such as the sum of the digits of n taken to the successive powers of p is equal to k * n. In other words:

Is there an integer k such as : (a ^ p + b ^ (p+1) + c ^(p+2) + d ^ (p+3) + ...) = n * k

If it is the case we will return k, if not return -1.
* Ex:
*       digPow(89, 1) should return 1 since 8¹ + 9² = 89 = 89 * 1
        digPow(92, 1) should return -1 since there is no k such as 9¹ + 2² equals 92 * k
        digPow(695, 2) should return 2 since 6² + 9³ + 54= 1390 = 695 * 2
        digPow(46288, 3) should return 51 since 4³ + 64+ 25 + 86 + 87 = 2360688 = 46288 * 51
*/

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <sstream>
using namespace std;


int digPow(int n, int p)
        {
                int result = pow(n, p);
                //convert base into a string
                stringstream ss;
                ss<< n;
                string temp = ss.str();

                int total=0;
                for (int i=0; i<temp.size(); i++)
                {
                        total = total + pow((temp[i] - '0'),p); //convert char into int, then add power to cumulative total
                        p++;
                }
                if (total == n*(total/n))
                {
                        return total/n;
                }
                else
                        return -1;
        }


int main()
{
        int base,
            power;
        cout << "Enter your base number: " << endl;
        cin >> base;
        while (!cin)
        {
                cout << "Bad input, enter another." << endl;
                cin >> base;
        }
        cout << "Enter your power: " << endl;
        cin >> power;
        while (!cin)
               {
                cout << "Bad input, enter another." << endl;
                cin >> power;
        }
        cout << "Your result: " << digPow(base, power);
        cout << endl;
        return 0;

}
                                             