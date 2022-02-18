/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"


 
int main()
{
    using namespace Graph_lib;

    int xmax = 1000;
    int ymax = 800;

    
	Simple_window win {Point{100,100},xmax,ymax,"Canvas"};

    int x_grid = 100;
    int y_grid = 100;

    Lines grid;
    for(int x = x_grid; x<=8*x_grid;x+=x_grid){
        grid.add(Point{x,0},Point{x,900});
    }
    for(int y= y_grid; y<8*y_grid;y+=y_grid){
        grid.add(Point{0,y},Point{800,y});
    }

    Vector_ref<Rectangle> rect;
    for(int i=0;i<8;++i){
            rect.push_back(new Rectangle{Point{i*100,i*100},100,100});
            rect[rect.size()-1].set_fill_color(Color::red);
            win.attach(rect[rect.size()-1]);
    }
    int x=0;
    int y=0;
    Image rita {Point{200,0},"kepes.jpg"};
    Image grita {Point{400,0},"kepes.jpg"};
    Image frita {Point{600,0},"kepes.jpg"};
    win.attach(rita);
    win.attach(grita);
    win.attach(frita);

    win.attach(grid);
	win.wait_for_button();


    

}
