#include<iostream>
using namespace std;
const int maxn = 32000 +10;
int n, m, f[maxn];
struct node{
    int v, p, q;
    int x[4];
    int num = 0;
}a[100];
bool cost(int i, int x1, int x2, int j){
    if(x1 && x2){
        if(a[i].num < 3 || a[a[i].x[1]].v + a[a[i].x[2]].v + a[a[i].x[3]].v > j)
        return false;
        return true;
    }
    if(x1){
        if(a[i].num < 2 || a[a[i].x[1]].v + a[a[i].x[2]].v > j)
        return false;
        return true;
    }

    if(x2){
        if(a[i].num < 2 || a[a[i].x[1]].v + a[a[i].x[3]].v > j)
        return false;
        return true;
    }

    if(a[i].v > j)
    return false;
    return true;
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        cin >> a[i].v >> a[i].p >> a[i].q;
        a[i].p *= a[i].v;
        if(!a[i].q)
        a[i].x[++a[i].num] = i;
    }
    //cout << endl;
    for(int i = 1; i <= m; ++i)
        if(a[i].q)
            a[a[i].q].x[++a[a[i].q].num] = i;

    int count = 1;
    for(int i = 1; i <= m; ++i)
        if(!a[i].q){
            for(int j = n; j >= 0; --j){
                if(cost(i, 1, 1, j))    f[j] = max(f[j], f[j - a[i].v - a[a[i].x[2]].v - a[a[i].x[3]].v] + a[i].p + a[a[i].x[2]].p + a[a[i].x[3]].p);
                if(cost(i, 1, 0, j))    f[j] = max(f[j], f[j - a[i].v - a[a[i].x[2]].v] + a[i].p + a[a[i].x[2]].p);
                if(cost(i, 0, 1, j))    f[j] = max(f[j], f[j - a[i].v - a[a[i].x[3]].v] + a[i].p + a[a[i].x[3]].p);
                if(cost(i, 0, 0, j))    f[j] = max(f[j], f[j - a[i].v] + a[i].p);
            }
            
        }
    cout << f[n] << endl;
    

}