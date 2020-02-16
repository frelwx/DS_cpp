#include<iostream>
#include<cstdio>
using namespace std;
int n;
const int maxn = 300 + 10;
struct p
{
    int d1, d2, d3, total, num;
} a[maxn];
void swap(p &x, p &y){
    p tmp = x;
    x = y;
    y = tmp;
}
bool cmp(p &x, p &y){
    if(x.total != y.total)  return x.total <= y.total;
    if(x.d1 != y.d1)    return x.d1 <= y.d1;
    return x.num >= y.num;
}
void sort(p arr[], int left, int right, bool (*q)(p &x, p &y))
{
    if(left >= right) return;
    int l = left , r = right;
    while(l < r){
        while(l < r && q(arr[r], arr[left])) --r;
        while(l < r && q(arr[left], arr[l])) ++l;
        swap(arr[l], arr[r]);
    }
    swap(arr[left], arr[r]);
    sort(arr, left, l - 1, cmp);
    sort(arr, l + 1, right, cmp);
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i].d1 >> a[i].d2 >> a[i].d3;
        a[i].num = i;
        a[i].total = a[i].d1 + a[i].d2 + a[i].d3;
    }
    sort(a,1,n,cmp);
    for(int i = 1; i <= 5; ++i)
    cout << a[i].num << ' ' << a[i].total << endl;
    return 0;
}
