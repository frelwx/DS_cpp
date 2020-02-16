#include<iostream>
using namespace std;
const int maxn = 110;
struct p{
    int num;
    p *next;
};
int n, m;
int main()
{
   
    cin >> n >> m;
     if(n == 1){
        cout << n << endl;
        return 0;
    }
    if(n == 0){
        return 0;
    }
    p *head, *q = NULL, *rear;
    rear = head = new p;
    for(int i = 1; i <= n; ++i){
        q = new p;
        q->num = i;
        rear->next = q;
        rear = q;
    }
    if(q)
    q->next = head->next;
    q = head;
    p *tmp;
    while(q->next != q){
        for(int i = 1; i < m; ++i)
            q = q->next;
        tmp = q->next;
        q->next = q->next->next;
        cout << tmp->num << ' ';
        delete tmp;
    }

    cout << q->num << endl;
    if(q)
    delete q;
    delete head;
    return 0;
}