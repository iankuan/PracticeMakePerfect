#include <iostream>

using namespace std;

class Integer_exp {
    public:
        int data;
        explicit Integer_exp(int i) { data = i;}
};

class Integer {
    public:
        int data;
        Integer(int i) { data = i;}
};

int main()
{
    Integer i = 10;
    //Integer_exp k = 10;
    Integer_exp j(10);
    cout << "integer: " << i.data << endl;
    cout << "integer exp: " << j.data << endl;
    return 0;
}
