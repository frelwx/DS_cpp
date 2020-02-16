#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 30000 + 10;
int n, w, p[maxn];
int main()
{
    cin >> w >> n;
    for(int i  =1; i <= n; ++i)
        cin >> p[i];
    sort(p + 1, p +n + 1);

    int ans = 0;
    int nn = n;
    for(int i = 1; i <= n; ++i){
        for(int j = nn ; j > i; --j){
            if(p[j] + p[i] <= w){
                p[j] = p[i] = 0;
                ++ans;
                nn = j - 1;
                break;
            }
        }
    }

    for(int i = 1; i <= n; ++i)
        if(p[i])
            ++ans;
    cout << ans << endl;
    return 0;
}