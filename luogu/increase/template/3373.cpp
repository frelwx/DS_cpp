#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const int maxn = 5e5 + 10, maxm = 1e7 + 100;
int n, m, p;
long long a[maxn], t[maxm], lazy[maxm], lazy_mul[maxm];
void push_up(int k){
    t[k] = (t[2 * k] + t[2 * k + 1]) % p;
}


void push_down(int l ,int r, int k){
        int mid = (l + r) >> 1;

        t[k << 1] = (lazy[k] * (mid - l + 1) + t[k << 1] * lazy_mul[k]) % p;
        t[k * 2 + 1] = (lazy[k] *(r - (mid + 1) + 1) + t[2 * k + 1] * lazy_mul[k]) % p;

        lazy[k << 1] = (lazy[k] + lazy[k << 1] * lazy_mul[k]) % p;
        lazy[k * 2 + 1] = (lazy[k] + lazy[k * 2 + 1] * lazy_mul[k]) % p;

        lazy_mul[k << 1] = (lazy_mul[k << 1] * lazy_mul[k]) % p;
        lazy_mul[k * 2 + 1] = (lazy_mul[k * 2 + 1] * lazy_mul[k]) % p;
       
        lazy[k] = 0;
        lazy_mul[k] = 1;
}


void buid(int l, int r, int k){
    lazy_mul[k] = 1;
    if(l == r)
        t[k] = a[l] % p;
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
            res = (query(L, R, l, mid, 2 * k) + res) % p;
        if(R > mid)
            res = (query(L, R, mid + 1, r, 2 * k + 1) + res) % p;
        return res;
    }
}



void update_interval(int L, int R, long long v, int l, int r, int k){
    if(L <= l && R >= r){
        lazy[k] = (v + lazy[k]) % p;
        t[k] = ((r - l + 1) * v + t[k]) % p;
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

void update_interval_mul(int L, int R, long long v, int l, int r, int k){
    //cout << " L R " << L << ' ' << R << endl;
    if(L <= l && R >= r){
        lazy_mul[k] = v * lazy_mul[k] % p;
        lazy[k] = v * lazy[k] % p;
        t[k] = (v * t[k]) % p;
    }

    else {
        int mid = (l + r) >> 1;
        push_down(l, r, k);
        if(L <= mid)
            update_interval_mul(L, R, v, l, mid, 2 * k);
        if(R > mid)
            update_interval_mul(L, R, v, mid + 1, r, 2 * k + 1);
        push_up(k);

    }
}

int main()
{
    cin >> n >> m >> p;
    for(int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    buid(1, n, 1);
    int tmp, x, y;
    long long k;
    //cout << query(2, 4, 1, n, 1) << endl;
    for(int i = 1; i <= m; ++i){
        scanf("%d", &tmp);
        if(tmp == 3){
           scanf("%d%d", &x, &y);
            printf("%lld\n", query(x, y, 1, n, 1));
        }
        else if(tmp == 2){
            scanf("%d%d%lld", &x, &y, &k);
            update_interval(x, y, k, 1, n ,1);
        }
        else{
            scanf("%d%d%lld", &x, &y, &k);
            update_interval_mul(x, y, k, 1, n, 1);
            //cout << query(x, y, 1, n, 1) << " ??? " << endl;
        }
    }

    
}