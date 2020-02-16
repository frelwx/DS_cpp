#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 10;
int n, m, p2[maxn], cnt = 0;
bool p1[maxn];
void prime(){
    for(int i = 2; i <= n; ++i)
    p1[i] = true;
    for(int i = 2; i <= n; ++i){
        if(p1[i])
            p2[++cnt] = i;
        for(int j = 1; i * p2[j] <= n && j <= cnt; ++j){
            p1[i * p2[j]] = false;
            if(i % p2[j] == 0)   break;
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    int tmp;
    prime();
    while(m--){
        scanf("%d", &tmp);
        if(p1[tmp])
            printf("Yes\n");
        else
            printf("No\n");
        
    }
}