// 当某件事的最大前驱结束即开始该事情
#include<iostream>
#include<queue>
using namespace std;
const int maxn = 1e5 + 10, maxm = 2e6 + 100;
int n, cnt, head[maxn], t[maxn], indeg[maxn], ans, end_time[maxn];
bool vis[maxn];
queue<int> q;
struct edge{
    int next, to;
}e[maxm];
void add(int u, int v){
    e[++cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

int topo_sort(){
    for(int i = 1; i <= n; ++i)
        if(!indeg[i]){
            q.push(i);
            end_time[i] = t[i];
        }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = head[u]; i; i = e[i].next){
            int v = e[i].to;
            --indeg[v];
            if(!indeg[v])
                q.push(v);
            end_time[v] = max(end_time[v], end_time[u] + t[v]);
        }
    }
    for(int i = 1; i <= n; ++i)
        ans = max(ans, end_time[i]);
    return ans;
}
int main()
{
    cin >> n;
    int x, len;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> t[i];
        while(1){
            cin >> x;
            if(!x)
                break;
            add(x, i);
            ++indeg[i];
        }
    }
    cout << topo_sort()<< endl;
}
