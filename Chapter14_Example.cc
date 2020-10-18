/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 10/13/2020 at 03:41 PM
 *
 * Chapter14_Example.cc
 * Override Example from Section 14.3.3
 * -----------------------------------------------------------------------------
 */

#include <iostream>
using namespace std;

struct B {
    virtual void f() const { cout << "B::f\n"; }
    void g() const { cout << "B::g\n"; } // Not virtual
};


struct D : B {
    void f() const override { cout << "D::f\n"; } // Overrides B::f
    void g()  { cout << "D::g\n"; }
};

struct DD : D {
    void f() const override { cout << "DD::f\n"; }
    void g() const { cout << "DD::g\n"; }

};

void call(const B& b){
    // a D is a kind of B, so call() can accept a D.
    // a DD is a kind of D and D is a kind of B, so call() can accept a DD.
    b.f();
    b.g();
}

int main(void){
    B b;
    D d;
    DD dd;

    cout << "Invoking call() for b, d, and dd.\n";
    call(b); cout << endl;
    call(d); cout << endl;
    call(dd);
    
    cout << endl << "Now calling directly..." << endl;
    b.f(); b.g(); cout << endl;
    d.f(); d.g(); cout << endl;
    dd.f(); dd.g(); 
    
}
