#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 1e5 + 10;
int n, to[maxn], in[maxn], ans[maxn], fr[maxn];
bool vis[maxn], if_delete[maxn], vis2[maxn];
void dfs(int start, int &step){
    ++step;
    if(vis[to[start]])
        return;
    if(ans[to[start]]){
            
            step += ans[to[start]];
        return;
    }
    vis[to[start]] = true;
    dfs(to[start], step);
    vis[to[start]] = false;
}
void delete_in(int x){
    --in[to[x]];
    if_delete[x] = true;
    if(in[to[x]] == 0)
        delete_in(to[x]);
}

void dfs3(int start, int &step){
    //cout << start << '\t' ;
    ans[start] = step;
    if(vis2[to[start]]){
        return;
    }
    vis2[to[start]] = true;
    dfs3(to[start], step);
}

void dfs2(int start, int &step){
    ++step;
    if(vis[to[start]]){
        vis2[to[start]] = true;
        dfs3(to[start], step);
        return;
    }
    vis[to[start]] = true;
    dfs2(to[start], step);
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i){
        scanf("%d", &to[i]);
        ++in[to[i]];
        fr[to[i]] = i;
    }
    //cout << endl;
    for(int i =1; i <= n; ++i){
        if(in[i] == 0 && !if_delete[i])
            delete_in(i);
    }

    for(int i = 1; i <= n; ++i)
    if(!ans[i] && !if_delete[i]){
        int step = 0;
        vis[i] = true;
        vis2[i] = true;
        dfs2(i, step);
            //cout << "in" << ' ' << i << ' ';
        ans[i] = step;
            //cout << endl;
    }

    for(int i = 1; i <= n; ++i)
        vis[i] = false;
    for(int i = 1; i <= n; ++i){
        if(if_delete[i] && !ans[i]){
            int step = 0;
            vis[i] = true;
            dfs(i, step);
            ans[i] = step;
            vis[i] = false;
        }
    }


    for(int i = 1; i <= n; ++i)
        printf("%d\n", ans[i]);
        
    return 0;
}