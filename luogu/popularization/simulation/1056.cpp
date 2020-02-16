#include<iostream>
using namespace std;
const int maxn = 2 * 1010;
int m, n, k, l, d, a1[maxn] = {0}, a2[maxn] = {0}, cnt1 = 0, cnt2 = 0;
struct p
{
    int n = 0;
    int w = 0;
};
bool cmp1(p &x, p &y){
    return x.w > y.w;
}
bool cmp2(p &x, p &y){
    return x.n < y.n;
}
p b1[maxn], b2[maxn];
void sort(p a[], int cnt, bool(*q)(p &x, p &y)){
    int delta = cnt;
    do{
        delta = delta / 3 + 1;
        for(int i = delta; i < cnt; ++i){
            if(q(a[i], a[i - delta])){
                p tmp = a[i];
                int j;
                for(j = i - delta; j >= 0 && q(tmp, a[j]); j -= delta){
                    a[j + delta] = a[j];
                }
                a[j + delta] = tmp;
            }
        }

    }while(delta > 1);
}


int main()
{
    cin >> m >> n >> k >> l >> d;
    int x, y, p, q;
    for(int i = 1; i <= d; ++i){
        cin >> x >> y >> p >> q;
        if(x == p)
            ++a2[min(y,q)];
        else
            ++a1[min(x,p)];
    }
    for(int i = 0; i < maxn; ++i){
        if(a1[i]){
            b1[cnt1].w = a1[i];
            b1[cnt1].n = i;
            ++cnt1;
        }
        if(a2[i]){
            b2[cnt2].w = a2[i];
            b2[cnt2].n = i;
            ++cnt2;
        }
    }
    sort(b1, cnt1, cmp1);
    sort(b2, cnt2, cmp1);
    sort(b1,k,cmp2);
    sort(b2,l,cmp2);
    for(int i = 0; i < k; ++i){
        cout << b1[i].n ;
        if(i != k - 1)
        cout << ' ';
    }
    cout << endl;
    for(int i = 0; i < l; ++i){
        cout << b2[i].n;
        if(i != l - 1)
        cout << ' ';
    }
    cout << endl;
}