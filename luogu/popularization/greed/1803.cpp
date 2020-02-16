#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1e6 + 10;
int n;
struct game{
    int a, b;
}g[maxn];
bool cmp(game x, game y){
    if(x.a != y.a)
        return x.a < y.a;
    else    
        return x.b < y.b;
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
        scanf("%d%d", &g[i].a, &g[i].b);
    sort(g + 1, g + 1 + n, cmp);

    int ans = 0, end = g[1].b;
    for(int i = 2; i <= n; ++i){
        if(g[i].a >= end){
            end = g[i].b;
            ++ans;
        }
        else if(g[i].b <= end)
            end = g[i].b;
    }

    cout << ans + 1<< endl;
}
