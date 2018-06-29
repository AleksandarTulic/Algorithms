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
vector <int> fenwick(100001,0);

void update(int x, int vr)
{
    for (;x<=100000;x+=x&-x)
        fenwick[x]+=vr;
}

int query(int x)
{
    int res = 0;
    for (;x>0;x-=x&-x)
        res+=fenwick[x];
    return res;
}

int main()
{
    cin>>n;
    for (int i=0;i<n;i++) { cin>>a[i]; update(a[i],1); }

    for (int i=0;i<n;i++)
        cout<<"Broj elemenata manjih od ovog elementa "<<a[i]<<" je "<<query(a[i])-1<<endl;
    return 0;
}
