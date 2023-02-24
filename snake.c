#include <stdio.h>
#include <stdlib.h>

// using i for rows, and j for columns to draw boundary
int i, j, height = 30;
int width = 30, gameover, score;


void draw(){

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(i == 0 || i == height - 1 || j == 0 || j == width - 1){
                printf("#");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(){

    draw();
    return 0;
}