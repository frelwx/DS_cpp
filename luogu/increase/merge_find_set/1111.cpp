#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100000 + 10, maxm = 100000 * 2 + 10;
int n, m, cnt, head[maxn], dis[maxn], f[maxn], ans;
struct edge
{
    int u, v, t;
}e[maxm];

int find(int x){
    return (f[x] == x) ? x : (f[x] = find(f[x]));
}
bool cmp(edge x, edge y){
    return x.t < y.t;
}
void kruskal(int &num){
    for(int i = 1;  i<= m; ++i){
        if(find(e[i].v) != find(e[i].u)){
            ++num;
            f[find(e[i].v)] = find(e[i].u);
            ans = e[i].t;
        }
        if(num == n - 1){
            break;
        }
    }
}
int main()
{
    cin >> n >> m;
    int x, y, tt;
    for(int i = 1; i <= n; ++i)
        f[i] = i;
    
    for(int i = 1; i <= m; ++i)
        cin >> e[i].u >> e[i].v >> e[i].t;
    
    sort(e + 1, e + 1 + m, cmp);
    int num = 0;
    kruskal(num);
    if(num != n -  1)
        cout << -1 << endl;
    else 
        cout << ans << endl;
    return 0;
}
