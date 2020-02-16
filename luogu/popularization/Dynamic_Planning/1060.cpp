#include<iostream>
using namespace std;
const int maxn = 100;
int n, m;
struct node
{
    int v, w;
}a[maxn];
int f[30000];

int main()
{
    cin >> n >> m;
    int tmp1;
    for(int i = 1; i <= m; ++i){
        cin >> a[i].v >> a[i].w;
        a[i].w *= a[i].v;
    }

    for(int i = 1; i <= m; ++i)
        for(int j = n; j >= 0; --j)
            if(j >= a[i].v)
                f[j] = max(f[j], f[j - a[i].v] + a[i].w);
    cout << f[n] << endl;
    

}