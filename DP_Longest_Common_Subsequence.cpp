#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <map>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    int a[n];
    for (int i=0;i<n;i++) cin>>a[i];
    int b[m];
    for (int i=0;i<m;i++) cin>>b[i];

    vector <int> vi(n+1,0);
    vector <vector <int> > dp(m+1,vi);

    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            if ( a[j-1] == b[i-1] ) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

    cout<<dp[m][n]<<endl;
    return 0;
}
