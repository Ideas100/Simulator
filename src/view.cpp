#include <view.h>

/* print_number(Window *win, int value)
 *  - print the analog values according to number of digits
 *    to avoid values to be printed into the terminal window.
 */
static void print_number(WINDOW *win, int value)
{
	if (value >= 0 && value < 10) {
		wprintw(win, "%d   ", value);
	} else if (value >= 10 && value < 100) {
		wprintw(win, "%d  ", value);
	} else if (value >=100 && value < 1000) {
		wprintw(win, "%d ", value);
	} else if (value >= 1000) {
		wprintw(win, "%d", value);
	}
		
}

static inline void reverse(WINDOW *win)
{
	wattron(win, A_REVERSE);
	wprintw(win, "  ");
	wattroff(win, A_REVERSE);
}

static inline void dim(WINDOW *win)
{
	wattron(win, A_REVERSE | A_DIM);
	wprintw(win, "  ");
	wattroff(win, A_REVERSE | A_DIM);
}

static void highlights(WINDOW *win, int mode, int value, int type)
{
	wprintw(win, "   ");
	switch (type) {
	case 0:
	        if (mode == 1) {
			if (value <= 255/3) {
				wprintw(win, "  ");
			} else if (value > 255/3 && value <= 255 * 2/3) {
				dim(win);
			} else if (value > 255 * 2/3) {
				reverse(win);
			}
		} else {
			if (value <= 1023/3) {
			       wprintw(win, "  ");
			} else if (value > 1023/3 && value <= 1023 * 2/3) {
				dim(win);
			} else if (value > 1023 * 2/3) {
				reverse(win);
			}
		}
		break;
	case 1:
		if (value){
			reverse(win);
		} else {
			wprintw(win, "  ");
		}
		break;
	}
}

char View::read_()
{	
	return getch();
}

void View::D_button_view(char button)
{
	wmove(View::win, View::cur_pos, (wd/16)* 12);
	wprintw(View::win, "Button-%c", button);
	wrefresh(View::win);
}

void View::A_button_view(char button_1, char button_2)
{
	
	wmove(View::win, View::cur_pos, (wd/16)* 12);
	wprintw(View::win, "Inc-%c : Dec-%c", button_1, button_2);
	wrefresh(View::win);
}

void View::print_title(string str, int type)
{
	char *ch = new char[str.length()] ;

	strcpy(ch, str.c_str());
	getmaxyx(View::win, ht, wd);
	wmove(View::win, type*2, (wd/2)-(str.length()/2)-2);
	if (type == 0) {
		wattron(View::win, A_UNDERLINE);
		wprintw(View::win,"%s", ch);
		wattroff(View::win, A_UNDERLINE);
	} else {
		wattron(View::win, A_STANDOUT);
		wprintw(View::win, "  %s  ", ch);
		wattroff(View::win, A_STANDOUT);
	}
	wrefresh(View::win);
}

void View::print(int pin_no, int mode, int value, int type)
{
	string str[] = {"INPUT", "OUTPUT"};
	char *ch = new char[6];

	wmove(View::win, View::cur_pos, wd/16);
	strcpy(ch, str[mode].c_str());
	wprintw(View::win, " -> Pin-%d :: mode-%s :: value-", pin_no, ch);
	print_number(View::win, value);
	
	highlights(View::win, mode, value,type);
	wrefresh(View::win);	
}

void View::print_err(int pin_no, string str)
{
	char *ch = new char[str.length()] ;

	strcpy(ch, str.c_str());
	wmove(View::win, View::cur_pos, wd/16);
	wprintw(View::win, " -> %s [pin-%d]", ch, pin_no);
	wrefresh(View::win);
}

void View::cleanup()
{
	delwin(View::win);
	endwin();
}
