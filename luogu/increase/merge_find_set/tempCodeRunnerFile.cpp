#include<iostream>
using namespace std;
const int maxn = 4e5 + 10, inf = 1e9;
int n, m, head[maxn], dis[maxn], cnt, ans;
bool vis[maxn];
struct edge{
    int next, v, w;
}e[maxn];
int min(int x, int y){
    return (x < y) ? x : y;
}
void add(int u, int v, int w){
    e[++cnt].w = w;
    e[cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void prime(){
    for(int i = 2; i <= n; ++i)
        dis[i] = inf;
    int min = inf, index;
    for(int j = 1; j <= n; ++j){
        min = inf;
        for(int i = 1; i <= n; ++i)
            if(!vis[i] && dis[i] < min){
                min = dis[i];
                index = i;
               // cout << "???" << i << ' ';
            }
        vis[index] = true;
        //cout << index << ' '  << dis[index] << '\t';
        ans  = max(ans, dis[index]);
        for(int i = head[index]; i; i = e[i].next){
            int v = e[i].v;
            if(!vis[v] && dis[v] > e[i].w){
                dis[v] = e[i].w;
                //cout << "here" << v <<' ' <<  dis[v] << '\t';
            }
        }
        //cout << endl;
    }
}
int main()
{
    cin >> n >> m;
    int u, v, w;
    for(int i = 1; i <= m; ++i){
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    prime();
    if(ans == inf)
        cout << -1 << endl;
    else 
        cout << ans << endl;
    return 0;
}