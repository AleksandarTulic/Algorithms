void shell_sort(int a[], int n)
{
    int i,j,tmp,h;

    for (h=n/2;h>0;h/=2)
    {
        for (i=h;i<n;i++)
        {
            tmp = a[i];
            for (j=i;j>=h && a[j-h]>tmp;j-=h) a[j] = a[j-h];
            a[j] = tmp;
        }
    }
}
