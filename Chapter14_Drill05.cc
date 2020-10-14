/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 10/14/2020 at 01:36 AM
 *
 * Chapter14_Drill05.cc
 * Add a pure virtual function called pf() to B1 and try to repeat 1 - 4.
 * Explain the result.
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


int main(){
    // B1 b1; // Can't create b1 because it is now a abstract class.
    // D1 d1; // Can't create d1 either since it doesn't implement pvf();
    // B1 &b2 = d1; // Can't assign d1 to b2 because it can't be created.
}
