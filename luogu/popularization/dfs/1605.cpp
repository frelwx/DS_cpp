#include<iostream>
using namespace std;
int n, m, t, sx, sy, fx, fy, dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0}, ans = 0;
bool maps[6][6], vis[6][6];
bool check(int x, int y){
    if(vis[x][y] || x < 1 || y < 1 || x > n || y > m || maps[x][y])
        return false;
    return true;
}

void dfs(int x, int y)
{
    if(x == fx && y == fy){
        ++ans;
        return;
    }

    for(int i = 0; i < 4; ++i){
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if(check(xx, yy)){
            vis[xx][yy] = true;
            dfs(xx, yy);
            vis[xx][yy] = false;
        }
    }
}
int main()
{
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;
    int x, y;
    for(int i = 1; i <= t; ++i){
        cin >> x >> y;
        maps[x][y] = 1;
    }
    vis[sx][sy] = true;
    dfs(sx, sy);
    cout << ans << endl;

    return 0;
}