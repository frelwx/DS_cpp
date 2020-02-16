#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 1e4;
char a[maxn];
int num[maxn];
char **p;
int main()
{
    p = new char*[21]();
    for(int i = 0; i < 21; ++i)
    p[i] = new char[100]();
    p[1] = "one";
    p[2] = "two";
    p[3] = "three";
    p[4] ="four";
    p[5] = "five";
    p[6] = "six";
    p[7] = "seven";
    p[8] = "eight";
    p[9] = "night";
    p[10] = "ten";
    p[11] = "eleven";
    p[12] = "twelve";
    p[13] = "thirteen";
    p[14] = "fourteen";
    p[15] = "fifteen";
    p[16] = "sixteen";
    p[17] = "seventeen";
    p[18] = "eighteen";
    p[19] = "nighteen";
    p[20] = "twenty";
    while(cin >> a){
        int i = 1;
        for(i = 1; i <= 20; ++i){
            if(!strcmp(a,p[i]))
            break;
        }
        if(i <= 20)
        ++num[i];

    }
    


}