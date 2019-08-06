/*

  Time complexity: O(n)

*/

int n;
vector <int> prime;
vector <int> lp(1000000, 0);

void Linear_Sieve(){
    for (int i=2;i<=n;i++){
        if ( !lp[i] ){
            lp[i] = i;
            prime.push_back(i);
        }
        for (int j=0;j<prime.size() && prime[j] <= lp[i] && prime[j] * i <= n;j++)
            lp[i * prime[j]] = prime[j];
    }
}
