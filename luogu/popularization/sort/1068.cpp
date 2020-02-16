#include<iostream>
using namespace std;
struct p{
    int k;
    int s;
} a[5010];
int n, m, line, num[101], num2[101];
void sort1(p * arr,int left, int right, bool (*p)(const p &x, const p &y));
void swap(p &x, p &y);
bool cmp1(const p &x, const p &y);
bool cmp2(const p &x, const p &y);
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> a[i].k >> a[i].s;
        ++num[a[i].s];
    }
    
    sort1(a,0,n - 1,cmp1);
    for(int i = 0; i < n; ++i){
        if(num[a[i].s] > 1) 
        {
            sort1(a, i, i + num[a[i].s] - 1,cmp2);
            num[a[i].s] = 1;
        }
        
    }
    for(int i = 0; i < n; ++i){
        ++num2[a[i].s];
    }
  
    int count = 0, line = m * 1.5;
    for(int i = a[line - 1].s; i <= 100; ++i){
        count += num2[i];
    }
    cout << a[line - 1].s <<' ' << count<<  endl;

    for(int i = 0; i < count; ++i){
        cout << a[i].k << ' '  << a[i].s  << endl;
    }
    return 0;
}
void sort1(p * arr,int left, int right, bool (*q)(const p &, const p &)){
    if(left >= right) return;
    int l = left, r = right;
    while(l < r){
        while(l < r && q(arr[r],arr[left])) --r;
        while(l < r && !q(arr[l],arr[left])) ++l;
        swap(arr[l],arr[r]);
    }
    swap(arr[left],arr[l]);
    sort1(arr,left,l - 1,q);
    sort1(arr,l + 1,right,q);
}

void swap(p &x, p &y){
    p tmp = x;
    x = y;
    y = tmp;
}


bool cmp1(const p &x, const p &y){
    return x.s <= y.s;
}
bool cmp2(const p &x, const p &y){
    return x.k >= y.k;
}