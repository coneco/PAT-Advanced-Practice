#include <iostream>
#include <string>
#include <stack>
#define MAX 30 



void getPO(int* preorder, int* inorder, int* postorder, int lpi);
int getIndex(int value, int* order, int l);

int main(int argc, char const *argv[])
{
  int preorder[MAX];
  int inorder[MAX];
  int postorder[MAX];

  std::stack<int> poStack;
  int n;
  std::cin >> n;
  int i = 0;
  int k = 0;
  while(i < n) 
  {

    std::string s;
    std::cin >> s;
    if (s == "Push")
    {
      int num;
      std::cin >> num;
      poStack.push(num);
      preorder[k]= num;
      ++k;
    } else {
      inorder[i] = poStack.top();
      ++i;
      poStack.pop();
    }
  }

  getPO(preorder, inorder, postorder, n);

  std::cout << postorder[0];
  for (int i = 1; i < n; ++i)
  {
    std::cout << " " << postorder[i];
  }
  std::cout << std::endl;
  return 0;
}

void getPO(int* preorder, int* inorder, int* postorder, int lpi)
{

  postorder[lpi - 1] = *preorder;

  int iRoot = getIndex(*preorder, inorder, lpi);
  int leftL = iRoot;
  int rightL = lpi - 1 - iRoot;
  if(leftL){
    getPO(preorder + 1, inorder, postorder, leftL);
  }
  if(rightL){
    getPO(preorder + leftL + 1, inorder + iRoot + 1, postorder + leftL, rightL);
  }
}

int getIndex(int value, int* order, int l)
{
  for (int i = 0; i < l; ++i)
  {
    if (value == order[i])
    {
      return i;
    }
  }
  return -1;
}