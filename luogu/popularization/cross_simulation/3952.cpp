#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn = 1e9;
int t, l, w, stack_[1000] = {0}, xx[1000] = {0}, yy[1000] = {0}, O[1000] = {0};
char gans[10], code[110][2], varname[110][10] = {0};
bool var[1000];
bool check_err(){
    int k = 0;
    for(int i =  1; i <= l; ++i){
        if(code[i][0] == 'F'){
            ++k;
            //cout << code[i][1] << endl;
            if(var[(int)varname[i][0]]) // 变量已存在
                return false;
            else
                var[(int)varname[i][0]] = true; 
            stack_[k] = (int)varname[i][0]; // 变量入栈（记录下标）
        }
        else if(code[i][0] == 'E'){
            if(k >= 1){
                var[stack_[k]] = false; // 变量出栈
                --k;
            }
            else return false;

        }
    }
    if(k)
    return false;
    return true;
}
void cal(){ 
    int tmp = 0, k = 0, ans = 0;
    for(int i = 1; i <= l; ++i){
        if(code[i][0] == 'F'){
            ++k;
            if(xx[i] > yy[i])
                O[k] = 0;
            else{
                if(xx[i] != maxn && yy[i] != maxn || xx[i] == maxn)
                    O[k] = 1;
                else{
                    O[k] = maxn;
                }
            }
        }
          
        else if(code[i][0] == 'E'){
            for(int m = 1; m <= k && O[m]; ++m)
            tmp += (O[m] == maxn) ? 1 : 0;
            ans = (tmp > ans) ? tmp : ans;
            --k;
            tmp = 0;
        }
    }
    //cout << w << '\t' << ans << endl;
    if(w == ans)
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;


}
int main()
{
    cin >> t;
    
    while(t--){
        memset(var, false, sizeof(var));
        memset(stack_, 0, sizeof(stack_));
        memset(xx, 0, sizeof(xx));
        memset(yy, 0, sizeof(yy));
        memset(O, 0, sizeof(O));
        w = 0;
        cin >> l >> gans;
        if(gans[2] != 'n')
            w = 0;
        else {
            for(int i = 4; i < strlen(gans); ++i){
                if(gans[i] >= '0' && gans[i] <= '9')
                    w = w * 10 + gans[i] - '0';
            }
        }
        for(int i = 1; i <= l; ++i){
            cin >> code[i][0];
            if(code[i][0] == 'E')
                continue;
            char tmp[5];
            cin >> varname[i];

            cin >> tmp;
            if(tmp[0] == 'n')
                xx[i] = maxn;
            else{
                //cout << "tmp[i]=" << tmp[0] - '0'<<'\n';
                for(int m = 0; m < strlen(tmp); ++m)
                xx[i] = xx[i] * 10 + tmp[m] - '0';
            }
            cin >> tmp;
            if(tmp[0] == 'n')
                yy[i] = maxn;
            else{
                for(int m = 0; m < strlen(tmp); ++m)
                yy[i] = yy[i] * 10 + tmp[m] - '0';
            }
            
            
            //cout << code[i][0] << '\t' << varname[i] << '\t' << xx[i] << '\t' << yy[i] << endl;
        }
        //cout << "begin" << endl;
        if(!check_err()){
            cout << "ERR" << endl;
            continue;
        }
        //cout << "end" << endl;
        cal();
    }
    return 0;
}