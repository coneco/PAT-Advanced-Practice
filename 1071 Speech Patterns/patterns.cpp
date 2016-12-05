#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>

char str[1050000];
std::map<std::string, int> count;

bool isC(char c)
{
    return (c >= 'a'&&c <= 'z') || (c >= '0'&&c <= '9');
}

int main()
{
    std::cin.getline(str, 1050000);
    strlwr(str);
    int i = 0;
    while (str[i])
    {
        if (isC(str[i]))
        {
            int j = i;
            std::string s;
            while (isC(str[j]))
            {
                s.push_back(str[j]);
                ++j;
            }
            i = j;
            if (count.find(s) == count.end())
            {
                count[s] = 1;
            }
            else
            {
                ++count[s];
            }
        }
        else
        {
            i++;
        }
    }
    std::string s;
    int n = 0;
    for (std::map<std::string, int>::iterator i = count.begin(); i != count.end(); ++i)
    {
        if ((*i).second > n)
        {
            s = (*i).first;
            n = (*i).second;
        }
        else if ((*i).second == n)
        {
            if ((*i).first < s)
            {
                s = (*i).first;
                n = (*i).second;
            }
        }
    }
    std::cout << s << ' ' << n << std::endl;
    return 0;
}
