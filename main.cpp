#include <ncurses.h>
#include "player_char.h"
#include <string.h>
#define KEY_ESC 27

void printmesg(char* text, int maxy, int maxx);
void itos(int input, char* out);
int main(void)
{
   Player player;
   int ch = 0;
	int y, x;
	char debug[25]={'t','e','s','t','\0'};

   initscr();
   raw();
   noecho();
   cbreak();
   keypad(stdscr, TRUE); 
	getmaxyx(stdscr, y, x);

   while(ch != KEY_ESC)
   {
      ch = getch();
      if(ch == KEY_UP || ch == KEY_DOWN ||
         ch == KEY_LEFT || ch == KEY_RIGHT)
      {
         player.SetNextMove(ch);
      }

      player.UpdatePlayer();
		printmesg(debug, y, x);
		refresh();
   }
   endwin();
   return 0;
}

void printmesg(char* text, int maxy, int maxx)
{
	mvprintw(maxy-1, 0, text);
}

void itos(int in, char *out)
{
	sprintf(out, "%d", in);
}
