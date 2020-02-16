#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn = 1e3 + 10;
int n;
struct peo{
    int t;
    int num;
}a[maxn];
bool cmp(peo x, peo y){
    return x.t < y.t;

}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i].t;
        a[i].num = i;
    }
    sort(a + 1, a + n + 1, cmp);
    long long ans = 0;

    for(int i = 1; i <= n; ++i){
        cout << a[i].num << ' ';
        ans += (n - i) * a[i].t;
    }
    printf("\n%.2lf\n", double(ans)/ n);
    return 0;

}