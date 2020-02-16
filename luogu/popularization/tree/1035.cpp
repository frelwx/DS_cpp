#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 100;
int n;

struct node{
    char l = '*', r = '*', p = '*';

}a[maxn];

void print(char x){
    cout << x;
    if(a[x - 'a' + 1].l != '*')
    print(a[x - 'a' + 1].l);

    if(a[x - 'a' + 1].r != '*')
    print(a[x - 'a' + 1].r);
    return;
}
int main()
{
    cin >> n;
    char tmp[4];
    for(int i = 1; i <= n; ++i){
        cin >> tmp;
        a[tmp[0] - 'a' + 1].l = tmp[1];
        a[tmp[0] - 'a' + 1].r = tmp[2];
        if(tmp[1] != '*')
        a[tmp[1] - 'a' + 1].p = tmp[0];
        if(tmp[2] != '*')
        a[tmp[2] - 'a' + 1].p = tmp[0];
    }
    char root;
    for(int i = 1; i <= 30; ++i)
    if(a[i].p == '*'){
        root = a[a[i].l - 'a' + 1].p;
        break;
    }
    print(root);
    return 0;

}