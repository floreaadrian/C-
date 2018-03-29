#include "fun.cpp"
#include <iostream>
#include <unistd.h>

using namespace std;

bool gameOver;

const int width = 30;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void Setup() {
  gameOver = false;
  dir = STOP;
  x = width / 2;
  y = height / 2;
  fruitX = rand() % width;
  fruitY = rand() % height;
  score = 0;
}

void Draw() {
  system("clear");
  cout << "+";
  for (int i = 0; i < width; i++)
    cout << "-";
  cout << "+";
  cout << "\n";
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (j == 0)
        cout << "|";
      if (i == y && j == x)
        cout << "O";
      else if (i == fruitY && j == fruitX)
        cout << "F";
      else {
        bool prt = false;
        for (int k = 0; k < nTail; k++) {
          if (tailX[k] == j && tailY[k] == i) {
            cout << "=";
            prt = true;
          }
        }
        if (!prt)
          cout << " ";
      }
      if (j == width - 1)
        cout << "|";
    }
    cout << "\n";
  }
  cout << "+";
  for (int i = 0; i < width; i++)
    cout << "-";
  cout << "+\n";
  cout << "Score: " << score << " Tail: " << nTail << "\n";
}

void Input() {
  if (kbhit()) {
    switch (getch()) {
    case 'a':
      if (dir != RIGHT)
        dir = LEFT;
      break;
    case 'd':
      if (dir != LEFT)
        dir = RIGHT;
      break;
    case 'w':
      if (dir != DOWN)
        dir = UP;
      break;
    case 's':
      if (dir != UP)
        dir = DOWN;
      break;
    case 'x':
      gameOver = true;
    }
  }
}

void Logic() {
  int prevX = tailX[0];
  int prevY = tailY[0];
  int prev2X, prev2Y;
  tailX[0] = x;
  tailY[0] = y;
  for (int i = 1; i < nTail; ++i) {
    prev2X = tailX[i];
    prev2Y = tailY[i];
    tailX[i] = prevX;
    tailY[i] = prevY;
    prevX = prev2X;
    prevY = prev2Y;
  }
  switch (dir) {
  case LEFT:
    x--;
    break;
  case RIGHT:
    x++;
    break;
  case UP:
    y--;
    break;
  case DOWN:
    y++;
    break;
  default:
    break;
  }
  // if (y < 0 || x < 0 || x > 20 || y > 20)
  //   gameOver = true;
  if (x >= width)
    x = 0;
  else if (x < 0)
    x = width - 1;
  if (y >= height)
    y = 0;
  else if (y < 0)
    y = width - 1;
  for (int i = 0; i < nTail; i++)
    if (tailX[i] == x && tailY[i] == y)
      gameOver = true;
  if (x == fruitX && y == fruitY) {
    nTail++;
    score += 10;
    fruitX = rand() % width;
    fruitY = rand() % height;
  }
}

int main() {
  Setup();
  while (!gameOver) {
    Draw();
    Input();
    Logic();
    usleep(120000);
  }
  return 0;
}
