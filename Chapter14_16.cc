/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 10/15/2020 at 05:15 PM
 *
 * Chapter14_16.cc
 * Define a class Controller with four virtual functions on() , off() ,
 * set_level(int) and show() . Derive at least two classes from Controller .
 * One should be a simple test class where show() prints out whether the class
 * is set to on or off and what is the current level.
 * The second derived class should somehow control the line color of a Shape ;
 * the exact meaning of “level” is up to you. Try to find a third “thing” to
 * control with such a Controller class.
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <string>
#include <vector>

class Controller {
public:
    Controller() =default;
    Controller(bool c_s, unsigned lvl) :
	controller_status{c_s}, level{lvl} { }
    void on() { controller_status = true; }
    void off() { controller_status = false; }
    bool get_status() const { return controller_status; }
    unsigned get_level() const { return level; }
    
private:
    bool controller_status{false};
    unsigned level{0}; // Level is the channel value; like a tv remote.
};

struct TestController : Controller {
    TestController() =default;
    TestController(bool c_s, unsigned lvl) : Controller::Controller(c_s, lvl) { }
    void show() const;
};

void TestController::show() const {
    std::cout << "Controller: "
	      << (get_status()? "On" : "Off") << "\n"
	      << "Level: " << get_level()
	      << std::endl;
	      
}


int main(){
    TestController tc{true, 420};
    tc.show();
}
