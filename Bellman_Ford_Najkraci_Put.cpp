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

    vector <int> dist(n+1,2e9);
    dist[1]=0;

    int graf[m][3];
    for (int i=0;i<m;i++) cin>>graf[i][0]>>graf[i][1]>>graf[i][2];

    for (int i=1;i<n;i++)
        for (int j=0;j<m;j++)
            if ( dist[graf[j][1]] > dist[graf[j][0]] + graf[j][2] ) dist[graf[j][1]] = dist[graf[j][0]] + graf[j][2];

    cout<<dist[n]<<endl;
    return 0;
}
