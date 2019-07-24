/*

  a - stores integers
  n - size of a
  m - stores sizes of increasing subsequnces of consecutive elements
where a[i] is the ending of that subsequences
  len - length of LICOS
  num - the number at which the subsequence ends
  
  Time complexity: O(n)

*/

pair <int, int> LISOC(int a[], int n)
{
    map <int, int> m;
    int num = 1;
    int len = 0;
    m[a[0]] = 1;

    for (int i=1;i<n;i++)
    {
        m[a[i]] = m[a[i]-1] + 1;
        if ( len < m[a[i]] )
        {
            len = m[a[i]];
            num = a[i];
        }
    }

    return {len, num};
}
