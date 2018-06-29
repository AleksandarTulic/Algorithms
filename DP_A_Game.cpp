#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int a[n];
    for (int i=0;i<n;i++) cin>>a[i];

    pair <int, int> DP[n+1][n+1];

    for (int i=0;i<n;i++) DP[i][i].first=a[i],DP[i][i].second=0;

    for (int l=2;l<=n;l++)
    {
        for (int i=0;i<=n-l;i++)
        {
            int j=i+l-1;

            if ( a[i]+DP[i+1][j].second > a[j]+DP[i][j-1].second )
            {
                DP[i][j].first=a[i]+DP[i+1][j].second;
                DP[i][j].second=DP[i+1][j].first;
            }
            else
            {
                DP[i][j].first=a[j]+DP[i][j-1].second;
                DP[i][j].second=DP[i][j-1].first;
            }
        }
    }

    cout<<DP[0][n-1].first<<" "<<DP[0][n-1].second<<endl;
    return 0;
}
