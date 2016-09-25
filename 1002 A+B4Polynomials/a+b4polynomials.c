#include <stdio.h>
#include <stdlib.h>

typedef struct term
{
  int n;
  float a;
  struct term* pNext;
}* pTerm;

int SIZE = sizeof(struct term);

void copyTerm(pTerm p, pTerm p0)
{
  p->n = p0->n;
  p->a = p0->a;
}

void buildTerms(int m, pTerm pHead)
{
  pTerm p1, p2;
  for (int i = 0; i < m; i++)
  {
    p1 = (pTerm) malloc(SIZE);
    scanf("%d %f", &p1->n, &p1->a);
    p1->pNext = NULL;
    if (i == 0)
    {
      pHead->pNext = p1;
    } else {
      p2->pNext = p1;
    }
    p2 = p1;
  }
}

int sumTerms(pTerm pHeadSum, pTerm pHead1, pTerm pHead2)
{
  int ret = 0;
  pTerm pT1, pT2, p1, p2;
  pT1 = pHead1->pNext;
  pT2 = pHead2->pNext;
  while (pT1 != NULL || pT2 != NULL)
  {
    p1 = (pTerm) malloc(SIZE);
    if (pT1 == NULL)
    {
      copyTerm(p1, pT2);
      pT2 = pT2->pNext;
    } else if (pT2 == NULL) {
      copyTerm(p1, pT1);
      pT1 = pT1->pNext;
    } else if (pT1->n > pT2->n) {
      copyTerm(p1, pT1);
      pT1 = pT1->pNext;
    } else if (pT1->n < pT2->n) {
      copyTerm(p1, pT2);
      pT2 = pT2->pNext;
    } else if (pT1->a + pT2->a != 0) {
      p1->n = pT1->n;
      p1->a = pT1->a + pT2->a;
      pT1 = pT1->pNext;
      pT2 = pT2->pNext;
    } else {
      free(p1);
      pT1 = pT1->pNext;
      pT2 = pT2->pNext;
      continue;
    }
    p1->pNext = NULL;
    if (ret == 0)
    {
      pHeadSum->pNext = p1;
    } else {
      p2->pNext = p1;
    }
    p2 = p1;
    ret += 1;
    free(p1);
  }
  return ret;
}

void printTerms(pTerm pHead)
{
  pTerm p;
  p = pHead->pNext;
  while (p != NULL)
  {
    printf(" %d %.1f", p->n, p->a);
    p = p->pNext;
  }
  printf("\n");
}

void freeTerms(pTerm pHead)
{
  pTerm temp;
  while (pHead != NULL)
  {
    temp = pHead->pNext;
    free(pHead);
    pHead = temp;
  }
}

int main()
{
  int m1, m2, mRet;
  pTerm pHeadSum, pHead1, pHead2;
  pHeadSum = (pTerm) malloc(SIZE);
  pHead1 = (pTerm) malloc(SIZE);
  pHead2 = (pTerm) malloc(SIZE);
  scanf("%d", &m1);
  buildTerms(m1, pHead1);
  scanf("%d", &m2);
  buildTerms(m2, pHead2);
  mRet = sumTerms(pHeadSum, pHead1, pHead2);
  printf("%d", mRet);
  printTerms(pHeadSum);
  freeTerms(pHeadSum);
  freeTerms(pHead1);
  freeTerms(pHead2);
  return 0;
}

