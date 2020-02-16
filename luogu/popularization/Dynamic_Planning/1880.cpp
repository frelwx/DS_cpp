#include<iostream>
using namespace std;
const int maxn = 1e3;
int n, a[maxn], dp[maxn][maxn], vis[maxn][maxn], sum[maxn], dp2[maxn][maxn], vis2[maxn][maxn];
int f(int l, int r){
    if(l >= r)
        return 0;
    if(vis[l][r])
        return dp[l][r];
    if(r - l == 1){
        //cout << "???" ;
        dp[l][r] = a[l] + a[r];
        vis[l][r] = 1;
        return dp[l][r];
    }
    for(int i = l; i <= r - 1; ++i){
        int tmp1 = f(l, i) + f(i + 1, r) + sum[i] - sum[l - 1] + sum[r] - sum[i];
        //cout << i << ' ' << tmp1 << ' ' << f(1,i) << ' ' << f(i + 1, r) << endl;
        dp[l][r] = max(dp[l][r], tmp1);
    }
    vis[l][r] = 1;
    return dp[l][r];
    
}

int min(int x, int y){
    return (x < y) ? x : y;
}

int f2(int l, int r){
    if(l >= r)
        return 0;
    if(vis2[l][r])
        return dp2[l][r];
    if(r - l == 1){
        dp2[l][r] = a[l] + a[r];
        vis2[l][r] = 1;
        return dp2[l][r];
    }
    dp2[l][r] = 1e9;
    for(int i = l; i <= r - 1; ++i){
        int tmp1 = f2(l, i) + f2(i + 1, r) + sum[i] - sum[l - 1] + sum[r] - sum[i];
        dp2[l][r] = min(dp2[l][r], tmp1);
    }
    vis2[l][r] = 1;
    return dp2[l][r];
    
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for(int i = 1; i <= 2 * n; ++i)
        sum[i] = sum[i - 1] + a[i];
    int ans1 = 0, ans2 = 1e9 + 1;
    //cout << f2(1, n) << endl;
    for(int i = 1; i <= n; ++i){
         ans1 = max(ans1, f(i, n + i - 1));
         ans2 = min(ans2, f2(i, i + n - 1));
         //cout << ans2 << ' ' << f2(i, i + n - 1) << endl;
     }
    cout << ans2 << endl << ans1 << endl;
}