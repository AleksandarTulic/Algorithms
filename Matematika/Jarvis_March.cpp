#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <map>
using namespace std;

/* Jarvis March */

struct point{ int x, y; };

bool orjentacija(point a, point b, point c)
{
    if ( ( (b.y-a.y) * (c.x-b.x) - (b.x-a.x) * (c.y-b.y) ) < 0 ) return true;
    return false;
}

void Convex_Hull(point ko[], int n)
{
    if ( n < 3 ) return;

    vector <int> next(n,-1);

    int l = 0;
    for (int i=1;i<n;i++)
        if ( ko[i].x < ko[l].x ) l=i;

    int p=l,q;
    do
    {
        q=(p+1)%n;
        for (int i=0;i<n;i++)
            if ( orjentacija(ko[p],ko[i],ko[q]) ) q=i;
        next[p]=q;
        p=q;

    }while (p!=l);

    for (int i=0;i<n;i++)
        if ( next[i] != -1 ) cout<<ko[i].x<<" "<<ko[i].y<<endl;
}

int main()
{
    int n;
    cin>>n;

    point ko[n];
    for (int i=0;i<n;i++) cin>>ko[i].x>>ko[i].y;

    Convex_Hull(ko,n);
    return 0;
}
