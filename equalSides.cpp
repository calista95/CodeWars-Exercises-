/*Program: equalSides.cpp
 * Kata: 6
 * Description:You are going to be given an array of integers. Your job is to take that array and find an index N where the sum of the integers to the left of N is equal to the sum of the integers to the right of N. If there is no index that would make this happen, return -1.
 * Example: Let's say you are given the array {1,2,3,4,3,2,1}:
Your function will return the index 3, because at the 3rd position of the array, the sum of left side of the index ({1,2,3}) and the sum of the right side of the index ({3,2,1}) both equal 6.
 * Date: 8/22/2018
 * */

#include <iostream>
#include <vector>
using namespace std;


int find_even_index(vector<int>numbers)
{

        int lsum=0; //left sum
        int rsum=0; //right sum
        for (int i=0; i<numbers.size(); i++)
                {
                        //find sum of all numbers to the left of numbers[i]
                        if (i==0) //there is nothing on the left side
                               lsum = 0;
                        else //there are numbers on the left side
                                {
                                        for (int j=0; j<i; j++)
                                                lsum = lsum+numbers[j];
                                }
                        //find sum of all numbers to the left of numbers[i]
                        if (i==numbers.size()-1) //there is nothing on the right side
                                rsum=0;
                        else //there are numbers on the right side
                        {
                                for (int k=i+1; k<numbers.size(); k++)
                                        rsum=rsum+numbers[k];
                        }
                        //if both sums match, return i
                        if (lsum == rsum)
                                return i;
                        else //reset lsum and rsum
                        {
                                lsum=0;
                                rsum=0;
                        }
                }
        return -1; //equal sides not found
}
int main()
{

        //vector <int> numbers { 1,2,3,4,3,2,1 }; //expected: 3
        //vector<int>numbers{1,100,50,-51,1,1}; //expected: 1
        vector<int>numbers{20, 10, -80, 10, 10, 15, 35}; //expected 0

        cout << find_even_index(numbers) << endl;
        return 0;
}
