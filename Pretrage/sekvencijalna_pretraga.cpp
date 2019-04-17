int Seq_pretraga(int a[], int n, int kljuc)
{
    for (int i=0;i<n;i++)
        if ( a[i] == kljuc ) return i;
    return -1;
}
