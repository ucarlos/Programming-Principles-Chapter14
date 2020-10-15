/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 10/15/2020 at 03:24 PM
 *
 * Chapter14_02.cc
 * Try to copy a Shape. What happens?
 * Solution:
 * It doesn't work since Shape has disabled its copy constructor and assignment.
 * through =delete.
 * -----------------------------------------------------------------------------
 */

#include "GUI/Simple_window.h"

using namespace Graph_lib;
using Simple_Window = Simple_window;

int main(void){
    Simple_Window win{Point{0, 0}, 1280, 720, "Chapter14_02"};

    Circle circle1 {Point{200, 200}, 50};
    Circle circle2 = circle1;
    
    win.wait_for_button();
}
