/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 10/15/2020 at 03:42 PM
 *
 * Chapter14_05.cc
 * Define a Striped_rectangle where instead of fill, the rectangle is “filled”
 * by drawing one-pixel-wide horizontal lines across the inside of the
 * rectangle (say, draw every second line like that). You may have to play
 * with the width of lines and the line spacing to get a pattern you like.
 * -----------------------------------------------------------------------------
 */

#include "GUI/Simple_window.h"
using namespace Graph_lib;
using Simple_Window = Simple_window;

class Striped_Rectangle : public Graph_lib::Rectangle {
public:    
    Striped_Rectangle(Point p, int w, int h) : Rectangle{p, w, h} { }
    void draw_lines() const;
};

void Striped_Rectangle::draw_lines() const {
    if (fill_color().visibility()) {
	// Draw the normal rectangle first:
	fl_rect(point(0).x, point(0).y, width(), height());

        // Now Draw the striped rectangle:
	fl_color(fill_color().as_int());
	for (int i = 0; i < height(); i += 10)
	    fl_rect(point(0).x, point(0).y + i, width(), 1);

    }

    if (color().visibility()) {
        fl_color(color().as_int());
        fl_rect(point(0).x,point(0).y,width(), height());	
    }

}

int main(void){
    Simple_Window win{Point{0, 0}, 1280, 720, "Chapter14_05"};
    Striped_Rectangle rec1 {Point{200, 200}, 400, 200};
    rec1.set_fill_color(Color::green);
    
    win.attach(rec1);
    win.wait_for_button();

}
