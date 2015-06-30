#include <iostream>
using namespace std;

class Parent
{
public:
  Parent(int i):m_parentMem(i)
  {
    
  }
  Parent()
  {
    cout << "Parent cons" << endl;
  }
protected:
  int m_parentMem;  
};

class Child : public Parent 
{
public:
  Child(int i) : Parent(i)
  {
    
  }
  Child()
  {
    cout << "child cons" << endl;
  }
  void TryToAccess(Child* p)
  {
    cout << p->m_parentMem << endl;
    cout << m_parentMem << endl;
  }
};

int main()
{
  Child p(11);
  Child c(12);

  c.TryToAccess(&p);
  Child child;
  return 0;
}