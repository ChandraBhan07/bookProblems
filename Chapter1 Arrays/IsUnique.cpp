/**
 Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you
cannot use additional data structures?
*/

#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

// Using set - O(n)
bool isUniqueUsingDatastructure(string s)
{
    unordered_set<char> seen;
    for (char c : s)
    {
        if (seen.find(c) != seen.end())
            return false;

        seen.insert(c);
    }
    return true;
}

// No Datastrucure - Sorting - O(nlogn)
#include <algorithm>
bool isUnique(string s)
{
    sort(s.begin(), s.end()); // Sort the string
    for (int i = 1; i < s.length(); ++i)
    {
        if (s[i] == s[i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s = "abcdefg";
    if (isUniqueUsingDatastructure(s))
        cout << "The string has all unique characters." << endl;

    if (isUnique(s))
        cout << "The string has all unique characters." << endl;

    return 0;
}
