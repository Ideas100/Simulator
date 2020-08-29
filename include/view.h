/* view.h - handles all the terminal functionalities */
#ifndef __VIEW_H__
#define __VIEW_H__

#include <ncurses.h>
#include <string>
#include <cstring>
using namespace std;

#define WIN_HT (ht - 4)
#define WIN_WD (wd - 6)
#define WIN_YPOS (ht/2 - WIN_HT/2)
#define WIN_XPOS (wd/2 - WIN_WD/2)

static int ht, wd;

/* class View
 *  - handles the terminal screen 
 *  - constructor methods invokes the properties for 
 *    ncurses to start the terminal screen
 */
class View
{
public:
	WINDOW *win;
	int cur_pos;
	
	View() {
		initscr();
		cbreak();
		noecho();
		halfdelay(1);
		curs_set(0);
		bkgd(A_REVERSE | A_DIM);
		getmaxyx(stdscr, ht, wd);
		win = newwin(WIN_HT, WIN_WD, WIN_YPOS, WIN_XPOS);
	        wborder(win, ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ');
		wbkgd(win, A_BOLD);
		refresh();
		wrefresh(win);
	}

/* read_()
 * - reads the input from the user.
 * - return char
 */
	char read_();

/* D_button_view(char button)
 * - provides hint to the user for the respective button 
 */
	void D_button_view(char button);

/* A_button_view(char button_1, char button_2)
 * - provides hint to the user for the respective button 
 * - Used in analog input, so Inc and Dec buttons were used.
 */
	void A_button_view(char button_1, char button_2);

/* print_title(string str, int type)
 * - print the heading and sub-heading
 * - type denotes type of the heading.
 */
	void print_title(string str, int type);

/* print(int pin_no, int mode, int value)
 * - prints the pin properties into terminal window
 */
	void print(int pin_no, int mode, int value, int type);

/* print_err(int pin_no, int mode, int value)
 * - prints the error made in code, into terminal window
 *   ie., logic error like pin_no mismatches etc.,
 */
	void print_err(int pin_no, string str);

/* cleanup()
 * - deallocates the resources allocated for ncurses library
 */
	void cleanup();
};

#endif /* __VIEW_H__ */
