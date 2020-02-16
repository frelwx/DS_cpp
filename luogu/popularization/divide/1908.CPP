#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 5e5 + 100;
int n, a[maxn], c[maxn], b[maxn];

long long merge(int l, int r, int mid){
    int i, j , k = 0, nb = mid - l + 1, nc = r - mid;
    long long ans = 0;
    for(int m = l; m <= mid; ++m)   b[m - l + 1] = a[m];
    for(int m = mid + 1; m <= r; ++m)   c[m - mid] = a[m];
    for(i = 1, j = 1, k = l; i <= nb && j <= nc; ++k){
        if(c[j] < b[i]){
            ans += nb - i + 1;
            
            a[k] = c[j++];
        }
        else
            a[k] = b[i++];
    }

    if(i <= nb)
    for(int l = 0; l <= nb - i; ++l)
    a[l + k] = b[l + i];

    if(j <= nc)
    for(int l = 0; l <= nc - j; ++l)
    a[l + k] = c[l + j];
    
    return ans;
}
long long sort(int l, int r){
    if(l == r)
        return 0;
    int mid = (l + r) >> 1;
    return sort(l , mid) + sort(mid + 1, r) + merge(l ,r ,mid);
}
int main()
{
    cin >> n;
    for(int i = 1; i<= n; ++i)
        scanf("%d", &a[i]);
    
    cout << sort(1, n) << endl;
    


}