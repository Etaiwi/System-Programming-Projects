#include <stdio.h>
#define BOARD_SIZE 16
#define ROW_SIZE 8

/********************************    Function prototypes     ********************************/
int is_move_legal(char board[][BOARD_SIZE],char,int,int,int,int);
int is_pawn_moveable(char board[][BOARD_SIZE],char,int,int);
int play_single_turn(char board[][BOARD_SIZE],char);
int play(char board[][BOARD_SIZE]);
void place_pawns(char board[][BOARD_SIZE]);
void print_board(char board[][BOARD_SIZE]);
int move_pawn(char board[][BOARD_SIZE],char,int,int,int,int);
char which_turn(int);
int another_game();
void print_turn(int);
int in_box(int,int);
void single_capture(char board[ROW_SIZE][BOARD_SIZE],int ,int ,int ,int);
void single_move(char board[ROW_SIZE][BOARD_SIZE],int ,int ,int ,int);
void swap(char board[ROW_SIZE][BOARD_SIZE],int ,int ,int ,int);
void win_by_points(char board[ROW_SIZE][BOARD_SIZE],char);
/********************************************************************************************/
int main() {
    char table[ROW_SIZE][BOARD_SIZE];
    while(play(table));
    return 0;
}
/******* Function definitions *******/
int is_move_legal(char board[ROW_SIZE][BOARD_SIZE],char pawn,int row_loc,int col_loc,int row_des,int col_des) {
    if (in_box(row_des,col_des)==0) return 0; // check if out of board
    else if (pawn == 'X') {
        if (row_des - row_loc == 1) {    // check if 1 square away
            if ((col_loc - col_des == 2 || col_des - col_loc == 2) && board[row_des][col_des] == '.') {
                return 1;
            }
            else return 0;
        }
        else if (row_des - row_loc == 2) {    // check if 2 squares away
            if ((col_loc - col_des == 4 && board[row_des - 1][col_des + 2] == 'O' && board[row_des][col_des] == '.')
                ||(col_des - col_loc == 4 && board[row_des - 1][col_des - 2] == 'O' && board[row_des][col_des] == '.')) { // left down
                return 1;
            }
            else return 0;
        }
    } // check if X move is legal
    else if (pawn == 'O') {
        if (row_loc - row_des == 1) {    // check if 1 square away
            if ((col_loc - col_des == 2 || col_des - col_loc == 2) && board[row_des][col_des] == '.') {
                return 1;
            }
            else return 0;
        }
        else if (row_loc - row_des == 2) {    // check if 2 squares away
            if ((col_loc - col_des == 4 && board[row_des + 1][col_des + 2] == 'X' && board[row_des][col_des] == '.')
            ||(col_des - col_loc == 4 && board[row_des + 1][col_des - 2] == 'X' && board[row_des][col_des] == '.')) { // left up
                return 1;
            }
            else return 0;
        }
    } // check if O move is legal
    return 0;
} // return 1 if move is legal and 0 if it is not legal

int is_pawn_moveable(char board[][BOARD_SIZE], char pawn, int row, int col)
{
    int r1_col, r2_col, l1_col, l2_col;
    r1_col = col+2;
    r2_col = col+4;
    l1_col = col-2;
    l2_col = col-4;
    int moveable=0;
    if(pawn == 'X'){
        if(r1_col>=0 && r1_col<=14) moveable = moveable+ is_move_legal(board, pawn, row, col, row+1, r1_col);
        if(r2_col>=0 && r2_col<=14 && row<6) moveable = moveable+ is_move_legal(board, pawn, row, col, row+2, r2_col);
        if(l1_col>=0 && l1_col<=14) moveable = moveable+ is_move_legal(board, pawn, row, col, row+1, l1_col);
        if(l2_col>=0 && l2_col<=14 && row<6) moveable = moveable+ is_move_legal(board, pawn, row, col, row+2, l2_col);
    }
    else if(pawn == 'O'){
        if(r1_col>=0 && r1_col<=14) moveable = moveable+ is_move_legal(board, pawn, row, col, row-1, r1_col);
        if(r2_col>=0 && r2_col<=14 && row>1) moveable = moveable+ is_move_legal(board, pawn, row, col, row-2, r2_col);
        if(l1_col>=0 && l1_col<=14) moveable = moveable+ is_move_legal(board, pawn, row, col, row-1, l1_col);
        if(l2_col>=0 && l2_col<=14 && row>1) moveable = moveable+ is_move_legal(board, pawn, row, col, row-2, l2_col);
    }
    return moveable;
}  // return 1 if pawn is moveable or return 0 if pawn is not moveable

int play_single_turn(char board[][BOARD_SIZE],char pawn)
{
    int row_loc,col_loc,row_des,col_des;
    int bad_loc_move = 1;
    printf("Player %c - Please enter pawn's location (row number followed by column number):\n",pawn);
    while(bad_loc_move) {
        scanf("%d %d", &row_loc, &col_loc);
        col_loc = 2*col_loc;
        if(row_loc==999 || col_loc==999*2) {
            printf("Player %c decided to quit!\n",pawn);
            return 2;
        }   // quit game
        else if(row_loc<0 || row_loc>7 || col_loc<0 || col_loc>=15 || (board[row_loc][col_loc]!=pawn)) {
            printf("Player %c - Bad pawn's selection please enter pawn's location again:\n",pawn);
        } // outside of board or wrong pawn selected
        /*else if(board[row_loc][col_loc]!=pawn) {
            printf("Player %c - Bad pawn's selection please enter pawn's location again:\n",pawn);
        } // wrong pawn selected*/
        else if(is_pawn_moveable(board, pawn, row_loc, col_loc)==0) {
            printf("This pawn has nowhere to move!\n");
            printf("Player %c - Bad pawn's selection please enter pawn's location again:\n",pawn);
        } // nowhere to move the pawn
        else bad_loc_move = 0;
    } // get input until the input is legal
    printf("Player %c - Please enter pawn's destination (row number followed by column number):\n",pawn);
    while(1) {
        scanf("%d %d", &row_des, &col_des);
        col_des = 2*col_des;
        if(is_move_legal(board,pawn, row_loc, col_loc, row_des, col_des)==0) {
            printf("Player %c - Bad pawn's destination please enter pawn's destination again:\n",pawn);
        } // bad pawn destination
        else {
            return (move_pawn(board,pawn,row_loc,col_loc,row_des,col_des));
        }
    }
} //return 0 if move was successful, return 1 if there was a capture, return 2 if the game is finished

