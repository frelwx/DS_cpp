#include<bits/stdc++.h>
using namespace std;
const int maxn = 10000 + 10;
int n, k, dp[maxn], vis[maxn], indexx, flag[maxn];
struct node{
    int begin, last;
}a[maxn];
bool cmp(node x, node y){
    if(x.begin != y.begin)
        return x.begin < y.begin;
    return x.last < y.last;
}
int find(int x){ 
    int low = 1, high = k, mid;
    while(low < high){
        //cout << low << ' ' << mid << endl;
        mid = (low + high) >> 1;
        if(a[mid].begin > x)
            high = mid - 1;
        else if(a[mid].begin < x)
            low = mid + 1;
        else {
            low = mid;
            break;
        }
    }
    //cout << "???";
    while(a[low].begin == a[low - 1].begin)
        --low;
    return low;
}
int f(int now){
    if(now > n)
        return 0;
    if(vis[now])
        return dp[now];
    if(!flag[now]){
        dp[now] = f(now + 1) + 1;
        vis[now] = 1;
        return dp[now];
    }
    else {
        int i = find(now);
        for(int j = 1; j <= flag[now]; ++j)
            dp[now] = max(dp[now], f(now + a[i + j - 1].last));
        vis[now] = 1;
        return dp[now];

    }

}


int main()
{
    cin >> n >> k;
    for(int i = 1; i <= k; ++i){
        scanf("%d%d", &a[i].begin, &a[i].last);
        ++flag[a[i].begin];
    }
    sort(a + 1, a + k + 1, cmp);
    cout << f(1) << endl;
    return 0;
}