#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int maxn2 = 5010;
int n, m, ans = 0, dis[maxn2], vis[maxn2];
int maps[maxn2][maxn2];
void prim(){
    vis[1] = true; // 选取第一个点

    for(int i = 1; i <= n; ++i)
    dis[i] = maps[1][i]; //初始化其余点到1的距离

    for(int i = 1; i < n; ++i){
        int min = 1e9, index = n;
        for(int j = 1; j <= n; ++j){
            if(!vis[j] && dis[j] < min){
                min = dis[j];
                index = j;
            }
        }
        ans += dis[index];
        vis[index] = true;
        for(int j = 1; j <= n; ++j){ // 更新剩下的点到树的最小距离（因为树新加入了点index）
            if(!vis[j] && maps[index][j] < dis[j]){
                dis[j] = maps[index][j];
            }
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    int x, y, z;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j){
            if(i -j)
                maps[i][j] = maxn;
            else
                maps[i][j] = 0;
        }
    for(int i = 1; i <= m; ++i){
        scanf("%d%d%d", &x, &y, &z);
        if(z < maps[x][y]){
            maps[x][y] = z;
            maps[y][x] = z;
        }
    }

    prim();
    printf("%d\n", ans);
    return 0;
}