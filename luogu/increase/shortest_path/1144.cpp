#include<iostream>
using namespace std;
const int maxn = 1000000 + 10, maxm = 2000000 * 2 + 10, inf = 1e9, mod = 100003;
int n, m, head[maxn], cnt, ans[maxn], dis[maxn];
bool vis[maxn];
struct edge{
    int to, next;
}e[maxm];
void add(int u, int to){
    e[++cnt].to = to;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dijk(){
    int min = inf, index;
    for(int i = 1; i <= n; ++i)
        dis[i] = inf;
    dis[1] = 0;
    ans[1] = 1;
    for(int j = 1; j <= n; ++j){
        min = inf;
        for(int i = 1; i <= n;++i)
            if(!vis[i] && dis[i] < min){
                min = dis[i];
                index = i;
            }

        vis[index] = true;
        for(int i = head[index]; i; i = e[i].next){
            int v = e[i].to;
           // cout << v << ' ' << dis[v] << ' '<< dis[index] < < endl;
            if(!vis[v] && dis[v] > dis[index] + 1){
                dis[v] = (dis[index] + 1);
                ans[v] = ans[index];
                //cout << "???" << endl;
            }
            else if(!vis[v] && dis[v] == dis[index] + 1)
                ans[v] = (ans[v] + ans[index]) % mod;
            }
    }
}
int main()
{
    cin >> n >> m;
    int u, v;
    for(int i = 1; i <= m; ++i){
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    dijk();
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << '\n';
    //cout << dis[n] << endl;
}

