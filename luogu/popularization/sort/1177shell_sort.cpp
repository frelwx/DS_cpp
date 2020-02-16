#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 1e5 + 10;
int n, a[maxn];
int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        scanf("%d",&a[i]);
    }
    int delta = n;
    do{
        delta = delta / 3 + 1;
        for(int i = delta; i < n; ++ i){
            if(a[i] < a[i - delta]){
                int tmp = a[i],j;
                for(j = i - delta;j >= 0 && tmp < a[j]; j -= delta)
                    a[j + delta] = a[j];
                a[j + delta] = tmp;
                
                
            }
        }
    }while(delta > 1);

    for(int i = 0; i < n; ++i)
    printf("%d\ ",a[i]);
}