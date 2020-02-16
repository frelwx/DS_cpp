#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 1e5 + 10;
int n, a[maxn];
void merge(int a1[], int a2[], int i, int m, int t){
    int j, k, l;
    for(j = m + 1, k = i;j <= t && i <= m; ++k){
        if(a1[i] < a1[j])
            a2[k] = a1[i++];
        else
            a2[k] = a1[j++];
        
    }
    if(i <= m){
        for(l = 0; l <= m - i; ++l){
            a2[k + l] = a1[i + l];
        }
    }

    if(j <= t){
        for(l = 0; l <= t - j; ++l){
            a2[k + l] = a1[j + l];
        }
    }
}

void mergepass(int a1[], int a2[], int delta, int len){
    int i = 0, j;
    while(i + 2 *delta - 1 <= len){
        merge(a1, a2,i,i + delta -1, i + 2 * delta - 1);
        i += 2 * delta;
    }
    
   

    if(i + delta -1 < len)
        merge(a1, a2, i, i + delta - 1, len);
    else
        for(j = i; j <= len; ++j)
            a2[j] = a1[j];

 
    
}
int main()
{
    scanf("%d",&n);
    for(int i = 0;i < n; ++i)
    scanf("%d",&a[i]);
    int *p = new int[n + 10];

    int k = 1;
    while(k < n){
        mergepass(a, p, k, n - 1);
        k *= 2;
        mergepass(p,a,k,n - 1);
        k *= 2;
    }
    for(int i = 0; i < n; ++i)
    printf("%d\ ",p[i]);


    delete p;
    return 0;

}