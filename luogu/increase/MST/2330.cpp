#include<iostream>
using namespace std;
const int maxn = 100000 * 2 + 10, INF = 1e9;
int n, m, cnt, f[maxn], ans;
bool vis[maxn];
struct edge{
    int u, v, w;
}e[maxn];

int find(int x){
    return (f[x] == x) ? x : (f[x] = find(f[x]));
}

void sort(){
    int delta = m;
    do{
        delta = delta / 3 + 1;
        for(int i = 1 + delta; i <= m; ++i){
            if(e[i].w < e[i - delta].w){
                edge tmp = e[i];
                int j;
                for(j = i - delta; j >= 1 && e[j].w > tmp.w; j -= delta)
                    e[j + delta] = e[j];
                e[j + delta] = tmp;
            }
        }
    }while(delta > 1);
}
void krukal(){
    int num = 0;
    sort();
    for(int i = 1; i <= n; ++i)
        f[i] = i;
    for(int i = 1; i <= m; ++i){
        if(find(e[i].u) != find(e[i].v)){
            ++num;
            f[find(e[i].u)] = find(e[i].v);
            ans = e[i].w;
        }

        if(num == n - 1)
            break;
    }
    cout << n - 1 << ' ' << ans << endl;
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; ++i)
        cin >> e[i].u >> e[i].v >> e[i].w;
    krukal();
    return 0;
}