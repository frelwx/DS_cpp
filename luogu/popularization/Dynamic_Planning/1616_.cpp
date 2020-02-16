#include<iostream>
using namespace std;
int f[100000 + 10];
int main()
{
    int t, n, v, w;
    cin >> t >> n;
    for(int i = 1; i <= n; ++i){
        cin >> v >> w;
        for(int j = v; j <= t; ++j)
            if(j >= v)
                f[j] = max(f[j], f[j - v] + w);
    }
    cout << f[t] << endl;
    return 0;
}