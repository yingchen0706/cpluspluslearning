#include <iostream>

using namespace std;

struct Node
{
  int data;
  Node* pNext;
  Node(int elem)
  {
    data = elem;
    pNext = NULL;
  }
};
class LinkedList;
ostream& operator<<(ostream&, const LinkedList&);

class LinkedList
{
public:
  LinkedList()
  {
    head = NULL;
  }
  void InsertAtHead(int elem)
  {
    Node* pNode = new Node(elem);
    pNode->pNext = head;
    head = pNode;
  }
  void InsertAtTail(int elem)
  {
    Node* pNode = new Node(elem);
    if (!head)
    {
      head = pNode;
    }
    else
    {
      Node* p = head;
      while(p->pNext)
      {
        p = p->pNext;
      }
      p->pNext = pNode;
    }
  }
  void Reverse()
  {
    if (!head || !head->pNext)
    {
      return;
    }
    Node* pNewHead = head;
    Node* p = head->pNext;
    pNewHead->pNext = NULL;
    Node* pNewElem;
    while(p)
    {
      pNewElem = p;
      p = p->pNext;
      pNewElem->pNext = pNewHead;
      pNewHead = pNewElem;
    }
    head = pNewHead;
  }
  ~LinkedList()
  {
    Node* p = head;
    while(p)
    {
      Node* q = p;
      p = p->pNext;
      delete q;
      q = NULL;
    }
  }
  friend ostream& operator<<(ostream&, const LinkedList&);
private:
  Node* head;
};

ostream& operator<<(ostream& out, const LinkedList& list)
{
  Node* p = list.head;
  while(p)
  {
    out << p->data << " ";
    p = p->pNext;
  }
  return out;
}

int main()
{
  LinkedList list;
  list.InsertAtTail(4);
  list.InsertAtTail(5);
  list.InsertAtHead(3);
  list.InsertAtTail(7);
  list.InsertAtHead(1);
  cout << list << endl;
  list.Reverse();
  cout << list << endl;
}