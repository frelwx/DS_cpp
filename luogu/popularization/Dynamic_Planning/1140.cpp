#include<bits/stdc++.h>
using namespace std;
const int maxn = 200;
int n, m, table[6][6] = {{0}, {0, 5, -1, -2, -1, -3}, {0, -1, 5, -3, -2, -4}, {0, -2, -3, 5, -2, -2}, {0, -1, -2, -2, 5, -1}, {0, -3, -4, -2, -1}};
int f[maxn][maxn], aa[maxn], bb[maxn], nn, mm;//a的前i个串和b的前j个串的相似度(非空)
char a[maxn], b[maxn];
int main()
{
    cin >> n >> a + 1 >> m >> b + 1;
    for(int i = 1; i <= n; ++i)
        if(a[i] == 'A')
            aa[++nn] = 1;
        else if(a[i] == 'C')
            aa[++nn] = 2;
        else if(a[i] == 'G')
            aa[++nn]  = 3;
        else if(a[i] == 'T')
            aa[++nn] = 4;
        else aa[++nn] = 5;
    
    for(int i = 1; i <= m; ++i)
        if(b[i] == 'A')
            bb[++mm] = 1;
        else if(b[i] == 'C')
            bb[++mm] = 2;
        else if(b[i] == 'G')
            bb[++mm]  = 3;
        else if(b[i] == 'T')
            bb[++mm] = 4;
        else bb[++mm] = 5;
    for(int i = 1;  i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            f[i][j] = -1e9;
    

    for(int i = 1; i <= n; ++i)
        f[i][0] = f[i - 1][0] + table[aa[i]][5];
    for(int j = 1; j <= m; ++j)
        f[0][j] = f[0][j - 1] + table[5][bb[j]];
    
    
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            f[i][j] = max(max(f[i - 1][j - 1] + table[aa[i]][bb[j]], f[i - 1][j] + table[aa[i]][5]), f[i][j - 1] + table[5][bb[j]]);
    cout << f[n][m] << endl;
    return 0;
}