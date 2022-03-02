#include "Simple_window.h"
#include "Graph.h"

int main(){
    using namespace Graph_lib;
    //1-3W
    int xmax = 600;
    int ymax = 600;

    int x_origo = xmax/2;
    int y_origo = ymax/2;
    
    Point origo{x_origo,y_origo};

    Simple_window win {Point{100,100},xmax,ymax,"Function graphs."};
    //4-5
    int xlength = 400, ylength = 400;
    int xscale = 20, yscale = 20;
    Axis x {Axis::x,Point{100,y_origo},xlength,xlength/xscale,"1 == 20 pixels" };
    Axis y {Axis::y,Point{x_origo,ylength+100},ylength,ylength/xscale,"1 == 20 pixels" };

    x.set_color(Color::red);
    y.set_color(Color::red);
    


    win.attach(x);
    win.attach(y);





    win.wait_for_button();




}

