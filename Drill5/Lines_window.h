#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
	Lines_window(Point xy, int w, int h, const string& title );
	Open_polyline lines;

    Menu color_menu;
	Button menu_button;
	//
	Menu style_menu;
	Button style_button;
	

	void change(Color c){lines.set_color(c);}
    void hide_menu(){color_menu.hide(); menu_button.show();}
	//
	void hide_style_menu(){style_menu.hide(); style_button.show();}

	
    void red_pressed(){change(Color::red);redraw();}
    void blue_pressed(){change(Color::blue);redraw();}
    void black_pressed(){change(Color::black);redraw();}
	void menu_pressed(){menu_button.hide();color_menu.show();}
	//
	void change_style(Line_style ls){lines.set_style(ls); hide_style_menu(); redraw();}
	void style_menu_pressed(){style_button.hide();style_menu.show();}
    
	static void cb_red(Address,Address);
	static void cb_blue(Address,Address);
    static void cb_black(Address,Address);
	static void cb_menu(Address,Address);
	//
	static void cb_style_menu(Address,Address);
	

    bool wait_for_button();

private:
	Button next_button;
	Button quit_button;
	


	In_box next_x;
	In_box next_y;

	Out_box xy_out;

	void next();
	void quit();

};