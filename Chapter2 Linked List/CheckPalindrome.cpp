// to check palindrome in linked list approach is to find middle term and reverse other half
// abcbc => no need to compare c
// abccba => similar parts

#include <iostream>

using namespace std;
class node
{
public:
    char data;
    node *next;
    node(char data)
    {
        this->data = data;
        next = NULL;
    }
    node *insert(char data)
    {
        node *n = new node(data);
        this->next = n;
        return n;
    }
};

node *reverse(node *&start)
{
    node *prev = NULL;
    node *next = NULL;
    node *curr = start;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

bool checkPalindrome(node *&start)
{
    // Step 1 Find middle using two ptr approach fast and slow
    node *fast = start;
    node *slow = start;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    // Step 2 Reverse the other string passing slow->next as start
    node *head = reverse(slow->next);

    delete slow;
    delete fast;

    // Step 3 Traverse both linked lists and compare
    // optimize- use head first in shortcircuit operator

    while (head != NULL && start != NULL)
    {
        if (head->data != start->data)
            return false;
        head = head->next;
        start = start->next;
    }

    delete head;
    return true;
}

int main()
{
    node *root = new node('a');
    root->insert('b')->insert('c')->insert('c')->insert('b')->insert('a');

    bool res = checkPalindrome(root);

    res ? cout << "Palindrome" : cout << "Not a Palindrome";

    delete root;

    return 0;
}