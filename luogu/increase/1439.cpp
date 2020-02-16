#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 1e5 + 100;
int n, a[maxn], b[maxn], dp[maxn], c[maxn];
bool cmp(int x, int y){
    return c[x] > c[y];
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        dp[i] = 1e9;
    }
    for(int i = 1; i <= n; ++i){
        scanf("%d", &b[i]);
        c[b[i]] = i;
    }
    dp[1] = a[1];
    int len = 1, low, high, mid;
    for(int i = 2; i <= n; ++i){
        if(cmp(a[i], dp[len]))
            dp[++len] = a[i];
        else {
            low = 1, high = len;
            while(low < high){
                mid = (low + high) >> 1;
                if(cmp(dp[mid], a[i]))
                    high = mid;
                else 
                    low = mid + 1;
            }
            if(dp[high - 1] == a[i])
                continue;
            dp[high] = a[i];
        }
    }

    cout << len << endl;
    return 0;


}