#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 2e5 + 10;
int n, r, q, ww = 1, ll = 1;
struct p
{
    int s;
    int w;
    int num;
}a[maxn];
p win[maxn], los[maxn];
void swap(p &x, p &y){
    p tmp = x;
    x = y;
    y = tmp;
}
bool cmp(p &x, p &y){
    if(x.s != y.s)  return x.s < y.s;
    return x.num >= y.num;
}
void changelow(p &x, p &y, p &z){
    p tmp;
    if(x.s > y.s)
    swap(x,y);
    if(y.s > z.s)
    swap(y,z);
    swap(x,y);
}
void sort2()
{
    int delta = 2 * n;
    do{
        delta = delta / 3 + 1;
        for(int i = delta + 1; i <= 2 * n; ++i){
            if(cmp(a[i - delta], a[i])){
                p tmp = a[i];
                int j;
                for(j = i - delta; j >= 1 && cmp(a[j], tmp); j -= delta)
                a[j + delta] = a[j];
                a[j + delta] = tmp;
            }
        }
    }while(delta > 1);


}
void sort1(p arr[], int left, int right, bool (*q)(p &x, p &y)){
    if(left >= right) return;
    int l = left, r = right;
    changelow(arr[left], arr[(left + right) / 2], arr[right]);
    while(l < r){
        while(l < r && q(arr[r],arr[left])) --r;
        while(l < r && q(arr[left], arr[l])) ++l;
        swap(arr[l], arr[r]);
    } 
    swap(arr[left], arr[l]);

    sort1(arr, left, r - 1, q);
    sort1(arr, r + 1, right, q);

}

void merge (p a1[], p a2[], p a3[]){
    int i = 1,j = 1,k = 1;
    for(; i <= ww && j <= ll; ++k){
        if(cmp(a3[j],a2[i]))
            a1[k] = a2[i++];
        else
            a1[k] = a3[j++];   
    }
    if(i <= ww){
        for(int l = 0; l <= ww-i; ++l)
        a1[k + l] = a2[i + l];
    }
    if(j <= ll){
        for(int l = 0; l <= ll - j; ++l)
        a1[k + l] = a3[j + l];
    }
}

int main()
{
    scanf("%d%d%d", &n, &r, &q);
    for(int i = 1; i <= 2 * n; ++i){
        scanf("%d", &a[i].s);
        a[i].num = i;
    }
    for(int i = 1; i  <= 2 *n; ++i)
    scanf("%d", &a[i].w);
    //sort1(a, 1, 2 * n, cmp);
    //sort(a + 1, a + 2*n + 1, cmp);
    sort2();
    for(int ii = 1; ii <= r; ++ii){
        ww = 1, ll = 1;
        for(int i = 1; i <= 2 * n - 1; i += 2)
        if(a[i].w > a[i + 1].w){
            ++a[i].s;
            win[ww++] = a[i];
            los[ll++] = a[i + 1];
        }
        else{
            ++a[i + 1].s;
            win[ww++] = a[i + 1];
            los[ll++] = a[i];

        }
        --ww;
        --ll;
        
        merge(a, win, los);
    }
    printf("%d\n", a[q].num);
}
