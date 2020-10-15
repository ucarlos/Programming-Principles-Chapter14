/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 10/15/2020 at 03:34 PM
 *
 * Chapter14_04.cc
 * Define a class Immobile_Circle , which is just like Circle but can’t be
 * moved.
 * -----------------------------------------------------------------------------
 */

#include "GUI/Simple_window.h"
using namespace Graph_lib;
using Simple_Window = Simple_window;

struct Immobile_Circle : Graph_lib::Circle {
    Immobile_Circle(Point center, int radius) : Circle(center, radius) { }
    void draw_lines() const override { Circle::draw_lines(); }
    void move(int dx, int dy) override final { } // Move is disallowed
};


int main(){
    Simple_Window win{Point{0, 0}, 1280, 720, "Chapter14_04"};
    Immobile_Circle circle{Point{300, 300}, 100};
    circle.move(1000, 1000); // Should not work.
    
    win.attach(circle);
    win.wait_for_button();

}
