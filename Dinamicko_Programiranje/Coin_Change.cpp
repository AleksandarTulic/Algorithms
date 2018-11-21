#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
    int sum,n;
    cin>>sum>>n;

    int a[n];
    for (int i=0;i<n;i++) cin>>a[i];

    vector <int> dp(sum+1,2e9);
    dp[0]=0;

    for (int i=0;i<n;i++)
        for (int j=1;j<=sum;j++)
            if ( j >= a[i] ) dp[j] = min(dp[j],dp[j-a[i]]+1);

    cout<<dp[sum]<<endl;
    return 0;
}
