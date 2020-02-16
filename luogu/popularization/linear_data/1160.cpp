#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 100000 + 100;
int n, m, res[maxn];
struct p{
    int l = 0, r = 0, check = 0;
}a[maxn];
int main()
{
    cin >> n;
    int k, p;
    for(int i = 2; i <= n; ++i){
        scanf("%d%d", &k, &p);
        if(p){ // 把i插到k的右边
            a[i].l = k;
            a[i].r = a[k].r;
            a[a[k].r].l = i;
            a[k].r = i;
        }
        else{ // 插到左边
            a[i].r = k;
            a[i].l = a[k].l;
           
            a[a[k].l].r = i;
            a[k].l = i;
        }
        
    }
    
    for(int i = 1; i <= n; ++i)
    a[i].check = 1;
    int x = 2;
    
    cin >> m;
    for(int i = 1; i <= m; ++i){
        scanf("%d", &x);
        if(a[x].check){
            a[a[x].l].r = a[x].r;
            a[a[x].r].l = a[x].l;
            a[x].check = 0;
        }
       
    }
    for(int i = 1; i <= n; ++i)
        if(a[i].check){
            x = i;
            break;
        }
    while(a[a[x].l].check && x <= n && x >= 1)
    x = a[x].l;
    int j = 0;
    for(int i = 1; i <= n; ++i){
        if(a[x].check){
            res[++j] = x;
            x = a[x].r;
        }
    }
    for(int i = 1; i < j; ++i)
    cout << res[i] << ' ';
    cout << res[j];
    
    return 0;
}