#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <queue>
#include <bits/stdc++.h>
#include <set>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    vector <int> vi(n+1,2e9);
    vector <vector <int> > graf;
    graf.insert(graf.begin(),n+1,vi);

    for (int i=0;i<=n;i++) graf[i][i] = 0;
    for (int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        graf[a][b]=c;
        graf[b][a]=c;
    }

    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if ( graf[i][j] > graf[i][k] + graf[k][j] ) graf[i][j] = graf[k][j] + graf[i][k];

    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++) cout<<graf[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
