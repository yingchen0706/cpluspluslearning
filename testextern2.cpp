#include <iostream>
using namespace std;
extern int a;
extern void fn(int);
int main()
{
  fn(a);
  a = 1;
  fn(a);
}