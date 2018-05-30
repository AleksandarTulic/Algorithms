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

    int rez = 0;
    for (int i=0;i<n;i++)
        rez^=a[i];
    cout<<rez<<endl;
    return 0;
}
