#include <cstdio>
#include <string.h>
#include <vector>
#include <algorithm>

int c;

typedef struct $stu
{
  int id;
  char name[9];
  int score;
} stu;

bool cmpStu(stu s1, stu s2);

int main(int argc, char const *argv[])
{
  std::vector<stu> stuList;
  int n;
  std::scanf("%d %d", &n, &c);
  for (int i = 0; i < n; ++i)
  {
    stu newOne;
    std::scanf("%d %s %d", &(newOne.id), newOne.name, &(newOne.score));
    stuList.push_back(newOne);
  }

  sort(stuList.begin(), stuList.end(), cmpStu);

  for (std::vector<stu>::iterator i = stuList.begin(); i != stuList.end(); ++i)
  {
    std::printf("%.6d %s %d\n", (*i).id, (*i).name, (*i).score);
  }

  return 0;
}

bool cmpStu(stu s1, stu s2)
{
  if (c == 1)
  {
    return s1.id < s2.id;
  } 
  else if (c == 2)
  {
    for (int i = 0; i < 9; ++i)
    {
      if (strcmp(s1.name, s2. name) < 0)
      {
        return true;
      }
      else if (strcmp(s1.name, s2. name) > 0)
      {
        return false;
      }
      return s1.id < s2.id;
    }
  }
  else if (c == 3)
  {
    if (s1.score == s2.score)
    {
      return s1.id < s2.id;
    }
    return s1.score < s2.score;
  }
}