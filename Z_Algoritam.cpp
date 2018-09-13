#include <iostream>
#include <vector>

using namespace std;

vector <int> Z_algoritam(string a)
{
    int lijevo = 0;
    int desno = 0;
    vector <int> Z(a.size());

    for (int i=1;i<a.size();i++)
    {
        if ( i > desno )
        {
            lijevo = desno = i;
            while ( desno < a.size() && a[desno] == a[desno-lijevo] ) desno++;
            Z[i] = desno - lijevo;
            desno--;
        }
        else
        {
             int j = i - lijevo;

             if ( Z[j] < desno - i + 1 ) Z[i] = Z[j];
             else
             {
                 lijevo = i;
                 while ( desno < a.size() && a[desno] == a[desno-lijevo] ) desno++;
                 Z[i] = desno - lijevo;
                 desno--;
             }
        }
    }

    return Z;
}

int FORMING(string text, string pattern)
{
    string niz = "";
    niz+=pattern;
    niz+='$';
    niz+=text;

    vector <int> Z_niz = Z_algoritam(niz);

    for (int i=pattern.size();i<Z_niz.size();i++)
        if ( Z_niz[i] == pattern.size() ) return i - pattern.size() - 1;
    return -1;
}

int main()
{
    string text, pattern;
    cin>>text>>pattern;

    cout<<FORMING(text, pattern)<<endl;
    return 0;
}
