#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
int n, a[maxn], dp1[maxn], dp2[maxn];
int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
        dp1[i] = dp2[i] = 1;
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
        for(int j = i - 1; j >= 1; --j)
            if(a[j] < a[i] && dp1[j] + 1 > dp1[i])
                dp1[i] = dp1[j] + 1;
    }
    for(int i = n; i >= 1; --i)
        for(int j = i + 1; j <= n; ++j)
            if(a[i] > a[j] && dp2[j] + 1 > dp2[i])
                dp2[i] = dp2[j] + 1;
    int ans = 0;
    for(int i = 0; i <= n; ++i)
        ans = max(ans,dp1[i] + dp2[i + 1]);
    cout << n - ans << endl;
    return 0;
}