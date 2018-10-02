void sieve_of_erathosten(int n)
{
    vector <bool> flag(n+1,false);

    for (int i=2;i*i<=n;i++)
        if (!flag[i])
            for (int j=i*2;j<=n;j+=i)
                flag[j] = true;

    for (int i=2;i<=n;i++)
        if ( !flag[i] ) cout<<i<<endl;
}
