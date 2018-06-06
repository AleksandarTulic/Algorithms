#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++) cin>>a[i];

    vector <int> dp(n,1);

    for (int i=1;i<n;i++)
        for (int j=0;j<i;j++)
            if ( a[i] > a[j] )dp[i]=max(dp[i],dp[j]+1);
    cout<<dp[n-1]<<endl;
    return 0;
}
