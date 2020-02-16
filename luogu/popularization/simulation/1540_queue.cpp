#include<iostream>
using namespace std;
const int maxn = 1e5;
int n, m, a[maxn], i = 1, j = 0 , ans = 0, len = 0;
bool find(int x){
    for(int k = i; k <= j; ++k)
        if(a[k] == x)
            return true;
     return false;
}
void push(int x){
    if(j - i + 1 < m){
        a[++j] = x;
    }
    else{
        ++i;
        push(x);
    }
    
}
int main()
{
    cin >> m >> n;
    int tmp;
    for(int k = 1; k <= n; ++k){
        cin >> tmp;
        if(!find(tmp)){
            ++ans;
            push(tmp);
        }
   
    }
    cout << ans << endl;
    return 0;
}