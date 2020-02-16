#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 200;
int n, b[22];
char a[22][maxn];
bool cmp(int x, int y){
    int n1 = strlen(a[x]), n2 = strlen(a[y]);
    if(n1 >= n2){
        for(int t = 1; t <= n1 / n2; ++t){
            for(int i = 0;i < n2; ++i)
                if(a[x][i * t] != a[y][i])
                    return a[x][i * t] > a[y][i];
        }

        for(int i = n1 / n2 * n2 ; i < n1;++i)
            if(a[x][i] != a[y][i - n1 / n2 * n2])
                return a[x][i] > a[y][i - n1 / n2 * n2];

        return false;
    }

    if(n2 > n1)
        return !cmp(y, x);

    
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i){
        b[i] = i;
        cin >> a[i];
    }
    sort(b + 1, b + n + 1, cmp);
    for(int i = 1; i <= n; ++i)
    cout << a[b[i]];
    return 0;
}