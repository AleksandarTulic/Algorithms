/*
    a - array of numbers
    n - size of the array
    dp - value of subarrays
    i (for loop) - place where the subarray would end (we assume)

    Time complexity: O(n)
    Space complexity: O(n)
*/

int kadane_s(vector <int> a, int n)
{
    vector <int> dp(n, 0);
    dp[0] = a[0];

    for (int i=1;i<n;i++)
        dp[i] = max(a[i], a[i] + dp[i-1]);

    sort(dp.begin(), dp.end());
    return dp[n-1];
}
