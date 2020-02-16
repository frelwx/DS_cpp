#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
const int maxn = 1e4 + 10, maxm = 2e5 + 10;
bool vis[maxn];
int n, m, b[maxn], ans[3], head[maxm], cnt;
struct edge{
    int to, next;
}e[maxm];
void dfs(int x, int y){
    for(int i = head[x]; i; i = e[i].next){
        if(!b[e[i].to]){
            ++ans[-y + 1];
            b[e[i].to] = -y;
            dfs(e[i].to, -y);
        }
        else if(b[e[i].to] != -y){
            cout << "Impossible\n";
            exit(0);
        }
    }
}

void add(int from, int to){
    e[++cnt].to = to;
    e[cnt].next = head[from];
    head[from] = cnt;
}
int main()
{
    cin >> n >> m;
    int u, v, res = 0;
    for(int i = 1; i <= m; ++i){
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    for(int i = 1; i <= n; ++i)
        if(!b[i]){
            b[i] = 1;
            ++ans[2];
            dfs(i, 1);
            res += min(ans[0], ans[2]);
            ans[0] = ans[2] = 0;
        }
    cout << res << endl;
    return 0;
}