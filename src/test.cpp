#include<iostream>
#include"dvar.h"
#include<string>
using std::cout, std::cin;
int main()
{   std::string tmp1 = "-3" ,tmp2 = "2",tmp3 = "\"",tmp5 = "123.1111",tmp6 = "12.1";
    dvar a(tmp6), b(tmp2);
   
    std::cout << std::string(a);
    return 0;
}