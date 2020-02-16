#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 201, maxm = 2e4 + 10;
int n, m, t[maxn], head[maxn], cnt, q, x, y, tt, dis[maxn], inf = 1e9, maps[maxn][maxn];
bool vis[maxn];
int f(int s, int e){
    int k;
    if(s < 0)
        s = 0;
    for(k = s; k < n && t[k] <= e; ++k)
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(maps[i][j] > maps[i][k] + maps[k][j])
                    maps[i][j] = maps[i][k] + maps[k][j];
    //cout << k << "kkk" << endl;
    if(k == 1 && t[0] > e)
        return -1;

    return k;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        scanf("%d", &t[i]);
    int u, v, w;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            maps[i][j] = inf;
    for(int i = 0; i < n; ++i)
        maps[i][i] = 0;
    for(int i = 1; i <= m; ++i){
        scanf("%d%d%d", &u, &v, &w);
        //maps[i - 1][i - 1] = 0;
        maps[u][v] = w;
        maps[v][u] = w;
    }

    cin >> q;
    int last = 0;
    if(t[0] != 0)
        last = -1;
    while(q--){
        cin >> x >> y >> tt;
        last = f(last,tt);
        if(t[x] > tt || t[y] > tt)
            cout << -1 << endl;
        else if(maps[x][y] != inf)
                cout << maps[x][y] << endl;
            else 
            cout << -1 << endl;
    }

}