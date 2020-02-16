#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1000000 + 10;
int n, m, l, r, sum[maxn];
bool prime[maxn];
void print_table(){
    memset(prime, 1, sizeof(prime));
    prime[1] = prime[0] = 0;
    for(int i = 2; i <= maxn; ++i)
        for(int j = 2 * i; j <= maxn; j += i)
            prime[j] = 0;
}
int main()
{
    cin >> n >> m;
    print_table();
    for(int i = 1; i <= maxn; ++i)
        sum[i] = sum[i - 1] + prime[i];
   

    while(n--){
        cin >> l >> r;
        if(l < 1 || r > m)
            printf("Crossing the line\n");
        else 
            printf("%d\n", sum[r] - sum[l - 1]);
    }
    return 0;
}