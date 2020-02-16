#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 2000 + 10;
int m, a[maxn], b[maxn], c[maxn];
char p[maxn], q[maxn];
int main()
{
    cin >> m >> p >> q;

    int na = strlen(p), nb = strlen(q);
    for(int i = 0; i < na; ++i){
        if(p[i] >= '0' && p[i] <= '9')
            a[na - i] = p[i] - '0';
        else 
            a[na - i] = p[i] - 'A' + 10;
    }
    for(int i = 0; i < nb; ++i){
        if(q[i] >= '0' && q[i] <= '9')
            b[nb - i] = q[i] - '0';
        else 
            b[nb - i] = q[i] - 'A' + 10;
    }
    int k = max(na, nb) + 1, delta = 0;
    for(int i = 1; i <= k; ++i){
        c[i] = a[i] + b[i] + delta;
        delta = c[i] / m;
        c[i] %= m;
    }

    while(c[k] == 0 && k > 1)
    --k;
    for(int i = k; i >= 1; --i)
        if(c[i] >= 10)
            cout << char(c[i] - 10 + 'A');
        else 
            cout << c[i];
    cout << endl;
}