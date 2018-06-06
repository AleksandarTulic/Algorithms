/* Ukoliko imamo zadatu sumu i pokusavamo je dobiti preko elemnata niza */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
    int visina;
    cin>>visina;

    int n;
    cin>>n;

    int ele[n];
    for (int i=0;i<n;i++) cin>>ele[i];

    for (int i=0;i<(1<<n);i++)
    {
        int suma = 0;
        for (int j=0;j<n;j++)
            if ( ( 1 << j ) & i ) suma+=ele[j];

        if ( suma == visina ) { cout<<"Moze se dobiti"<<endl; return 0; }
    }

    cout<<"Ne moze se dobiti"<<endl;
    return 0;
}
