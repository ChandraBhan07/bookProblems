// L1  2 -> 5 -> 3   L2  4 -> 2 -> 7
// L3  253 + 427 => 6 -> 8 -> 0
#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
    node *insert(int data)
    {
        node *n = new node(data);
        this->next = n;
        return n;
    }
};

node *reverse(node *&start)
{
    node *prev = NULL;
    node *curr = start;
    node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

node *sumLists(node *&list, node *&list2)
{
    // Step 1: We need to reverse lists as addition is done from right
    node *listOne = reverse(list);
    node *listTwo = reverse(list2);
    int sum = 0, carry = 0, digit = 0;

    node *res = new node(-1);
    node *temp = res;

    // Step 2 Simple addition
    while (listOne != NULL || listTwo != NULL)
    {
        int a = 0;
        if (listOne != NULL)
        {
            a = listOne->data;
            listOne = listOne->next;
        }

        int b = 0;
        if (listTwo != NULL)
        {
            b = listTwo->data;
            listTwo = listTwo->next;
        }

        sum = a + b + carry;
        carry = sum / 10;
        digit = sum % 10;

        node *n = new node(digit);
        temp->next = n;
        temp = temp->next;
    }

    if (carry >= 1)
    {
        node *n = new node(carry);
        temp->next = n;
        delete n, temp;
    }

    // Step 3 Reverse the output
    return reverse(res->next);
}

int main()
{
    node *listOne = new node(6);
    listOne->insert(5)
        ->insert(3)
        ->insert(3);
    node *listTwo = new node(4);
    listTwo->insert(2)
        ->insert(7);

    node *res = sumLists(listOne, listTwo);

    while (res != NULL)
    {
        cout << res->data << " ";
        res = res->next;
    }

    delete listOne, listTwo, res;

    return 0;
}