/*

  Time complexity: O(log B)

*/

#define ll long long

ll binpow(ll a, ll b, ll m){
    ll res = 0;
    a%=m;

    while ( b > 0 ){
        if ( b & 1 ) res = (res + a) % m;

        a = (2 * a) % m;;
        b>>=1;
    }

    return res;
}
