/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/
void pushNode(Node *&tail, Node *curr) {
  tail->next = curr;
  tail = curr;
}

Node *sortList(Node *head) {
  Node *zeroHead = new Node(-1);
  Node *zeroTail = zeroHead;
  Node *oneHead = new Node(-1);
  Node *oneTail = oneHead;
  Node *twoHead = new Node(-1);
  Node *twoTail = twoHead;

  Node *curr = head;

  while (curr != NULL) {
    if (curr->data == 0) {
      pushNode(zeroTail, curr);
    } else if (curr->data == 1) {
      pushNode(oneTail, curr);
    } else if (curr->data == 2) {
      pushNode(twoTail, curr);
    }
    curr=curr->next;
  }

  // for merging all the nodes according to the order we

  if (oneHead->next != NULL) {
    zeroTail->next = oneHead->next;
  } else {
    zeroTail->next = twoHead->next;
  }

  oneTail->next = twoHead->next;
  twoTail->next = NULL;

  // Now deleting the extra Nodes (-1)

  head = zeroHead->next;

  delete zeroHead;
  delete oneHead;
  delete twoHead;

  return head;
}