#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 6300 * 2;//双向边
int n, m, s,t, head[maxn],cnt, dis[maxn], inf = 1e9;
bool vis[maxn];
struct edge{
    int to, w, next;
}e[maxn];
void add(int u, int v, int w){
    e[++cnt].w =w;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}
void Dijkstra(){
    for(int i = 1; i<= n; ++i)
        dis[i] = inf;
    dis[s] = 0;
    int min = inf, index;
    for(int j = 1; j <= n; ++j){
        min = inf;
        for(int i = 1; i <= n; ++i)
            if(!vis[i] && dis[i] < min){
                min = dis[i];
                index = i;
            }
        vis[index] = true;
        for(int i = head[index]; i; i = e[i].next)
            if(!vis[e[i].to] && dis[e[i].to] > dis[index] + e[i].w)
                dis[e[i].to] = dis[index] + e[i].w;
    }
}
int main()
{
    cin >> n >> m >> s >> t;
    int u, v, w;
    for(int i = 1; i <= m; ++i){
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    Dijkstra();
    cout << dis[t] << endl;
}