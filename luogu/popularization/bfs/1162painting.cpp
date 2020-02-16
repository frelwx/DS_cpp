#include<iostream>
#include<queue>
using namespace std;
const int maxn = 40;
int map[maxn][maxn],vis[maxn][maxn],dir[4][2] = {1,0,0,1,-1,0,0,-1},n;
struct node
{
    int x;
    int y;
};
queue <node> q;



void bfs(int x,int y)
{
    q.push({x,y});
    while (!q.empty())
    {
        node a = q.front();
        q.pop();
       
        for(int i = 0;i < 4;++i)
        {
            int x1 = a.x + dir[i][0],
                y1 = a.y + dir[i][1];
                if(map[x1][y1] == 2 )
                {
                    map[x1][y1] = 0;
                    q.push({x1,y1});
                }
        }
    }
}

int main ()
{
    cin >> n;
    for (int i = 1 ;i <= n;++i)
    for (int j = 1;j <= n ;++j)
    cin >> map[i][j];

    for(int i = 1;i <= n;++i)
    for(int j = 1;j <= n;++j)
    if(!map[i][j])
    map[i][j] =2;

    for(int i = 1;i <= n;++i)
    {  
        if(map[1][i] == 2)
        map[1][i] = 0;

        if(map[n][i] == 2)
        map[n][i] = 0;

        if(map[i][1] == 2)
        map[i][1] = 0;

        if(map[i][n] == 2)
        map[i][n] = 0;

    }

   

    for(int i = 1;i <= n;++i)
    {
        if (!map[1][i])
        bfs(1,i);

        if (!map[n][i])
        bfs(n,i);

        if (!map[i][1])
        bfs(i,1);

         if (!map[i][n])
        bfs(i,n);
    }
    

    for(int i = 1 ;i <= n;++i)
    {
     for(int j = 1;j <= n;++j)
     cout << map[i][j] <<' ';
     cout << endl;
     
    }
    return 0;

    }