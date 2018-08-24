/* Program: primeWord
 * Description: X and Y are playing a game. A list will be provided which contains n pairs of strings and integers. They have to add the integeri to the ASCII values of the stringi characters. Then they have to check if any of the new added numbers is prime or not. If for any character of the word the added number is prime then the word will be considered as prime word.
 * Example: prime_word({{"Emma",30},{"Liam",30}}) = {1,1};
 * For the first word "Emma" ASCII values are: 69 109 109 97
After adding 30 the values will be: 99 139 139 127
As 139 is prime number so "Emma" is a Prime Word.
 * Kata: 6
 * Date: 8/23/2018
 */
#include <iostream>
#include <vector>
using namespace std;

bool foundPrime(vector<int>temp) //function that checks if there is a prime in a vector
{
        for (int i=0; i<temp.size(); i++)
        {
                if (temp[i] ==1)
                        return 1; //prime is found
        }
        return 0; //assume prime is not found otherewise
}

vector<int> prime_word(vector<pair<string, int>>list)
{
        vector<int>results;
        vector<int>temp;
        bool prime = true;
        for (int i=0; i<list.size(); i++)
        {
                string myStr = list[i].first;
                //evaluate each char of the string
                for (int j=0; j<myStr.size(); j++)
                {
                        int sum=int(myStr[j]) +list[i].second;
                        for (int k=2; k<sum; k++)
                        {
                                if (sum%k == 0) //divisible by a factor other than 1 and self
                                {
                                        prime = false; //set flag to not prime
                                        break;
                                }
                        }
                        if(prime == true)
                                temp.push_back(1);
                        else
                                temp.push_back(0);
                        prime = true; //reset the flag
                }
                if (foundPrime(temp)) //there is a prime in the vector
                        results.push_back(1);
                else //no prime found
                        results.push_back(0);
                temp.clear(); //reset temp vector for next round
        }
        return results;
}



int main()
{
        vector<int>results;
        //results = prime_word({{"Emma",30},{"Liam",30}});
        //results = prime_word({{"Olivia",20},{"Noah",45}});
        results = prime_word({{"Ava",75},{"William",50}});

  	//display results
        for (int i=0; i<results.size(); i++)
        {
                cout << results[i] << " ";
        }

        return 0;
}

