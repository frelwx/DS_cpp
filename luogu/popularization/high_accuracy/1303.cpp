#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn = 1e6;
char a[maxn], b[maxn];
int aa[maxn], bb[maxn], cc[maxn];
int main()
{
    cin >> a >> b;
    int na = strlen(a), nb = strlen(b);
    for(int i = 0; i < na; ++i)
        aa[na - i] = a[i] - '0';

    for(int i = 0; i < nb; ++i)
        bb[nb - i] = b[i] - '0';

    for(int i = 1; i <= na; ++i)
        for(int j = 1; j <= nb; ++j){
            cc[i + j - 1] += aa[i] * bb[j];
            cc[i + j] +=cc[i + j - 1] / 10;
            cc[i + j - 1] %= 10;
            //cout << cc[i + j - 1] << ' '  << aa[i] << ' ' << bb[i] << endl;
        }
    int nc = na + nb;
    while(cc[nc] == 0 && nc > 1)
    --nc;

    for(int i = nc; i >= 1; --i)
    printf("%d", cc[i]);
    cout << endl;
    return 0;
}