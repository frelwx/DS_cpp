#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, m, f[maxn], ans = 0;
struct e{
    int u, v, w;
}edge[maxn];
bool cmp(e &x, e &y){
    return x.w < y.w;
}
int find(int x){
    return (f[x] == x) ? x : (f[x] = find(f[x]));
}
void kruskal(){
    int cnt = 0;
    for(int i = 1; i <= m; ++i){
        if(find(edge[i].u) == find(edge[i].v))
        continue;
        ans += edge[i].w;
        ++cnt;
        f[find(edge[i].u)] = find(edge[i].v);
        if(cnt == n - 1)
        break;
    }
}
void sort1(){
    int delta = m;
    int i;
    do{
        delta = delta / 3 + 1;
        for(i = delta + 1; i <= m; ++i){
            if(edge[i].w < edge[i - delta].w){
                e tmp = edge[i];
                int j;
                for(j = i -delta; j >= 1 && edge[j].w > tmp.w; j -= delta)
                    edge[j + delta] = edge[j];
                edge[j + delta] = tmp;
            }
        }

    }while(delta > 1);
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i)
    f[i] = i;
    for(int i = 1; i <= m; ++i)
    scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
    sort1();
    kruskal();
    printf("%d\n", ans);
}