#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 100;
int n;
char a[maxn], b[maxn]; //中根:左根右， 后根:左右根， 先根：根左右
void f(int l, int r, int al, int ar){
    if(l > r) return;
    cout << b[ar];
    //char aa = cin.get();
    
    int i = l;
    for(; i <= r; ++i)
    if(a[i] == b[ar])
    break;
    f(l, i - 1, al, al + (i - 1 - l));
    f(i + 1, r,al + (i - 1 - l) + 1, ar - 1);
    return;
}
int main()
{
    cin >> a + 1 >> b + 1;
    n = strlen(a + 1);
    f(1, n, 1, n);
    return 0;
}