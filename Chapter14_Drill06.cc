/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 10/14/2020 at 01:42 AM
 *
 * Chapter14_Drill06.cc
 * Define a class D2 derived from D1 and override pvf() in D2. Make an object
 * of class D2 and invoke f(), vf(), and pvf() for it.
 *
 * -----------------------------------------------------------------------------
 */

#include <iostream>
using namespace std;

class B1 {
public:
    void virtual vf() { cout << "B1::vf()" << endl; }
    void f() { cout << "B1:f()" << endl; }
    void virtual pvf() =0; // Create a pure virtual function
};

struct D1 : public B1 {
    void vf() override { cout << "D1::vf()" << endl; }
    void f() { cout << "D1::f() " << endl; }
};

struct D2 : D1 {
    void pvf() override { cout << "D2::pvf()" << endl; }  
};

int main(){
    D2 d2;
    d2.vf();
    d2.f();
    d2.pvf();

}
