#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char a[30][30] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "night", "ten",
 "eleven", "twleve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nighteen", 
 "twenty"}, tmp[20];
int num[100], indexx = 0;
bool cmp(int x, int y){
    return x< y;
}
int main()
{
    
    for(int i = 1; i <= 6; ++i){
        cin >> tmp;
        for(int j = 0; j < 20; ++j)
            if(!strcmp(tmp, a[j]))
                num[++indexx] = (j + 1) * (j + 1) % 100;
        if(!strcmp(tmp, "a") || !strcmp(tmp, "first") || !strcmp(tmp, "another"))
            num[++indexx] = 1;
        if(!strcmp(tmp, "second") || !strcmp(tmp, "both"))
            num[++indexx] = 4;
        if(!strcmp(tmp, "third"))
            num[++indexx] = 9;
        
    }
    
    sort(num + 1, num + indexx + 1, cmp);
    int s = 1;
    while(num[s] == 0 && s <= indexx)
    ++s;
    cout << num[s];
    for(int i = s + 1; i <= indexx; ++i)
        if(num[i] < 10)
            cout << 0 << num[i];
        else
            cout << num[i];
    cout << endl;
    return 0;


}