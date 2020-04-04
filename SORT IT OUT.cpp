#include<stdio.h>

#include<stdlib.h>

#include <windows.h>

#include<graphics.h>

#include<time.h>

void Game_Matrix(int matrix_data[][4]);
void printingMatrix(int matrix_data[][4]);
void up_key(int Matrix_Data[][4]);
void down_key(int Matrix_Data[][4]);
void left_key(int Matrix_Data[][4]);
void right_key(int Matrix_Data[][4]);
int winning_condition(int Matrix_Data[][4]);
void select_level(int * remain_moves);
int key_check();
char main_menu();
void Game_Play();
char main_menu();
void start_up();

int main() {
  initwindow(705, 500);
  int Matrix_Data[4][4], remain_moves;
  char name[10];
  char closing_key;
  start_up();
  begin: cleardevice();
  setcolor(WHITE);
  Game_Matrix(Matrix_Data);
  if (main_menu() == '1') {
    select_level( & remain_moves);
  } else if (main_menu() == '2') {

  }
  cleardevice();
  int i = 0;

  while (!winning_condition(Matrix_Data)) {
    system("cls");
    if (!remain_moves) {
      cleardevice();
      settextstyle(7, 0, 3);
      setcolor(WHITE);
      outtextxy(120, 150, "You've lost, Thanks for Playing");
      outtextxy(120, 250, "Press Key to play again(Y/N)");
      play_again: closing_key = getch();
      if (closing_key == 'Y' || closing_key == 'y') {
        system("cls");
        goto begin;
      } else if (closing_key == 'N' || closing_key == 'n') {
        exit(0);
      } else {
        goto play_again;
      }
    }
    settextstyle(6, 0, 2);
    char num[100];
    setcolor(WHITE);
    outtextxy(260, 0, "SORT IT OUT");
    settextstyle(6, 0, 1);
    sprintf(num, "Remaining Moves: %d", remain_moves);
    outtextxy(230, 50, num);
    Game_Play();
    printingMatrix(Matrix_Data);
    int key = key_check();
    switch (key) {
    case 119:
      {
        down_key(Matrix_Data);
        remain_moves--;
        break;
      }
    case 115:
      {
        up_key(Matrix_Data);
        remain_moves--;
        break;
      }
    case 97:
      {
        right_key(Matrix_Data);
        remain_moves--;
        break;
      }
    case 100:
      {
        left_key(Matrix_Data);
        remain_moves--;
        break;
      }
    default:
      setcolor(WHITE);
      settextstyle(6, 0, 2);
      outtextxy(280, 430, "Wrong Key");
      settextstyle(6, 1, 2);
      outtextxy(140, 170, "Wrong Key");
      settextstyle(6, 3, 2);
      outtextxy(560, 310, "Wrong Key");
      delay(200);
      cleardevice();
    }
  }

  cleardevice();
  settextstyle(7, 0, 3);
  setcolor(WHITE);
  outtextxy(120, 150, "You've WON, Thanks for Playing");
  outtextxy(120, 250, "Press Key to play again(Y/N)");
  ask_again: closing_key = getch();
  if (closing_key == 'Y' || closing_key == 'y') {
    system("cls");
    goto begin;
  } else if (closing_key == 'N' || closing_key == 'n') {
    exit(0);
  } else {
    goto ask_again;
  }
}
void Game_Matrix(int Matrix_Data[][4]) {
  int rand_num[] = {
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    9,
    10,
    11,
    12,
    13,
    14,
    15
  }, pointing, number = 14, i, j;
  srand(time(NULL));
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      if (number >= 0) {
        pointing = rand() % (number + 1);
        Matrix_Data[i][j] = rand_num[pointing];
        rand_num[pointing] = rand_num[number];
        number--;
      }
    }

  }
  Matrix_Data[i - 1][j - 1] = 0;
}
void printingMatrix(int matrix_data[][4]) {

  setcolor(RED);
  settextstyle(10, 0, 5);
  setbkcolor(7);
  for (int i = 0, k = 1, y = 120; i < 4; i++, y += 80) {
    for (int j = 0, x = 190; j < 4; j++, k++, x += 100) {
      if (matrix_data[i][j] == 0) {
        char num[100];
        sprintf(num, "");
        outtextxy(x, y, num);
      } else {
        char num[100];
        sprintf(num, "%d", matrix_data[i][j]);
        outtextxy(x, y, num);
      }
    }
  }
}
int key_check() {
  char key = getch();

  return key;
}

