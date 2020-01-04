#ifndef big_integer
#define big_integer
#include<iostream>
#include<cstring>
#include<string>
using std::string;

class Int 
{
    friend Int operator+ (const Int &I1, const Int &I2);
    friend Int operator* (const Int &I1, const Int &I2);
    friend Int operator- (const Int &I1, const Int &I2);
    friend Int operator/ (const Int &I1, const Int &I2);
    friend Int operator% (const Int &I1, const Int &I2);
    friend bool operator> (const Int &I1, const Int &I2);
    friend bool operator>= (const Int &I1, const Int &I2);
    friend bool operator<= (const Int &I1, const Int &I2);
    friend bool operator< (const Int &I1, const Int &I2);
    friend bool operator== (const Int &I1, const Int &I2);
    friend bool operator!= (const Int &I1, const Int &I2);
    friend std::ostream& operator<< (std::ostream &os,const Int &tmp);
    friend std::istream& operator>> (std::istream &os, Int &tmp);

    public:
    std::string p;
    int size;
    int flag;
    
    Int (const char *tmp) 
    {
        size = strlen(tmp);

        if(tmp[0] == '-') 
        {
            for(int i = 1; i < size;++i)
                p += tmp[i];
            flag = -1;
            --size;
        }
        else 
        {
            flag = 1;
            for(int i = 0;i < size;++i)
                p += tmp[i];
        }
    }

    Int (const std::string &tmp) 
    {
        size = tmp.length();
        if(tmp[0] == '-') 
        {
            for(int i = 1; i < size;++i)
                p += tmp[i];
            flag = -1;
            --size;
        }
        else 
        {
            flag = 1;
            for(int i = 0;i < size;++i)
                p += tmp[i];
        }
    }
    Int (const Int &tmp)
    {
        size = tmp.size;
        flag = tmp.flag;
        p = tmp.p;
    }

    Int (const std::string &tmp,int sign)
    {
        size = tmp.length();
        p = tmp;
        flag = sign;

    }
   Int (const char *tmp,int sign)
    {
        size = strlen(tmp);
        for(int i = 0;i < size;++i)
            p += tmp[i];
        flag = sign;

    }


    Int ()
    {
        p = "";
        size = 0;
        flag = 1;
    }
    Int& operator= (const Int &tmp)
    {
        
        size = tmp.size;
        flag = tmp.flag;
        p = tmp.p;
        return *this;
    }
    Int& operator+= (const Int &I2)
    {
        *this = *this + I2;
        return *this;
    }
    Int& operator-= (const Int &I2)
    {
        *this = *this - I2;
        return *this;
    }
    Int& operator*= (const Int &I2)
    {
        *this = *this * I2;
        return *this;
    }
    Int& operator/= (const Int &I2)
    {
        *this = *this / I2;
        return *this;
    }
    Int& operator%= (const Int &I2)
    {
        *this = *this % I2;
        return *this;
    }

    ~Int()
    {
        
    }
    void modi ()
    {
        p.erase(size-1,1);
        --size;
        
    }
    operator bool () const
    {
        Int tmp("0", 1);
        return (*this == tmp);
    }
    operator std::string ()const
    {
        return p;
    }
    operator double ()const
    {
        double tmp = 0.0;
        if(flag == 1)
        {
            for (int i = 0;i < size;++i)
            tmp = 10.0 * tmp + (double)(p[i] - '0');
            return tmp;
        }
        if(flag == -1)
        {
            for (int i = 0;i < size;++i)
            tmp = 10.0 * tmp + (double)(p[i] - '0');
            return -tmp;
        }
    }
    



    


    
};

bool operator> (const Int &I1, const Int &I2) 
{
    if (I1.flag > 0 && I2.flag < 0) return true; 
        else if (I1.flag < 0 && I2.flag > 0) return false;
            else if (I1.flag > 0 && I2.flag > 0) 
                    {
                        if(I1.size != I2.size) return I1.size > I2.size; 
                            else //从高位向低位比较
                            {
                                for (int i = 0;i <= I1.size -1 ;++i)
                                    if(I1.p[i] != I2.p[i]) return I1.p[i] > I2.p[i];
                            }
                                
                       
                    }

                  else  //两个负数的比较
                    {
                        if(I1.size != I2.size) return I1.size < I2.size; //先判断位数
                            else //从高位向低位比较
                            {
                                for (int i = 0;i <= I1.size -1; ++i)
                                    if(I1.p[i] != I2.p[i]) return I1.p[i] < I2.p[i];
                            }
                    }

    return false; //相等
}

