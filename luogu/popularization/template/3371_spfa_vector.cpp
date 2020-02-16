#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
int n , m , s, dis[maxn], inf;
struct edge{
    int w;
    int to;
};
vector<edge> e[maxn];
bool vis[maxn];
int quickpower(){
    long long base = 2,k = 31, ans = 1;
    while(k){
        if(k & 1){
            ans *= base;
            k >>= 1;
        }
        base *= base;
    }
    return ans - 1;
}
void spfa(){
    queue<int> q;
    q.push(s);
    vis[s] = true;
    for(int i = 1; i <= n; ++i)
    dis[i] = inf;
    dis[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = 0; i < e[u].size(); ++i){
            int v = e[u][i].to, w = e[u][i].w;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
}
int main(){
    scanf("%d%d%d", &n, &m, &s);
    inf = quickpower();
    int x, y, z;
    while(m--){
        scanf("%d%d%d", &x, &y, &z);
        e[x].push_back({z, y});
    }
    spfa();
    for (int i = 1; i <= n; ++i)
    printf("%d\ ", dis[i]);
    
}