/*

  Space complexity: O(sqrt(n) + S)
    - S - block size

*/

int n;
vector <int> prime;

void sieve(){
    int kor = sqrt(n);
    vector <char> flag(kor+1, true);
    for (int i=2;i<=kor;i++){
        if ( flag[i] ){
            prime.push_back(i);
            for (int j=i*i;j<=kor;j+=i){
                flag[j] = false;
            }
        }
    }
}

void Block_Sieve(){

    sieve();
    int S = 1e5;
    vector <int> block(S);

    for (int k=0;k*S<=n;k++){
        fill(block.begin(), block.end(), true);
        int start = k * S;
        for (int i=0;i<prime.size();i++){
            int sidx = (start + prime[i] - 1) / prime[i];
            int j = max(sidx, prime[i]) * prime[i] - start;
            for (;j<S;j+=prime[i]){
                block[j] = false;
            }
        }

        if ( k == 0 ) block[0] = block[1] = false;
        for (int i=0;i<S;i++){
            if ( block[i] && i <= n ) cout<<i+start<<endl;
            else if ( i > n ) return;
        }
    }
}
