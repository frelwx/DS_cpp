#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 1e6, inf = 1e9;
struct {
    int size, cnt, v;
}a[maxn];

void add(int num, int v){
    ++a[num].size;
    if(a[num].v == v){
        ++a[num].cnt;
        return;
    }

    if(a[num].v > v){
        if(a[num * 2].cnt){
            add(2 * num, v);
            return;
        }
        else {
            a[num * 2].v = v;
            ++a[num].cnt;
        }
    }
}
