#include<bits/stdc++.h>
using namespace std;
const int maxn = 2510;
int n, m, maps[maxn][maxn], sum[maxn][maxn];

bool check(int x){
    for(int i = x; i <= n; ++i)
        for(int j = x; j <= m; ++j){
            int num1 = 0, num2 = 0, tmp = sum[i][j] - sum[i - x][j] - sum[i][j - x] + sum[i - x][j - x];
            if(tmp != x)
                continue;
            for(int k = 1; k <= x; ++k)
                num1 += maps[i - k + 1][j - k + 1];
            if(num1 == tmp) 
                return true;
            for(int k = 1; k <= x; ++k)
                num2 += maps[i - k + 1][j - x + k];
            if(num2 == tmp)
                return true;
            
        }
    return false;
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j){
            scanf("%d", &maps[i][j]);
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + maps[i][j];
        }
    int low = 0, high = min(n, m) + 1, mid;
    //cout << check(3) << endl;
    while(1 + low < high){
        mid = (low + high) >> 1;
        if(check(mid))
            low = mid;
        else 
            high = mid;
    }

    cout << low << endl;
    return 0;
}