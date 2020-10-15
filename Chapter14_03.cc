/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 10/15/2020 at 03:29 PM
 *
 * Chapter14_03.cc
 * Define an abstract class and try to define an object of that type. What
 * happens?
 *
 * Solution: The compiler prevents you from doing so by giving out the following
 * error:
 * 
 * error: cannot declare variable ‘bs’ to be of abstract type ‘BaseClass’
 * because because the following virtual functions are pure within ‘BaseClass’:
 * virtual void BaseClass::f()
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>


class BaseClass {
public:
    BaseClass() =default;
    BaseClass(int v) : val{v} { }
    
    int get_val() const { return val; }
    void set_val(int v) { val = v; }
    void virtual f() =0;
private:
    int val;
};

int main(){
    BaseClass bs;

}
