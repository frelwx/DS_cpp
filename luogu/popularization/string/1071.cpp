#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 110;
char a[maxn], b[maxn], c[maxn], ans[maxn], table[maxn], anti_table[maxn];
int main()
{
    cin >> a >> b >> c;
    memset(table, '*', sizeof(table));
    memset(anti_table, '*', sizeof(anti_table));
    int n = strlen(a);
    for(int i = 0; i < n; ++i){
        if(table[a[i] - 'A'] == '*' || table[a[i] - 'A'] == b[i])
            table[a[i] - 'A'] = b[i];
        else{
            cout << "Failed" << endl;
            return 0;
        }
        if(anti_table[b[i] - 'A'] == '*' || anti_table[b[i] - 'A'] == a[i])
            anti_table[b[i] - 'A'] = a[i];
        else{
           
            cout << "Failed" << endl;
            return 0;
        }
    }

    for(int i = 0; i <= 25; ++i)
        if(table[i] == '*' || anti_table[i] == '*'){
            
            cout << "Failed" << endl;
            return 0;
        }

    for(int i = 0 , n = strlen(c); i < n; ++i)
    cout << table[c[i] - 'A'];
    cout << endl;
    return 0;
}
