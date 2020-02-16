#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 2e5 + 100;
int n, a[maxn], vis[maxn];
long long t, ans;
int main()
{
    cin >> n >>  t;
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    
    while(t){
        int s = 0, l = 0;
        for(int i = 1; i <= n; ++i){
            if(vis[i])
                continue;
            if(a[i] + s <= t)
                s += a[i],
                ++l;
            else 
                vis[i] = true;
        }
        if(!s)
            break;
        //cout << s << ' ' << l << endl;
        ans += t / s * l;
        t %= s;
        
    }
    cout << ans << endl;
    return 0;
}