int play(char board[][BOARD_SIZE])
{
    printf("Lets play Draughts!\n");
    int points_X=0,points_O=0,state,turn=1;
    char pawn;
    place_pawns(board);
    while(1) {
        print_turn(turn);
        print_board(board);
        pawn = which_turn(turn);
        state = play_single_turn(board,pawn);
        if(state==2) {
            print_board(board);
            return another_game();
        } // game is finished, return 0 to finish or 1 to play again
        if(state==1) {
            if(pawn=='X') {
                points_X++;
                if(points_X==12) {
                    win_by_points(board,pawn);
                    return another_game();
                }
            }
            else {
                points_O++;
                if(points_O==12) {
                    win_by_points(board,pawn);
                    return another_game();
                }
            }
            printf("X score:%d       O score:%d\n",points_X,points_O);
            turn++;
        } // check if game is finished by points, or another move
        else {
            printf("X score:%d       O score:%d\n",points_X,points_O);
            turn++;
        } // normal move
    } // until game is over
}

void win_by_points(char board[][BOARD_SIZE],char pawn)
{
    printf("Wooohooo! player %c Won!\n",pawn);
    print_board(board);
}

void place_pawns(char board[][BOARD_SIZE])
{
    int row,col;
    for(row=0; row<=7; row++) {
        for(col=0; col<=15; col++){
            if(row%2==1) {
                if(col%4==0){
                    if(row<=2)
                        board[row][col] = 'X';
                    else if(row>=5)
                        board[row][col] = 'O';
                    else
                        board[row][col] = '.';
                }
                else
                    board[row][col] = ' ';
            }
            if(row%2==0) {
                if ((col-2)%4==0) {
                    if (row <= 2)
                        board[row][col] = 'X';
                    else if (row >= 5)
                        board[row][col] = 'O';
                    else
                        board[row][col] = '.';
                } else
                    board[row][col] = ' ';
            }
        }
    }

} // create initial board

void print_board(char board[ROW_SIZE][BOARD_SIZE])
{
    int i,j;
    printf(" |0 1 2 3 4 5 6 7\n *----------------\n");
    for (i = 0; i < 8; i++) {
        printf("%d|",i);
        for (j = 0; j < 16; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
} // print current board

int move_pawn(char board[ROW_SIZE][BOARD_SIZE],char pawn,int row_loc,int col_loc,int row_des,int col_des)
{
    if(row_loc-row_des==2 || row_des-row_loc==2) {
        single_capture(board,row_loc,col_loc,row_des,col_des);
        if(row_des==0 || row_des==7){
            printf("Wooohooo! player %c Won!\n", pawn);
            return 2;
        } // player captured + game finished
        else{ //just player captured
            printf("Ho nice move! you got him...\n");
            return 1;
        }
    }  // player captured
    else {
        single_move(board,row_loc,col_loc,row_des,col_des);
        if (row_des == 0 || row_des == 7) {
            printf("Wooohooo! player %c Won!\n", pawn);
            return 2;
        } // moved one step + game finished
        else return 0; // moved one step and game isnt finished
    } // normal player move
} // make a legal move with pawn in checkers, return 0 for normal step, 1 for capture and 2 for game finished

void single_capture(char board[ROW_SIZE][BOARD_SIZE],int row_loc,int col_loc,int row_des,int col_des)
{
    int row_cap,col_cap;
    row_cap = (row_loc+row_des)/2;
    col_cap = (col_loc+col_des)/2;
    swap(board,row_loc,col_loc,row_des,col_des);
    board[row_cap][col_cap] = '.';
} // capture a single piece and update the board accordingly

void single_move(char board[ROW_SIZE][BOARD_SIZE],int row_loc,int col_loc,int row_des,int col_des)
{
    swap(board,row_loc,col_loc,row_des,col_des);
} // normal move

void swap(char board[ROW_SIZE][BOARD_SIZE],int row_loc,int col_loc,int row_des,int col_des)
{
    char temp = board[row_loc][col_loc];
    board[row_loc][col_loc] = board[row_des][col_des];
    board[row_des][col_des] = temp;
} // swap between location and destination

char which_turn(int turn)
{
    if (turn%2==1) {
        return 'X';
    }
    else return 'O';
} // change between 'X' and 'O' each turn

int another_game()
{
    char again;
    while(1) {
        printf("Would you like to play another game?(y\\n)\n");
        while(getchar()!='\n');
        scanf("%c",&again);
        while(getchar()!='\n');
        if(again=='y') return 1;
        else if(again =='n') return 0;
    }

} // ask the player if another game or to finish

void print_turn(int turn)
{
    printf("----------Play number:%d----------\n\n",turn);
} // print turn as needed

int in_box(int row, int col)
{
    if(row>=0 && row<=7 && col>=0 && col<=14) {
        return 1;
    }
    else return 0;
} // checks if coordinates inside the board, return 1 if they are and 0 if they aren't
