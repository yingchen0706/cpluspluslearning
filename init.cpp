#include <iostream>
using namespace std;


class A
{
public:
  A() 
  {
    cout << "Construct A" << endl;
  }
  A(A& a) 
  {
    cout << "Copy A" << endl;
  }
};


class B
{
public:
  B() 
  {
    cout << "Construct B" << endl;
  }
  B(B& b) 
  {
    cout << "copy B" << endl;
  }
};

class Parent
{
private:
  virtual void fn(int a)  { cout << a << endl;}
public:
  void testPrivate(Parent p) {p.fn(1);}
  Parent() 
  {
    cout << "Construct Parent" << endl;
  }
};

class Parent2
{
public:
  Parent2() 
  {
    cout << "Construct Parent2" << endl;
  }
};

class Child : Parent2, Parent
{
public:
  void fn(int a) {}
  Child(A& _a, B& _b): b(_b), a(_a) 
  {
    cout << "Construct Child" << endl;
  }
  A a;
  B b;
};


class PP
{
  private:
  int _a;
public:
  PP(int a){_a = a;}
  int getA(){return _a;}
};

class CC : public PP
{
  public:
  CC(int b): PP(b){ 
    _b = 10*b;
  }
  int getB(){return _b;}
  private:
  int _b;

};

int main()
{
  A a;
  B b;
  
  Child c(a,b);
  c.fn(1);
  CC p(10);
  
  cout<<p.getA()<<endl;
  cout<<p.getB()<<endl;
  
  Parent pa, pb;
  pb.testPrivate(pb);
}