#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <queue>

char subjectName[] = {'C', 'M', 'E', 'A'};

typedef struct gradeList 
{
  int grade[4];
  int rank[4];
} g_and_r;

int main ()
{
  std::map<int, g_and_r> students;
  std::queue<int> checkList;
  int n, m;
  std::cin >> n >> m;

  int id, gc, gm, ge, ga;
  for (int i = 0; i < n; ++i)
  {
    std::cin >> id >> gc >> gm >> ge;
    ga = (gc + gm + ge) / 3;
    students[id] = {.grade = {gc, gm, ge, ga}};
  }

  for (int i = 0; i < m; ++i)
  {
    std::cin >> id;
    checkList.push(id);
  }
  
  int studentsRemain[4] = {n, n, n, n};
  int rankCur[4];
  int rankNext[4] = {1, 1, 1, 1};

  for (int grade = 100; grade >= 0; --grade)
  {
    memcpy(rankCur, rankNext, 4 * sizeof(int));
    std::map<int, g_and_r>::iterator iter = students.begin();
    while (iter != students.end())
    {
      for (int j = 0; j < 4; ++j) {
        if ((iter->second).grade[j] == grade)
        {
          (iter->second).rank[j] = rankCur[j];
          ++rankNext[j];
          --studentsRemain[j];
        }
      }
      ++iter;
    }
    if (studentsRemain[0] == 0 && studentsRemain[1] == 0 && studentsRemain[2] == 0 && studentsRemain[3] == 0)
    {
      break;
    }
  }

  
  while (!checkList.empty())
  {
    int id = checkList.front();
    checkList.pop();
    std::map<int, g_and_r>::iterator stuChecked = students.find(id);
    if (stuChecked != students.end())
    {
      int maxRank = (stuChecked->second).rank[3];
      int maxRankI = 3;
      for (int i = 0; i < 3; ++i)
      {
        if ((stuChecked->second).rank[i] < maxRank)
        {
          maxRank = (stuChecked->second).rank[i];
          maxRankI = i;
        }
      }
      std::cout << maxRank << ' ' << subjectName[maxRankI] << std::endl;
    } else {
      std::cout << "N/A" << std::endl;
    }
  }

  return 0;
}