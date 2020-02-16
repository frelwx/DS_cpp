#include<iostream>
using namespace std;
int a, b ,c, d;
int main()
{
    cin >> a >> b >> c >> d;
    if(d >= b)
    {
        cout << c - b << ' ' << d - b << endl;
    } 
    else
    {
        cout << c - b - 1 << ' ' << d - b + 60 << endl; 
    }
    return 0;
}