/*
    g++ lines_main.cpp Graph.cpp Window.cpp GUI.cpp Lines_window.cpp -o DRILL `fltk-config --ldflags --use-images` -std=c++11 && ./DRILL
*/
#include "Lines_window.h"
#include "Graph.h"



int main()
{
    Lines_window win {Point{100,100}, 1920, 1080, "Lines"};
    
    return gui_main();
}
