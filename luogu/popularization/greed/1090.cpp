#include<iostream>
#include<algorithm>
using namespace std;
int n, a[10009];
void sort2(int x){
    int i;
    for(i = x + 1; i <= n; ++i)
        if(a[i] > a[x])
            break;
    if(i <= n){ // 把x插到i前面
        int tmp = a[x];
        for(int j = x; j <= i - 2; ++j)
            a[j] = a[j + 1];
        a[i - 1] = tmp;
    }
    else {
        int tmp = a[x];
        for(int j = x; j <= n - 1; ++j)
            a[j] = a[j + 1];
        a[n] = tmp;
    }
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
    cin >> a[i];
    sort(a + 1, a + 1 + n);
    int ans = 0;
    for(int i = 2; i <= n; ++i){
        a[i] += a[i - 1];
        ans += a[i];
        sort2(i);
    }
    cout << ans << endl;
}