/*

  Time complexity: O(N*log log N)

*/

void SIEVE_of_ERATHOSTHEN(){
    bitset <10001> prime;
    prime[0] = prime[1] = 1;

    for (int i=2;(long long)i*i<=10000;i++)
        if ( !prime[i] )
            for (int j=i*i;j<=10000;j+=i) prime[j] = 1;

    for (int i=2;i<=100;i++)
        if ( !prime[i] ) cout<<i<<" ";
}