bool operator< (const Int &I1, const Int &I2)
{
    return (!(I1 > I2) && !(I1==I2));
}
bool operator== (const Int &I1, const Int &I2)
{
    if(I1.size != I2.size || I1.flag != I2.flag) return false;
    for(int i = 0; i < I1.size; ++i)
        if(I1.p[i] != I2.p[i]) return false;
      return true;
}
bool operator<= (const Int &I1, const Int &I2)
{
    return !(I1 > I2);
}
bool operator>= (const Int &I1, const Int &I2)
{
    return !(I1 < I2);
}
bool operator!= (const Int &I1, const Int &I2)
{
    return !(I1 == I2);
}
Int operator+ (const Int &I1, const Int &I2)
{
    
    if(I1.flag > 0 && I2.flag > 0)
    {
        int maxn = std::max(I1.size,I2.size);
        int *a = new int [maxn + 10](), *b = new int [maxn + 10](), *c = new int [maxn + 10]();
        //倒序处理
        for (int i = 0; i < I1.size; ++i)
            a[I1.size-i-1] = I1.p[i]-'0';
        for (int i = 0; i < I2.size; ++i)
            b[I2.size-i-1] = I2.p[i]-'0';

        int w = 0, delta = 0;
        while(w <= maxn)
        {
            c[w] = a[w] + b[w] + delta;
            delta=c[w]/10;
            c[w] %=10;
            ++w;
        }

        if (c[w-1] == 0 && w > 0) //去除前导零
            --w;
           
        char tmp[w + 1]{0};
        for(int i = w - 1;i >= 0; --i)
            {tmp[w - 1 - i] = c[i] + '0';} // 返回原序
        Int TMP(tmp);
        delete [] a;
        delete [] b;
        delete [] c;
        return TMP;
    }

    else if (I1.flag < 0 && I2.flag < 0)
    {
        int maxn = std::max(I1.size,I2.size);
        int *a = new int [maxn + 10](), *b = new int [maxn + 10](), *c = new int [maxn + 10]();
        //倒序处理
        for (int i = 0; i < I1.size; ++i)
            a[I1.size-i-1] = I1.p[i]-'0';
        for (int i = 0; i < I2.size; ++i)
            b[I2.size-i-1] = I2.p[i]-'0';

        int w = 0, delta = 0;
        while(w <= maxn)
        {
            c[w] = a[w] + b[w] + delta;
            delta=c[w]/10;
            c[w] %=10;
            ++w;
        }

        if (c[w-1] == 0) //去除前导零
            --w;
           
        char tmp[w + 1]{0};
        for(int i = w - 1;i >= 0; --i)
            {tmp[w - 1 - i] = c[i] + '0';} // 返回原序
        Int TMP(tmp,-1);
        delete [] a;
        delete [] b;
        delete [] c;
        return TMP;
    }

    else 
    {
        if (I1 > I2) 
        {
            Int tmp2(I2.p, 1);
            return (I1 - tmp2);
        }
        else
        {
            Int tmp2(I1.p,1);
            return (I2 - tmp2);
            
        }
        
    }

    
}
Int operator- (const Int &I1, const Int &I2)
{
    if (I1 == I2) {Int TMP("0",1);return TMP;}

    if(I1.flag * I2.flag < 0) //异号
    {
        if (I1 > I2)  
        {
            Int tmp3(I2.p,1);
            return (tmp3 + I1);
        }
        else 
        {
            Int tmp3(I1.p,1);
            Int tmp4(tmp3 + I2);
            Int tmp5(tmp4.p,-1);
            return tmp5;
        }
    }

   
        if (I1 > I2 && I1.flag > 0)
            {
                int maxn = std::max(I1.size,I2.size);
                int *a = new int [maxn + 10](), *b = new int [maxn + 10](), *c = new int [maxn + 10]();
                //倒序处理
                for (int i = 0; i < I1.size; ++i)
                a[I1.size-i-1] = I1.p[i]-'0';
                for (int i = 0; i < I2.size; ++i)
                b[I2.size-i-1] = I2.p[i]-'0';

                for (int i = 0; i < maxn; ++i)
                {
                    if(a[i] < b[i]) //借位处理
                    {
                        a[i] += 10;
                        --a[i + 1];
                    }
                    c[i] = a[i] - b[i];
                }

                int index = maxn;
                while (!c[index]) --index;//前导零
                ++index;
                char tmp[index + 1] = {0};
                for(int i = index - 1;i >= 0; --i)
                tmp[index - 1 - i] = c[i] + '0';
                delete [] a;
                delete [] b;
                delete [] c;
                Int TMP(tmp,1);
                return TMP;

            }

            if (I1 > I2 && I1.flag < 0)
            {
                int maxn = std::max(I1.size,I2.size);
                int *a = new int [maxn + 10](), *b = new int [maxn + 10](), *c = new int [maxn + 10]();
                //倒序处理
                for (int i = 0; i < I1.size; ++i)
                a[I1.size-i-1] = I1.p[i]-'0';
                for (int i = 0; i < I2.size; ++i)
                b[I2.size-i-1] = I2.p[i]-'0';
                for (int i = 0; i < maxn; ++i)
                {
                    if(b[i] < a[i]) //借位处理
                    {
                        b[i] += 10;
                        --b[i + 1];
                    }
                    c[i] = b[i] - a[i];
                }

                int index = maxn;
                while (!c[index]) --index;//前导零
                ++index;
                char tmp[index + 1] = {0};
                for(int i = index - 1;i >= 0; --i)
                tmp[index - 1 - i] = c[i] + '0';
                delete [] a;
                delete [] b;
                delete [] c;
                
                Int TMP(tmp,1);
                return TMP;

            }


            if(I1 < I2 && I1.flag < 0)
           {
                int maxn = std::max(I1.size,I2.size);
                int *a = new int [maxn + 10](), *b = new int [maxn + 10](), *c = new int [maxn + 10]();
                //倒序处理
                for (int i = 0; i < I1.size; ++i)
                a[I1.size-i-1] = I1.p[i]-'0';
                for (int i = 0; i < I2.size; ++i)
                b[I2.size-i-1] = I2.p[i]-'0';

                for (int i = 0; i < maxn; ++i)
                {
                    if(a[i] < b[i]) //借位处理
                    {
                        a[i] += 10;
                        --a[i + 1];
                    }
                    c[i] = a[i] - b[i];
                }

                int index = maxn;
                while (!c[index]) --index;//前导零
                ++index;
                char tmp[index + 1] = {0};
                for(int i = index - 1;i >= 0; --i)
                tmp[index - 1 - i] = c[i] + '0';
                delete [] a;
                delete [] b;
                delete [] c;
                Int TMP(tmp,-1);
                return TMP;

            }

            if(I1 < I2 && I1.flag > 0)
           {
                int maxn = std::max(I1.size,I2.size);
                int *a = new int [maxn + 10](), *b = new int [maxn + 10](), *c = new int [maxn + 10]();
                //倒序处理
                for (int i = 0; i < I1.size; ++i)
                a[I1.size-i-1] = I1.p[i]-'0';
                for (int i = 0; i < I2.size; ++i)
                b[I2.size-i-1] = I2.p[i]-'0';

                for (int i = 0; i < maxn; ++i)
                {
                    if(b[i] < a[i]) //借位处理
                    {
                        b[i] += 10;
                        --b[i + 1];
                    }
                    c[i] = b[i] - a[i];
                }

                int index = maxn;
                while (!c[index]) --index;//前导零
                ++index;
                char tmp[index + 1] = {0};
                for(int i = index - 1;i >= 0; --i)
                tmp[index - 1 - i] = c[i] + '0';
                delete [] a;
                delete [] b;
                delete [] c;
                Int TMP(tmp,-1);
                return TMP;

            }
            
    
}
Int operator* (const Int &I1, const Int &I2)
{
        if (I1.p[0] == '0' || I2.p[0] == '0') {Int TMP("0",1);return TMP;}
        int maxn = std::max(I1.size,I2.size);
        int *a = new int [maxn + 10](), *b = new int [maxn + 10](), *c = new int [2 * maxn + 10]();
        //倒序处理
        for (int i = 0; i < I1.size; ++i)
            a[I1.size-i-1] = I1.p[i]-'0';
        for (int i = 0; i < I2.size; ++i)
            b[I2.size-i-1] = I2.p[i]-'0';

        int w = 0, delta = 0;

        for(int i = 0; i < I1.size ; ++i)
            for(int j = 0 ; j < I2.size ; ++j)
               c[i+j] += a[i] * b[j];

         for(int i = 0; i < I1.size + I2.size - 1; ++i)
           { 
                c[i+1] += c[i]/10;
                c[i] %= 10;
           }

        int index = I1.size + I2.size - 1;
        while(!c[index]) ///去除前导零
            --index;
        ++index;
        char tmp[index + 1] = {0};
        for(int i = index - 1;i >= 0; --i)
        tmp[index - 1 - i] = c[i] + '0';
        delete [] a;
        delete [] b;
        delete [] c;
        
        if ((I1.flag > 0 && I2.flag > 0) || (I1.flag < 0 &&I2.flag < 0 ))
        {
            Int TMP(tmp,1);
            return TMP;
        }
        else
        {
            Int TMP(tmp,-1);
            return TMP;
        }
        
    
}

