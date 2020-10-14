/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 10/14/2020 at 01:14 AM
 * 
 * Chapter14_Drill01.cc
 * Define a class B1 with a virtual function vf() and a non-virtual function 
 * f(). Define both of these functions within class B1 . Implement each
 * function to output its name (e.g., B1::vf() ). Make the functions public.
 * Make a B1 object and call each function.
 * -----------------------------------------------------------------------------
 */

#include <iostream>
using namespace std;

class B1 {
public:
    void virtual vf() { cout << "B1:vf()" << endl; }
    void f() { cout << "B1:f()" << endl; }
};


int main(void){
    B1 b1;
    b1.vf();
    b1.f();

}
