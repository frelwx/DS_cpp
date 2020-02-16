#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e4 + 100;
int n, a, b, sum[2000], ans[2000], n_sum, n_ans, n_div, tmp[2000], divi[2000];
struct p{
    unsigned long long a, b;
}x[maxn];
bool cmp(p x1, p x2){
    return double(x1.a) / x2.b < double(x2.a) / x1.b;
}

bool cmp2(int x[], int y[], int nx, int ny){
    if(nx != ny)
        return nx > ny;
    for(int i = nx; i >= 1; --i)
        if(x[i] != y[i])
            return x[i] > y[i];
}



void multi(long long x){
    int k = 0;
    while(x){
        for(int i = 1; i <= n_sum; ++i){
            tmp[i + k] += x % 10 * sum[i];
            tmp[i + k + 1] += tmp[i + k] / 10;
            tmp[i + k ] %= 10;
        }
        ++k;
        x /= 10;
    }

    n_sum += k;
    while(tmp[n_sum] == 0)
        --n_sum;
    for(int i = 1; i <= n_sum; ++i){
        sum[i] = tmp[i];
        tmp[i] = 0;
    }
}
void divide(long long x){
    int tmp2[200] = {0}, k = 0, tans[2000] = {0};
    long long y = x;
    while(y){
        tmp2[++k] = y % 10;
        y /= 10;
    }
    if(cmp2(tmp2, sum, k, n_sum)){
        for(int i = 1; i <= n_div; ++i)
            divi[i] = 0;
        n_div = 1;
        return;
    }
    for(int i = 1; i <= n_sum; ++i)
        tmp[i] = sum[n_sum - i + 1];
    int mod = 0;
    for(int i = 1; i <= n_sum; ++i){
        tans[i] = (mod * 10 + tmp[i]) / x;
        mod = (mod * 10 + tmp[i]) % x;
        tmp[i] = 0;
    }
    int s = 1;
    while(tans[s] == 0 && s <= n_sum)
    ++s;
    n_div = n_sum - s + 1;
    for(int i = s; i<= n_sum; ++i)
    divi[n_sum - i + 1] = tans[i];
    return;
   

}

void update(){
    if(cmp2(ans, divi, n_ans, n_div))
        return;
    n_ans = n_div;
    for(int i = 1;i <= n_ans; ++i)
        ans[i] = divi[i];
}
int main()
{
    cin >> n >> a >> b;
    for(int i = 1; i <= n; ++i)
        cin >> x[i].a >> x[i].b;
    sort(x + 1, x + 1 + n, cmp);
    while(a){
        sum[++n_sum] = a % 10;
        a /= 10;
    }



    for(int i = 1; i <= n ; ++i){
        divide(x[i].b);
        update();
        multi(x[i].a);
    }
    for(int i = n_ans; i >= 1; --i)
        cout << ans[i];
    cout << endl;
    return 0;
    
}