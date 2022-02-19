/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"


 
int main()
{
    using namespace Graph_lib;
    //Rajzábla
    int xmax = 1000;
    int ymax = 800;

    
	Simple_window win {Point{100,100},xmax,ymax,"Canvas"};

    //Négyzetek felrajzolása
    int x_grid = 100;
    int y_grid = 100;

    Lines grid;
    for(int x = x_grid; x<=8*x_grid;x+=x_grid){
        grid.add(Point{x,0},Point{x,900});
    }
    for(int y= y_grid; y<8*y_grid;y+=y_grid){
        grid.add(Point{0,y},Point{800,y});
    }

    //Szinezés
    Vector_ref<Rectangle> rect;
    for(int i=0;i<8;++i){
            rect.push_back(new Rectangle{Point{i*100,i*100},100,100});
            rect[rect.size()-1].set_fill_color(Color::red);
            rect[rect.size()-1].set_color(Color::invisible);
            win.attach(rect[rect.size()-1]);
    }
    
    //Képek rajzolása
    Image rita {Point{200,0},"kepes.jpg"};
    Image grita {Point{400,0},"kepes.jpg"};
    Image frita {Point{600,0},"kepes.jpg"};
    win.attach(rita);
    win.attach(grita);
    win.attach(frita);

    int valueX = 0;
    int valueY = 0;
    //makes use of the computer's internal clock to control the choice of the seed. 
    //Since time is continually changing, the seed is forever changing.

    srand(time(NULL));
    valueY = rand()%8*100;
    valueX = rand()%8*100;

    Image tp {Point{valueX,valueY},"tp.jpg"};
    win.attach(tp);
    win.attach(grid);

    
	while(win.wait_for_button()){
        
        int dx = rand()%8*100-valueX;
        int dy = rand()%8*100-valueY;
        valueX+=dx;
        valueY+=dy;

        tp.move(dx,dy);
    }


    


    

}
