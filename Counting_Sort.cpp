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
    vector <int> br(1e5+1,0);
    vector <int> niz;

    for (int i=0;i<n;i++)
    {
        cin>>a[i];

        bool flag = true;

        for (int j=0;j<niz.size();j++)
            if ( niz[j] == a[i] ) { flag=false; break; }

        if ( flag ) niz.push_back(a[i]);
    }

    for (int i=0;i<niz.size();i++)
        for (int j=0;j<n;j++)
            if ( niz[i] == a[j] ) br[niz[i]]++;

    for (int i=0;i<niz.size();i++)
        for (int j=0;j<br[niz[i]];j++) cout<<niz[i]<<" ";
    return 0;
}
