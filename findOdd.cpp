/* Program: findOdd.cpp
 * Description: Given an array, find the int that appears an odd number of times.
There will always be only one integer that appears an odd number of times. Find that integer.
 * Kata: 6
 * Date: 8/28/2018
 *  */

#include <iostream>
#include <vector>
using namespace std;


struct NumCount //to store key-value pair of number identity and count
{
        int num;
        int count;
};

bool found(vector<NumCount*>temp, int n)
{
        for (int i=0; i<temp.size(); i++)
        {
                if (temp[i]->num == n)
                        return true;
        }
        return false;
}

int findOdd(vector<int>v)
{
        vector<NumCount*>temp;
        NumCount*nc;
        //put first number in temp vector after initializing values
        nc = new NumCount;
        nc->num = v[0];
        nc->count = 1;
        temp.push_back(nc);

        //iterate through the rest of the array
        for (int i=1; i<v.size(); i++)
        {
                if (found(temp, v[i]) == false) //not in the array yet
                {
                        nc = new NumCount;
                        nc->num = v[i];
                        nc->count = 1;
                        temp.push_back(nc);
                }
                else //already in the array
                {
                        //find the pair with matching num, then increment count
                        for (int j=0; j<temp.size(); j++)
                        {
                                if (temp[j]->num == v[i])
                                {
                                        temp[j]->count++;
                                        break;
                                }
                        }
                }
        }

        NumCount*oddCount;

        for (int i=0; i<temp.size(); i++)
        {
                if (temp[i]->count%2 !=0) //odd count
                        oddCount = temp[i];
        }
        return oddCount->num;
}


int main()
{
        /*test cases*/

        vector<int>v;
                //v={20,1,-1,2,-2,3,3,5,5,1,2,4,20,4,-1,-2,5}; //expected 5
                //v={1,1,2,-2,5,2,4,4,-1,-2,5}; //expected -1
  		//v={20,1,1,2,2,3,3,5,5,4,20,4,5}; //expected 5
                v={1,1,1,1,1,1,10,1,1,1,1}; //expected 10
        	cout << "The largest count comes from number: " << findOdd(v)<< endl;

        return 0;
}

