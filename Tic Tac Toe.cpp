#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define space 11

void printMatrix(char pin[3][3]) {
	printf("\n\t\t\033[0;33m Tic Tac ToeÅ\033[0;37m\n");
    printf("---------------------------------------\n");
    printf("\n");
    for (int i = 0; i < 3; i++) {
    	    printf("\t\t");
        for (int j = 0; j < 3; j++) {
            printf("\033[0;32m %c\033[0;37m ",pin[i][j]);
            if (j < 2) printf("\033[0;36m|\033[0;37m");
        }
        printf("\n");
        if (i < 2 ) printf("\t\t\033[0;36m---\033[0;31m+\033[0;37m\033[0;36m---\033[0;31m+\033[0;37m\033[0;36m---\033[0;37m\n");
    }
    printf("\n");
}

int Winner(char pin[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if ((pin[i][0] == player && pin[i][1] == player && pin[i][2] == player) || 
            (pin[0][i] == player && pin[1][i] == player && pin[2][i] == player) ||
			(pin[0][0] == player && pin[1][1] == player && pin[2][2] == player) ||
			(pin[0][2] == player && pin[1][1] == player && pin[2][0] == player)) {  
            return true;
        }
    }
    return false;
}
int NoWinner(char pin[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (pin[i][j] == '-') {
                return false; 
            }
        }
    }
    return true; 
}
int Reaction(char pin[3][3], int row, int column, char player) {
    if (row < 0 || row >= 3 || column < 0 || column >= 3 || pin[row][column] != '-') {
        printf("Try Again.\n");
        return false;
    }
    pin[row][column] = player;
    return true;
}
int main() {
	system("CHCP 1253 > nul");
    char matrix[3][3] = { {'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'} };
    int row, column,next_move = 0,movement=0, movement1 = 0;
    char player1,player2;
    char name[space],name1[space];
   
 	printf("\t\t\033[38;5;208m Type name  1st Player.\033[0;34m\n");
    gets(name1); 
	printf("\t\t\033[38;5;208m Type name 2nd Player.\033[0;34m\n");
    gets(name);  
    
    do{ 
    printf("\033[0;31m%s\033[0;37m Choose a symbol, X or O. \n",name1);
    fflush(stdin);
    scanf("%c",&player1);
    }while(player1!='x' && player1!='X' && player1!='o' && player1!='O'&& player1!='◊' && player1!='˜'&& player1!='œ' && player1!='Ô');
    
    do{
    printf("\033[0;31m%s\033[0;37mChoose a symbol, X or O.\n",name);
     fflush(stdin);
    scanf("%c",&player2);
     }while(player2!='x' && player2!='X' && player2!='o' && player2!='O'&& player2!='◊' && player2!='˜'&& player2!='œ' && player2!='Ô');
        
    while (true) {
        printMatrix(matrix);   
    if(next_move==0){
     	printf(" \033[0;31m%s,\033[0;37m Turn of symbol \033[0;33m %c \033[0;37m Enter row and column #:  \033[0;37m", name1,player1);
	  
        while (movement=movement^1) {
            scanf("%d %d", &row, &column);
            movement = Reaction(matrix, row, column, player1);
        }
       
        if (Winner(matrix, player1)) {
            printMatrix(matrix);
            printf("The player \033[0;32m %s \033[0;37m Wins!\n", name1);
            break;
        }
        
        if (NoWinner(matrix)) {
            printMatrix(matrix);
            printf("It's a draw.!\n");
            break;
        }
   }
    if(next_move==1){
   		printf(" \033[0;31m%s,\033[0;37m Turn of symbol \033[0;33m %c \033[0;37m Enter row and column #:  \033[0;37m", name,player2);
	  
        while (movement1=movement1^1) {
            scanf("%d %d", &row, &column);
            movement1 = Reaction(matrix, row, column, player2);
        }
        
        if (Winner(matrix, player2)) {
            printMatrix(matrix);
            printf("The player \033[0;32m %s \033[0;37m Wins!\n", name);
            break;
        }
       
        if (NoWinner(matrix)) {
            printMatrix(matrix);
            printf("It's a draw.!\n");
            break;
        }
   }
        
       next_move= next_move^1;
        system("CLS");
    }
    return 0;
}
