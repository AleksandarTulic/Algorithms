/*

  n - numbers of cities
  m - the number of paths that we have
  dist - place for storing minimum distance from city 1
  graf - storage for the paths
    column 0 - city 1
    column 1 - city 2
    column 2 - distance from city 1 to city 2
    
  Time Complexity: O(n*m)
  Space Complexity: O(n)
    
*/

int n, m;
int graf[10001][3];
vector <int> dist(10001, 2e9);

void Bellman_Ford()
{
    dist[1] = 0;

    for (int i=1;i<n;i++)
        for (int j=0;j<m;j++)
            if ( dist[graf[j][1]] > dist[graf[j][0]] + graf[j][2] ) dist[graf[j][1]] = dist[graf[j][0]] + graf[j][2];

    for (int i=1;i<=n;i++) cout<<dist[i]<<" ";
}
