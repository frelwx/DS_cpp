#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 2e5 + 10;
int n, k, e[11];
struct p{
    int w;
    int num;
} a[maxn];
void swap(p &x, p &y){
    p tmp = x;
    x = y;
    y = tmp;
    return;
}
bool cmp(p &x, p &y){
    if(x.w != y.w)
    return x.w < y.w;
    return x.num >= y.num;
}
void sort(p arr[],int left, int right, bool(*q)(p &x, p &y)){
    if(left >= right) return;
    int l = left, r = right;
    p k = arr[left];
    while(l < r)
    {
        while(l < r && q(arr[r], k)) --r;
        while(l < r && q(k, arr[l])) ++l;
        swap(arr[l], arr[r]);

    }
    swap(arr[left], arr[l]);
    sort(arr, left, r - 1, q);
    sort(arr, r + 1, right, q);
}
int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 1;i <= 10; ++ i)
    scanf("%d",&e[i]);
    
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i].w);
        a[i].num = i;
    }

    sort(a, 1, n, cmp);
    for(int i = 1; i <= n; ++i){
        a[i].w += e[(i - 1) % 10 + 1];
    }
    sort(a,1,n,cmp);


    for(int i = 1; i <= k; ++i)
    printf("%d\ ", a[i].num);



}