#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <map>

using namespace std;

int n;
int a[100001];

int binarna_pretraga(int l, int r, int broj)
{
    if ( l > r ) return -1;
    int mid = l+(r-l)/2;

    if ( a[mid] == broj ) return mid;
    else if ( a[mid] > broj ) return binarna_pretraga(l,mid-1,broj);
    else return binarna_pretraga(mid+1,r,broj);
}

int main()
{
    cin>>n;

    for (int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);

    int m;
    cin>>m;

    int poz = binarna_pretraga(0,n-1,m);

    if ( poz == -1 ) cout<<"broj nije u nizu"<<endl;
    else cout<<"broj se nalazi na poziciji "<<poz<<endl;
    return 0;
}
