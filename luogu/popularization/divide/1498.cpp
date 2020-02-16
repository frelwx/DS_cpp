#include<iostream>
#include<cstring>
using namespace std;
int n;
const int maxn = 2050;
char a[maxn][maxn];
int w = 4, high = 2;
void right(){
    for(int i = 1; i <= high; ++i)
        for(int j = 1; j <= w; ++j)
            a[i][j + w] = a[i][j];
}
void down(){
    for(int i = 1; i <= high; ++i)
        for(int j = 1; j <= w; ++j)
            a[i + high][j + w / 2] = a[i][j];
}
int main()
{
    cin >> n;
    memset(a, ' ', sizeof(a));
    a[1][1] = a[2][2] = '\\';
    a[1][2] = a[1][3] = '_';
    a[1][4] = a[2][3] = '/';
    right();
    down();
    for(int i = 1; i < n; ++i){
        right();
        down();
        high *= 2;
        w *= 2;
    }


    for(int i = high; i >= 1; --i){
        for(int j = 1; j <= w; ++j){
            if(a[i][j] == '/')
                cout << '\\';
            else if(a[i][j] == '\\')
                cout << '/';
            else
                cout << a[i][j] ;
        }
        cout << endl;
    }

    
}
//   __ 
//  \  /
//   \/