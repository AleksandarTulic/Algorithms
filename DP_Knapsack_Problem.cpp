#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
    int n,granica;
    cin>>n>>granica;

    int v[n],t[n];
    for (int i=0;i<n;i++) cin>>v[i]>>t[i];

    int dp[n][granica+1];

    for (int i=0;i<=granica;i++)
        if ( i >= t[0] ) dp[0][i] = v[0];
        else dp[0][i] = 0;

    for (int i=0;i<n;i++) dp[i][0] = 0;

    for (int i=1;i<n;i++)
        for (int j=1;j<=granica;j++)
            if ( j >= t[i] ) dp[i][j] = max(dp[i-1][j],dp[i-1][j-t[i]]+v[i]);
            else dp[i][j] = dp[i-1][j];
            
    cout<<dp[n-1][granica]<<endl;
    return 0;
}
