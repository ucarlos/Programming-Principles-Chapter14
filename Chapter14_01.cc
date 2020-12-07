/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 10/15/2020 at 02:16 PM
 *
 * Chapter14_01.cc
 * Define two classes Smiley and Frowny, which are both derived from class
 * Circle and have two eyes and a month. Next, derive classes from Smiley and
 * Frowny which add an appropriate hat to each.
 * -----------------------------------------------------------------------------
 */

#include "GUI/Simple_window.h"
using namespace Graph_lib;
using Simple_Window = Simple_window;

class Smiley : public Graph_lib::Circle {
public:
    Smiley(Point x, int radius): Circle(x, radius) { }
    void draw_lines() const;    
};

void Smiley::draw_lines() const {
    Circle::draw_lines(); // Call Circle's draw lines:
    int x = point(0).x + radius() / 2;
    int y = point(0).y + radius() / 2;

    // Draw the eyes
    fl_arc(x, y, radius() / 4, radius() / 4, 0, 360);
    
    fl_arc(x + (3 * radius() / 4), y, radius() / 4, radius() / 4, 0, 360);

    // Now Draw the mouth
    fl_arc(point(0).x + radius() / 2, point(0).y + radius() / 2,
		   radius(), radius(), 180, 360);
}



struct Frowny : Graph_lib::Circle {
    Frowny(Point x, int radius): Circle(x, radius) { }
    void draw_lines() const;
};

void Frowny::draw_lines() const {
    Circle::draw_lines(); // Call Circle's draw lines:

    int x = point(0).x + radius() / 2;
    int y = point(0).y + radius() / 2;

    // Draw the eyes
    fl_arc(x, y, radius() / 4, radius() / 4, 0, 360);
    
    fl_arc(x + (3 * radius() / 4), y, radius() / 4, radius() / 4, 0, 360);

    // Now Draw the mouth
    fl_arc(point(0).x + radius() / 2, point(0).y + radius(),
		   radius(), radius(), 0, 180);
}

struct HatSmiley : Smiley {
    HatSmiley(Point x, int radius) : Smiley(x, radius) { }
    void draw_lines() const;
};

void HatSmiley::draw_lines() const {
    Smiley::draw_lines(); // Call Smiley's draw lines function

    // Now draw a hat on top of Smiley:
    // Point(0).x + radius() / 4, Point(0).y - radius() / 4
    fl_rect(point(0).x + 4 * radius() / 8, point(0).y - radius() / 2,
			radius(), radius() / 2);
}

struct HatFrowny : Frowny {
    HatFrowny(Point x, int radius) : Frowny(x, radius) { }
    void draw_lines() const;
};

void HatFrowny::draw_lines() const {
    Frowny::draw_lines(); // Call Frowny's draw lines function

    // Now draw a hat on top of Smiley:
    fl_rect(point(0).x + 4 * radius() / 8, point(0).y - radius() / 2,
			radius(), radius() / 2);    
}


int main(void){
    Simple_Window win{Point{0, 0}, 1280, 720, "Chapter14_01"};
    Smiley smile {Point{200, 200}, 100};
    Frowny frown {Point{600, 200}, 100};

    HatSmiley hat_smile{Point{200, 500}, 100};
    HatFrowny hat_frown{Point{600, 500}, 100};
    win.attach(smile);
    win.attach(frown);
    win.attach(hat_smile);
    win.attach(hat_frown);
    win.wait_for_button();
}
