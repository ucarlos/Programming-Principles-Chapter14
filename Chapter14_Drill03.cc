/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 10/14/2020 at 01:26 AM
 *
 * Chapter14_Drill03.cc
 * Define a reference to B1 (a B1&) and initialize that to the D1 object you
 * just defined. Call vf() and f() for that reference.
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
};

int main(){
    D1 d1;
    B1& b1 = d1;
    b1.vf();
    b1.f();

}
