int najmanji_zajednicki(int a, int b)
{
    if ( b == 0 ) return a;
    return najmanji_zajednicki(b, a % b);
}

int najveci_zajednicki(int a, int b)
{
    return a / najmanji_zajednicki(a,b) * b;
}
