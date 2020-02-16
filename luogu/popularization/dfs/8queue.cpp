#include<iostream>
using namespace std;
const int maxn = 50;
int res[maxn],r[maxn],c[maxn],lr[maxn],rl[maxn];
int n,flag = 0,count = 0;
bool check(int x,int y)
{
    if(!r[x] && !c[y] && !lr[x+y] && !rl[y-x+20])
    return true;
    else return false;
}
void dfs(int x)
{     
    if(x > n) return;

    for(int j = 1;j <= n;++j)
    {
        if(check(x,j))
        {
            r[x] = true;
            c[j] = true;
            lr[x+j] = true;
            rl[j-x+20] = true;
            res[x] = j;


        if (x == n && flag <=2)
        {
         for(int i = 1;i <= n;++i)
         cout << res[i] <<' ';
         cout << endl;
         ++flag;
         
        }
        if (x == n) ++count;
     
            dfs(x+1);

            r[x] = false;
            c[j] = false;
            lr[x+j] = false;
            rl[j-x+20] = false;

        }

    }
    return;
}

int main()
{
    cin >> n;
    for(int j = 1;j <= n;++j)
    {  
        r[1] = true;
        c[j] = true;
        lr[1+j] = true;
        rl[j-1+20] = true;
        res[1] = j;

        dfs (2);

        r[1] = false;
        c[j] = false;
        lr[1+j] = false;
        rl[j-1+20] = false;


    }
    cout << count <<endl;
}