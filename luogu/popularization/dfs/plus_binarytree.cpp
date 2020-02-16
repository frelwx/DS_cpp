#include<iostream>
#include<vector>
using namespace std;
const int maxn = 40;
int n,s[maxn],dp[maxn][maxn],root[maxn][maxn];
int dfs(int l,int r)
{   
    if(l > r) return 1;
    if(l == r)
     {  
        root[l][r] = l;
        return s[r];
     }
     if (dp[l][r]) return dp[l][r];

    int tmp = 0;
    for (int i = l ;i <=r ;++i)
    {
        tmp = dfs(l,i - 1) * dfs(i + 1,r) + dfs(i,i);
        if (tmp > dp[l][r]) 
        {
            dp[l][r] = tmp;
            root[l][r] = i;
        }
    }
    return dp[l][r];
    
}
void print_pre(int l,int r)
{
    if(l > r) return;
    cout << root[l][r] << ' ';
    print_pre (l,root[l][r] - 1);
    print_pre (root[l][r] + 1,r);
}
int main ()
{
    cin >> n;
    for(int i = 1;i <= n;++i)
    {
        cin >> s[i];
        dp[i][i] = s[i];
    }
    
    int ans = dfs(1,n);
    cout << ans << endl;
    print_pre (1,n);
}