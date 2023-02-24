#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>


int height = 30, width = 30;
int gameover, score, flag;
int snakex, snakey, foodx, foody;


void set_noncanonical_mode() {
    struct termios tty_attr;
    tcgetattr(STDIN_FILENO, &tty_attr);
    tty_attr.c_lflag &= ~(ICANON | ECHO);
    tty_attr.c_cc[VMIN] = 1;
    tty_attr.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &tty_attr);
}



void draw(){
    system("cls");
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(i == 0 || i == height - 1 || j == 0 || j == width - 1){
                printf("#");
            }
            else{
                // prints the snake head
                if(i == snakex && j == snakey){
                    printf("0");
                }
                // prints food
                else if(i == foodx && j == foody){
                    printf("*");
                }
                // prints the open area
                else{
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("score = %d", score);
    printf("\n");
    printf("press X to quit the game");
}

void setup(){
    set_noncanonical_mode();

    // to randomly place the food anywhere on the board, within boundaries
    // to handle game state, 
    gameover = 0;
    score = 0;

    // start in the middle of the game board
    snakex = height / 2;
    snakey = width / 2;

    // always make sure the food is in proper boundaries
    label1:
        foodx = rand() % 30;
        if(foodx == 0)
            goto label1;
    label2:
        foody = rand() % 30;
        if(foody == 0)
            goto label2;
}

void input(){
    int ch = getchar();
        switch(ch) {
            case 'a':
                flag = 1;
                break;
            case 's':
                flag = 2;
                break;
            case 'd':
                flag = 3;
                break;
            case 'w':
                flag = 4;
                break;
            case 'x':
                gameover = 1;
                break;
        }
    }

void logic(){

    usleep(10000);

    switch(flag) {
        case 1:
            snakey--;
            break;
        case 2:
            snakex++;
            break;
        case 3:
            snakey++;
            break;
        case 4:
            snakex--;
            break;
        default:
            break;
    }

    if(snakex < 0 || snakex > height || snakey < 0 || snakey > width){
        gameover = 1;
    }

    // when snake eats the food, generate new food item on board
    if(snakex == foodx && snakey == foody){
        label3:
            foodx = rand() % 30;
            if(foodx == 0){
                goto label3;
            }


        label4:
            foody = rand() % 30;
            if(foody == 0){
                goto label4;
            }
            score+=10;
    }
}

int main(){

   setup();

   while(!gameover){
        draw();
        input();
        logic();
   }

   
   return 0;
}