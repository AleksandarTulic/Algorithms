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

    int rez = 0;
    while (x>>=1) { rez++; }
    cout<<rez<<endl;
    return 0;
}
