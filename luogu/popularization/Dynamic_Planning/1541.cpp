#include<bits/stdc++.h>
using namespace std;
const int maxn = 352, maxm = 51;
int n ,m, a[maxn], b[maxn], num[maxn], dp[maxm][maxm][maxm][maxm]; // 四张卡片用了多少时获得的最大分数
int f(int x, int y, int k, int l){
    if(dp[x][y][k][l])
        return dp[x][y][k][l];
    int tmp = 0, now = x + 2 * y + 3 * k + 4 * l + 1;
    if(x > 0)
        tmp = max(tmp, f(x - 1, y, k, l));
    if(y > 0)
        tmp = max(tmp, f(x, y - 1, k, l));
    if(k > 0)
        tmp = max(tmp, f(x, y, k - 1, l));
    if(l > 0)
        tmp = max(tmp, f(x, y, k, l - 1));

        
        
    return dp[x][y][k][l] = tmp + a[now];
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= m; ++i){
        cin >> b[i];
        ++num[b[i]];
    }
    dp[0][0][0][0] = a[1];
    cout << f(num[1], num[2], num[3], num[4]) << endl;
    return 0;
}