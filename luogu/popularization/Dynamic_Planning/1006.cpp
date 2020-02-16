#include<bits/stdc++.h>
using namespace std;
const int maxn = 51;
int m, n, maps[maxn][maxn], dp[maxn][maxn][maxn][maxn]; // 定义dp为 第一张纸条传到i, j, 第二张传到k, l时的最小花费
int max(int x, int y, int xx, int yy){
    int tmp = 0;
    tmp = max(x, y);
    tmp = max(tmp, xx);
    tmp = max(tmp, yy);
    return tmp;
}
int main()
{
    cin >> m >> n;
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> maps[i][j];
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
            for(int k = 1; k <= m; ++k)
                for(int l = j + 1; l <= n; ++l)
                    dp[i][j][k][l] = max(dp[i - 1][j][k - 1][l], dp[i][j - 1][k - 1][l], dp[i - 1][j][k][l - 1], dp[i][j - 1][k][l - 1]) + maps[i][j] + maps[k][l];
    cout << dp[m][n - 1][m - 1][n] << endl;
    return 0;
}   