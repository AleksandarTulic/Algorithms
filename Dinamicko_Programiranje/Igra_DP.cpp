pair <int, int> GAME_DP(int n, int a[])
{
    pair <int, int> dp[n+1][n+1];

    for (int i=0;i<n;i++) dp[i][i].first = a[i], dp[i][i].second = 0;

    for (int l=2;l<=n;l++)
    {
        for (int i=0;i<=n-l;i++)
        {
            int j = i+l-1;

            if ( a[i] + dp[i+1][j].second > a[j] + dp[i][j-1].second )
            {
                dp[i][j].first = a[i] + dp[i+1][j].second;
                dp[i][j].second = dp[i+1][j].first;
            }
            else
            {
                dp[i][j].first = a[j] + dp[i][j-1].second;
                dp[i][j].second = dp[i][j-1].first;
            }
        }
    }

    return {dp[0][n-1].first, dp[0][n-1].second};
}
