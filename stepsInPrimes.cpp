/* Program: stepsInPrimes.cpp
 * Description: The prime numbers are not regularly spaced. For example from 2 to 3 the step is 1. From 3 to 5 the step is 2. From 7 to 11 it is 4. Between 2 and 50 we have the following pairs of 2-steps primes:

3, 5 - 5, 7, - 11, 13, - 17, 19, - 29, 31, - 41, 43

We will write a function step with parameters:

g (integer >= 2) which indicates the step we are looking for,

m (integer >= 2) which gives the start of the search (m inclusive),

n (integer >= m) which gives the end of the search (n inclusive)

In the example above step(2, 2, 50) will return [3, 5] which is the first pair between 2 and 50 with a 2-steps.

So this function should return the first pair of the two prime numbers spaced with a step of g between the limits m, n if these g-steps prime numbers exist otherwise nil or null or None or Nothing or [] or "0, 0" or {0, 0} (depending on the language).

#Examples:

step(2, 5, 7) --> [5, 7] or (5, 7) or {5, 7} or "5 7"

step(2, 5, 5) --> nil or ... or [] in Ocaml or {0, 0} in C++

step(4, 130, 200) --> [163, 167] or (163, 167) or {163, 167}
 * Kata: 6
 * Date: 8/25/2018
*/

#include <iostream>
#include <utility>
using namespace std;


bool isPrime(int n)
{
        for (int i=2; i<n; i++)
        {
                if (n%i ==0)
                        return false;
        }
        return true;
}



pair<int, int> step(int target, int start, int end)
{
 	pair<int, int> result;
        for (int i=start; i<end; i++) //outer loop for first number
        {
                if (isPrime(i)) //first number is prime
                        {

                                for (int j=start+1; j<=end; j++) //inner loop for second number
                                        {
                                                if (isPrime(j)) //second number is prime
                                                        {
                                                                //cout << "first num: " << i << endl;
                                                                //cout << "second num: " << j << endl;
                                                                if (j-i == target)
                                                                {
                                                                        //cout << "difference found" << endl;
                                                                        result.first = i;
                                                                        result.second = j;
                                                                        return result;
                                                                }

                                                        }
                                        }
                        }
        }

        result.first = 0;
        result.second = 0;
        return result;
}




int main()
{

        /*test cases*/

        //pair<int, int>result = step(2, 2, 7);
        pair<int, int> result = step(2,100,110);
        cout << result.first << " ";
        cout << result.second;
        cout << endl;
        /*
        pair<int, int> result = step(11, 3000, 10000);
        cout << result.first << " ";
        cout << result.second;
        cout << endl;

  	pair<int, int> result = step(2,2,50);
        cout << result.first << " ";
        cout << result.second;
        cout << endl;

        pair<int, int> result = step(4,100,110);
        cout << result.first << " ";
        cout << result.second;
        cout << endl;

        pair<int, int> result = step(6,100,110);
        cout << result.first << " ";
        cout << result.second;
        cout << endl;

        pair<int, int> result = step(8,300,400);
        cout << result.first << " ";
        cout << result.second;
        cout << endl;

        pair<int, int> result = step(10,300,400);
        cout << result.first << " ";
        cout << result.second;
        cout << endl;
        */

        return 0;
}
                          