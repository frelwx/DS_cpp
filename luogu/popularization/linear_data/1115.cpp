#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 200000 + 10;
int a[maxn], n;
long long sum[maxn];
long long max(long long x1, long long x2, long long x3){
    if(x1 > x2){
        if(x1 > x3)
            return x1;
        else
            return x3;
        
    }

    else{
        if(x2 > x3)
            return x2;
        else
            return x3;
    }
}
long long f(int l, int r){
    if(l == r) return (long long )a[l];
    int mid = (l + r) / 2;
    long long tmp1 = f(l, mid), tmp2 = f(mid + 1, r), tmp3 = a[mid], tmp4 = a[mid + 1];
    for(int i = mid; i >= l; --i){
        if(sum[mid] - sum[i - 1] > tmp3)
        tmp3 = sum[mid] - sum[i - 1];
    }

    for(int j = mid + 1; j <= r; ++j){
        if(sum[j] - sum[mid] > tmp4)
        tmp4 = sum[j] - sum[mid];
    }

    return max(tmp1, tmp2, tmp3 + tmp4);
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    //cout << sum[1] << sum[2] << endl;
    cout << f(1, n) << endl;
    return 0;
}