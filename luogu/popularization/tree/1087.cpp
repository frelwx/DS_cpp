#include<iostream>
#include<cmath>
using namespace std;
const int maxn = 2000, maxm = 1e6;
char a[maxn];
int n, sum1[maxn], sum2[maxn];
struct node{
    int l, r, t;
}tree[maxm];
void buid(int l, int r, int k){

    if(sum1[r] - sum1[l - 1] && sum2[r] - sum2[l - 1])
        tree[k].t = 3;
    else if(!(sum1[r] - sum1[l - 1]) && sum2[r] - sum2[l - 1])
        tree[k].t = 2;
    else if(sum1[r] - sum1[l - 1] && !(sum2[r] - sum2[l - 1]))
        tree[k].t = 1;
    tree[k].l = 2 * k;
    tree[k].r = 2 * k + 1;
    //cout << tree[k].t << '\t';
    if(r - l >= 1){
        int mid = (l + r) / 2;
        buid(l, mid, 2 * k);
        buid(mid + 1, r, 2 * k + 1);
    }
    return;
}
void print(int k){
    if(tree[k].l)
    print(2 * k);
    if(tree[k].r)
    print(2 * k + 1);
    if(tree[k].t == 3)
        cout << 'F';
    else if(tree[k].t == 2)
        cout << 'I';
    else if(tree[k].t == 1)
        cout << 'B';
    return;
}
int main()
{
    cin >> n >> (a + 1);
    n = pow(2, n);
    for(int i = 1; i <= n; ++i){
        if(a[i] == '0'){
            sum1[i] = sum1[i - 1] + 1;
            sum2[i] = sum2[i - 1];
        }
        else{
            sum1[i] = sum1[i - 1];
            sum2[i] = sum2[i - 1] + 1;
        }
        //cout << sum1[i] << ' ' << sum2[i] << endl;
    }

  
    buid(1, n, 1);
    print(1);
    return 0;
}