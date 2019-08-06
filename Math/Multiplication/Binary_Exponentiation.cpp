/*
  Time coplexity: O(log N)
  Recursive
  
*/

#define ll long long

ll binpow(ll a, ll n){
    if ( n == 0 ) return 1;
    ll res = binpow(a, n/2);
    if ( n & 1 ) return res * res * a;
    else return res * res;
}

/*
  Iterative
*/

ll binpow(ll a, ll n){
    ll res = 1;
    while ( n > 0 ){
        if ( n & 1 ) res*=a;

        a*=a;
        n>>=1;
    }

    return res;
}
