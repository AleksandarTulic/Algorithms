int Seq_pretraga_sa_uredjenom_kolekcijom(int a[], int n, int kljuc)
{
    int br = 0;
    while ( a[br] < kljuc && br < n ) br++;

    if ( a[br] == kljuc ) return br;
    return -1;
}
