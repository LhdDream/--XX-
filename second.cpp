#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
class A{
    public:
        size_t length() const;
        A()
        {
            textlength = 0;
            lengths = false;
        }
        ~A()
        {

        }
    private:
        mutable size_t textlength;
        mutable bool lengths;
};
size_t A::length() const
{
    if(!lengths)
    {
        textlength = 1;
        lengths = 1;
    }
    return textlength ;
}
int main()
{

    return 0;
}