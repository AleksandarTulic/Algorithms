void counting_sort(int n, int a[])
{
    vector <int> br(n+1, 0);

    for (int i=0;i<n;i++)
        br[a[i]]++;

    for (int i=0;i<n;i++)
        for (int j=0;j<br[i];j++)
            cout<<i<<endl;
}
