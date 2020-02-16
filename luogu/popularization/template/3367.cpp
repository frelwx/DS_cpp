#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, m, z, x, y, f[maxn];
int find(int p){
    return (f[p] == p) ? p : (f[p] = find(f[p]));
}
void check(int p1, int p2){
    if(find(p1) == find(p2))
        printf("Y\n");
    else
        printf("N\n");
}
void merge(int p1, int p2){
    f[find(p1)] = find(p2);
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i)
    f[i] = i;
    while(m--){
        scanf("%d%d%d", &z, &x, &y);
        if(z == 1)
            merge(x, y);
        else
            check(x, y);
        
    }
    return 0;
}