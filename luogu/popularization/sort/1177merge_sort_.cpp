#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 1e5 + 10;
int n, a[maxn],p[maxn];
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

void sort(int a1[], int a2[], int s, int t){
    int m;
   
    int a3[maxn];
    if(s == t)
        a2[s] = a1[s];
    else{
        
        m = (s + t) / 2;
        sort(a1, a3, s, m);
        sort(a1, a3, m + 1, t);
        merge(a3,a2,s,m,t);
    }
    //delete a3;
}

int main()
{
    scanf("%d",&n);
    for(int i = 0;i < n; ++i)
    scanf("%d",&a[i]);
   

    sort(a, p, 0, n - 1);
    for(int i = 0; i < n; ++i)
    printf("%d\ ",p[i]);


    
    return 0;

}