Int operator% (const Int &I1, const Int &I2)
{
    
   Int tmp = I1 - (I1 / I2) * I2; 
   return tmp;
}
Int operator/ (const Int &I1, const Int &I2)
{
    if (I1.flag * I2.flag > 0)
    {
        //直接返回
        Int tmp1(I1.p,1);
        Int tmp2(I2.p,1);
        Int st("0",1);
        if (tmp1 < tmp2) return st;

        char a1[I1.size + 10] = {0}, b1[I1.size + 10]{0}, ans[I1.size]{0}; //初始化，并且对齐补零
        for (int i = 0; i < I1.size; ++i)
        a1[i] = I1.p[i];
        for (int i = 0; i < I2.size; ++i)
        b1[i] = I2.p[i];
        for (int i = I2.size; i < I1.size; ++i)
        b1[i] = '0';
        Int a(a1,1), b(b1,1);
        int cnt = 0;
        
        for(int  i = 0; i <= I1.size - I2.size; ++i)
        {
            while (a > b || a == b)
            {
                a = a - b;
                ++cnt;
            }
            b.modi();
            ans[i] = cnt + '0';
            cnt = 0;
        }
        int index = I1.size - I2.size;
        char rans[I1.size + 10]{0};
        if(ans[0] == '0')
        {
            for(int i = 1;i <= index; ++i)
            rans[i - 1] = ans[i];
        }
        else
        {
            for(int i = 0;i <= index; ++i)
            rans[i] = ans[i];
        }
        
        
        Int tmp(rans,1);
        return tmp;


    }

    else
    {
        Int tmp1(I1.p,1);
        Int tmp2(I2.p,1);
        Int st("1",-1);
        if (tmp1 <= tmp2) return st;
        char a1[I1.size + 10] = {0}, b1[I1.size + 10]{0}, ans[I1.size]{0}; //初始化，并且对齐补零
        for (int i = 0; i < I1.size; ++i)
        a1[i] = I1.p[i];
        for (int i = 0; i < I2.size; ++i)
        b1[i] = I2.p[i];
        for (int i = I2.size; i < I1.size; ++i)
        b1[i] = '0';
        Int a(a1,1), b(b1,1);
        int cnt = 0;
        
        for(int  i = 0; i <= I1.size - I2.size; ++i)
        {
            while (a >= b)
            {
                a = a - b;
                ++cnt;
            }
            b.modi();
            ans[i] = cnt + '0';
            cnt = 0;
        }
        int index = I1.size - I2.size;
        char rans[I1.size + 10]{0};
        if(ans[0] == '0')
        {
            for(int i = 1;i <= index; ++i)
            rans[i - 1] = ans[i];
        }
        else
        {
            for(int i = 0;i <= index; ++i)
            rans[i] = ans[i];
        }

        Int tmp6("0",1);
        if(a > tmp6)
        {
            Int tmp4(rans,-1);
            Int tmp5("1",1);
            tmp6 = tmp4 - tmp5;
        }
        else
        {
            Int tmp5(rans, -1);
            tmp6 = tmp5;
        }
        
        return tmp6;
    }

}

std::ostream& operator<< (std::ostream &os,const Int &tmp)
{
    if(tmp.flag > 0)
        os << tmp.p;
    else 
        os << '-' << tmp.p;
}


#endif
