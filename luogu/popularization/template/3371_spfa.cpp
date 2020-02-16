#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10, maxm = 5e5 + 10;
int n, m , s, cnt = 0, head[maxn], dis[maxn], inf;
bool vis[maxn];
struct edge{
    int w;
    int to;
    int next;
}e[maxm];
void add(int from, int to, int weight){
    e[++cnt].w = weight;
    e[cnt].to = to;
    e[cnt].next = head[from];
    head[from] = cnt;
}

void spfa(){
    for(int i = 1; i <= n; ++i)
    dis[i] = inf;
    dis[s] = 0;
    vis[s] = true;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        vis[tmp] = false;
        for(int i = head[tmp]; i; i = e[i].next){
            int v = e[i].to;
            if(dis[v] > dis[tmp] + e[i].w){
                dis[v] = dis[tmp] + e[i].w;
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

int quickpower(){
    int base = 2, ans = 1, k = 31;
    while(k){
        if(k&1){
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
        add(x, y, z);
    }
   
    spfa();
    for(int i = 1; i <= n; ++i)
    printf("%d\ ", dis[i]);
}