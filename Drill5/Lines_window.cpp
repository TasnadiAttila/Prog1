#include "Lines_window.h"

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window{xy,w,h,title},
    color_menu{Point{x_max()-70,40},70,20,Menu::vertical,"Color"},
    menu_button{Point{x_max()-80,40},80,20,"color menu",cb_menu},
    //
    style_menu{Point{x_max()-70,110},80,20,Menu::vertical,"Style"},
    style_button{Point{x_max()-80,110},80,20,"Style menu",cb_style_menu},

    next_button{Point{x_max()-300,0}, 150, 40, "Next point",
        [](Address, Address pw) {reference_to<Lines_window>(pw).next();}},
    quit_button{Point{x_max()-150,0}, 150, 40, "Quit",
        [](Address, Address pw) {reference_to<Lines_window>(pw).quit();}},
    next_x{Point{300,0}, 50, 40, "next x:"},
    next_y{Point{450,0}, 50, 40, "next y:"},
    xy_out{Point{100,0}, 100, 40, "current (x,y):"}
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    attach(lines);

    color_menu.attach(new Button{Point{0,0},0,0,"Red",cb_red});
    color_menu.attach(new Button{Point{0,0},0,0,"Blue",cb_blue});
    color_menu.attach(new Button{Point{0,0},0,0,"Black",cb_black});
    
    attach(color_menu);
    color_menu.hide();
    attach(menu_button);

    style_menu.attach(new Button{Point{0,0},0,0,"Solid",[](Address,Address pw) {reference_to<Lines_window>(pw).change_style(Line_style::solid);}});
    style_menu.attach(new Button{Point{0,0},0,0,"Dash",[](Address,Address pw) {reference_to<Lines_window>(pw).change_style(Line_style::dash);}});
    style_menu.attach(new Button{Point{0,0},0,0,"Dot",[](Address,Address pw) {reference_to<Lines_window>(pw).change_style(Line_style::dot);}});
    style_menu.attach(new Button{Point{0,0},0,0,"Dashdot",[](Address,Address pw) {reference_to<Lines_window>(pw).change_style(Line_style::dashdot);}});
    style_menu.attach(new Button{Point{0,0},0,0,"Dashdotdot",[](Address,Address pw) {reference_to<Lines_window>(pw).change_style(Line_style::dashdotdot);}});

    attach(style_menu);
    style_menu.hide();
    attach(style_button);
    


}
    
    

void Lines_window::quit()
{
    hide();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point{x,y});

    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
    color_menu.hide();
    menu_button.show();
}
void Lines_window::cb_red(Address,Address pw){
    reference_to<Lines_window>(pw).red_pressed();
}
void Lines_window::cb_black(Address,Address pw){
    reference_to<Lines_window>(pw).black_pressed();
    
}
void Lines_window::cb_blue(Address,Address pw){
    reference_to<Lines_window>(pw).blue_pressed();
}
void Lines_window::cb_menu(Address,Address pw){
    reference_to<Lines_window>(pw).menu_pressed();
}
void Lines_window::cb_style_menu(Address,Address pw){
    reference_to<Lines_window>(pw).style_menu_pressed();
}