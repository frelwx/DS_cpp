#include<iostream>
#include<cmath>
using namespace std;
const int maxn = 30;
int m, n, k, maps[maxn][maxn], index = 0;
struct p{
    int x;
    int y;
    int w;
}a[maxn * maxn];
void sort(){
    int delta = index;
    do{
        delta = delta / 3 + 1;
        for(int i = delta + 1; i <= index; ++i){
            if(a[i].w > a[i - delta].w){
                p tmp = a[i];
                int j;
                for(j = i - delta; j >= 1 && a[j].w < tmp.w; j -= delta)
                    a[j + delta] = a[j];
                a[j + delta] = tmp;
            }
        }
    }while(delta > 1);
}
int main()
{
    cin >> m >> n >> k;
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j){
            cin >> maps[i][j];
            if(maps[i][j]){
                a[++index].x = i;
                a[index].y = j;
                a[index].w = maps[i][j];
            }
        }
    sort();
    int ans = 0, t = 0;
    if(a[1].x * 2 + 1 > k){
        cout << ans << endl;
        return 0;
    }
    t += a[1].x + 1;
    ans += a[1].w;
    //cout << ans << ' ' << t << endl;
    for(int i = 2; i <= index; ++i){
        int tmp = abs(a[i].x - a[i - 1].x) + abs(a[i].y - a[i - 1].y);
        if(t + tmp + 1 + a[i].x <= k){
            ans += a[i].w;
            t += tmp + 1;
        }
        else{
            t += a[i - 1].x;
            break;
        }
        //cout << ans << ' ' << t << endl;
    }
    cout << ans << endl;

    
}