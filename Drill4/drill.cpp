#include "Simple_window.h"
#include "Graph.h"

int main(){
    using namespace Graph_lib;

    int xmax = 600;
    int ymax = 600;

    int x_origo = xmax/2;
    int y_origo = ymax/2;

    Simple_window win {Point{100,100},xmax,ymax,"Function graphs."};

    win.wait_for_button();




}

