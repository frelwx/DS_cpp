#include<bits/stdc++.h>
using namespace std;
const int maxn = 100;
int n, m, dp[maxn][maxn], ans;
int f(int x, int y){ // 传了x次， 传到第y个人
    if(x < 0)
        return 0;
    if(dp[x][y])
        return dp[x][y];
    if(y != 1 && x == 0)
        return 0;
    if(y == 1)
        return dp[x][y] = f(x - 1, n) + f(x - 1, y + 1);
    else if(y == n)
        return dp[x][y] = f(x - 1, y - 1) + f(x - 1, 1);
    else 
        return dp[x][y] = f(x - 1, y - 1) + f(x - 1, y + 1);
}

int main()
{
    cin >> n >> m;  
    dp[1][2] = dp[1][n] = dp[0][1] = 1;
    cout << f(m, 1) << endl;
    return 0;
}
