#include<bits/stdc++.h>
using namespace std;
const int maxn = 201;
int n, k, dp[maxn][maxn];
int f(int x, int y){
    //情况1：至少有一份只有1，那么去掉只有1的一分不影响。 情况2：每一份至少有2， 那么每一份都拿掉1， 也不影响
    if(x < y)
        return 0;
    if(dp[x][y])
        return dp[x][y];
    return dp[x][y] = f(x - 1, y - 1) + f(x - y, y);
}
int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        dp[i][1] = 1;
    cout << f(n, k) << endl;
    return 0;
}