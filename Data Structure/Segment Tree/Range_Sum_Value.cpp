/*

    build() -  complexity: O(N)
    update() - complexity: O(log N)
    query()  - complexity: O(log N)
    
      - l starts from 1
      - r ends at N

*/

vector <int> tree(1000001, 0);
int niz[1000001];

void build(int node, int l, int r){
    if ( l == r ){
        tree[node] = niz[l];
        return;
    }

    int mid = ( l + r ) / 2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);

    tree[node] = tree[2*node] + tree[2*node+1];
}

void update(int node, int l, int r, int index, int v){
    if ( l == r ){
        tree[node]=v;
        //niz[index]+=v;
    }
    else{
        int mid = (l + r) / 2;
        if ( l <= index && index <= mid ){
            update(2*node, l, mid, index, v);
        }
        else{
            update(2*node+1, mid+1, r, index, v);
        }

        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

int query(int node, int l, int r, int ll, int rr){
    if ( rr < l || r < ll ) return 0;
    if ( ll <= l && r <= rr ) return tree[node];

    int mid = (l + r) / 2;

    return query(2*node, l, mid, ll, rr) + query(2*node+1, mid+1, r, ll, rr);
}
