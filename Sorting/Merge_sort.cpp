void merge_sort(int a[], int begin, int end)
{
    if ( begin < end )
    {
        int sredina = ( begin + end ) / 2;
        merge_sort(a,begin,sredina);
        merge_sort(a,sredina+1,end);

        int niz[end-begin+1];int i = begin,j = sredina + 1,k = 0;
        for (;i<=sredina && j<=end;k++)
            niz[k] = a[i] < a[j] ? a[i++] : a[j++];

        while ( i <= sredina ) niz[k++] = a[i++];
        while ( j <= end ) niz[k++] = a[j++];

        for (i=begin;i<=end;i++)
            a[i] = niz[i-begin];
    }
}
