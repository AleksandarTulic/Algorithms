/*

    Finding query:
        - choose a range to find minimum value
        - l is the number the says how many elements is in the range
        - k is log2(l) it tells us how many elements we are looking (2^k) from position left
            - if k is 0 then we will look only minimum of one element 2^0
            - if k is 1 then we will look minimum of two elements     2^1
            - and so on
        - l - (1<<k) is the number of elements we still need to check
        - we compare value from position [left][k] and we move to the next left + l - (1<<k) element and find
minimum from the next 2^k elements and compare with [left][k]
    Computing:
        - the first column is always as same as the i (because if we compare one number than the smallest number is
himself)
        - then we will go throw the columns j while ( 2^j <= n ) that is while the length is smaller than the size of the array
        - we go over rows i while ( i + 2^j - 1 < n ) that is while the position(from where we are looking) + size
-1 (because array starts with 0 index) is smaller then the elements left in array to look for
        - we look if element minimum of elements at [i][j-1] and [i + (1 << (j - 1))][j-1]
            - we look those elements because every 2^j can be divided into two groups
                - one group is the element from where we are looking(left) and the next 2^(j-1) elements
                - second group is the element at i+2^(j-1)(why is this so because we looked already the previous 
2^(j-1) elements and now we look at the other half starting from that element) and the next 2^(j-1)
    Time complexity (pre_computing): O(Nlog N)
    Space complexity: O(Nlog N)
    Time complexity (for query): O(1)
*/


int a[1000];
int st[1000][25];
int n;

void pre_compute()
{
    for (int i=0;i<n;i++) st[i][0] = i;

    for (int j=1;1<<j<=n;j++){
        for (int i=0;i+(1<<j)-1<n;i++){
            if ( a[st[i][j - 1]] < a[st[i + (1 << (j - 1))][j-1]] ){
                st[i][j] = st[i][j-1];
            }
            else{
                st[i][j] = st[i + (1 << (j - 1))][j-1];
            }
        }
    }
}

int query(int left, int right)
{
    int l = right - left + 1;
    int k = log2(l);

    if ( a[st[left][k]] <= a[st[left + l - (1 << k)][k]] ) return a[st[left][k]];
    else return a[st[right - (1 << k)+1][k]];
}
