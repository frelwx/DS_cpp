#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 1e6 + 100;
int n;
struct node{
    int l, r, w;
}a[maxn];
bool flag;
void check(int x, int y){
    if(x == -1 && y == -1)
        return;
    if(a[x].w != a[y].w){
        flag = false;
        return;
    }

    check(a[x].l, a[y].r);
    check(a[x].r, a[y].l);
}

int count(int x){
    if(x == -1)
        return 0;
    return (count(a[x].l) + count(a[x].r) + 1);
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i].w);
    for(int i = 1; i <= n; ++i)
    scanf("%d%d", &a[i].l, &a[i].r);
    int ans = 1;
    for(int i = 1; i <= n; ++i){
        flag = true;
        check(a[i].l, a[i].r);
        if(flag)
        ans = max(count(i), ans);
    }
    cout << ans << endl;
}
