#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e6 + 10;
int n, a[maxn], ans[maxn];
struct node{
    int num, v;
};
stack<node> st;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; ++i){
        //cout << a[i] << endl;
        if(!st.empty()){
            while(!st.empty() && a[i] > st.top().v){
                ans[st.top().num] = i;
                st.pop();
            }
            st.push({i, a[i]});
        }
        else 
            st.push({i, a[i]});
    }

    for(int i = 1; i <= n; ++i)
        printf("%d\ ", ans[i]);
    return 0;
}