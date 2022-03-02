#include "Simple_window.h"
#include "Graph.h"
//1,4,6
double one(double x) { return 1;};
double slope(double x) {return x/2;};
double square(double x) {return x*x;};

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
    
    //Separate shape
    //1-2
    int n_points = 400;
    int r_min=-10, r_max=11;
    Function f{one,r_min,r_max,origo,n_points,xscale,yscale};

    //5
    Function slopy{slope,r_min,r_max,origo,n_points,xscale,yscale};
    Text text_for_slopy{Point{100,385},"x/2"};
    //7
    Function cosF{cos,r_min,r_max,n_points,xscale,yscale};
    

    win.attach(x);
    win.attach(y);
    win.attach(f);
    win.attach(slopy);
    win.attach(text_for_slopy);
    win.attach(cosinus);


    win.wait_for_button();




}

