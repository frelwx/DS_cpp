#include<iostream>
using namespace std;
const int maxn = 100000 + 10;
long long  f[maxn], v[100000], w[100000], t, n ,v2[100000], w2[100000], num;
int main()
{
    cin >> t >> n;
    for(int i = 1; i <= n; ++i){
        cin >> v[i] >> w[i];
        if(t / v[i] < 1){
            --i;
            --n;
            continue;
        }
        // 每种草药至多被采t / v[i] 次
        int k = 0, tmp = 0;
        for(; (1 << k) + tmp <= t / v[i]; ++k){
            v2[++num] = (1 << k) * v[i];
            w2[num] = (1 << k) * w[i];
        }
        if(tmp < t / v[i]){
            v2[++num] = (t / v[i] - tmp) * v[i];
            w2[num] = (t / v[i] - tmp) * w[i];
        }

    }

    for(int i = 1; i <= num; ++i)
        for(int j = t; j >= v2[i]; --j)
            if(j >= v2[i])
                f[j] = max(f[j], f[j - v2[i]] + w2[i]);
    cout << f[t] << endl;
}