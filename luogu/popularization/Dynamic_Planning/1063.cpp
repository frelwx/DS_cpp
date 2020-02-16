#include<bits/stdc++.h>
using namespace std;
const int maxn = 210;
long long n, a[maxn], dp[maxn][maxn], head[maxn], tail[maxn];
long long f(int l, int r){
    if(r <= l)
        return 0;
    if(dp[l][r])
        return dp[l][r];
    if(r - l == 1)
        return dp[l][r] = head[l] * tail[l] * tail[r];
    for(int i = l; i <= r - 1; ++i)
        dp[l][r] = max(dp[l][r], f(l, i) + f(i + 1, r) + head[l] * tail[i] * tail[r]);
    return dp[l][r];
     
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> head[i];
        head[i + n] = head[i];
        tail[i - 1] = tail[i + n - 1] = head[i];
    }

    tail[2 * n] = head[1];
    long long ans = 0;
    for(int i = 1; i <= n; ++i)
        ans = max(ans, f(i, i + n - 1));
    cout << ans << endl;
    return 0;


}