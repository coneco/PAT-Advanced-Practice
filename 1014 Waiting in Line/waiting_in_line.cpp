#include <cstdio>
#include <queue>
#define NL -1
#define EPT -1
#define CLZ -2

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
int canFin(int* tRemain, int n);

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

  std::queue<int> queries;

  int maxT = 0;
  for (int i = 0; i < k; ++i)
  {
    std::scanf("%d", t + i);
    if (t[i] > maxT)
    {
      maxT = t[i];
    }
    tFinish[i] = -1;
  }

  for (int i = 0; i < q; ++i)
  {
    int query;
    std::scanf("%d", &query);
    queries.push(query - 1);
  }

  for (int i = 0; i < n; ++i)
  {
    tRemain[i] = 0;
  }

  while (behindLine < k && behindLine < n) //初始化，铺满窗口一层
  {
    tRemain[behindLine] = t[behindLine];
    lines[behindLine].push(behindLine);
    ++behindLine;
  }

  do
  {

    int l2i;
    while (((l2i = line2insert(lines, n, m)) != NL) && behindLine < k && tNow <= 540) //插满队列
    {
      lines[l2i].push(behindLine);
      ++behindLine;
    }

    for (int i = 0; i < n; ++i)
    {
      if (tRemain[i] == EPT && lines[i].size())
      {
        pCustomer cCus = lines[i].top();
        tRemain[i] = t[cCus->id];
      }
    }


    int minRI;
    int minRemain = maxT + 1;
    for (int i = 0; i < n; ++i) // 时间经过minRemain
    {
      if (tRemain[i] != EPT && tRemain[i] != CLZ && tRemain[i] < minRemain)
      {
        minRI = i;
        minRemain = tRemain[i];
      }
    }
    tNow += minRemain;

    for (int i = 0; i < n; ++i)
    {
      if (tRemain[i] != EPT && tRemain[i] != CLZ)
      {
        tRemain[i] -= minRemain;
      }
    }

    pCustomer cur = lines[minRI].top(); //离开队列
    tFinish[cur->id] = tNow;
    lines[minRI].pop();
    if (tNow >= 540)
    {
      tRemain[minRI] = CLZ;
      continue;
    }

    if (lines[minRI].size())
    {
      pCustomer next1 = lines[minRI].top();
      tRemain[minRI] = t[next1->id];
    } else {
      tRemain[minRI] = EPT;
    }
    

  } while (!canFin(tRemain, n));

  while(!queries.empty()) 
  {
    int timeFin = tFinish[queries.front()];
    if (timeFin == -1)
    {
      std::printf("Sorry\n");
    } else {
      std::printf("%.2d:%.2d\n", timeFin / 60 + 8, timeFin % 60);
    }
    queries.pop();
  }

  
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

int canFin(int* tRemain, int n)
{
  for (int i = 0; i < n; ++i)
  {
    if (tRemain[i] != EPT && tRemain[i] != CLZ)
    {
      return 0;
    }
  }
  return 1;
}
