/*

  n - numbers of cities
  m - the number of paths that we have
  graf[u][v] - distance between cities u and v
  If road between city u and city v does not exist then the value of graf[u][v] = INF (very large number)
    
  Time Complexity: O(n^3)
  Space Complexity: O(n*n)
  
  How it works: if we know the distance between u and v we look if there is path with smaller distance
between u and v for example some k. so that the complete distance between two cities (u and v) would be graf[u][k] + graf[k][v]

*/

int n,m;
vector <int> buff(501, 7e7);
vector <vector <int> > graf(501, buff);

void Floyd_Warshall()
{
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                graf[i][j] = min(graf[i][j], graf[i][k] + graf[k][j]);
}
