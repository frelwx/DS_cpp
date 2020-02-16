#include<bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 100;
int a[maxn], dp[maxn], n, len;
int find2(int x){//数组单调递增，寻找第一个大于x的数的下标
    int low = 1, high = len, mid;
    while(low < high){
        mid = (low + high) >> 1;
        if(dp[mid] > x)
            high = mid;
        else 
            low = mid + 1;
    }
    return high;
}

int find1(int x){//数组单调递减，寻找第一个小于等于x的数的下标
    int low = 1, high = len, mid;
    while(low < high){
        mid = (low + high) >> 1;
        if(dp[mid] <= x)
            high = mid;
        else 
            low = mid + 1;
    }
    return high;
}
int main()
{
    while(cin >> a[++n]){
    }
    --n;
    //cout << n << endl;
    int ans1;
    dp[0] = 1e9;
    for(int i = 1; i <= n; ++i){
        if(a[i] <= dp[len]){
            dp[++len] = a[i];//dp[i]为长度为i的不上升子序列的最大末尾数值
            //cout << len << ' ' << a[i] << endl;
        }
        else {
            //cout << i << ' '  << len << ' '<< find1(a[i])  << ' ' << dp[find1(a[i])]<< endl;
            dp[find1(a[i])] = a[i];//用a[i]替换从左至右第一个小于a[i]的数
        }
    }
    ans1 = len;
    //cout << len << endl;
    len = 0;
    //cout << dp[0] << endl;
    dp[0] = -1;
    for(int i = 1; i <= n; ++i)
        if(a[i] > dp[len]){
            //cout << a[i] << ' ' << dp[len] << endl;
            dp[++len] = a[i];
            
        }
        else {
            //cout << i << ' ' << a[i] << ' ' << dp[len] << endl;
            int tmp = find2(a[i]); // 第一个大于a[i]的数的下标
            if(a[i] != dp[tmp - 1])
                dp[tmp] = a[i];
        }
    cout << ans1 << endl << len << endl;
    return 0;

}