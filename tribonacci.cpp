/*Program: Tribonacci Sequence
 *Date: 8/6/2018
 *Description: Well met with Fibonacci bigger brother, AKA Tribonacci.
As the name may already reveal, it works basically like a Fibonacci, but summing the last 3 (instead of 2) numbers of the sequence to generate the next. And, worse part of it, regrettably I won't get to hear non-native Italian speakers trying to pronounce it :(
So, if we are to start our Tribonacci sequence with [1, 1, 1] as a starting input (AKA signature), we have this sequence:
[1, 1 ,1, 3, 5, 9, 17, 31, ...]


But what if we started with [0, 0, 1] as a signature? As starting with [0, 1] instead of [1, 1] basically shifts the common Fibonacci sequence by once place, you may be tempted to think that we would get the same sequence shifted by 2 places, but that is not the case and we would get:
[0, 0, 1, 1, 2, 4, 7, 13, 24, ...]


Well, you may have guessed it by now, but to be clear: you need to create a fibonacci function that given a signature array/list, returns the first n elements - signature included of the so seeded sequence.
Signature will always contain 3 numbers; n will always be a non-negative number; if n == 0, then return an empty array and be ready for anything else which is not clearly specified
*Example:
        input: signature = [0, 0, 1]
        output: [0, 0, 1, 1, 2, 4, 7, 13, 24, ...]
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> tribonacci(vector<int> sig, int n)
{
        if (n>=3)
        {
                int num1=sig[0];
                cout << num1 << " ";
                int num2=sig[1];
                cout << num2 << " ";
                int num3=sig[2];
                cout << num3 << " ";
                int sum=num1+num2+num3;

                for (int i=0; i<n-3; i++)
                {
                        int temp = num3;
                        num3 = num3 + num2 + num1;
                        cout << num3 << " ";
                        sig.push_back(num3);
                        num1=num2;
                        num2=temp;
                }
        }
        else //n<3
        {
  		if (n==2)
                        sig.pop_back();
                else if (n==1)
                        {
                        sig.pop_back();
                        sig.pop_back();
                        }
                else
                        sig.clear();

        }
        return sig;
}


int main()
{
        int num;
        int input;
        vector<int> sig = {0,0,1};

        cout << "How many numbers do you want to display?" << endl;
        cin >> num;
        while (!cin)
        {
                cout << "Bad input. Please enter again. " << endl;
                cin >> num;
        }
        cout << "How many numbers are in your signature? Select an option." << endl;
        cout << "0" << endl;
        cout << "1" << endl;
        cout << "2" << endl;
        cout << "3" << endl;
        cin >> input;
        while (input <0 || input>3 || !cin)
        {
                cout << "Bad input. Please enter another." << endl;
                cin >> input;
        }
        int temp;
        switch(input)
        {
                case 1:
                        cout << "Enter number: " << endl;
                        cin >> temp;
                        while (!cin)
                        {
                                cout << "Bad input, enter another." << endl;
                                cin >> temp;
   			}
                        sig.push_back(temp);

                        break;
                case 2:
                        for (int i=0; i<2; i++)
                        {
                        cout << "Enter number: " << endl;
                        cin >> temp;
                        while (!cin)
                        {
                                cout << "Bad input, enter another." << endl;
                                cin >> temp;
                        }
                        sig.push_back(temp);
                        }
                        break;
                case 3:
                        for (int i=0; i<3; i++)
                        {
                        cout << "Enter number: " << endl;
                        cin >> temp;
                        while (!cin)
                        {
                                cout << "Bad input, enter another." << endl;
                                cin >> temp;
                        }
                        sig.push_back(temp);

                        }
        }

        tribonacci(sig, num);

        return 0;
}
                                           