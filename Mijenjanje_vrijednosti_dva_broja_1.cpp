#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;

    a^=b;
    b^=a;
    a^=b;

    cout<<a<<" "<<b<<endl;
    return 0;
}
