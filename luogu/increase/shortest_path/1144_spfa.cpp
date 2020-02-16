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
class que{
    int a[1000000];
    int s, e;
    public:
    que():s(1), e(0){}
    bool empty(){
        return s > e;
    }
    void push(int x){
        a[++e] = x;
    }
   int front(){
        return a[s];
    }
    void pop(){
        ++s;
    }
}q;
void spfa(){
    
    q.push(1);
    vis[1] = true;
    for(int i = 1; i <= n; ++i)
        dis[i] = inf;
    dis[1] = 0;
    ans[1] = 1;
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        vis[tmp] = false;
        for(int i = head[tmp]; i; i = e[i].next){
            int v = e[i].to, u = tmp;
            if(dis[v] > dis[u] + 1){
                ans[v] = ans[u];
                dis[v] = dis[u] + 1;
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
            else if(dis[v] == (dis[u] + 1)){
                
                ans[v] = (ans[v] + ans[u]) % mod;
            }
           
            
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
    spfa();
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << '\n';
    //cout << dis[n] << endl;
    //cout << dis[1] << endl;
}

