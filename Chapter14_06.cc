/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 10/15/2020 at 04:05 PM
 *
 * Chapter14_06.cc
 * Define a Striped_circle using the technique from Striped_rectangle.
 * -----------------------------------------------------------------------------
 */

#include "GUI/Simple_window.h"
using namespace Graph_lib;
using Simple_Window = Simple_window;

struct Striped_Circle : Graph_lib::Circle {
    Striped_Circle(Point center, int r) : Circle(center, r) { }
    void draw_lines() const;

};

//------------------------------------------------------------------------------
// distance() : Calculate the distance of two points using the distance
// formula
//------------------------------------------------------------------------------
int distance(int x, int y, int xx, int yy){
    return sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
}

void Striped_Circle::draw_lines() const {
    Circle::draw_lines(); // Call Circle's draw_lines
    if (fill_color().visibility()) {

		int x, y, xx, yy;

		fl_color(fill_color().as_int()); // Set color:
		// For each degree of a semi-circle:
		double radian = M_PI / 180;
		int width;
		for (int i = 0; i < 180; i += 4){
			x = center().x + radius() * cos(radian * (90 + i));
			y = center().y + radius() * sin(radian * (90 + i));

			xx = center().x + radius() * cos(radian * (90 - i));
			yy = center().y + radius() * sin(radian * (90 - i));

			width = distance(x, y, xx, yy);
			fl_rect(x, y, width, 1);
		}
	

    }


}

int main(void){
    Simple_Window win{Point{0, 0}, 1280, 720, "Chapter14_06"};
    Striped_Circle circ{Point{400, 400}, 200};
    circ.set_fill_color(Color::blue);
    win.attach(circ);
    win.wait_for_button();

}
