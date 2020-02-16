#include<iostream>
using namespace std;
int n, m, len = 0, ans = 0;
struct node{
    int data;
    node *next;
};
node *head , *rear;
void creat(){
    head = new node;
    head->next = NULL;
    rear = head;
}
bool find(int x){
    node *p = head->next;
    
    int i = 0;
    while(i < len){
        if(p->data == x)
            return true;
        p = p->next;
        ++i;
    }
    return false;
}
void insert(int x){
    if(len < m){
        node *tmp = new node;
        tmp->data = x;
        ++len;
        rear->next = tmp;
        rear = tmp;
        rear->next = NULL;
    }

    else{
        node *tmp = head->next;
        head->next = head->next->next;
        delete tmp;
        --len;
        insert(x);
    }
    


}
int main()
{
    cin >> m >> n;
    int tmp;
    creat();
    for(int i = 0; i < n; ++i){
        cin >> tmp;
        if(!find(tmp)){
            ++ans;
            
            insert(tmp);
        }
       
    }
    cout << ans << endl;
    return 0;
}