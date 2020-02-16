#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int maxn = 100000+10;
double cost_sell, delta, maxp = 0, ps[maxn], ps2[maxn], ps3[maxn];
double k, b, sup = maxn, inf = -maxn;
int cost, ex;
int main(){
    cin >> ex;
    cin >> cost >> cost_sell;
    ps[cost] = cost_sell;
    int tmp1, index = 0;
    double tmp2;
    while(1){
        cin >> tmp1 >> tmp2;
        if(tmp1 == -1)
            break;
        ps2[++index] = tmp2;
        ps3[index] = tmp1;
        ps[tmp1] = tmp2;
        if(tmp1 > maxp)
            maxp = tmp1;
    }
    cin >> delta;
  
    double d = -(cost_sell - ps2[1]) / (cost - ps3[1]);

    for(int i = cost; i < maxp; ++i)
        if(!(ps[i + 1] > 0))
            ps[i + 1] = ps[i] - d;
    
    for(int i = maxp; i < maxn; ++i)
        if(!(ps[i + 1] > 0))
            ps[i + 1] = ps[i] - delta;

    //for(int i = cost; i < maxn && ps[i] > 0; ++i)
    //cout << i << '\t' << ps[i] << endl;
    
    for(int i = cost + 1;i < ex && ps[i] > 0; ++i){
        double tmp = ((ex - cost) * ps[ex] - (i - cost) * ps[i]) / (ps[i] - ps[ex]);
        if(tmp < sup)
        sup = tmp;
        
    }
    for(int i = ex + 1; i < maxn && ps[i] > 0; ++i){
        double tmp = ((i - cost) * ps[i] - (ex - cost) * ps[ex]) /(ps[ex] - ps[i]);
        if(tmp > inf)
        inf = tmp;
        //cout << "11 \t"<< tmp << endl;
    }
    //cout << int(inf) << ' '  << sup << endl;
    if(sup - inf < 1){
        printf("NO SOLUTION\n");
        return 0;
    }
    if(inf < 0){
        if(fabs(inf - int(inf)) >= 1e-3)
        inf = -(int(-inf));
    }
    else{
        if(fabs(inf - int(inf)) >= 1e-3)
        inf = int(inf) + 1;
    }
    if(sup < 0){
        if(fabs(sup - int(sup)) > 1e-3)
        sup = -(int(-sup) + 1);
    }
    else{
        if(fabs(sup - int(sup)) > 1e-3)
        sup = -(int(-sup));
    }
    int inf2 = inf, sup2 = sup;
    if(inf > 0 && sup > 0)
        cout << inf << endl;
            else if(inf < 0 && sup < 0)
                cout << sup << endl;
                    else
                        cout << 0 << endl;
                    
            
    
    return 0;
}