#include<bits/stdc++.h>
using namespace std;
long long int b ,p ,k = 2019;
int main()
{
    cin >> b >> p >> k;
    long long int  res = 1, base = b, tmp = p;
    while(p){
        if(p & 1)
        res = (res * (base % k)) % k;
        p >>= 1;
        base = ((base % k) * (base % k)) % k;
        
    }
    cout << b << "^" << tmp << " mod " << k << "=" << res % k << endl;
    return 0;
}