// a -> b -> c -> d -> e
// g -> q -> e -> r -> y
// e is the intersection we have to find it if exits
// simple approach is to use map => O(n) space and time

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
        next = nullptr;
    }
    node *insert(int data)
    {
        node *n = new node(data);
        this->next = n;
        return n;
    }
};

node *findIntersection(node *listOne, node *listTwo)
{
    map<node *, bool> buffer;

    while (listOne != NULL)
    {
        buffer[listOne] = true;
        listOne = listOne->next;
    }

    while (listTwo != NULL)
    {
        if (buffer.find(listTwo) != buffer.end())
            return listTwo;

        listTwo = listTwo->next;
    }

    return nullptr;
}

void deleteList(node *start)
{
    while (start != nullptr)
    {
        node *temp = start;
        start = start->next;
        delete temp;
    }
}

int main()
{
    node *listOne = new node(1);
    node *tail = listOne->insert(3)->insert(5)->insert(7);
    node *intersection = tail->insert(9);

    node *listTwo = new node(2);
    (listTwo->insert(4)->insert(6)->insert(8))->next = intersection;

    node *intersect = findIntersection(listOne, listTwo);
    cout << intersect->data <<endl;

    deleteList(listOne);
    deleteList(listTwo);
    delete tail, intersection, intersect;

    return 0;
}