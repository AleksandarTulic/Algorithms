void insertion_sort(int a[], int n)
{
    int i,j,tmp;

    for (i=1;i<n;i++)
    {
        tmp = a[i];
        for (j=i;j>0 && a[j-1] > tmp;j--) a[j] = a[j-1];
        a[j] = tmp;
    }
}
