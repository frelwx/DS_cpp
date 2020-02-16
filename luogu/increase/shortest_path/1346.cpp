//本题不需要回头
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int maxn = 1e5;
int n, a, b, dis[maxn], head[maxn], cnt;
bool vis[maxn];

struct node{
    int to, next, w;
}e[maxn];
void add(int u, int v, int w){
    e[++cnt].w = w;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;

}

int dijk(){
    int min = 1e9, index;
    for(int i = 1; i <= n; ++i)
        dis[i] = min;
    dis[a] = 0;
    for(int i = 1; i <= n; ++i){
        min = 1e9;
        for(int j = 1; j <= n; ++j)
            if(!vis[j] && dis[j] < min){
                min = dis[j];
                index = j;
            }
        
        vis[index] = true;
        for(int j = head[index]; j; j = e[j].next){
            int v = e[j].to;
            if(!vis[v] && dis[v] > dis[index] + e[j].w)
                dis[v] = dis[index] + e[j].w;
        }
    }
    if(dis[b] != 1e9)
        return dis[b];
    else 
        return -1;
}

int main()
{
    cin >> n >> a >> b;
    int k, v;
    for(int i = 1; i <= n; ++i){
        cin >> k;
        if(k){
            cin >> v;
            add(i, v, 0);
        }
        for(int j = 2; j <= k; ++j){
            cin >> v;
            add(i, v, 1);
        }
    }
    cout << dijk() << endl;
    return 0;
    
}