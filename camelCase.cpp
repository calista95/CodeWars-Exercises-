/* Program: camelCase.cpp
 * Description: Complete the method/function so that it converts dash/underscore delimited words into camel casing. The first word within the output should be capitalized only if the original word was capitalized.
 * Example: to_camel_case("the-stealth-warrior") // returns "theStealthWarrior"
 * Kata: 6
 * Date: 8/26/2018
 */

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;

string to_camel_case(string s)
        {
                vector<char>temp;
                for (int i=0; i<s.size(); i++) //put string into vector
                        temp.push_back(s[i]);
                for (int i=0; i<temp.size(); i++) //process
                {
                        if (temp[i] == '_' || temp[i] == '-')
                        {
                                //make the next char cap
                                temp[i+1] = toupper(temp[i+1]);
                                //delete the '_'
                                temp.erase(temp.begin()+i);
                                //i--;
                        }
                }
                string strC(temp.begin(), temp.end());
                return strC;
        }


int main()
{
        string s;
        cout << "Type in your string: " << endl;
        cin >> s;

        cout << to_camel_case(s) << endl;

        return 0;
}
