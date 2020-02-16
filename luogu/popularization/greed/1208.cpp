#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 5e3 + 100;
int n, m;
struct farmer{
    int p, a;
}b[maxn];
bool cmp(farmer x, farmer y){
    return x.p < y.p;
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; ++i)
        cin >> b[i].p >> b[i].a;
    sort(b + 1, b + 1 + m, cmp);

    int sum = 0, cost = 0;
    int i = 1;
    for(; i <= m; ++i)
        if(sum + b[i].a <= n){
            sum += b[i].a;
            cost += b[i].p * b[i].a;

        }
        else 
            break;
    cout << cost + (n - sum) * b[i].p << endl;

}