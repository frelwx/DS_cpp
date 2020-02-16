#include<iostream>
using namespace std;
const int maxn = 110;
int r, c, maps[maxn][maxn], ans[maxn][maxn], dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
bool vis[maxn][maxn];
bool check(int x, int y, int x2, int y2){
    if(vis[x][y] || x < 1 || y < 1 || x > r || y > c || maps[x][y] >= maps[x2][y2])
        return false;
    return true;
}
int dfs(int x, int y){
    if(ans[x][y] > 0)
        return ans[x][y];
    bool flag = false;
    for(int i = 0; i < 4; ++i){
        int xx = x + dir[i][0],
            yy = y + dir[i][1];
        if(check(xx,yy, x, y)){
            
            vis[xx][yy] = true;
            flag = true;
            ans[x][y] = max(ans[x][y],dfs(xx, yy) + 1);
            vis[xx][yy] = false;
        }
    }
    if(!flag)
        ans[x][y] = 0;
    return ans[x][y];
}
int main()
{
    cin >> r >> c;
    for(int i = 1;  i<= r; ++i)
        for(int j = 1; j <= c; ++j){
            cin >> maps[i][j];
            ans[i][j] = -1;
        }
    int res = 0;
    for(int i = 1; i <= r; ++i)
        for(int j = 1; j <= c; ++j){
            if(ans[i][j] >= 0)
                res = max(res, ans[i][j]);
            else 
                res = max(dfs(i, j), res);
            
        }
    cout << res + 1 << endl;
    return 0;
}