#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 100000 + 10;
int n, a[maxn], m;
bool check(int x){
    int sum = 0, k = 0;
    for(int i = 1; i < n; ++i){
        if(sum + a[i] <= m)
            sum += a[i];
        else{
            sum = a[i];
            ++k;
        }
    }
    ++k;

    return (k <= x) ? 1 : 0;
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
    int sum = 0, k = 0;
    for(int i = 1; i <= n; ++i){
        if(sum + a[i] <= m){
            sum += a[i];
        }
        else{
            sum = a[i];
            ++k;
        }
    }
    ++k;
    // int low = 1, high = n, mid;
    // while(low < high){
    //     mid = (low + high) >> 1;
    //     if(check(mid))
    //         high = mid;
    //     else
    //         low = mid;

    //     if(high - low == 1)
    //         break;
    // }
    //cout << check(2) << endl;
    cout << k << endl;
    return 0;
}