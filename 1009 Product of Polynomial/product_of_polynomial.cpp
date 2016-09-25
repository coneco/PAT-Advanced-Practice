#include <cstdio>
#include <vector>

typedef struct polynomial_term
{
  double a;
  int n;
} term;

std::vector<term> sum(std::vector<term> p1, std::vector<term> p2);

term termProduct(term t1, term t2);

std::vector<term> product(std::vector<term> p, term t);
std::vector<term> product(std::vector<term> p1, std::vector<term> p2);


int main(int argc, char const *argv[])
{
  std::vector<term> p1, p2, result;
  int k;
  term inputTerm;

  std::scanf("%d", &k);
  for (int i = 0; i < k; ++i)
  {
    std::scanf("%d %lf", &inputTerm.n, &inputTerm.a);
    p1.push_back(inputTerm);
  }

  std::scanf("%d", &k);
  for (int i = 0; i < k; ++i)
  {
    std::scanf("%d %lf", &inputTerm.n, &inputTerm.a);
    p2.push_back(inputTerm);
  }
  result = product(p1, p2);

  std::vector<term>::iterator iter = result.begin();
  std::printf("%d", (int) result.size());
  while (iter != result.end())
  {
    std::printf(" %d %.1lf", (*iter).n, (*iter).a);
    iter++;
  }
  std::printf("\n");

  return 0;
}


std::vector<term> sum(std::vector<term> p1, std::vector<term> p2)
{
  std::vector<term> ret;
  term sumHead;
  std::vector<term>::iterator iter1, iter2;
  iter1 = p1.begin();
  iter2 = p2.begin();
  while (! (iter1 == p1.end() && iter2 == p2.end()))
  {
    if (iter1 == p1.end())
    {
      sumHead = *iter2;
      iter2++;
    } else if (iter2 == p2.end())
    {
      sumHead = *iter1;
      iter1++;
    } else if ((*iter1).n < (*iter2).n) {
      sumHead = *iter2;
      iter2++;
    } else if ((*iter2).n < (*iter1).n) {
      sumHead = *iter1;
      iter1++;
    } else if ((*iter2).a + (*iter1).a != 0) {
      sumHead.n = (*iter1).n;
      sumHead.a = (*iter1).a + (*iter2).a;
      iter1++;
      iter2++;
    } else {
      iter1++;
      iter2++;
      continue;
    }
    ret.push_back(sumHead);
  }
  return ret;
}

term termProduct(term t1, term t2)
{
  term ret;
  ret.n = t1.n + t2.n;
  ret.a = t1.a * t2.a;
  return ret;
}

std::vector<term> product(std::vector<term> p, term t)
{
  std::vector<term> ret;
  std::vector<term>::iterator iter = p.begin();
  while (iter != p.end())
  {
    ret.push_back(termProduct(*iter, t));
    iter++;
  }
  return ret;
}

std::vector<term> product(std::vector<term> p1, std::vector<term> p2)
{
  std::vector<term> ret;
  std::vector<term>::iterator iter1 = p1.begin();
  while (iter1 != p1.end())
  {
    ret = sum(ret, product(p2, *iter1));
    iter1++;
  }
  return ret;
}
