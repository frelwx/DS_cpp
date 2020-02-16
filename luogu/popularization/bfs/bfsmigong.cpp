#include<iostream>
#include<queue>
using namespace std;
const int maxn = 1030;
int n,m,res[maxn][maxn];
struct node
{
    int x;
    int y;
};
queue <node> q;
node a[maxn*maxn];
char map[maxn][maxn];
bool vis[maxn][maxn];
int dir[4][2] = {1,0,0,1,-1,0,0,-1};

bool check(int x1,int y1,int x2,int y2)
{
    if(x1 < 0||x1 > n-1||y1 < 0||y1 > n-1 || map[x1][y1] == map[x2][y2]||vis[x1][y1])
    return false;
    else
    return true;
}
int bfs(int x,int y)
{   
    int num = 1;
    vis[x][y] = true;
    a[1] = {x,y};
    q.push(a[1]);
    while(!q.empty())
    {
        node tmp = q.front();
        q.pop();
        for(int i = 0;i < 4;++i)
        {
            int x1 = tmp.x + dir[i][0],
                y1 = tmp.y + dir[i][1];
                
                if (check(x1,y1,tmp.x,tmp.y))
                {   
                    q.push({x1,y1});
                    vis[x1][y1] = true;
                    ++num;
                    a[num].x = x1;
                    a[num].y = y1;
                }
        }
    }

    for(int i = 1;i <= num;++i)
    res[a[i].x][a[i].y] = num;
    return num;
}
int main()
{
    cin >> n >> m;
    for (int i = 0;i < n;++i)
        cin >>map[i];


        for (int i = 1;i <= m;++i)
        {
            int x,y;
            cin >> x >> y;
            if(res[x-1][y-1])
            cout << res[x-1][y-1] << endl;
            else
            {
                int ans = bfs(x-1,y-1);
                cout << ans <<endl;
            }
        }


}
