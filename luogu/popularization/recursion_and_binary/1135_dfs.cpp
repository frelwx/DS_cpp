#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3, inf = 1e9;
int n, k[maxn], a, b, ans = inf, vis[maxn];
void dfs(int num, int end, int step){
    if(vis[num] || step > ans || num < 0 || num > n)
        return;
    if(num == end){
        ans = min(step, ans);
        return;
    }
    vis[num] = 1;
    dfs(num + k[num], end, step + 1);
    dfs(num - k[num], end, step + 1); 
    vis[num] = 0;
}

int main()
{
    cin >> n >> a >> b;
    for(int i = 1; i <= n; ++i)
        cin >> k[i];
    dfs(a, b, 0);
    if(ans == inf)
        ans = -1;
    cout << ans << endl;
    return 0;

}