#include <cstdio>
#include <queue>

typedef struct node
{
  int id;
  struct node* next;
  struct node* last;
}* pCustomer;

class Line
{
private:
  int length;
  pCustomer head;
  pCustomer end;

public:
  Line()
  {
    length = 0;
    head = new struct node;
    end = new struct node;
    head->last = NULL;
    head->next = end;
    end->last = head;
    end->next = NULL;
  }

  void push(int id, int during)
  {
    pCustomer pLast = end->last;
    pCustomer pCus = new struct node;
    pCus->id = id;
    pCus->next = end;
    pCus->last = pLast;
    end->last = pCus;
    pLast->next = pCus;
    ++length;
  }

  void pop()
  {
    if (length)
    {
      pCustomer pTop = head->next;
      head->next = pTop->next;
      (head->next)->last = head;
      delete pTop;
    }
  }

  pCustomer top()
  {
    return head->next;
  }

  int size()
  {
    return length;
  }

  ~Line()
  {
    pCustomer toDelete;
    while (head != end)
    {
      toDelete = head->next;
      delete head;
      head = toDelete;
    } 
    delete end;
  }

  
};

int main(int argc, char const *argv[])
{
  int n, m, k, q;
  int behindLine = 0;
  int tNow = 0;
  std::scanf("%d %d %d %d", &n, &m, &k, &q);
  int* t = new int[k];
  int* tFinish = new int[k]; 
  int* tRemain = new int[n];
  Line* lines = new Line[n];

  for (int i = 0; i < k; ++i)
  {
    std::scanf("%d", t + i);
  }

  for (int i = 0; i < n; ++i)
  {
    tRemain[i] = 0;
  }

  while (behindLine < k && behindLine < n)
  {
    tRemain[behindLine] = t[behindLine];
    lines[behindLine].push(behindLine);
    ++behindLine;
  }



  
  delete[] t;
  delete[] tFinish;
  delete[] tRemain;
  delete[] lines;
  return 0;
}