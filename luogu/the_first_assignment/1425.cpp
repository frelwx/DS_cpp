#include<iostream>
using namespace std;
int a, b ,c, d;
int main()
{
    cin >> a >> b >> c >> d;
    if(d >= b)
    {
        cout << c - a << ' ' << d - b << endl;
    } 
    else
    {
        cout << c - a - 1 << ' ' << d - b + 60 << endl; 
    }
    return 0;
}