#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    vector <int> vi(n+1,2e9);
    vector <vector <int> > graf(n+1,vi);

    for (int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        graf[a][b]=c;
        graf[b][a]=c;
    }

    vector <int> uda(n+1,2e9);
    vector <bool> bio(n+1,true);
    uda[1]=0;
    int MST = 0;

    for (int i=1;i<=n;i++)
    {
        int dist = 2e9, tko;
        for (int j=1;j<=n;j++)
            if ( bio[j] && dist > uda[i] ) dist = uda[i], tko = j;
        bio[tko] = false;
        MST+=dist;

        for (int j=1;j<=n;j++)
            if ( uda[j] > graf[tko][j] ) uda[j] = graf[tko][j];
    }

    cout<<MST<<endl;
    return 0;
}
