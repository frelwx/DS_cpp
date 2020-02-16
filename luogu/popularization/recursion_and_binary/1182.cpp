#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, m, a[maxn];
bool check(int x){
    int sum = 0, k = 1;
    for(int i = 1; i <= n; ++i)
        if(sum + a[i] <= x)
            sum += a[i];
        else {
            ++k;
            sum = a[i];
        }
    if(k == 1 && m == 1)
        return false;
    return k <= m;
}
int main(){
    cin >> n >> m;
    int low = 0, high = 0, mid;
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
        low = max(a[i], low);
        high += a[i];
    }
    
    while(low < high){
        mid = (low + high) >> 1;
        if(check(mid))
            high = mid;
        else 
            low = mid + 1;
    }
    cout << high << endl;
    return 0;
}