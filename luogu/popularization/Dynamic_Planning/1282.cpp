#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10, maxm = 8e3, del = 5001;
int n, a[maxn], b[maxn], dp[maxn][maxm], sum;//dp[i][j] 为将前i张牌上下差变为j的最小旋转次数
int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < maxm; ++j)
            dp[i][j] = 1e9;
    for(int i = 1; i <= n; ++i){
        cin >> a[i] >> b[i];
        sum += a[i] - b[i];
    }
    dp[1][b[1] - a[1] + del] = 1;
    dp[1][a[1] - b[1] + del] = 0;
    
    
    for(int i = 2; i <= n; ++i)
        for(int j = -del; j <= del; ++j)
            dp[i][j + del] = min(dp[i - 1][j - (a[i] - b[i]) + del], dp[i - 1][j - (b[i] - a[i]) + del] + 1); //反转或者不反转

    sum = (sum < 0) ? -sum : sum;
    for(int i = 0; i <= del; ++i)
        if(dp[n][i + del] < sum || dp[n][-i + del] < sum){
            cout << min(dp[n][i + del], dp[n][-i + del]) << endl;
            return 0;
        }
    cout << 0 << endl;
    return 0;
}