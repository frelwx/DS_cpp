#include<iostream>
using namespace std;
const int maxn = 1e3, inf = 1e9;
int n, maps[maxn][maxn], dis[maxn], ans;
bool vis[maxn];
void prime(){
    int min = inf, index;
    for(int i = 2; i <= n; ++i)
        dis[i] = inf;
    for(int j = 1; j <= n; ++j){
        min = inf;
        for(int i = 1; i <= n; ++i)
            if(!vis[i] && dis[i] < min){
                min = dis[i];
                index = i;
            }
        vis[index] = true;
        ans += dis[index];
        for(int i = 1; i <= n; ++i)
            if(dis[i] > maps[i][index])
                dis[i] = maps[i][index];
    }
    
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> maps[i][j];
    prime();
    cout << ans << endl;
    return 0;
}