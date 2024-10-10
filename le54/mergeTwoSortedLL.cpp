#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int data)
    {
        this->val = data;
        this->next = NULL;
    }
};

// Function to print the linked list
void print(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to insert a new node at the end of the list
void Insert(ListNode *&tail, int element)
{
    ListNode *newListNode = new ListNode(element);
    tail->next = newListNode;
    tail = newListNode;
}

// Function to merge two sorted linked lists
ListNode* mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (!list1) return list2;
    if (!list2) return list1;

    // Creating a dummy node to simplify the merge process
    ListNode *dummy = new ListNode(-1);
    ListNode *tail = dummy;

    ListNode *pt1 = list1;
    ListNode *pt2 = list2;

    // Merge the two lists by choosing the smaller node each time
    while (pt1 != NULL && pt2 != NULL)
    {
        if (pt1->val <= pt2->val)
        {
            tail->next = pt1;
            pt1 = pt1->next;
        }
        else
        {
            tail->next = pt2;
            pt2 = pt2->next;
        }
        tail = tail->next;
    }

    // Attach the remaining nodes of list1 or list2
    if (pt1 != NULL)
        tail->next = pt1;
    else
        tail->next = pt2;

    // Return the merged list starting from the next of dummy node
    ListNode *mergedHead = dummy->next;
    delete dummy; // Free the dummy node
    return mergedHead;
}

int main()
{
    // Create the first sorted linked list
    ListNode *Node1 = new ListNode(5);
    ListNode *head1 = Node1;
    ListNode *tail1 = Node1;
    Insert(tail1, 7);
    Insert(tail1, 10);
    Insert(tail1, 15);
    Insert(tail1, 17);

    // Create the second sorted linked list
    ListNode *Node2 = new ListNode(1);
    ListNode *head2 = Node2;
    ListNode *tail2 = Node2;
    Insert(tail2, 3);
    Insert(tail2, 5);
    Insert(tail2, 6);
    Insert(tail2, 14);
    Insert(tail2, 19);
    Insert(tail2, 20);

    // Merge the two sorted linked lists
    ListNode *mergedList = mergeTwoLists(head1, head2);

    // Print the merged list
    cout << "After merging two sorted linked lists, we get: " << endl;
    print(mergedList);

    return 0;
}
