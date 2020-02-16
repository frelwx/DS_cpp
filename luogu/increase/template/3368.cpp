#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10, maxm = 1e7 + 100;
int n, m;
long long a[maxn], t[maxm], lazy[maxm];
void push_up(int k){
    t[k] = t[2 * k] + t[2 * k + 1];
}

void push_down(int l ,int r, int k){
    if(lazy[k]){
        lazy[k << 1] += lazy[k];
        lazy[k * 2 + 1] += lazy[k];
        int mid = (l + r) >> 1;
        t[k << 1] += lazy[k] * (mid - l + 1);
        t[k * 2 + 1] += lazy[k] *(r - (mid + 1) + 1);
        lazy[k] = 0;
    }
}
void buid(int l, int r, int k){
    if(l == r)
        t[k] = a[l];
    else {
        int mid = (l + r) >> 1;
        buid(l, mid, 2 * k);
        buid(mid + 1, r, 2 * k + 1);
        push_up(k);
    }
}

long long query(int L, int R, int l, int r, int k){
    if(L <= l && R >= r)
        return t[k];
    else {
        int mid = (l + r) >> 1;
        long long res = 0;
        push_down(l, r, k);
        if(L <= mid)
            res += query(L, R, l, mid, 2 * k);
        if(R > mid)
            res += query(L, R, mid + 1, r, 2 * k + 1);
        return res;
    }
}

void update(int p, long long v, int l, int r, int k){
    if(l == r) {
        a[l] += v;
        t[k] += v;
    }

    else{
        int mid = (l + r) >> 1;
        if(p <= mid)
            update(p, v, l, mid, 2 * k);
        else 
            update(p, v, mid + 1, r, 2 * k + 1);
        push_up(k);
    }
}



void update_interval(int L, int R, long long v, int l, int r, int k){
    if(L <= l && R >= r){
        lazy[k] += v;
        t[k] += (r - l + 1) * v;
    }

    else {
        int mid = (l + r) >> 1;
        push_down(l, r, k);
        if(L <= mid)
            update_interval(L, R, v, l, mid, 2 * k);
        if(R > mid)
            update_interval(L, R, v, mid + 1, r, 2 * k + 1);
        push_up(k);

    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    buid(1, n, 1);
    int tmp, x, y;
    long long k;
    for(int i = 1; i <= m; ++i){
        scanf("%d", &tmp);
        if(tmp == 2){
           scanf("%d", &x);
            //cout << "???" << endl;
            printf("%lld\n", query(x, x, 1, n, 1));
        }
        else {
            scanf("%d%d%lld", &x, &y, &k);
            update_interval(x, y, k, 1, n ,1);
        }
    }

    
}