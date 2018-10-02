int binarna_pretraga(int lijevo, int desno, int niz[], int ele)
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
