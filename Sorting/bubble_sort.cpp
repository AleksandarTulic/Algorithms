void bubble_sort(int n, int a[])
{
    int br = n;
    while (br--)
        for (int i=0;i<n-1;i++)
            if ( a[i] > a[i+1] ) swap(a[i],a[i+1]);

    for (int i=0;i<n;i++) cout<<a[i]<<" ";
}