void up_key(int Matrix_Data[][4]) {
  int i, j, k = 0;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      if (Matrix_Data[i][j] == 0) {
        k = 1;
        break;
      }
    }
    if (k == 1) {
      break;
    }
  }
  if (i != 0) {
    int temp = Matrix_Data[i][j];
    Matrix_Data[i][j] = Matrix_Data[i - 1][j];
    Matrix_Data[i - 1][j] = temp;
  }
}
void down_key(int Matrix_Data[][4]) {
  int i, j, k = 0;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      if (Matrix_Data[i][j] == 0) {
        k = 1;
        break;
      }

    }
    if (k == 1) {
      break;
    }
  }
  if (i != 3) {

    int temp = Matrix_Data[i][j];
    Matrix_Data[i][j] = Matrix_Data[i + 1][j];
    Matrix_Data[i + 1][j] = temp;
  }
}
void right_key(int Matrix_Data[][4]) {
  int i, j, k = 0;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      if (Matrix_Data[i][j] == 0) {
        k = 1;
        break;
      }
    }
    if (k == 1) {
      break;
    }
  }
  if (j != 3) {
    int temp = Matrix_Data[i][j];
    Matrix_Data[i][j] = Matrix_Data[i][j + 1];
    Matrix_Data[i][j + 1] = temp;
  }
}
void left_key(int Matrix_Data[][4]) {
  int i, j, k = 0;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      if (Matrix_Data[i][j] == 0) {
        k = 1;
        break;
      }
    }
    if (k == 1) {
      break;
    }
  }
  if (j != 0) {
    int temp = Matrix_Data[i][j];
    Matrix_Data[i][j] = Matrix_Data[i][j - 1];
    Matrix_Data[i][j - 1] = temp;
  }
}
int winning_condition(int Matrix_Data[][4]) {
  int i, j, k = 1;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++, k++)
      if (Matrix_Data[i][j] != k && k != 16)
        break;
    if (j < 4)
      break;
  }
  if (j < 4)
    return 0;
  return 1;
}

void select_level(int * remain_moves) {
  cleardevice();
  char level;

  enter_again: settextstyle(6, 0, 4);
  outtextxy(130, 150, "Select difficulty level:");
  settextstyle(2, 0, 6);
  outtextxy(200, 250, "--> PRESS 1 for Easy Level");
  outtextxy(200, 300, "--> PRESS 2 for Medium Level");
  outtextxy(200, 350, "--> PRESS 3 for Hard Level");
  level = getch();
  if (level == '1') {
    * remain_moves = 400;
  } else if (level == '2') {
    * remain_moves = 300;
  } else if (level == '3') {
    * remain_moves = 200;
  } else {
    goto enter_again;
  }
}
char main_menu() {
  char menu;

  enter_again: settextstyle(6, 0, 5);
  outtextxy(200, 150, "Main Menu");
  settextstyle(2, 0, 6);
  outtextxy(200, 250, "--> PRESS 1 to Play");
  outtextxy(200, 300, "--> PRESS 2 for Help");
  menu = getch();
  if (menu == '1') {
    return '1';
  } else if (menu == '2') {
    return '2';
  } else {
    goto enter_again;
  }
}
void Game_Play() {
  setcolor(BROWN);
  setfillstyle(SOLID_FILL, 7);
  bar(150, 100, 550, 420);
  setlinestyle(0, 0, 4);

  rectangle(150, 100, 550, 420);
  setcolor(8);
  line(250, 100, 250, 420);
  line(350, 100, 350, 420);
  line(450, 100, 450, 420);
  line(150, 180, 550, 180);
  line(150, 260, 550, 260);
  line(150, 340, 550, 340);

}
void start_up() {
  settextstyle(6, 0, 7);
  setcolor(BROWN);
  outtextxy(60, 100, "SORT IT OUT");
  settextstyle(2, 0, 6);
  setcolor(WHITE);
  outtextxy(215, 300, "PRESS ANY KEY TO CONTINUE");
  getch();
}
