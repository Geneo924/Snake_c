#include <stdio.h>
#include <stdlib.h>


int row, column, height = 30;
int width = 30, gameover, score;
int snakex, snakey, foodx, foody;


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
}

void setup(){
    
}

int main(){

    draw();
    return 0;
}