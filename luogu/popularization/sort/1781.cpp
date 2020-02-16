#include<iostream>
#include<cstring>
using namespace std;
int n, maxn = 0;
struct p{
    char num[101] = {0};
} a[100];
bool cmp(const p &x, const p &y){
    if(strlen(x.num) != strlen(y.num))
    return strlen(x.num) > strlen(y.num);
    for(int i = 0; i < strlen(x.num); ++i){
        if(x.num[i] != y.num[i]) return x.num[i] > y.num[i];
    }
    return false;
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].num;
    }
    p tmp = a[0];
    for(int i = 0; i < n; ++i){
        if(cmp(a[i],tmp))
        {
            tmp = a[i];
            maxn = i + 1;
        }
    }
    cout << maxn << endl << tmp.num << endl;
}

