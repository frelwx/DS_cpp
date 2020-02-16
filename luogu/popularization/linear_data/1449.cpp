#include<iostream>
using namespace std;
const int maxn = 1010;
char a[maxn];
long long  s[maxn], j = 0;
int main()
{
    cin >> a;
    int i = 0;
    long long  tmp1, tmp2;
    while(a[i] != '@'){
        //cout << a[i] << '\t';
        if(a[i] == '+'){
            tmp1 = s[j--];
            tmp2 = s[j--];
            s[++j] = tmp1 + tmp2;
            ++i;
            continue;
        }
          if(a[i] == '*'){
            tmp1 = s[j--];
            tmp2 = s[j--];
            s[++j] = tmp1 * tmp2;
            ++i;
            continue;
        }
          if(a[i] == '-'){
            tmp1 = s[j--];
            tmp2 = s[j--];
            s[++j] = tmp2 - tmp1;
            ++i;
            continue;
        }
          if(a[i] == '/'){
            tmp1 = s[j--];
            tmp2 = s[j--];
            s[++j] = tmp2 / tmp1;
            ++i;
            continue;
        }
        if(a[i] == '.'){
            ++i;
            continue;
        }
        long long  num = 0;
        while(a[i] >= '0' && a[i] <= '9'){
            num = num * 10 + a[i] - '0';
            ++i;
        }
        s[++j] = num;
        //cout << num << endl;
        //char aa = cin.get();
    }

    cout << s[j] << endl;
}