/* Prosti brojevi od 1 do nekog broja n */

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

    vector <bool> prost(n+1,true);

    for (int i=2;i*i<=n;i++)
        if ( prost[i] )
            for (int j=i*2;j<=n;j+=i) prost[j]=false;

    for (int i=2;i<=n;i++)
        if ( prost[i] ) cout<<i<<endl;
    return 0;
}
