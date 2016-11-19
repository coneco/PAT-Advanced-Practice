#include <iostream>
#include <string>
#include <vector>

typedef struct $user
{
  std::string name;
  std::string pw;
}user;

int main(int argc, char const *argv[])
{
  int n, cnt = 0;
  std::vector<user> uList;
  std::cin >> n;
  for (int i = 0; i < n; ++i)
  {
    std::string name, pw;
    std::cin >> name >> pw;
    bool flag = false;
    for (int i = 0; i < pw.length(); ++i)
    {
      if (pw[i] == '1')
      {
        pw[i] = '@';
        flag = true;
      }
      if (pw[i] == '0')
      {
        pw[i] = '%';
        flag = true;
      }
      if (pw[i] == 'l')
      {
        pw[i] = 'L';
        flag = true;
      }
      if (pw[i] == 'O')
      {
        pw[i] = 'o';
        flag = true;
      }
    }
    if (flag)
    {
      user newOne = {.name = name, .pw = pw};
      uList.push_back(newOne);
      cnt++;
    }
  }
  if (!cnt)
  {
    if (n > 1)
    {
      std::cout << "There is " << n << " accounts and no account is modified" << std::endl;
    } 
    else
    {
      std::cout << "There are " << n << " account and no account is modified" << std::endl;
    }
  }
  else
  {
    std::cout << cnt << std::endl;
    for (std::vector<user>::iterator i = uList.begin(); i != uList.end(); ++i)
    {
      std::cout << (*i).name << " " << (*i).pw << std::endl;
    }
  }
  return 0;
}