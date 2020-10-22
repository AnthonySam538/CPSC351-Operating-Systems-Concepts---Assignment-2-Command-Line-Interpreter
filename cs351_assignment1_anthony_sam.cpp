#include <iostream>

using namespace std;

int main()
{
  int myNum;
  
  cout << "Type in a number: ";
  cin >> myNum; //So I think this invokes a system call
  cout << myNum;
  
  system("PAUSE"); //Or maybe this invokes a system call
  
  return 0;
}
