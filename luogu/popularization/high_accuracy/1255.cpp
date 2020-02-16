#include<iostream>
using namespace std;
const int maxn = 5e3 + 10;
int n, f[maxn][6000], len[maxn];
void add(int x){
    int k = max(len[x - 1], len[x - 2]), delta = 0;

    for(int i = 1; i <= k + 1; ++i){
        f[x][i] = f[x - 1][i] + f[x - 2][i] + delta;
        delta = f[x][i] / 10;
        f[x][i] %= 10;
    }
    while(f[x][k + 1] == 0)
        --k;
    len[x] = k + 1;
}
int main()
{
    cin >> n;
    f[0][1] = f[1][1] = len[0] = len[1] = 1;

    for(int i = 2;i <= n; ++i)
    add(i);
    f[0][1] = 0;
    for(int i = len[n]; i >= 1; --i)
    cout << f[n][i];
    cout << endl;
    return 0;
}