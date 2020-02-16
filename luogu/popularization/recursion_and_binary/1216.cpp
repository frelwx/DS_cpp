#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int n, a[maxn][maxn], ans, dp[maxn];
int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= i; ++j)
            scanf("%d", &a[i][j]);
    for(int i = 1; i <= n; ++i)
        for(int j = i; j >= 1; --j)
            dp[j] = max(dp[j],dp[j - 1]) + a[i][j];
    
    for(int i = 1; i <= n; ++i)
        ans = max(ans, dp[i]);
    cout << ans << endl;
        
}