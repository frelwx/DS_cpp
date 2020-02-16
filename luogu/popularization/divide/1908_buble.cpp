#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 5e5 + 100;
int n, a[maxn], c[maxn], b[maxn];
int main()
{
    cin >> n;
    long long ans = 0;
    for(int i = 1; i<= n; ++i)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; ++i)
        for(int j = i + 1; j <= n; ++j)
            if(a[j] < a[i])
                ++ans;
    cout << ans << endl;
}