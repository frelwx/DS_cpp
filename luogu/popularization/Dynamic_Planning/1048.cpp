#include<iostream>
using namespace std;
int t ,m, a[110], f[1000000], b[110];
int main()
{
    cin >> t >> m;
    for(int i = 1; i <= m; ++i)
    cin >> a[i] >> b[i];

    for(int i = 1; i <= m; ++i)
        for(int j = t; j >= 0; --j)
            if(j >= a[i])
                f[j] = max(f[j], f[j - a[i]] + b[i]);
    cout << f[t] << endl;
}