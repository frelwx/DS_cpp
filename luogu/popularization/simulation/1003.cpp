#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 1e4 + 10;
int n, x, y;
struct p
{
    int a, b, g, k;
}q[maxn];

int main()
{
    scanf("%d", &n);
    int mx = 0, my = 0;
    for(int i = 1; i <= n; ++i){
        scanf("%d%d%d%d", &q[i].a, &q[i].b, &q[i].g, &q[i].k);
        if(q[i].a + q[i].g > mx) mx = q[i].a + q[i].g;
        if(q[i].b + q[i].k > my) my = q[i].b + q[i].k;
        
    }
    scanf("%d%d", &x, &y);
    if(x > mx || y > my){
    printf("%d\n",-1);
    return 0;
    }
    
    for(int i = n; i >= 1; --i){
        if(x >= q[i].a && x <= q[i].a + q[i].g && y >= q[i].b && y <= q[i].b + q[i].k){
            printf("%d\n",i);
            return 0;
        }
    }



}