#include <iostream>

using namespace std;

int getFive()
{
    return 5;
}

int square(int x)
{
    return x * x;
}

int fac(int x)
{
    return x > 2 ? x * fac(x - 1) : 1;
}

int main()
{
    int var_arrary0[getFive()] = {0};
    int var_arrary1[getFive() + 5] = {0};

    int x = 9;

    float arrary[square(x)] = {0};
    cout<< sizeof(arrary) <<endl;
    //<abs(-87)> s;
}
