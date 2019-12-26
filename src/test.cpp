#include<iostream>
#include"dvar.h"
#include<string>
using std::cout, std::cin;
int main()
{   std::string tmp1 = "-3" ,tmp2 = "2",tmp3 = "\"",tmp5 = "123.1",tmp6 = "12.1";
    dvar a(tmp1), b(tmp2);
   
    std::cout << (a / b);
    return 0;
}