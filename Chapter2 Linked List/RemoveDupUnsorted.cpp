// O(n) for time and space - using map
#include <iostream>
#include <map>

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
    void print()
    {
        node *n = this;
        while (n != NULL)
        {
            cout << n->data << endl;
            n = n->next;
        }
    }
};

void removeDupUnsorted(node *start)
{
    map<int, bool> buffer;
    node *prev = NULL;
    while (start != NULL)
    {
        if (buffer[start->data])
        {
            prev->next = start->next;
        }
        else
        {
            buffer[start->data] = true;
            prev = start;
        }
        start = start->next;
    }
}

int main()
{
    node *root = new node(3);
    root->insert(5)->insert(1)->insert(7)->insert(3)->insert(7)->insert(3)->insert(5);
    removeDupUnsorted(root);
    root->print();
    return 0;
}