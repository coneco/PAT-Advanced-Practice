#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, m, c1, c2;
  scanf("%d %d %d %d", &n, &m, &c1, &c2);
  
  int nTeams[500] = {0};
  int graph[500][500] = {0};
  for (int i = 0; i < n; i++)
  {
    scanf("%d", nTeams + i);
  }
  
  for (int k = 0; k < m; k++)
  {
    int i, j, d;
    scanf("%d %d %d", &i, &j, &d);
    graph[i][j] = graph[j][i] = d;
  }
  
  int dist[500] = {0};
  int visited[500] = {0};
  int nPathes[500] = {0};
  int nMaxTeams[500] = {0};
  
  visited[c1] = 1;
  nPathes[c1] = 1;
  for (int i = 0; i < n; i++)
  {
    nMaxTeams[i] = nTeams[i];
  }
  
  for (int k = 1; k < n; k++)
  {
    int minIndex = c1;
    for (int i = 0; i < n; i++)
    {
      if (!visited[i])
      {
        for (int j = 0; j < n; j++)
        {
          if(visited[j] && graph[i][j] != 0)
          {
            if (dist[i] == 0 || dist[i] > dist[j] + graph[i][j])
            {
              dist[i] = dist[j] + graph[i][j];
              nPathes[i] = nPathes[j]; 
              nMaxTeams[i] = nMaxTeams[j] + nTeams[i];
            } else if (dist[i] == dist[j] + graph[i][j])
            {
              nPathes[i] += nPathes[j];
              if (nMaxTeams[i] < nMaxTeams[j] + nTeams[i])
              {
                nMaxTeams[i] = nMaxTeams[j] + nTeams[i];
              }
            }
          }
        }
        
        if ((dist[minIndex] == 0 || dist[minIndex] > dist[i]) && dist[i] != 0)
        {
          minIndex = i;
        }
      }
    }
    visited[minIndex] = 1;
    for (int i = 0; i < n; i ++){
      if (!visited[i]) nPathes[i] = 0;
    }
    if (visited[c2]) break;
  }
  
  printf("%d %d\n", nPathes[c2], nMaxTeams[c2]);
  
  return 0;
}
