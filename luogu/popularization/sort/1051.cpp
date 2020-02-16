#include<iostream>
using namespace std;
int n;
const int maxn = 1000;
struct p{
    char name[25];
    int final, judge, num, money = 0, paper;
    char worker, iswest;
}a[maxn];
bool cmp(p &x, p &y){
    if(x.money != y.money) return x.money > y.money;
    else return x.num < y.num;
}
void sort(bool (*q)(p &x, p &y)){
    int delta = n;
    do{
        delta = delta / 3 + 1;
        for(int i = delta + 1; i <= n; ++i){
            if(cmp(a[i], a[i - delta])){
                p tmp = a[i];
                int j;
                for(j = i - delta; j >= 1 && cmp(tmp, a[j]); j -= delta)
                    a[j + delta] = a[j];
                a[j + delta] = tmp;
            }
        }
    }while(delta > 1);

}
int main()
{
    cin >> n;
    int total = 0;
    for(int i = 1; i <= n; ++i){
        cin >> a[i].name >> a[i].final >> a[i].judge >> a[i].worker >> a[i].iswest >> a[i].paper;
        a[i].num = i;
        if(a[i].final > 80 && a[i].paper >= 1)
        a[i].money += 8000;
        if(a[i].final > 85 && a[i].judge > 80)
        a[i].money += 4000;
        if(a[i].final > 90)
        a[i].money += 2000;
        if(a[i].final > 85 && a[i].iswest == 'Y')
        a[i].money += 1000;
        if(a[i].judge > 80 && a[i].worker == 'Y')
        a[i].money += 850;
        total += a[i].money;
    }
    sort(cmp);
    cout << a[1].name << endl << a[1].money << endl << total << endl;


}