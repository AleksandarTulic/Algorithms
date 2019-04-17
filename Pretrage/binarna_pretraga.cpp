int binarna_pretraga1(int lijevo, int desno, int niz[], int ele)
{
    while ( lijevo <= desno )
    {
        int mid = lijevo + ( desno - lijevo ) / 2;

        if ( niz[mid] == ele ) return mid;
        else if ( niz[mid] > ele ) desno = mid - 1;
        else lijevo = mid + 1;
    }

    return lijevo;
}

int binarna_pretraga2(int a[], int begin, int end, int kljuc)
{
    if ( begin <= end )
    {
        int sredina = (begin + end)/2;

        if ( a[sredina] == kljuc ) return sredina;
        else if ( a[sredina] > kljuc ) return binarna_pretraga(a,begin, sredina -1, kljuc);
        else return binarna_pretraga(a, sredina+1, end,kljuc);
    }
}
