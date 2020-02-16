#include<iostream>
using namespace std;
int n, na, nb, NA[410], NB[410], s1 = 0, s2 = 0;
int t[5][5] = {{0, -1, 1, 1, -1}, {1, 0, -1, 1, -1}, {-1, 1, 0, -1, 1}, {-1, -1, 1, 0, 1}, {1, 1, -1, -1, 0}};
int main()
{
    cin >> n >> na >> nb;
    for(int i = 0; i < na; ++i)
    cin >> NA[i];
    for(int i = 0; i < nb; ++i)
    cin >> NB[i];
    for(int i = 1; i * na + na <= 400; ++i)
    for(int j = i * na; j < i * na + na; ++j)
    NA[j] = NA[j - na];
    for(int i = 1; i * nb + nb <= 400; ++i)
    for(int j = i * nb; j < i * nb + nb; ++j)
    NB[j] = NB[j - nb];
    
    for(int i = 0; i < n; ++i){
        if(t[NA[i]][NB[i]] == 1)
            ++s1;
        else if(t[NA[i]][NB[i]] == -1)
            ++s2;
         
    }
    cout << s1 << ' ' << s2 << endl;
}