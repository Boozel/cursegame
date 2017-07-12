#include <ncurses.h>
#include "player_char.h"

#define KEY_ESC 27

int main(void)
{
   Player player;
   int ch = 0;

   initscr();
   raw();
   noecho();
   cbreak();
   keypad(stdscr, TRUE);
   

   while(ch != KEY_ESC)
   {
      ch = getch();
      if(ch == KEY_UP || ch == KEY_DOWN ||
         ch == KEY_LEFT || ch == KEY_RIGHT)
      {
         player.SetNextMove(ch);
      }

      player.UpdatePlayer();
      refresh();
   }
   endwin();
   return 0;
}
