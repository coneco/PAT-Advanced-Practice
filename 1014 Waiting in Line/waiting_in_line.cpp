#include <cstdio>
#include <queue>
#define NL -1

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

  void push(int id)
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
      --length;
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

int line2insert(Line* lines, int n, int m);
int allEmpty(Line* lines, int n);

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

  do
  {

    int l2i;
    while (((l2i = line2insert(lines, n, m)) != NL) && behindLine < k)
    {
      lines[l2i].push(behindLine);
      ++behindLine;
    }


    int minRI = 0;
    int minRemain = tRemain[0];
    for (int i = 1; i < n; ++i)
    {
      if (tRemain[i] < minRemain)
      {
        minRI = i;
        minRemain = tRemain[i];
      }
    }
    tNow += minRemain;

    for (int i = 0; i < n; ++i)
    {
      tRemain[i] -= minRemain;
    }

    pCustomer cur = lines[minRI].top();
    tFinish[cur->id] = tNow;
    lines[minRI].pop();
    pCustomer next1 = lines[minRI].top();
    tRemin[minRI] = t[next1->id];

  } while (!allEmpty(lines, n));

  
  delete[] t;
  delete[] tFinish;
  delete[] tRemain;
  delete[] lines;
  return 0;
}

int line2insert(Line* lines, int n, int m)
{
  int shortest = 0;
  int slength = lines[0].size();

  for (int i = 1; i < n; ++i)
  {
    if (lines[i].size() < slength)
    {
      shortest = i;
      slength = lines[i].size();
    }
  }

  if (slength < m)
  {
    return shortest;
  } else {
    return NL;
  }
}

int allEmpty(Line* lines, int n)
{
  for (int i = 0; i < n; ++i)
  {
    if (lines[i].size() > 0)
    {
      return 0;
    }
  }
  return 1;
}