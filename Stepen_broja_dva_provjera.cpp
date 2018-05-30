#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
    int x;
    cin>>x;

    if ( x && (x & (x-1)) == false ) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
