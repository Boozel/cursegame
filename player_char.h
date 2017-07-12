#include "actionbuffer.h"
#include <ncurses.h>

class Player
{
   private:
      ActionBuffer actionb;
      int x;
      int y;

   public:
      Player();
      void UpdatePlayer(void);
      void SetNextMove(int);
      void SetNextAction(int);      
};

Player::Player()
{
   x = 0;
   y = 0;
}

void Player::UpdatePlayer(void)
{
   int action = actionb.GetNextMove();
   
   switch(action)
   {
      case KEY_UP:
         y -= 1;
         break;
      case KEY_DOWN:
         y += 1;
         break;
      case KEY_LEFT:
         x -= 1;
         break;
      case KEY_RIGHT:
         x += 1;
         break;
      case 0:
      default:
         break;
   }

   mvprintw(y, x, "@");
}

void Player::SetNextMove(int input)
{
   actionb.BufferMove(input);
}

void Player::SetNextAction(int input)
{
}
