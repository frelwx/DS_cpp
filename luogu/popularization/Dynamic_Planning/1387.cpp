#include<bits/stdc++.h>
using namespace std;
const int maxn = 200;
int n, m, maps[maxn][maxn], sum[maxn][maxn];
bool check(int x){
    for(int i = x; i <= n; ++i)
        for(int j = x; j <= m; ++j)
            if(sum[i][j] - sum[i - x][j] - sum[i][j - x] + sum[i - x][j - x] == x * x)
                return true;
    return false;
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j){
            cin >> maps[i][j];
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + maps[i][j];
        }

    int low = 1, high  = max(n, m), mid;
    while(1 + low < high){
        mid = (low + high) >> 1;
        if(check(mid))
            low = mid;
        else 
            high = mid;
    }
    //cout << check(2) << endl;
    cout << low << endl;
    return 0;
}