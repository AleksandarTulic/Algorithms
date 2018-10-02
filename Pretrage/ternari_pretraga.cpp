int ternari_pretraga(int lijevo, int desno, int a[], int ele)
{
    while ( lijevo <= desno )
    {
        int mid1 = lijevo + ( desno - lijevo ) / 3;
        int mid2 = desno - ( desno - lijevo ) / 3;

        if ( a[mid1] == ele ) return mid1;
        else if ( a[mid2] == ele ) return mid2;

        if ( a[mid1] > ele ) return ternari_pretraga(lijevo, mid1 - 1, a, ele);
        else if ( a[mid2] < ele ) return ternari_pretraga(desno, mid2 + 1, a, ele);
        else return ternari_pretraga(mid1 + 1, mid2 - 1, a, ele);
    }

    return -1;
}
