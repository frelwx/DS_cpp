#include<iostream>
#include<cstring>
using namespace std;
int p1, p2, p3, indexx = 0;
char a[110] = {0}, b[20000] = {0};
bool check_num(int x){
    if(a[x] != '-')
        return false;
    if(a[x + 1] > '9' || a[x + 1] < '0')
        return false;
    if(a[x -1] > '9' || a[x - 1] < '0')
        return false;
    if(a[x + 1] <= a[x - 1])
        return false;
    return true;
}
bool check_alp(int x){
    if(a[x] != '-')
        return false;
    if(a[x + 1] < 'a' || a[x + 1] > 'z')
        return false;
    if(a[x - 1] < 'a' || a[x - 1] > 'z')
        return false;
    if(a[x + 1] <= a[x - 1])
        return false;
    return true;  
}
int main()
{
    cin >> p1 >> p2 >> p3;
    cin >> a;
    if(p1 == 1){
        if(p3 == 1){
            for(int i = 0 ;i < strlen(a); ++i){
                if(check_num(i)){
                   for(int k = 1 ; k < a[i + 1] - a[i - 1]; ++k){
                       char tmp = a[i - 1] + k;
                       for(int m = 1; m <= p2; ++m){
                           b[++indexx] = tmp;
                       }
                   }
                }
                else if(check_alp(i)){
                    for(int k = 1; k < a[i + 1] - a[i - 1]; ++k){
                        char tmp = a[i - 1] + k;
                        for(int m = 1; m <= p2; ++m){
                            b[++indexx] = tmp;
                        }
                    }
                }
                else
                b[++indexx] = a[i];
            }
        }
            else{
                for(int i = 0 ;i < strlen(a); ++i){
                    if(check_num(i)){
                        for(int k = 1 ; k < a[i + 1] - a[i - 1]; ++k){
                            char tmp = a[i + 1] - k;
                            for(int m = 1; m <= p2; ++m){
                                b[++indexx] = tmp;
                            }
                        }
                    }
                    else if(check_alp(i)){
                        for(int k = 1; k < a[i + 1] - a[i - 1]; ++k){
                            char tmp = a[i + 1] - k;
                            for(int m = 1; m <= p2; ++m){
                                b[++indexx] = tmp;
                            }
                        }
                    }
                    else
                    b[++indexx] = a[i];
                }
            }
    }
        else if(p1 == 2){
            if(p3 == 1){
            for(int i = 0 ;i < strlen(a); ++i){
                if(check_num(i)){
                   for(int k = 1 ; k < a[i + 1] - a[i - 1]; ++k){
                       char tmp = a[i - 1] + k;
                       for(int m = 1; m <= p2; ++m){
                           b[++indexx] = tmp;
                       }
                   }
                }
                else if(check_alp(i)){
                    for(int k = 1; k < a[i + 1] - a[i - 1]; ++k){
                        char tmp = (a[i - 1] + k) - 'a' + 'A';
                        for(int m = 1; m <= p2; ++m){
                            b[++indexx] = tmp;
                        }
                    }
                }
                else
                b[++indexx] = a[i];
            }

        }
            else{
                for(int i = 0 ;i < strlen(a); ++i){
                    if(check_num(i)){
                        for(int k = 1 ; k < a[i + 1] - a[i - 1]; ++k){
                            char tmp = a[i + 1] - k;
                            for(int m = 1; m <= p2; ++m){
                                b[++indexx] = tmp;
                            }
                        }
                    }
                    else if(check_alp(i)){
                        for(int k = 1; k < a[i + 1] - a[i - 1]; ++k){
                            char tmp = a[i + 1] - k - 'a' + 'A';
                            for(int m = 1; m <= p2; ++m){
                                b[++indexx] = tmp;
                            }
                        }
                    }
                    else
                    b[++indexx] = a[i];
                }
            }
        }
            else{
                if(p3 == 1){
                for(int i = 0 ;i < strlen(a); ++i){
                if(check_num(i)){
                   for(int k = 1 ; k < a[i + 1] - a[i - 1]; ++k){
                       char tmp = '*';
                       for(int m = 1; m <= p2; ++m){
                           b[++indexx] = tmp;
                       }
                   }
                }
                else if(check_alp(i)){
                    for(int k = 1; k < a[i + 1] - a[i - 1]; ++k){
                        char tmp = '*';
                        for(int m = 1; m <= p2; ++m){
                            b[++indexx] = tmp;
                        }
                    }
                }
                else
                b[++indexx] = a[i];
            }

        }
            else{
                for(int i = 0 ;i < strlen(a); ++i){
                    if(check_num(i)){
                        for(int k = 1 ; k < a[i + 1] - a[i - 1]; ++k){
                            char tmp = '*';
                            for(int m = 1; m <= p2; ++m){
                                b[++indexx] = tmp;
                            }
                        }
                    }
                    else if(check_alp(i)){
                        for(int k = 1; k < a[i + 1] - a[i - 1]; ++k){
                            char tmp = '*';
                            for(int m = 1; m <= p2; ++m){
                                b[++indexx] = tmp;
                            }
                        }
                    }
                    else
                    b[++indexx] = a[i];
                }
            }

            }
    
    for(int i = 1; i <= indexx; ++i)
    cout << b[i];
    cout << endl;
    return 0;
}