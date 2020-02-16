#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e6 + 10, inf = 1e9;
int a[maxn], num, n;
void modify_up(int x){
    if(x == 1)
        return;
    if(a[x] < a[x / 2]){
        swap(a[x], a[x / 2]);
        modify_up(x / 2);
    }
}
void push(int x){
    a[++num] = x;
    modify_up(num);
}
void modify_down(int x){
    if(a[x] == inf)
        return;
    int tmp = (a[x * 2] <  a[x * 2 + 1]) ? (x * 2):(x * 2 + 1);
    if(a[x] > a[tmp]){
        swap(a[x], a[tmp]);
        modify_down(tmp);
    } 
}

void pop(){
    swap(a[1], a[num]);
    a[num--] = inf;
    modify_down(1);
}
int main()
{
    cin >> n;
    for(int i = 1; i < maxn; ++i)
        a[i] = inf;
    int x;
    for(int i = 1; i <= n; ++i){
        scanf("%d", &x);
        if(x == 1){
            scanf("%d", &x);
            push(x);
        }
        else if (x == 2)
            printf("%d\n", a[1]);
        else 
            pop();
        
    }
    return 0;
    
}