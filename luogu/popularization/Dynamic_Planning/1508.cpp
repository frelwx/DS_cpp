#include<iostream>
using namespace std;
const int maxn = 210;
int n, m, maps[maxn][maxn], dp[maxn][maxn], vis[maxn][maxn], dir[3] = {0, -1, 1}, ans;
bool check(int x, int y){
    if(x < 1 || x > n || y < 1 || y > m)
        return false;
    return true;
}
int f(int x, int y){
    if(!check(x, y))
        return 0;
    if(vis[x][y])
        return dp[x][y];
    dp[x][y] = max(max(f(x - 1, y), f(x - 1, y - 1)), f(x - 1, y + 1)) + maps[x][y];
    vis[x][y] = 1;
    return dp[x][y];
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> maps[i][j];
    
    int ans = 0, y = m / 2 + 1;
    ans = max(max(f(n, y), f(n, y - 1)), f(n, y + 1));
    cout << ans << endl;
    return 0;
   
}