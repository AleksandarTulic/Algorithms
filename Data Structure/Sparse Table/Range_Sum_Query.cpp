void pre_compute()
{
    for (int i=0;i<n;i++) st[i][0] = a[i];

    for (int j=1;(1<<j)<=n;j++){
        for (int i=0;i+(1<<j)-1<n;i++){
            st[i][j] = st[i][j-1] + st[i + (1 << (j-1))][j-1];
        }
    }
}

int query(int left, int right)
{
    int sum = 0;
    for (int j=2;j>=0;j--){
        if ( (1<<j) <= right-left+1 )
        {
            sum+=st[left][j];
            left+=(1<<j);
        }
    }

    return sum;
}
