/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 10/14/2020 at 01:29 AM
 *
 * Chapter14_Drill04.cc
 * Now define a function called f() for D1 and repeat 1 - 3.
 * -----------------------------------------------------------------------------
 */

#include <iostream>
using namespace std;

class B1 {
public:
    void virtual vf() { cout << "B1::vf()" << endl; }
    void f() { cout << "B1:f()" << endl; }
};

struct D1 : public B1 {
    void vf() override { cout << "D1::vf()" << endl; }
    void f() { cout << "D1::f() " << endl; }
};

int main(){    
    B1 b1;
    b1.vf();
    b1.f();  
    cout << endl;
    
    D1 d1;
    d1.vf();
    d1.f();
    cout << endl;
    
    B1 &b2 = d1;
    b2.vf();
    b2.f();
    cout << endl;
}
