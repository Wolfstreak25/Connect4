#include <bits/stdc++.h>
using namespace std;
class GameLoop
{
private:
string GameArray[6];
int dx,dy;
int column,row;
int cont = 0;
char c;
char PlayerInput;

public:
bool gameOver = false;
GameLoop()
{
  //initialize
  cout<<"Enter Column number in range [0,5]\n";
  for(int i = 0; i < 6; i++)
    {
      GameArray[i].clear();
    }
    print();
}
void input(string player)
{
  do{
  cin>>PlayerInput;
      if(!EmptySlotCheck() && columncheck(PlayerInput))
        {
              GameArray[column] += player;
              print();
              row = GameArray[column].length()-1;
              checks();
              cout << endl;
        }
    }while(!columncheck(PlayerInput));
}

bool columncheck(int playerInput)
{
  column = int(playerInput - 48);
  if((column <= 5  && column >= 0) && GameArray[column].length() < 7 )
  {
    return true;
  }
  cout<<"\nInvalid input\nTry Again between range [0,5]\n";
  return false;
}

bool EmptySlotCheck()
{ 
  for(int i=0; i< 6; i++)
    {
      if(GameArray[i].length() < 7)
          return false;
    }
  cout<<"\nNo slots left\n";
  cout<<"Game Over\n";
  return gameOver = true;
}

void checks()
{
  c = GameArray[column][row];
  for(int i = column-1; i <= column+1; i++)
    {
      for(int j = row-1; j <= row+1; j++)
        {
          if(i >= 0 && i <= 5 && j >= 0 && j <= 6){
            if(GameArray[i][j] == c && (i != column || j != row))
            {
              dx = column-i;
              dy = j-row;
              cont = 1;
              //forward check and add
              cont += (doublecheck(dx,dy) - 1);
              //backward check and add
              cont += (doublecheck(-dx,-dy) - 1);
              if(cont>=4)
              {
                cout<<"\nconnected\n";
                gameOver = true;
                GameOver();
                break;
              }
            }
          }
        }
    }
}

int doublecheck(int dx, int dy)
{ int count = 1;
  int x = column;
  int y =row;
      x -= dx;
      y += dy;
  while(x>=0 && x<= 5 && y>=0 && y<=6)
  { 
    if(GameArray[x][y] == c && (x != column || y != row))
    {
      count++;
      if( count >= 4)
      {
        return count;
      }
      x -= dx;
      y += dy;
    }
    else {
      break;}
  }
  return count;
}

void print()
{
  cout<<"\n";
  for(int j = 6 ; j >= 0 ; j--)//row
    {
      for (int i = 0; i < 6; i++)//column
        {
          if(GameArray[i][j] == 'X' || GameArray[i][j] == 'O')
            {cout <<"["<< GameArray[i][j]<<"] ";}
          else
            cout <<"[ ] ";
        }    
        cout << endl;
    }
}
bool GameOver()
{ 
  if(gameOver == true)
  {
    char GameEnd;
    cout<<"Player "<<GameArray[column][row]<<" won !\n";
    cout<<"\nPlay Again Y/N : ";
    cin>>GameEnd;
      if(GameEnd == 'Y' || GameEnd == 'y')
        {  
          GameLoop();
          system("CLS");
          return gameOver = false;
        }
  }
  return gameOver;
}
};

int main() {
  char St;
  there:
  cout<<"Press Any Key to Start\n";
  cin>> St ;
  GameLoop *game = new GameLoop();;
  do
    {
      cout<<"\n here\n";
      if(!game->gameOver)
        {
          cout<<"\nPlayer O chose Column Number : ";
          game->input("O");
        }
      if(!game->gameOver)
        {
          cout<<"\nPlayer X chose Column Number : ";
          game->input("X");
        }
      
    }while(!game->gameOver);
    cout<<"\nThank You\n";
}


