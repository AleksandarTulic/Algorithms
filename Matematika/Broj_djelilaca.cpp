int number_divisor(int n)
{
    map <int, int> broj;
    vector <int> num;
    for (int i=2;i<=n && n != 0 ;i++)
    {
        int br = 0;
        while ( n % i == 0 )
        {
            br++;
            n/=i;
        }

        if ( br != 0 )
        {
            broj[i] = br;
            num.push_back(i);
        }
    }

    int p = broj[num[0]] + 1;
    for (int i=1;i<num.size();i++) p*=(broj[num[i]]+1);

    return p;
}
