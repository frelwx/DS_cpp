//因为每个点的出度都是一， 所以每个点至多存在一个环中， 各个环之间互不干扰
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 200000 + 10;
int n, to[maxn], ans = 1e9, in[maxn];
bool vis[maxn], check_delete[maxn];
void dfs(int start, int step){
    if(vis[to[start]] && step){
        ans = min(step, ans);
        return;
    }
    vis[to[start]] = true;
    dfs(to[start], step + 1);
}

void delete_in_0(int x){
    check_delete[x] = true;
    --in[to[x]];
    if(in[to[x]] == 0)
        delete_in_0(to[x]);
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> to[i];
        ++in[to[i]];
    }
    for(int i = 1; i <= n; ++i){
        if(in[i] == 0 && !check_delete[i])
            delete_in_0(i);
    }
    for(int i = 1; i <= n; ++i){
        if(!check_delete[i] && !vis[i]){
            vis[i] = true;
            dfs(i, 1);
        }
    }
    cout << ans << endl;
}