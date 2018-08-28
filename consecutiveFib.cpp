/* Program: consecutiveFib
 * Description: Given a number, say prod (for product), we search two Fibonacci numbers F(n) and F(n+1) verifying

F(n) * F(n+1) = prod.

Your function productFib takes an integer (prod) and returns an array:

[F(n), F(n+1), true] or {F(n), F(n+1), 1} or (F(n), F(n+1), True)

 * Example:

productFib(714) # should return {21, 34, true},
                # since F(8) = 21, F(9) = 34 and 714 = 21 * 34

productFib(800) # should return {34, 55, false},
                # since F(8) = 21, F(9) = 34, F(10) = 55 and 21 * 34 < 800 < 34 * 55
 * Kata: 5
 * Date: 8/27/2018
 */
#include <iostream>
#include <vector>
typedef unsigned long long ull;
using namespace std;

//takes a position and returns the corresponding fib number
//ex: fibonacci(8)=21 because 8th num of sequence is 21
int fib(int n)
{
   if (n <= 1)
      return n;
   return fib(n-1) + fib(n-2);
}


vector<ull> productFib(int target)
{
        vector<ull>results;
        int num1=1;
        int num2=2;
        int product =0;
        bool found;

        while (product <=target)
        {
                product = fib(num1)*fib(num2);
                if (product == target)
                        {
                                results.push_back(fib(num1));
                                results.push_back(fib(num2));
                                found = true;
                                results.push_back(found);
                                return results;
                        }
                else if (product >target)
                        {
                                results.push_back(fib(num1));
                                results.push_back(fib(num2));
                                found = false;
                                results.push_back(found);
                                return results;
                        }
                else
                {
                        //variable reassignment
                        num1=num2;
                        num2++;
                }
        }
}



int main()
{
        int num;
        cout << "Type your number: " << endl;
        cin >> num;
        vector<ull>test = productFib(num);
        //display results
        for (int i=0; i<3; i++)
  	{
                cout << test[i] << " " ;
        }
        cout << endl;

        return 0;
}


