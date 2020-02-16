#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 10000 + 10, maxm = 2 * 50000 + 10;
int n, m, b, head[maxn], f[maxn], cnt, dis[maxn];
bool control[maxn], vis[maxn];
struct edge{
    int to, w, next;
}e[maxm];
void add(int u, int v, int w){
    e[++cnt].w = w;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

class que{
    int s, j;
    int a[1000000];
    public:
    que() :s(1), j(0){}
    void push(int x){
        a[++j] = x;
    }
    bool empty(){
        return s > j;
    }
    void pop(){
        ++s;
    }
    int front(){
        return a[s];
    }
    void ini(){
        s = 1;
        j = 0;
    }


}q;

bool check(int limit){
     if(f[1] > limit || f[n] > limit)
            return false;
    for(int i = 1; i <= n; ++i)
        control[i] = (f[i] <= limit) ? 1 : 0;
    int min = 1e9, index;
    for(int i = 1; i <= n; ++i)
        dis[i] = min;
    dis[1] = 0;
    q.ini();
    q.push(1);
    vis[1] = true;
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        vis[tmp] = false;
        for(int i = head[tmp]; i; i = e[i].next){
            int v = e[i].to;
            if(control[v] && dis[v] > dis[tmp] + e[i].w){
                dis[v] = dis[tmp] + e[i].w;
                if(!vis[v]){
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    //cout << dis[n]  << "dis[n]\n";
    if(b - dis[n] <= 0)
        return false;
    else 
        return true;
    
}
int main()
{
    cin >> n >> m >> b;
    int low = 1e9, high = 0, mid;
    for(int i = 1; i <= n; ++i){
        scanf("%d", &f[i]);
        if(f[i] > high)
            high = f[i] + 1;
        if(f[i] < low)
            low = f[i];
    }
    int u, v, w;
    for(int i = 1; i <= m; ++i){
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    
   while(low < high){
       mid = (low + high) / 2;
       if(check(mid))
            high = mid;
        else 
            low = mid;
        if(high - low == 1)
            break;

   }

   if(check(high))
        cout << high << endl;
    else 
        cout << "AFK" << endl;


    return 0;
}