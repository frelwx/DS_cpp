#include<iostream>
using namespace std;
const int maxn = 1e4;
int j = 0;
char a[maxn];
int main()
{
    cin >> a;
    for(int i = 0; a[i] != '@'; ++i){
        if(a[i] == '(')
            ++j;
        else if(a[i] == ')'){
            if(!j){
                cout << "NO" << endl;
                return 0;
            }
            else
            --j;
        }
        //cout << j << ' ' ;
    }
    if(j)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}