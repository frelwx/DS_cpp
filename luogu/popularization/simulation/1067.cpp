//本题分三种情况特判，即n >= 2, n == 1 和 n == 0
//n >= 2时， 开头结尾进行特判， 其余循环
//n == 1，直接输出一次项和0次项
//n == 0， 直接输出系数
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 110;
int n, a[maxn];
int main() 
{
    cin >> n;
    for(int i = 1; i <= n + 1; ++i)
        cin >> a[i];
  
    if(n >= 2){
            if(a[1] > 0){
                if(a[1] != 1)
                    cout << a[1] << "x^" << n;
                else
                    cout << "x^" << n;
                
            }
            else if(a[1] < 0){
                if(a[1] != -1)
                    cout << "-" << -a[1] << "x^" << n;  
                else
                    cout << "-x^"  << n;
                
            }
        

        for(int i = 2; i <= n-1; ++i){
            if(a[i] > 0){
                if(a[i] != 1)
                    cout << "+" << a[i] << "x^" << n - i + 1;
                else 
                    cout << "+" << "x^" << n - i + 1;
            }
            else if(a[i] < 0){
                if(a[i] != -1)
                    cout <<  a[i] << "x^" << n - i + 1;
                else
                    cout << "-x^" << n - i + 1;
                
            }
            
        }

        if(a[n] > 0){
            if(a[n] != 1)
                cout << "+" << a[n] << "x";
            else
                cout << "+x"; 
            
        }
        else if(a[n] < 0){
            if(a[n] != -1)
                cout << a[n] << "x";
            else
                cout << "-x";
            
        }

        if(a[n + 1] > 0){
            cout << "+" << a[n + 1] ;
        }
        else if(a[n + 1] < 0)
            cout << a[n + 1];
            
    }

    if(n == 1){
         if(a[n] > 0){
            if(a[n] != 1)
                cout << a[n] << "x";
            else
                cout << "x"; 
            
        }
        else if(a[n] < 0){
            if(a[n] != -1)
                cout << a[n] << "x";
            else
                cout << "-x";
        }

        if(a[n + 1] > 0){
            cout << "+" << a[n + 1] ;
        }
        else if(a[n + 1] < 0)
            cout << a[n + 1];


    }
    if(n == 0){
        cout << a[1];
    }
     
     return 0;
}