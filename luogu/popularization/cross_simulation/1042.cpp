#include<iostream>
#include<cmath>
using namespace std;
const int maxn = 25 * 2500 + 10;
char a[maxn];
int a1[maxn], a2[maxn], b1[maxn], b2[maxn];
int main()
{
    int index = 0;
    char tmp;
    while(1){
        cin.get(tmp);
        if(tmp == 'E')
            break;
        if(tmp != 'W' && tmp != 'L')
            continue;
        a[++index] = tmp;
    }
    ++index;
    //cout << index << ' ' << tmp << endl;
    //cin.get(tmp);
    //cout << index << endl;
    int k = 1;
    for(int i = 1; i < index; ++i){
        if(a[i] == 'W')
            ++a1[k];
        else
            ++b1[k];
        if(abs(a1[k] - b1[k]) >= 2 && (a1[k] >= 11 || b1[k] >= 11))
        ++k;
    }
   
    for(int i = 1; i <= k; ++i){
        cout << a1[i] << ":" << b1[i] << endl;
    }
    cout << endl;
    k = 1;
    for(int i = 1; i < index; ++i){
    if(a[i] == 'W')
        ++a2[k];
    else
        ++b2[k];
    if(abs(a2[k] - b2[k]) >= 2 && (a2[k] >= 21 || b2[k] >= 21))
        ++k;
    }
   
    for(int i = 1; i <= k; ++i){
        cout << a2[i] << ":" << b2[i] << endl;
    }
    return 0;
}