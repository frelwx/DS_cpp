#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e5 + 10, maxm = 1e6 + 100;
ll n, m, a[maxn], t[maxm], lazy[maxm];
void push_up(ll k){
    t[k] = t[2 * k] + t[2 * k + 1];
}

void push_down(ll l ,ll r, ll k){
    if(lazy[k]){
        lazy[k << 1] += lazy[k];
        lazy[k * 2 + 1] += lazy[k];
        ll mid = (l + r) >> 1;
        t[k << 1] += lazy[k] * (mid - l + 1);
        t[k * 2 + 1] += lazy[k] *(r - (mid + 1) + 1);
        lazy[k] = 0;
    }
}
void buid(ll l, ll r, ll k){
    if(l == r)
        t[k] = a[l];
    else {
        ll mid = (l + r) >> 1;
        buid(l, mid, 2 * k);
        buid(mid + 1, r, 2 * k + 1);
        push_up(k);
    }
}

ll query(ll L, ll R, ll l, ll r, ll k){
    if(L <= l && R >= r)
        return t[k];
    else {
        ll mid = (l + r) >> 1;
        ll res = 0;
        push_down(l, r, k);
        if(L <= mid)
            res += query(L, R, l, mid, 2 * k);
        if(R > mid)
            res += query(L, R, mid + 1, r, 2 * k + 1);
        return res;
    }
}

void update(ll p, ll v, ll l, ll r, ll k){
    if(l == r) {
        a[l] += v;
        t[k] += v;
    }

    else{
        ll mid = (l + r) >> 1;
        if(p <= mid)
            update(p, v, l, mid, 2 * k);
        else 
            update(p, v, mid + 1, r, 2 * k + 1);
        push_up(k);
    }
}



void update_llerval(ll L, ll R, ll v, ll l, ll r, ll k){
    if(L <= l && R >= r){
        lazy[k] += v;
        t[k] += (r - l + 1) * v;
    }

    else {
        ll mid = (l + r) >> 1;
        push_down(l, r, k);
        if(L <= mid)
            update_llerval(L, R, v, l, mid, 2 * k);
        if(R > mid)
            update_llerval(L, R, v, mid + 1, r, 2 * k + 1);
        push_up(k);

    }
}

int main()
{
    cin >> n >> m;
    for(ll i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    buid(1, n, 1);
    ll a, b, c, tmp;
    for(ll i = 1; i <= m; ++i){
        scanf("%lld", &tmp);
        if(tmp == 2){
           scanf("%lld%lld", &a, &b);
            //cout << "???" << endl;
            cout << query(a, b, 1, n, 1) << endl;
        }
        else {
            scanf("%lld%lld%lld", &a, &b, &c);
            //cout << "  begin  " << query(a, b, 1, n, 1) << endl;
            update_llerval(a, b, c, 1, n, 1);
            //cout << "  end  " << query(a, b, 1, n, 1) << endl;
        }
    }

    
}