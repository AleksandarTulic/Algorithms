#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <iomanip>
#include <map>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int a[n];
    for (int i=0;i<n;i++) cin>>a[i];

    int br = n;
    while (br!=1)
    {
        for (int i=0;i<br-1;i++)
        {
            if ( a[i] > a[i+1] )
            {
                a[i+1]^=a[i];
                a[i]^=a[i+1];
                a[i+1]^=a[i];
            }
        }
        br--;
    }

    for (int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}
