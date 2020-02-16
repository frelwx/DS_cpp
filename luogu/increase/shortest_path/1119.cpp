#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 201, maxm = 5e4;
int n, m, t[maxn], head[maxn], cnt, q, x, y, tt, dis[maxn], inf = 1e9;
bool vis[maxn];
struct edge{
    int next, w, to;
}e[maxm];
void add(int u, int v, int w){
    e[++cnt].w = w;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}
int dijk(){
    if(t[x] > tt || t[y] > tt)
        return -1;
    int min = inf, index = x;
    for(int i = 0; i < n; ++i){
        dis[i] = min;
        vis[i] = false;
    }
    dis[x] = 0;
    for(int j = 1; j <= n; ++j){
        min = inf;
        for(int i = 0; i < n; ++i)
            if(t[i] <= tt && dis[i] < min && !vis[i]){
                min = dis[i];
                index = i;
            }
        vis[index] = true;
        //cout << "index " << index << ' ' << x << ' ';
        for(int i = head[index]; i; i = e[i].next){
            int v = e[i].to;
            if(t[v] <= tt && !vis[v] && dis[v] > dis[index] + e[i].w)
                dis[v] = dis[index] + e[i].w;
        }
        
    }
    if(dis[y] == inf)
        return -1;
    else 
        return dis[y];

}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        scanf("%d", &t[i]);
    int u, v, w;
    for(int i = 1; i <= m; ++i){
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    cin >> q;
    while(q--){
        cin >> x >> y >> tt;
        cout << dijk() << endl;
    }

}