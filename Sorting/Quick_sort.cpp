int split(int a[], int begin, int end)
{
    int i,j,pivot;
    i = begin;j = end;
    pivot = a[begin];

    while (i < j)
    {
        while (a[i] <= pivot && i < j) i++;
        while (a[j] > pivot) j--;
        if ( i < j ) a[i]^=a[j],a[j]^=a[i],a[i]^=a[j];
    }

    a[begin] = a[j];
    a[j] = pivot;
    return j;
}

void quick_sort(int a[], int begin, int end)
{
    if ( begin < end )
    {
        int pivot = split(a, begin, end);
        quick_sort(a, begin, pivot-1);
        quick_sort(a, pivot+1, end);
    }
}
