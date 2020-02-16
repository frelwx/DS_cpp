#include<bits/stdc++.h>
using namespace std;
const int maxn = 101, maxm = 201;
int n, m, t, dp[maxm][maxm];
struct  node{
    int m ,t;
}a[maxn];

int main()
{
    cin >> n >> m >> t;
    for(int i = 1; i <= n; ++i)
        cin >> a[i].m >> a[i].t;
    for(int i = 1; i <= n; ++i)
        for(int j = m; j >= a[i].m; --j)
            for(int k = t; k >= a[i].t; --k)
                    dp[j][k] = max(dp[j][k], dp[j - a[i].m][k - a[i].t] + 1);
                    
    cout << dp[m][t] << endl;
}