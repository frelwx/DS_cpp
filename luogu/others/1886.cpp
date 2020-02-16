#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int n, k, ans1 = 0, ans2 = 1e9, a[maxn];
struct node{
    int v, num;
}q[maxn];
void f1(){
    int head = 1, tail = 0;
    for(int i = 1; i <= n; ++i){
        while(head <= tail && a[i] > q[tail].v)
            --tail;
        while(head <= tail && q[head].num < i - k + 1)
            ++head;
        q[++tail].v = a[i], q[tail].num = i;
        if(i >= k)
            cout << q[head].v << ' ';
    }
}

void f2(){
    int head = 1, tail = 0;
    for(int i = 1; i <= n; ++i){
        while(head <= tail && a[i] < q[tail].v)
            --tail;
        while(head <= tail && q[head].num < i - k + 1)
            ++head;
        q[++tail].v = a[i], q[tail].num = i;
        if(i >= k)
            cout << q[head].v << ' ';
    }
}
int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    
    f2();
    cout << endl;
    f1();
    return 0;
}