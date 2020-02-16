// 本题采用类似贪心的策略， 先预处理
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int maxn = 110;
int n, a[maxn];
int main()
{
    cin >> n;
    int all = 0;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        all += a[i];
    }
    all /= n;//计算均值
    for(int i = 1; i <= n; ++i)
    a[i] -= all;//减去平均值以便处理
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        if(a[i] != 0){
        //从左至右，先处理第一堆， 如果第一堆 < 0,则第一堆必须从右边一堆取相应值补上，否则不可能最优
        // > 0同理， == 0时不必处理， 除去第一堆以外， 问题规模减小，继续处理
        // 右边一堆不够移， 可以先借着，反正迟早得从右边一堆取过来， 从其他地方调过来和先欠着结果是一样的，因为必须经过右边一堆
            ++ans;
            a[i + 1] += a[i];
        }
    }
    cout << ans << endl;
    
}