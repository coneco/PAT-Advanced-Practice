#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>


std::map<std::string, std::vector<int> > library[5];

int main(int argc, char const *argv[])
{
  int n;
  std::cin >> n;
  while(n--)
  {
    int id;
    std::string title;
    std::string author;
    std::string keys;
    std::vector<std::string> kws;
    std::string puber;
    std::string year;

    std::cin >> id;
    std::cin.get();
    std::getline(std::cin, title);
    std::getline(std::cin, author);
    std::getline(std::cin, keys);
    std::getline(std::cin, puber);
    std::getline(std::cin, year);

    library[0][title].push_back(id);
    library[1][author].push_back(id);

    std::string key = "";
    for (int i = 0; i < keys.length(); ++i)
    {
      if (keys[i] != ' ')
      {
        key.append(1, keys[i]);
      }
      else
      {
        kws.push_back(key);
        key="";
      }
      if (i == keys.length() - 1)
      {
        kws.push_back(key);
      }
    }

    for (std::vector<std::string>::iterator i = kws.begin(); i != kws.end(); ++i)
    {
      library[2][*i].push_back(id);
    }

    library[3][puber].push_back(id);
    library[4][year].push_back(id);
  }

  int m;
  std::cin >> m;
  while(m--) 
  {
    int k;
    std::string query;
    std::scanf("%d: ", &k);
    std::getline(std::cin, query);
    std::cout << k << ": " << query << std::endl;
    if (library[k-1][query].empty())
    {
      std::cout << "Not Found" << std::endl;
    }
    else
    {
      sort(library[k-1][query].begin(), library[k-1][query].end());
      for (std::vector<int>::iterator i = library[k-1][query].begin(); i != library[k-1][query].end(); ++i)
      {
        int output = *i;
        std::printf("%.6d\n", output);
      }
    }
  }
  return 0;
}