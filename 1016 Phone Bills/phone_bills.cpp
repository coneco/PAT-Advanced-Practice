#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>


typedef struct callRecord
{
  int sd;
  int sh;
  int sm;
  int fd;
  int fh;
  int fm;
  int callLength;
  int callFee;
} c_rcd;

typedef struct inputRecord
{
  std::string name;
  int date;
  int hour;
  int minute;
  int type;
} record;

bool cmpRcd(record r1, record r2);

int fee(int sd, int sh, int sm, int fd, int fh, int fm, int* rate, int* callLength);

int main(int argc, char const *argv[])
{
  int n, month, rate[24];
  std::vector<record> records;
  for (int i = 0; i < 24; ++i)
  {
    std::scanf("%d", rate + i);
  }

  std::scanf("%d", &n);

  for (int i = 0; i < n; ++i)
  {
    record rcd;
    std::string tp;
    std::cin >> rcd.name;
    std::scanf("%d:%d:%d:%d", &month, &rcd.date, &rcd.hour, &rcd.minute);
    std::cin >> tp;

    if (tp == "on-line")
    {
      rcd.type = 1;
    } else {
      rcd.type = 0;
    }
    records.push_back(rcd);
  }

  sort(records.begin(), records.end(), cmpRcd);

  std::queue<c_rcd> rcdQueue;
  int total = 0;
  int tag = 0;
  int sd, sh, sm, fd, fh, fm;
  std::vector<record>::iterator iter = records.begin();
  std::string nameCur = (*iter).name;

  // std::cout << nameCur << ' ';
  // std::printf("%.2d\n", month);

  while(iter != records.end())
  {
    if ((*iter).name != nameCur)
    {
      if (!rcdQueue.empty())
      {
        std::cout << nameCur << ' ';
        std::printf("%.2d\n", month);
        while(!rcdQueue.empty()) 
        {
          c_rcd sRcd = rcdQueue.front();
          std::printf("%.2d:%.2d:%.2d %.2d:%.2d:%.2d %d $%d.%.2d\n", 
            sRcd.sd, sRcd.sh, sRcd.sm, sRcd.fd, sRcd.fh, sRcd.fm, sRcd.callLength, sRcd.callFee/100, sRcd.callFee%100);
          rcdQueue.pop();
        }
        std::printf("Total amount: $%d.%.2d\n", total/100, total%100);
      }
      total = 0;
      nameCur = (*iter).name;
      tag = 0;
    }

    if ((*iter).type)
    {
      sd = (*iter).date;
      sh = (*iter).hour;
      sm = (*iter).minute;
      tag = 1;
    }
    if (tag && (!((*iter).type)))
    {
      fd = (*iter).date;
      fh = (*iter).hour;
      fm = (*iter).minute;

      c_rcd geneRcd;
      int callLength;
      int callFee = fee(sd, sh, sm, fd, fh, fm, rate, &callLength);
      total += callFee;
      geneRcd.sd = sd; 
      geneRcd.sh = sh; 
      geneRcd.sm = sm; 
      geneRcd.fd = fd; 
      geneRcd.fh = fh; 
      geneRcd.fm = fm; 
      geneRcd.callLength = callLength; 
      geneRcd.callFee = callFee;
      rcdQueue.push(geneRcd);
      tag = 0;
    }
    ++iter;
  }
  if (!rcdQueue.empty())
  {
    std::cout << nameCur << ' ';
    std::printf("%.2d\n", month);
    while(!rcdQueue.empty()) 
    {
      c_rcd sRcd = rcdQueue.front();
      std::printf("%.2d:%.2d:%.2d %.2d:%.2d:%.2d %d $%d.%.2d\n", 
        sRcd.sd, sRcd.sh, sRcd.sm, sRcd.fd, sRcd.fh, sRcd.fm, sRcd.callLength, sRcd.callFee/100, sRcd.callFee%100);
      rcdQueue.pop();
    }
    std::printf("Total amount: $%d.%.2d\n", total/100, total%100);
  }
  
  return 0;
}

bool cmpRcd(record r1, record r2){
  if (r1.name != r2.name)
  {
    return r1.name < r2.name;
  } else if (r1.date != r2.date) {
    return r1.date < r2.date;
  } else if (r1.hour != r2.hour) {
    return r1.hour < r2.hour;
  } else {
    return r1.minute < r2.minute;
  }
}

int fee(int sd, int sh, int sm, int fd, int fh, int fm, int* rate, int* callLength)
{
  int minutes[24] = {0};
  while (!(sm == fm && sh == fh && sd == fd))
  {
    ++minutes[sh];
    ++sm;
    if (sm == 60)
    {
      sm = 0;
      ++sh;
    }
    if (sh == 24)
    {
      sh = 0;
      ++sd;
    }
  }
  int ret = 0;
  *callLength = 0;
  for (int i = 0; i < 24; ++i)
  {
    ret += rate[i] * minutes[i];
    *callLength += minutes[i];
  }
  return ret;
}