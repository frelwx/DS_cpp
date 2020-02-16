#include<iostream>
#include<cstdio>
using namespace std;
int n, a[101], b[101],index = 0;
bool check(int x){
    for(int i = 0;  i < n; ++i)
    if(a[i] == a[x] && i != x)
    return false;
    return true;
}
void swap(int &x, int &y){
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}
void sort(int * arr,int left, int right){
    if(left >= right) return;
    int l = left, r = right, k = arr[left];
    while(l < r){
        while(l < r && arr[r] >= k) --r;
        while(l < r && arr[l] <= k) ++l;
        swap(arr[l],arr[r]);
  
    }
   
    swap(arr[left],arr[l]);
 
    sort(arr,left,r - 1);
    sort(arr,r + 1,right);
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    cin >> a[i];

    for(int i = 0; i < n ; ++i){
        for(int j = 0;j < n && a[i]; ++j)
        if(a[j] == a[i] && j != i)
            a[j] = 0;
    }
    

    for(int i = 0; i < n; ++i){
        if(a[i]){
            b[index] = a[i];
            ++index;
        }
    }
    
  
    sort(b, 0, index - 1);
    cout << index << endl;
    for(int i = 0; i < index; ++i)
    cout << b[i] << ' ';
    
    return 0;
    
    

}