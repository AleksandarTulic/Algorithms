#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
    int visina;
    cin>>visina;

    int n;
    cin>>n;

    int a[n];
    for (int i=0;i<n;i++) cin>>a[i];

    int dp[n][visina+1];
    for (int i=0;i<=visina;i++) dp[0][i]=2e9;
    for (int i=0;i<n;i++) dp[i][0]=0;

    dp[0][a[0]]=1;

    for (int i=1;i<n;i++)
        for (int j=1;j<=visina;j++)
            if ( j >= a[i] && dp[i][j]!=2e9 ) dp[i][j]=min(dp[i-1][j],dp[i-1][j-a[i]]+1);
            else dp[i][j]=dp[i-1][j];

    if ( dp[n-1][visina] != 2e9 ) cout<<dp[n-1][visina]<<endl;
    else cout<<"Suma se ne moze ostvariti"<<endl;
    return 0;
}
