int n,m;
vector <int> puni(501, 7e7);
vector <vector <int> > graf(501, puni);

void Floyd_Warshall()
{
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                graf[i][j] = min(graf[i][j], graf[i][k] + graf[k][j]);
}
