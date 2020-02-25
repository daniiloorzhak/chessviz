#include <stdio.h>
#include <string.h>

int main()
{
    char chess_board[9][18] = {
        {"8rnbqkbnr"},
        {"7pppppppp"},
        {"6        "},
        {"5        "},
        {"4        "},
        {"3        "},
        {"2PPPPPPPP"},
        {"1RNBQKBNR"},
        {" ABCDEFGH"}
        };
    FILE *file;
    char move[8];
    int i,j, move_counter = 2;
    file = fopen("chess_match.txt", "w");
    
    while (move[0] != 'q'){
        for (i = 0; i < 9 ; i++){
            for (j = 0; j < 9 ; j++){
                printf("%c ",chess_board[i][j]);
                fprintf(file, "%c ", chess_board[i][j]);
            }
            printf("\n");
            fputs("\n", file);

        }
        printf("\n");
        printf("\n");
        printf("%d.", (move_counter/2));
        scanf("%s", move);
        if((0x40 < move[0] )&&(move[0] < 0x49)){
            chess_board['8' - move[5]][move[4] - '`'] = chess_board['8' - move[2]][move[1] - '`'];
            chess_board['8' - move[2]][move[1] - '`'] = ' ';
        }
        else {
            chess_board['8' - move[4]][move[3] - '`'] = chess_board['8' - move[1]][move[0] - '`'];
            chess_board['8' - move[1]][move[0] - '`'] = ' ';
        }
        move_counter++;
        printf("\n");
    }
    fclose(file);
    return 0;
}