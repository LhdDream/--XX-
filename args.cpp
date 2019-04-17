//可变参数的例子
#include<iostream>
using namespace std;

template<typename T>
ostream &print(ostream &os,const T &t)
{
    return os << t ;
}
template <typename T ,typename... Args>
ostream &print(ostream &os ,const T &t,const Args&... rest)
{
    os << t << "," ;
    return print(os,rest...);
}

int main()
{
    //os：cout,cer
    print(cout,1,2,3,4,5,6);
    return 0;
}