#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e5+2;
int n,a[maxn];

void swap(int &tmp1,int &tmp2)
{
    int c;
    c = tmp1;
    tmp1 = tmp2;
    tmp2  = c;
}

void changelow (int low,int mid,int high)
{
    if (a[low] > a[mid])
        swap(a[low],a[high]);

    if (a[mid] > a[high])
        swap(a[mid],a[high]);

    swap(a[low],a[mid]);
}

void quicksort (int low,int high)
{
    if (low >= high) return;
    changelow (low,(low+high)/2,high);
    int i = low ,j = high,k = a[low];
    while (i < j)
    {
     while(i < j && a[j] >= k) --j;
     while(i < j && a[i] <= k) ++i;
     swap(a[i],a[j]);

    }

    swap(a[i],a[low]);
    while(a[i] == a[i - 1]) --i;
    while(a[j] == a[j + 1]) ++j;

    quicksort(low,i-1),quicksort(j+1,high);
}
int main()
{ cin >> n;
  for (int i = 1;i <= n;++i)
  scanf("%d",&a[i]);
  quicksort(1,n);

  for (int i = 1;i <=n ;i++)
  {
      printf ("%d\ ",a[i]);
  }


}
