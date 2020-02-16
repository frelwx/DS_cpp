#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
const int maxn = 30;
int n;
double tmp = 1e9,res = 1e9;
bool vis[maxn];
struct node
{
    double x;
    double y;
} a[maxn];

double sqr(int n1,int n2)
{   double q = (a[n1].x - a[n2].x) * (a[n1].x - a[n2].x) + (a[n1].y - a[n2].y) * (a[n1].y - a[n2].y);
    return  sqrt (q);
}

void dfs (int num,double step,int count)
{   if (step > tmp) return;
    for(int i = 1;i <= n;++i)
    { 
        if(!vis[i])
        {
         double p = sqr(i,num);
         vis[i] = true;
         dfs(i,step + p,count+1);
         vis[i] = false;
        }
    }
    if(count == n)
    tmp = min(tmp,step);
}
int main()
{
    cin >> n;
    for(int i = 1;i <=n;++i)
    {
        double tmp1 ,tmp2;
        cin >> tmp1 >> tmp2;
        a[i].x = tmp1;
        a[i].y = tmp2;
    }
     
         a[0].x = 0,a[0].y = 0;
         dfs(0,0,0);
         
        
         
     
     printf("%.2lf\n",tmp);

}
