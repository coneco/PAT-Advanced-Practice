#include <iostream>
#include <string>
#include <map>
#include <stack>

using namespace std;

int main()
{
  map<int, string> numDict;
  numDict[0] = "zero";
  numDict[1] = "one";
  numDict[2] = "two";
  numDict[3] = "three";
  numDict[4] = "four";
  numDict[5] = "five";
  numDict[6] = "six";
  numDict[7] = "seven";
  numDict[8] = "eight";
  numDict[9] = "nine";
  
  string n;
  int sum = 0;
  cin >> n;
  
  for (unsigned int i = 0; i < n.length(); i++)
  {
    sum += (int) n[i] - (int) '0';
  }
  
  stack<string> numStack;
  do
  {
    numStack.push(numDict[sum % 10]);
    sum /= 10;
  } while (sum);
  
  cout << numStack.top();
  numStack.pop();
  while (!numStack.empty())
  {
    cout << " " << numStack.top();
    numStack.pop();
  }
  
  cout << endl;
  
  
  return 0;
}

