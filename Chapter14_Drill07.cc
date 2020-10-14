/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 10/14/2020 at 01:46 AM
 *
 * Chapter14_Drill07.cc
 * Define a class B2 with a pure virtual function pvf(). Define a class D21
 * with a string data member and a member function that overrides pvf();
 * D21::pvf() should output the value of the string. Define a class D22 that is
 * just like D21 except that its data member is an int. Define a function f()
 * that takes a B2& argument and calls pvf() for its argument. Call f() with a
 * D21 and a D22.
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <string>
using namespace std;

class B2 {
public:
    void virtual pvf() const =0;
};

class D21 : public B2 {
public:
    D21() =default;
    D21(const std::string s) : str{s} { }
    void pvf() const override { cout << "D21::pvf(): " <<  str << endl; }
private:
    std::string str{"[Default]"};
};

struct D22 : B2 {
    D22() =default;
    D22(int v) : val{v} { }
    void pvf() const override { cout << "D22::pvf(): " << val << endl; }
private:
    int val{};
};


void f(const B2 &b2){
    b2.pvf();
}

int main(void){
    D21 d21{"Hello World!"};
    D22 d22{15};

    f(d21);
    f(d22);

}
