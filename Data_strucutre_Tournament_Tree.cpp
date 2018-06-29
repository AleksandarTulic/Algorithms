#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <map>

using namespace std;

vector <int> tree;

void update(int a, int b)
{
    tree[a]=b;
    for (a/=2;a;a/=2)
        tree[a]=max(tree[a*2],tree[a*2+1]);
}

int position()
{
    int poz = 1;
    while ( poz*2+1<tree.size() )
        if (  tree[poz*2] > tree[poz*2+1] ) poz*=2;
        else poz=poz*2+1;

    return poz;
}

int query(int node, int par, int to, int a, int b)
{
    if ( par>=a && to<=b ) return tree[node];

    int maks1 = -1; int maks2 = -1;

    if ( (par+to)/2 >= a ) maks1 = query(node*2,par,(par+to)/2,a,b);
    if ( (par+to)/2+1 <= b ) maks2 = query(node*2+1,(par+to)/2+1,to,a,b);

    return max(maks1,maks2);
}

int main()
{
    int n;
    cin>>n;

    int poz=0;
    for (poz=1;poz<n;poz*=2)
        tree.insert(tree.begin(),poz+n+1,-1);

    for (int i=0;i<n;i++) cin>>tree[poz+i];
    for (int i=poz+n-1;i>1;i--)
        if ( tree[i/2] < tree[i] ) tree[i/2]=tree[i];

    update(poz,7);
    cout<<position()<<endl;
    cout<<query(1,0,poz-1,4,6)<<endl;
    return 0;
}
