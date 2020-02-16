#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 1e4 + 100;
int n, m, f[maxn], a[maxn];
int main()
{
    cin >> n >> m;
    for(int i = 1;i <= n; ++i)
    cin >> a[i];
    
    f[0] = 1;


    for(int i = 1; i <= n; ++i)
        for(int j = m; j >= 0; --j)
            if(j >= a[i])
                f[j] = f[j - a[i]] + f[j]; // 拿 + 不拿
    cout << f[m] << endl;    
            
            
                
}