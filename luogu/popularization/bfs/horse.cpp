#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
const int maxn = 410;
int n,m,map[maxn][maxn] ,dir[8][2] = {2,1, 1,2, -1,2, -2,1, 2,-1, 1,-2, -1,-2,-2,-1},sx,sy,res[maxn][maxn];
bool vis[maxn][maxn];
struct node
{
    int x;
    int y;
    int step;
};
queue <node> q;
bool check(int x,int y )
{
   if(vis[x][y] || x < 1 || x > n || y < 1 || y > m)
   return false;
   return true;
}
void bfs()
{
  q.push({sx,sy,0});
  vis[sx][sy] = true;
  while(!q.empty())
  {
      node a = q.front();
      q.pop();
      
      for(int i = 0;i < 8;++i)
      {
          int x1 = a.x + dir[i][0],
              y1 = a.y + dir[i][1];//cout << x1 << y1<<endl;
              if(check(x1,y1))
              {
                  vis[x1][y1] = true;
                  q.push({x1,y1,a.step+1});
                  res[x1][y1] = a.step + 1;
              }
              
      }
  }
}
int main ()
{
    cin >> n >> m >> sx >> sy;
    bfs();res[sx][sy] = 99999;
    for(int i = 1;i <= n;++i)
    {
        for(int j = 1;j <= m;++j)
            if(!res[i][j])
                printf("%-5d",-1);
            else if(res[i][j] != 99999)
                printf("%-5d",res[i][j]);
            else 
                printf("%-5d",0);
        cout << endl;
    }

    return 0;
}
