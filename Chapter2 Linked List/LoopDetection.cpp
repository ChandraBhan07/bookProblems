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
        next = nullptr;
    }
};

node *loopDetection(node *start)
{
    // Step 1 two pointers approach meeting
    node *fast = start;
    node *slow = start;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
        {
            return slow;
        }
    }

    return nullptr;
}

void loopCorrection(node *start, node *slow)
{
    node *prev = nullptr;
    while (start != nullptr && slow != nullptr)
    {
        prev = slow;
        start = start->next;
        slow = slow->next;
        if (start == slow)
        {
            // we break link where the loop exists
            prev->next = nullptr;
            return;
        }
    }
}
int main()
{
    node *head = new node(5);
    head->next = new node(7);
    head->next->next = new node(1);
    head->next->next->next = new node(8);
    head->next->next->next->next = head->next;

    node *slow = loopDetection(head);
    cout << slow->data << endl;
    if (slow != nullptr)
        loopCorrection(head, slow);

    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }

    for (int i = 0; i < 5; i++)
    {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}