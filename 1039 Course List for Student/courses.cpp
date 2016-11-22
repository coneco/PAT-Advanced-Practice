#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include <cstdio>

int n2i(char* n);


int main(int argc, char const *argv[])
{
  std::vector<std::vector<int> > nameMap(175760);
  int n, k;
  std::scanf("%d %d", &n, &k);
  while(k--) 
  {
    int crs, nStu;
    std::scanf("%d %d", &crs, &nStu);
    for (int i = 0; i < nStu; ++i)
    {
      char stu[5];
      std::scanf("%s", stu);
      int iStu = n2i(stu);
      nameMap[iStu].push_back(crs);
    }
  }
  while(n--) 
  {
    char qry[5];
    std::scanf("%s", qry);
    std::vector<int> v = nameMap[n2i(qry)];
    std::sort(v.begin(), v.end());
    std::cout << qry << ' ' << v.size();
    for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
    {
      std::cout << ' ' << *i;
    }
    std::cout << std::endl;
  }
  return 0;
}

int n2i(char* n){
  return (n[0] - 'A') * 6760 + (n[1] - 'A') * 260 + (n[2] - 'A') * 10 + (n[3] - '0');
}

