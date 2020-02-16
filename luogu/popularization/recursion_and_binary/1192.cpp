#include<bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10, mod = 100003;
int dp[maxn], n, k;
int f(int x){
    //cout << x << endl;
    if(x < 0)
        return 0;
    if(dp[x])
        return dp[x];
    for(int i = 1; i <= k; ++i)
        dp[x] = ((long long)dp[x] + f(x - i)) % mod;
    return dp[x];

}
int main()
{
    cin >> n >> k;
    dp[0] = dp[1] = 1;
    cout << f(n) << endl;
  
    return 0;
}