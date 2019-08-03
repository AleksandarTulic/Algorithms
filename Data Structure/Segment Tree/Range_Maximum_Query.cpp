vector <int> tree(1000001, -1);
int niz[1000001];
int vel;

void build(int l, int r, int pos){
    if ( l == r ){
        tree[pos] = niz[l];
        return;
    }

    int mid = (l + r)/2;
    build(l, mid, 2*pos+1);
    build(mid+1, r, 2*pos+2);

    tree[pos] = max(tree[2*pos+1], tree[2*pos+2]);
}

void update(int index, int v, int l, int r, int pos){
    if ( index < l || index > r ) return;
    if ( l == r ){
        tree[pos] = v;
        return;
    }

    int mid = (l + r)/2;
    update(index, v, l, mid, 2*pos+1);
    update(index, v, mid+1, r, 2*pos+2);
    tree[pos] = max(tree[2*pos+1], tree[2*pos+2]);
}

int query(int l, int r, int ll, int rr, int pos){
    if ( ll  <= l && rr >= r ) return tree[pos];
    if ( ll > r || rr < l ) return -1;

    int mid = (l + r)/2;

    return max(query(l, mid, ll, rr, 2*pos+1), query(mid+1, r, ll, rr, 2*pos+2));
}

int seg_size(int v){
    for (; !(v && !(v&(v-1))); v++);
    return v;
}
