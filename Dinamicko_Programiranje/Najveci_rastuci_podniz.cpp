int najveci_rastuci_podniz(int n, int a[])
{
    vector <int> dp(n+1,1);

    for (int i=1;i<n;i++)
        for (int j=0;j<i;j++)
            if ( a[i] > a[j] ) dp[i] = max(dp[i], dp[j] + 1);

    return dp[n-1];
}
