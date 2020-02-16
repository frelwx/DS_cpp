#include <iostream>
#include<string>
using namespace std;
const int maxn = 21;
int n,l[maxn],vis[maxn],res = 0,tmp = 0,th = 0 ;
string a[maxn];
char head;
int cut(string x,string y)
{
    int lx = x.size(),ly = y.size();//cout<<lx<<' '<<ly<<endl;
    for (int i = lx-1;i >= lx-ly+1 && i >=1 ;--i)
    {
       if (x[i] == y[0])
       {   
           bool flag = true;
           for(int j = i;j <= lx-1;++j)
           if(x[j] != y[j-i])
           {
               flag = false;
               break;
           }
           if(flag)
           return ly-lx+i;
       }

       
    }
    return 0;
}
void dfs(string x)
{   //cout << x<<endl;
    for(int i = 1;i <= n;++i)
    {
        if(vis[i] <2 && cut(x,a[i]))
        {  
            int tmp2 = cut(x,a[i]);
            tmp += tmp2 ;
            ++vis[i];
            dfs (a[i]);
            --vis[i];
            tmp -= tmp2;
        }

    }
   th = max (tmp,th);
}

int main ()
{
    cin >> n;
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i];
        l[i] = a[i].size();
    }

    cin >> head;

    for(int i = 1;i <= n;++i)
    {
        if(a[i][0] == head)
        {   
            ++vis[i];
            dfs(a[i]);
            --vis[i];
            th += a[i].size();
            res = max(res,th);
            
        }
        

        
        tmp = 0,th = 0;
    }
    
    cout << res ;
    return 0;
}


