void Seq_pretraga_samoorganizujuca1(int *a, int n, int kljuc)
{
    int i,j;

    for (i=0;i<n;i++)
    {
        if ( *(a + i) == kljuc )
        {
            int b = *(a + i);
            for (j=i;j>0;j--) *(a+j)=*(a+j-1);
            *a = b;
        }
    }
}

void Seq_pretraga_samoorganizujuca2(int *a, int n, int kljuc)
{
    int i,j;

    for (i=0;i<n;i++)
    {
        if ( *(a+i) == kljuc )
        {
            for (j=i;j<n-1;j++) *(a + j) = *( a + j + 1 );
            *( a + n - 1 ) = kljuc;
        }
    }
}
