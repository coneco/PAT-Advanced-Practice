#include <iostream>
#include <string>

typedef struct studentInfo
{
  std::string name;
  char gender;
  std::string id;
  int grade;
} stu;

int main(int argc, char const *argv[])
{
  int n;
  stu minMale, maxFemale, cur;
  minMale.gender='D';
  maxFemale.gender='D';
  std::cin >> n;
  while(n--) {
    std::cin >> cur.name >> cur.gender >> cur.id >> cur.grade;
    if (cur.gender == 'M' && (minMale.gender == 'D' || cur.grade < minMale .grade))
    {
      minMale = cur;
    }

    if (cur.gender == 'F' && (maxFemale.gender == 'D' || cur.grade > maxFemale .grade))
    {
      maxFemale = cur;
    }

  }

  int flag = 1;
  if (maxFemale.gender != 'D')
  {
    std::cout << maxFemale.name << " " << maxFemale.id << std::endl;
  }
  else
  {
    flag = 0;
    std::cout << "Absent" << std::endl;
  }

  if (minMale.gender != 'D')
  {
    std::cout << minMale.name << " " << minMale.id << std::endl;
  }
  else
  {
    flag = 0;
    std::cout << "Absent" << std::endl;
  }  
  if (flag)
  {
    std::cout << maxFemale.grade - minMale.grade << std::endl;
  }
  else
  {
    std::cout << "NA" << std::endl;
  }
  return 0;
}