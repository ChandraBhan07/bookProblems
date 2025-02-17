/*
Given two strings, write a method to decide if one is a permutation of the other.
*/
/*
bruteforce - to slide a window of length of smaller on larger and sort the window charaters
then if both string matches then its permutation

Better Approach yet to find
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// sorting * iteration
// nlogn * N => n = len(smaller), N = len(larger)
int countPermutationBruteForce(string sm, string lg)
{
    sort(sm.begin(), sm.end());
    int count = 0;
    int windowSize = sm.length();
    for (int i = 0; i < lg.length() - windowSize + 1; i++)
    {
        string str = lg.substr(i, windowSize);
        sort(str.begin(), str.end());
        if (str == sm)
        {
            cout << i << " ";
            count++;
        }
    }
    cout << endl;

    return count;
}

int countPermutationRecursive(string sm, string lg, int start, int count)
{
    // base case
    if (start >= lg.length() - sm.length() + 1)
    {
        return count;
    }
    string str = lg.substr(start, sm.length());
    sort(str.begin(), str.end());
    if (str == sm)
        return countPermutationRecursive(sm, lg, start + 1, count + 1);

    return countPermutationRecursive(sm, lg, start + 1, count);
}

int main()
{
    string smaller = "abbc";
    string larger = "abcabccabbc";

    // cout << countPermutationBruteForce(smaller, larger) << endl;

    int num = countPermutationRecursive(smaller, larger, 0, 0);
    cout << num;

    return 0;
}