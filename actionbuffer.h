class ActionBuffer
{
   private:
      bool moveReady;
      bool actionReady;
      int movement;
      int action;
   public:
      ActionBuffer();
      int   GetNextMove();
      int   GetNextAction();
      void  BufferMove(int);
      void  BufferAction(int);
};

ActionBuffer::ActionBuffer()
{
   moveReady = false;
   actionReady = false;
   movement = -1;
   action = -1;
}

int ActionBuffer::GetNextMove()
{
   int ret = 0;
   if(moveReady == true)
   {
      ret = movement;
      movement = -1;
      moveReady = false;
   }
   return ret;
}

int ActionBuffer::GetNextAction()
{
   int ret = 0;
   if(actionReady == true)
   {
      ret = action;
      action = -1;
      actionReady = false;
   }
   return ret;
}

void ActionBuffer::BufferMove(int input)
{
   movement = input;
   moveReady = true;
}

void ActionBuffer::BufferAction(int input)
{
   action = input;
   actionReady = true;
}
