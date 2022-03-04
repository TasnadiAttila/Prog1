#include "Simple_window.h"
#include "Graph.h"
//1,4,6
double one(double x) { return 1;};
double slope(double x) {return x/2;};
double square(double x) {return x*x;};
double sloping_cos(double x) {return cos(x) + slope(x);};

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
    Text text_for_slopy{Point{slopy.point(0).x,slopy.point(0).y - 20},"x/2"};
    //6
    Function parabola(square,r_min,r_max,origo,n_points,xscale,yscale);
    //7
    Function cosine{cos,r_min,r_max,origo,n_points,xscale,yscale};    
    //8
    cosine.set_color(Color::blue);
    //9
    Function sloping_cosine{sloping_cos,r_min,r_max,origo,n_points,xscale,yscale};


    win.attach(x);
    win.attach(y);
    win.attach(f);
    win.attach(slopy);
    win.attach(text_for_slopy);
    win.attach(parabola);
    win.attach(cosine);
    win.attach(sloping_cosine);

    win.wait_for_button();




}

