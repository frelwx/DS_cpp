#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, m, s, dis[maxn], inf;
struct edge
{
    int to;
    int w;
};

vector<edge> e[maxn];
bool vis[maxn];
void dijkstra(){
    for(int i = 1; i <= n; ++i)
    dis[i] = inf;
    dis[s] = 0;
    int min = inf, index;
    for(int i = 1; i <= n; ++i){
        min = inf;
        for(int j = 1; j <= n; ++j)
        if(!vis[j] && dis[j] < min){
            index = j;
            min = dis[j];
        }
        vis[index] = true;

        for(int j = 0; j < e[index].size(); ++j){
            if(!vis[e[index][j].to] && dis[e[index][j].to] > dis[index] + e[index][j].w)
                dis[e[index][j].to] = dis[index] + e[index][j].w;
        }
    }
}
int quickpower(){
    long long base = 2, k = 31, ans = 1;
    while(k){
        if(k & 1){
            ans *= base;
            k >>= 1;
        }
        base *= base;
    }
    return ans - 1;
}
int main()
{
    scanf("%d%d%d", &n, &m, &s);
    int x, y, z;
    inf = quickpower();
    while(m--){
        scanf("%d%d%d", &x, &y, &z);
        e[x].push_back({y,z});
    }
    dijkstra();
    for(int i = 1; i <= n; ++i)
    printf("%d\ ", dis[i]);
}