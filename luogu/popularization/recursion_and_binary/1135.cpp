#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3, inf = 1e9;
int n, k[maxn], a, b, ans = 1e9, maps[maxn][maxn], dp[maxn], vis[maxn], head[maxn], cnt;
void dfs(int num, int end, int step){
    if(step > ans || num < 0 || num > n)
        return;
    //cout << num << ' ' << step << endl;
    if(num == end){
        ans = min(step, ans);
        return;
    }
    dfs(num + k[num], end, step + 1);
    dfs(num - k[num], end, step + 1); 
}

struct node{
    int v, step;
};

bool check(int x){
    if(x < 1 || x > n || vis[x])
        return false;
    return true;
}
int bfs(){
    queue<node> q;
    q.push({a, 0});
    while(!q.empty()){
        node u = q.front();
        q.pop();
        if(u.v == b)
            return u.step;
        int x = u.v + k[u.v];
        int y = u.v - k[u.v];
        if(check(x)){
            q.push({x, u.step + 1});
            vis[x] = 1;
        }
        if(check(y)){
            q.push({y, u.step + 1});
            vis[y] = 1;
        }
    }
    return -1;
}

int main()
{
    cin >> n >> a >> b;
    for(int i = 1; i <= n; ++i)
        cin >> k[i];
    cout << bfs() << endl;
    return 0;

}