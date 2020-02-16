#include<iostream>
#include<algorithm>
using namespace std;
int n, limit, v[100], f[20000];
int main()
{
    cin >> limit >> n;

    for(int i = 1; i <= n; ++i)
    cin >> v[i];
    for(int i = 1; i <= n; ++i)
        for(int j = limit; j >= 1; --j)
            if(j >= v[i])
                f[j] = max(f[j], f[j - v[i]] + v[i]);
    cout << limit - f[limit] << endl;
    
}