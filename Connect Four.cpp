//https://replit.com/@Wolfstrrak/DS-MAT01#main.cpp
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
  here:
  cin>>PlayerInput;
  column = int(PlayerInput - 48);
  if(column <= 5 && column >= 0)
    {
      if(!EmptySlotCheck())
        {
          if( GameArray[column].length() < 7)
            {
              GameArray[column] += player;
              print();
              row = GameArray[column].length()-1;
              checks();
              cout << endl;
            }
        else 
          {
            cout<<"Column is full try another : ";
            goto here;
          }
        }
    else
      {
        cout<<"\nNo slots left\n";
        cout<<"Game Over\n";
        gameOver = true;
      }
    }
  else
    {
      cout<<"\nInvalid input\nTry Again between range [0,5]\n";
      goto here;
    }
}

bool EmptySlotCheck()
{ 
  bool isFilled = true;
  for(int i=0; i< 6; i++)
      if(GameArray[i].length() < 7)
          isFilled =  false;
  return isFilled;
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
                cout<<"connected\n";
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
{ gameOver = true;
  cout<<"Player "<<GameArray[column][row]<<" won !\n";
  return true;
}
};

int main() {
  GameLoop game;
  char St;
  bool Stop = game.gameOver;
  there:
  cout<<"Press Any Key to Start\n";
  cin>> St;
  while(!Stop)
    {
      if(!Stop)
        {
          cout<<"\nPlayer O chose Column Number : ";
          game.input("O");
        }
      if(!Stop)
        {
          cout<<"\nPlayer X chose Column Number : ";
          game.input("X");
        }
    }
  cout<<"\nPlay Again Y/N";
  cin>>St;
  if(St == 'Y' || St == 'y')
  {  
    system("CLS");
    Stop = false;
    goto there;
  }
  else{cout<<"\nThank You\n";}
}
