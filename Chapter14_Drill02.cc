/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 10/14/2020 at 01:21 AM
 *
 * Chapter14_Drill02.cc
 * Derive a class D1 from B1 and override vf() . Make a D1 object and call vf()
 * and f() for it
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
    d1.vf();
    d1.f();
    
}
