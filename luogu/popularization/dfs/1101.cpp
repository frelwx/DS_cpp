#include<iostream>
using namespace std;
const int maxn = 109;
int dir[8][2] = {0, -1, 0, 1, -1, 0, 1, 0, 1, 1, 1, -1, -1, 1, -1, -1}, n;
bool vis[maxn][maxn];
char maps[maxn][maxn], ans[maxn][maxn], w[] = "yizhong";
void print(int fr, int endx, int endy){

}
bool check(int x, int y){
    if(vis[x][y] || x < 0 || y < 0 || x >= n || y >= n)
    return false;
    return true;
}
void dfs(int x, int y, int fr)
{
    int xx = x, yy = y;
    bool flag = true;
    for(int i = 0; i < 5; ++i){
        x += dir[fr][0];
        y += dir[fr][1];
        if(!check(x, y) || maps[x][y] != w[i + 2]){
            flag = false;
            break;
        }
    }

    if(flag){
        ans[xx][yy] = w[1];
        ans[xx - dir[fr][0]][yy - dir[fr][1]] = w[0];
        for(int i = 0; i < 5; ++i){
            xx += dir[fr][0];
            yy += dir[fr][1];
            ans[xx][yy] = w[i + 2];
        }
        return;
    }
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> maps[i];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            ans[i][j] = '*';
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if(maps[i][j] == 'y'){
                for(int k = 0; k < 8; ++k){
                    int xx = i + dir[k][0];
                    int yy = j + dir[k][1];
                        if(check(xx, yy) && maps[xx][yy] == 'i')
                            dfs(xx, yy, k);
                }
            }
   
    for(int i = 0; i < n; ++i)
    cout << ans[i] << endl;
    return 0;
    
}