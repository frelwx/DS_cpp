#include<bits/stdc++.h>
using namespace std;
const int maxn = 10000000 + 1;
int n, m ;
bool p[maxn];
void prime(){
    for(int i = 1; i <= maxn; ++i)
    p[i] = true;
    p[1] = p[0] = false;
    for(int i = 2; i <= n; ++i){
        if(!p[i])
        continue;
        for(int j = 2 * i; j <= n; j += i)
            p[j] = false;
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    int tmp;
    prime();
    while(m--){
        scanf("%d", &tmp);
        if(p[tmp])
            printf("Yes\n");
        else
            printf("No\n");
        
        
    }
}