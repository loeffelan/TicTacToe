#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char xTurn = 1;
char place = '0';
char winner = '0'; //0=still playing, N=no one won, X=x won, O=o won
char turn = 1;
char color = 0; 
char board[9] = {"123456789"};

void printBoard();
void askPlace();
void updateBoard();
char end();
void checkWinner();

int main (int argc, char **argv){

    if(argc == 2){
        if(strcpy(argv[1], "-C") || strcpy(argv[1], "-c")){
            color = 1;
        }
    }
    
    while(1){
    printBoard();
    askPlace();
    checkWinner();
    if(end()){break;}
    }

    turn--;
    printBoard();
    printf("*******************************************************************************\n");

    return 0;
}

void printBoard(){

    system("clear");

    printf("**********************************Tic Tac Toe**********************************\n");
    printf("Turn # %d \n\n", turn);

    if(color == 0){
    printf("%c|%c|%c\n-----\n%c|%c|%c\n-----\n%c|%c|%c\n\n", board[0], board[1], board[2], board[3], board[4], board[5], board[6], board[7],board[8]);
    }
    else{
//colored output for cell 1
    if(board[0] == 'X'){
        printf("\033[0;32m""%c""\033[0m", board[0]);
    }else if(board[0] == 'O'){
        printf("\033[0;34m""%c""\033[0m", board[0]);
    }else printf("%c", board[0]);

    printf("|");
//colored output for cell 2
    if(board[1] == 'X'){
        printf("\033[0;32m""%c""\033[0m", board[1]);
    }else if(board[1] == 'O'){
        printf("\033[0;34m""%c""\033[0m", board[1]);
    }else printf("%c", board[1]);

    printf("|");
//colored output for cell 3
    if(board[2] == 'X'){
        printf("\033[0;32m""%c""\033[0m", board[2]);
    }else if(board[2] == 'O'){
        printf("\033[0;34m""%c""\033[0m", board[2]);
    }else printf("%c", board[2]);

    printf("\n-----\n");
//colored output for cell 4
    if(board[3] == 'X'){
        printf("\033[0;32m""%c""\033[0m", board[3]);
    }else if(board[3] == 'O'){
        printf("\033[0;34m""%c""\033[0m", board[3]);
    }else printf("%c", board[3]);

    printf("|");
//colored output for cell 5
    if(board[4] == 'X'){
        printf("\033[0;32m""%c""\033[0m", board[4]);
    }else if(board[4] == 'O'){
        printf("\033[0;34m""%c""\033[0m", board[4]);
    }else printf("%c", board[4]);

    printf("|");
//colored output for cell 6
    if(board[5] == 'X'){
        printf("\033[0;32m""%c""\033[0m", board[5]);
    }else if(board[5] == 'O'){
        printf("\033[0;34m""%c""\033[0m", board[5]);
    }else printf("%c", board[5]);

    printf("\n-----\n");
//colored output for cell 7
if(board[6] == 'X'){
        printf("\033[0;32m""%c""\033[0m", board[6]);
    }else if(board[6] == 'O'){
        printf("\033[0;34m""%c""\033[0m", board[6]);
    }else printf("%c", board[6]);

    printf("|");
//colored output for cell 8
    if(board[7] == 'X'){
        printf("\033[0;32m""%c""\033[0m", board[7]);
    }else if(board[7] == 'O'){
        printf("\033[0;34m""%c""\033[0m", board[7]);
    }else printf("%c", board[7]);

    printf("|");
//colored output for cell 9
    if(board[8] == 'X'){
        printf("\033[0;32m""%c""\033[0m", board[8]);
    }else if(board[8] == 'O'){
        printf("\033[0;34m""%c""\033[0m", board[8]);
    }else printf("%c", board[8]);

    printf("\n\n");
    }

    switch (winner)
    {
    case 'O':
    if (color == 1){
        printf("\033[0;36m""O Winns !!!!\n""\033[0m");
    }else{
        printf("O Winns !!!!\n");
    }
    break;

    case 'X' : 
    if (color == 1){
        printf("\033[0;36m""X Winns !!!!\n""\033[0m");
    }else{
        printf("X Winns !!!!\n");
    }
    break;

    case 'N' : 
    if(color == 1){
        printf("\033[0;31m""Tie !!!!\n""\033[0m");
    }else{
        printf("Tie !!!!\n");
    }
    break;
    
    default:
        if(xTurn){
            printf("X's turn\n");
        }
        else{
            printf("O's turn\n");
        }
    break;
    }

}

void askPlace(){
    scanf("%c", &place);
    updateBoard();
}

char end(){

    if (winner == '0'){
        return 0;
    }
    return 1;
}

void updateBoard(){
//place-'0' tranforms a ascii value to an int
    if(xTurn && board[(place-'0') - 1] == place){
        board[(place- '0') - 1] = 'X';
        turn ++;
        xTurn = 0;

        if(turn == 10){
            winner = 'N';
        }
        return;
    }
    if(!xTurn && board[(place-'0') - 1] == place){
        board[(place- '0') - 1] = 'O';
        turn ++;
        xTurn = 1;

        if(turn == 10){
            winner = 'N';
        }
        return;
    }
}

void checkWinner(){

    if(xTurn){

        if(board[0] == 'O' && board[4] == 'O' && board[8] == 'O'){
            winner = 'O';
        }
        if(board[2] == 'O' && board[4] == 'O' && board[6] == 'O'){
            winner = 'O';
        }
        if(board[0] == 'O' && board[1] == 'O' && board[2] == 'O'){
            winner = 'O';
        }
        if(board[3] == 'O' && board[4] == 'O' && board[5] == 'O'){
            winner = 'O';
        }
        if(board[6] == 'O' && board[7] == 'O' && board[8] == 'O'){
            winner = 'O';
        }
        if(board[0] == 'O' && board[3] == 'O' && board[6] == 'O'){
            winner = 'O';
        }
        if(board[1] == 'O' && board[4] == 'O' && board[7] == 'O'){
            winner = 'O';
        }
        if(board[2] == 'O' && board[5] == 'O' && board[8] == 'O'){
            winner = 'O';
        }
    }
    else{

        if(board[0] == 'X' && board[4] == 'X' && board[8] == 'X'){
            winner = 'X';
        }
        if(board[2] == 'X' && board[4] == 'X' && board[6] == 'X'){
            winner = 'X';
        }
        if(board[0] == 'X' && board[1] == 'X' && board[2] == 'X'){
            winner = 'X';
        }
        if(board[3] == 'X' && board[4] == 'X' && board[5] == 'X'){
            winner = 'X';
        }
        if(board[6] == 'X' && board[7] == 'X' && board[8] == 'X'){
            winner = 'X';
        }
        if(board[0] == 'X' && board[3] == 'X' && board[6] == 'X'){
            winner = 'X';
        }
        if(board[1] == 'X' && board[4] == 'X' && board[7] == 'X'){
            winner = 'X';
        }
        if(board[2] == 'X' && board[5] == 'X' && board[8] == 'X'){
            winner = 'X';
        }
    }
}