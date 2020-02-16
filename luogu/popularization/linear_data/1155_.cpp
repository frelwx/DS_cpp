//贪心解法， 直接模拟
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 200000 + 10;
int n, tmp;
int main()
{
    cin >> n;
    long long ans, sum;
    cin >> sum;
    ans = sum;
    for(int i = 2; i <= n; ++i){
        if(sum < 0)
            sum = 0; // 负数的连续一段还不如不要
            cin >> tmp;
        sum += tmp;
        ans = max(ans, sum);
    }
    cout << ans << endl;
}