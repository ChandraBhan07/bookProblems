/*
 Given two strings, write a function to check if they are
one edit (or zero edits) away.
*/

// naive approach is to use two for loops and increase iterator to check elements
#include <iostream>
#include <string>

using namespace std;

bool oneEditAway(string original, string edited)
{
    int editCount = 0;

    int i = 0, j = 0;

    while (i < original.length())
    {
        while (j < edited.length())
        {

            cout << "i j " << i << " " << j << endl;
            if (original[i] == edited[j])
            {
                cout << "if " << endl;
                i++;
                j++;
                break;
            }
            else
            {
                cout << "else " << endl;
                editCount++;
                i++;
            }
        }
    }
    cout << "final i j " << i << " " << j << endl;

    while (j <= edited.length())
    {
        editCount++;
        j++;
    }

    return editCount;
}

int main()
{

    string original = "abcd";
    string edited = "abde";

    cout << oneEditAway(original, edited);

    return 0;
}