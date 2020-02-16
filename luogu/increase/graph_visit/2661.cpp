//因为每个点的出度都是一， 所以每个点至多存在一个环中， 各个环之间互不干扰
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 200000 + 10;
int n, to[maxn], ans = 1e9;
int find(int x, int &step){
    ++step;
    if(to[x] == x)
        return x;
    return find(to[x], step);
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
        to[i] = i;
    int T;
    for(int i = 1;  i<= n; ++i){ // a->b, 切记将环连起来， 否则find会死循环
        cin >> T;
        int step = 0;
        if(find(T, step) == i)
            ans = min(ans, step);
        else 
            to[i] = T;
    }

    cout << ans << endl;
}