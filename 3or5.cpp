/* Program: 3or5.cpp
 * Description: If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Finish the solution so that it returns the sum of all the multiples of 3 or 5 below the number passed in.
 * Example: solution(10) = 23
 * Kata: 6
 * Date: 8/31/2018
 */
#include <iostream>
using namespace std;


int solution(int number)
{
        int sum = 0;
        for (int i=0; i<number; i++)
        {
                if (i %3 ==0 || i%5 ==0) //multiple of 3 or 5
                {
                        sum = sum +i;
                }
        }
        return sum;
}


int main()
{
        int n;
        cout << "Enter your number: " << endl;
        cin >> n;
        cout << solution(n) << endl;
        return 0;
}
