#include<iostream>
#include<cmath>
using namespace std;
int n;

void f(int x){
    bool flag = false;
    if(x <= 1 + 2 + 4){
        if(x >= 4){
            cout << "2(2)";
            x -= 4;
            flag = true;
        }
        if(x >= 2){
            if(flag)
                cout << "+";
            cout << "2";
            flag = true;
            x -= 2;
        }
        if(x){
            if(flag)
                cout << "+";
            cout << "2(0)";
        }
        return;
    }
    while(x > 7){
        for(int i = 1; i <= 1e9; ++i){
            if((2 << i)  <= x && (2 << (i + 1)) > x){
                if(flag)
                cout << "+";
                cout << "2(" ;
                flag = true;
                //cout << endl << (2 << 3) << ' ' << x << endl;
                f(i + 1);
                cout << ")";
                x -= (2 << i);
                break;
            }
        }
    }

    if(x){
        cout << "+";
        f(x);
    }


}
int main()
{
    cin >> n;
    f(n);
    return 0;
}