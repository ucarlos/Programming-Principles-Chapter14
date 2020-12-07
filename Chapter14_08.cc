/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 10/15/2020 at 04:38 PM
 *
 * Chapter14_08.cc
 * Define a class Octagon to be a regular octagon. Write a test that exercises
 * all of its functions (as defined by you or inherited from Shape).
 * -----------------------------------------------------------------------------
 */

#include "GUI/Simple_window.h"
#include <iostream>
using namespace Graph_lib;
using Simple_Window = Simple_window;

struct Octagon : Shape {
    Octagon(Point center, int rad) : radius{rad} { add(center); }
    int get_radius() const { return radius; }
    void set_radius(int r) { radius = r; }
    Point get_center() const { return Point{point(0).x, point(0).y}; }
    void draw_lines() const;
    
private:
    int radius;
};

void Octagon::draw_lines() const {
    double angle_radian = M_PI / 4;
    Point center = get_center();

    double x, y, xx, yy;
    if (color().visibility()) {
		fl_color(color().as_int());

    }
       
    x = radius * cos(angle_radian);
    y = radius * sin(angle_radian);

    // Draw the first line
    fl_line(center.x + radius, center.y,
			center.x + x, center.y + y);
	
    // For the next lines:
    for (int i = 1; i < 7; i++){
		xx = radius * cos((i + 1) * angle_radian);
		yy = radius * sin((i + 1) * angle_radian);
	
		fl_line(center.x + x, center.y + y,
				center.x + xx, center.y + yy);

		// Now update x and y for the next angle:
		x = xx; y = yy;
    }
	
    // Now connect the first and last line:
    fl_line(center.x + x, center.y + y,
			center.x + radius, center.y);    

    
}

int main(){
    Simple_Window win{Point{0, 0}, 1280, 720, "Chapter14_08"};
    Octagon oct{Point{400, 400}, 200};
    oct.set_radius(100);
    std::cout << "Radius of Octagon: " << oct.get_radius() << std::endl;
    oct.set_color(Color::red);
    
    
    win.attach(oct);
    win.wait_for_button();
}
