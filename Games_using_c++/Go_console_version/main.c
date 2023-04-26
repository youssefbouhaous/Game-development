
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
int board[9][9]; //notre GOBAN
int prev_board[9][9]; //LE tableau pour verifier les etats c'est pour le ko
int prev_board1[9][9];
int prev_board2[9][9];
//int KoCounter=0;
bool visited[9][9];//tableau pour marquer les noeuds
int group[81][2]; //Tableau qui va contient les elements d'une chaine
int Nelements=0; // Le nombre des elements qu'on va entrer à ce group
bool ter_visited[9][9];// Tableau pour suivre les positions qui sont déja visité
int ter_group[81][2];//Tableau pour contenir les elements d'un territoire
int NUMBER_OF_ELEMENTS_IN_GROUP_TERRITORY=0;
int TerNelements=0;//c'est le nombre des elements qu'on a entré à ter_group
int capture_b=0;//le nombre des pieres capturer par le noir
int capture_w=0;//le nombre des pieres capturer par le blanc
int blacksnumber=0;//le nombre des pieres noir dans le tableau
int whitesnumber=0;//le nombre des pieres blanc dans le tableau
int score_du_black=0;
int score_du_white=6;
int tsumo2_x,tsumo2_y;



void initial_prevs(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            prev_board1[i][j]=-1;
            prev_board2[i][j]=-1;
        }
    }
}

//fonction que l'on appelle à la fin du jeu
void finish(){
        system("cls");
        if(score_du_black>score_du_white){
                color(12,0);
            printf("\n\n\n");
        printf("\t\t\t\t\t\t\t__|_|_|_|_|   _|    _|   _|_|_|_|   _|_|_|    _|           _|_|      _|_|_|  _|    _|   \n");
        printf("\t\t\t\t\t\t\t    _|       _|    _|   _|         _|    _|  _|         _|    _|  _|        _|  _|     \n");
        printf("\t\t\t\t\t\t\t    _|       _|_|_|_|   _|_|_|     _|_|_|    _|         _|_|_|_|  _|        _|_|        \n");
        printf("\t\t\t\t\t\t\t    _|       _|    _|   _|         _|    _|  _|         _|    _|  _|        _|  _|     \n");
        printf("\t\t\t\t\t\t\t    _|       _|    _|   _|_|_|_|   _|_|_|    _|_|_|_|   _|    _|    _|_|_|  _|    _|   \n");

        printf("\n\n\n");
        printf("\t\t\t\t\t_|_|_|     _|_|_|    _|_|_|_|_|  _|    _|   _|_|_|_|       _|          _|   _|_|_|   _|      _|   _|      _|   _|_|_|_|   _|_|_|\n");
        printf("\t\t\t\t\t  _|     _|              _|      _|    _|   _|             _|          _|     _|     _|_|    _|   _|_|    _|   _|         _|    _| \n");
        printf("\t\t\t\t\t  _|       _|_|          _|      _|_|_|_|   _|_|_|         _|    _|    _|     _|     _|  _|  _|   _|  _|  _|   _|_|_|     _|_|_|    \n");
        printf("\t\t\t\t\t  _|           _|        _|      _|    _|   _|               _|  _|  _|       _|     _|    _|_|   _|    _|_|   _|         _|    _|  \n");
        printf("\t\t\t\t\t_|_|_|   _|_|_|          _|      _|    _|   _|_|_|_|           _|  _|       _|_|_|   _|      _|   _|      _|   _|_|_|_|   _|    _|  \n");
        }
        else{
            color(11,0);
            printf("\n\n\n");
        printf("\t\t\t\t\t\t_|_|_|_|_|   _|    _|   _|_|_|_|       _|          _|   _|    _|   _|_|_|   _|_|_|_|_|   _|_|_|_| \n");
        printf("\t\t\t\t\t\t    _|       _|    _|   _|             _|          _|   _|    _|     _|         _|       _|       \n");
        printf("\t\t\t\t\t\t    _|       _|_|_|_|   _|_|_|         _|    _|    _|   _|_|_|_|     _|         _|       _|_|_|   \n");
        printf("\t\t\t\t\t\t    _|       _|    _|   _|               _|  _|  _|     _|    _|     _|         _|       _|       \n");
        printf("\t\t\t\t\t\t    _|       _|    _|   _|_|_|_|           _|  _|       _|    _|   _|_|_|       _|       _|_|_|_|  \n");
        printf("\n\n\n");
        printf("\n\n\n");
        printf("\t\t\t\t_|_|_|     _|_|_|    _|_|_|_|_|  _|    _|   _|_|_|_|       _|          _|   _|_|_|   _|      _|   _|      _|   _|_|_|_|   _|_|_|\n");
        printf("\t\t\t\t  _|     _|              _|      _|    _|   _|             _|          _|     _|     _|_|    _|   _|_|    _|   _|         _|    _| \n");
        printf("\t\t\t\t  _|       _|_|          _|      _|_|_|_|   _|_|_|         _|    _|    _|     _|     _|  _|  _|   _|  _|  _|   _|_|_|     _|_|_|    \n");
        printf("\t\t\t\t  _|           _|        _|      _|    _|   _|               _|  _|  _|       _|     _|    _|_|   _|    _|_|   _|         _|    _|  \n");
        printf("\t\t\t\t_|_|_|   _|_|_|          _|      _|    _|   _|_|_|_|           _|  _|       _|_|_|   _|      _|   _|      _|   _|_|_|_|   _|    _|  \n");
        }

        system("pause");
        replay();
        first_interface();
}


int board_backup[9][9];

//faire une copy pour aider dans le backup
void backup_board() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            board_backup[i][j] = board[i][j];
        }
    }
}






//for colors
void color(int t,int f)
{
HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(H,f*16+t);
}


//fonction qui aide à l'affichage d'une element du tableau avec un couleur
void cellcolor(int colorc){
    if(colorc==0){
        color(7,0);
        printf("  ");
        color(7,0);
    }
    if(colorc==1){
        color(12,12);
        printf("oo");
        color(7,0);
        //printf("");
    }
    if(colorc==2){
        color(11,11);
        printf("xx");
        color(7,0);
        //printf("");
    }
}

//L'INTERFACE D'ACCEUILLE

void first_interface(){
    system("cls");
    int choice;
    color(3,0);
    printf("\n\n\n");
    printf("\t\t\t\t_|_|_|_|_|   _|    _|   _|_|_|_|         _|_|_|     _|_|     _|      _|   _|_|_|_|         _|_|_    _|_|_|_|         _|_|_|     _|_|_  \n");
    printf("\t\t\t\t    _|       _|    _|   _|             _|         _|    _|   _|_|  _|_|   _|             _|    _|   _|             _|         _|    _|  \n");
    printf("\t\t\t\t    _|       _|_|_|_|   _|_|_|         _|  _|_|   _|_|_|_|   _|  _|  _|   _|_|_|         _|    _|   _|_|_|         _|  _|_|   _|    _|  \n");
    printf("\t\t\t\t    _|       _|    _|   _|             _|    _|   _|    _|   _|      _|   _|             _|    _|   _|             _|    _|   _|    _|  \n");
    printf("\t\t\t\t    _|       _|    _|   _|_|_|_|         _|_|_|   _|    _|   _|      _|   _|_|_|_|         _|_|     _|               _|_|_|     _|_|   \n");
    printf("\n\n\n");
    color(3,0);
    printf("\t\t\t\t\t\t                              ________________________________\n");
    printf("\t\t\t\t\t\t                             |                                | \n");
    printf("\t\t\t\t\t\t                             |    1 >  P L A Y vs PLAYER      |\n");
    printf("\t\t\t\t\t\t                             |________________________________|\n");
    printf("\t\t\t\t\t\t                              ________________________________\n");
    printf("\t\t\t\t\t\t                             |                                | \n");
    printf("\t\t\t\t\t\t                             |    2 > ORDINATEUR VS PLAYER    |\n");
    printf("\t\t\t\t\t\t                             |________________________________|\n");
    printf("\t\t\t\t\t\t                              ________________________________\n");
    printf("\t\t\t\t\t\t                             |                                | \n");
    printf("\t\t\t\t\t\t                             |    3 >   R U L E S             |\n");
    printf("\t\t\t\t\t\t                             |________________________________|\n");
    color(7,0);
    scanf("%d",&choice);
    if(choice==1){
        player_vs_player();
    }
    else if (choice==2){
        system("cls");
        printf("\n\n\n\n\n");
        color(3,0);
        printf("\t\t\t\t\t\t\t\t---------------------------\n");
        printf("\t\t\t\t\t\t\t\t|     1> EASY VERSION      |\n");
        printf("\t\t\t\t\t\t\t\t---------------------------\n");
        printf("\t\t\t\t\t\t\t\t---------------------------\n");
        printf("\t\t\t\t\t\t\t\t|     2> MEDIUM VERSION    |\n");
        printf("\t\t\t\t\t\t\t\t---------------------------\n");
        printf(" choose your difficulty\n");
        scanf("%d",&choice);
        if(choice==1){
            player_vs_easy_computer();
        }
        else if(choice==2){
            computer_medium_version_choice();
        }
    }
    else if(choice==3){
        rules_interface();
    }
    else{
        first_interface();
    }
}


void rules_interface(){
    system("cls");  // clear the console screen
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t                           *** WELCOME TO THE GAME OF GO ***\n");
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t||   Go is a two-player board game that originated in China more than 2,500 years ago.||\n");
    printf("\t\t\t\t\t\t\t\t||   The game is played on a board with a 19x19 grid of intersecting lines.           ||\n");
    printf("\t\t\t\t\t\t\t\t||   Each player has an effectively unlimited supply of pieces (called stones),       ||\n");
    printf("\t\t\t\t\t\t\t\t||   one taking the black stones, the other taking white.                             ||\n");
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t||   The goal of the game is to surround more territory than your opponent does.      ||\n");
    printf("\t\t\t\t\t\t\t\t||   Players take turns placing their stones on the intersections of the board.       ||\n");
    printf("\t\t\t\t\t\t\t\t||   Once a stone is placed, it cannot be moved to a different intersection.          ||\n");
    printf("\t\t\t\t\t\t\t\t||   However, if a player's stones surround their opponent's stones,                  ||\n");
    printf("\t\t\t\t\t\t\t\t||   the surrounded stones are captured and removed from the board.                   ||\n");
    printf("\t\t\t\t\t\t\t\t||   The game ends when both players pass their turn consecutively,                   ||\n");
    printf("\t\t\t\t\t\t\t\t||   or when one player resigns.\n");
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t   Good luck and have fun playing Go!\n");
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t if you want to go to the manu press 0\n");
    int x;
    scanf("%d",&x);
    if(x==0){
        first_interface();
    }
    while(x!=0){
        scanf("%d",&x);
    if(x==0){
        first_interface();
    }
    }
}



void play(){
    printf("****");
    system("pause");
    first_interface();
}


//LA FONCTION DE RECHERCHE POUR TROUVER LES ELEMENTS D'UNE CHAINE EN UTILISONS LE PRINCIPE DE LA RECHERCHE EN PROFFENDEUR DFS (DEAPTH FIRST SEARCH)

void findGroup(int x, int y, int color,int group[81][2]) {
    if (x < 0 || x >= 9 || y < 0 || y >= 9) // VIRIFICATION DE LA VALIDITE DU POSITION
        return;
    if (visited[x][y] || board[x][y] != color) // EST CE QUE LA POSITION EST DE LA MEME COLOR ET EST CE QU'ELLE N'EST PAS VISITE
        return;
    visited[x][y] = true; // APRES LA VIRRIFICATION DES CONDITIONS EN MARQUE LA POSITION COMME VISITE ET ON L'AJOUTE A SON GROUP
    group[Nelements][0]=x;
    group[Nelements][1]=y;
    Nelements++;//ON ACCREMENTE LE NOMBRE DES ELEMENTS DU GROUPE
    findGroup(x-1, y, color,group);
    findGroup(x+1, y, color,group);
    findGroup(x, y-1, color,group);
    findGroup(x, y+1, color,group);
}


//C'EST LA FONCTION RESPONSABLE DU CAPTURE

bool capture_group(int group[80][2]){
    bool we_should_capture=true; // FLAG POUR VERIFIER EST CE QU'ON DOIT CAPTURE OU NON DANS UN PREMIER TEMPS ON ASSUME QU'ON DOIT CAPTURER
    for(int i=0;i<81 && group[i][0]!=-1;i++){
        int x=group[i][0];
        int y=group[i][1];
        if(x > 0 && x < 8){
            if(y > 0 && y < 8){
                if(board[x+1][y]==0 || board[x-1][y]==0 || board[x][y+1]==0 || board[x][y-1]==0){
                    we_should_capture=false; // CAD QUE LE GROUP A UNE LIBERTIE CE QUI SIGNIFIE ON PEUT PAS CAPTURER
                }
            }
            if(y==0){
                if(board[x+1][y]==0 || board[x-1][y]==0 || board[x][y+1]==0){
                    we_should_capture=false;
                }
            }
            if(y==8){
                if(board[x+1][y]==0 || board[x-1][y]==0 || board[x][y-1]==0){
                    we_should_capture=false;
                }
            }
        }
        if(x==0){
            if(y > 0 && y < 8){
                if(board[x+1][y]==0 || board[x][y+1]==0 || board[x][y-1]==0){
                    we_should_capture=false;
                }
            }
            if(y==0){
                if(board[x+1][y]==0 || board[x][y+1]==0){
                    we_should_capture=false;
                }
            }
            if(y==8){
                if(board[x+1][y]==0 || board[x][y-1]==0){
                    we_should_capture=false;
                }
            }
        }
        if(x==8){
            if(y > 0 && y < 8){
                if(board[x-1][y]==0 || board[x][y+1]==0 || board[x][y-1]==0){
                    we_should_capture=false;
                }
            }
            if(y==0){
                if(board[x-1][y]==0 || board[x][y+1]==0){
                    we_should_capture=false;
                }
            }
            if(y==8){
                if(board[x-1][y]==0 || board[x][y-1]==0){
                    we_should_capture=false;
                }
            }
        }
    }

    if(we_should_capture){
        for(int i=0;i<Nelements;i++){
            board[group[i][0]][group[i][1]]=0;
        }
    }
    return we_should_capture;
}



// La fonction responsable sur le calcule du score
void calcul_score(){

}

//fonction pour vérifier est ce que un voisine est de meme couleur ou le position est valide
bool neighbor(int x, int y, int color){
    if (x < 0 || x >= 9 || y < 0 || y >= 9)
        return false;
    else if(board[x][y] == color){
        return true;
    }
    return false;
}


//fonction pour chercher le territoire a partir d'un position
void cherche_territoir(int x,int y){
    if(ter_visited[x][y]==true){
        return;
    }
    if(board[x][y]==0 && ter_visited[x][y]!=true){
    ter_visited[x][y]=true;
    ter_group[TerNelements][0]=x;
    ter_group[TerNelements][1]=y;
    TerNelements++;
    if(neighbor(x-1,y,0)){
        cherche_territoir(x-1,y);
    }
    if(neighbor(x+1,y,0)){
        cherche_territoir(x+1,y);
    }
    if(neighbor(x,y-1,0)){
        cherche_territoir(x,y-1);
    }
    if(neighbor(x,y+1,0)){
        cherche_territoir(x,y+1);
    }
    }
}



//la fonction qui calcule le territoire de chaque couleur

void calcul_territory(){

    int a=0;
    int bs=0;//flag pour indiquer est ce que le territoire est entourer par le noir
    int ws=0;//flag pour indiquer est ce que le territoire est entourer par le blanc
    int x;
    int y;
    int scoreb=0;
    int scorew=0;
    for(int j=0;j<9;j++){
            for(int t=0;t<9;t++){
                    if (ter_visited[j][t]!=true){



                            TerNelements=0;
                            bs=0;
                            ws=0;
                            cherche_territoir(j,t);
                            for(int i=0;i<TerNelements;i++)
                                {
                                        x=ter_group[i][0];
                                        y=ter_group[i][1];
                                if(neighbor(x-1,y,1)){
                                    bs=1;
                                }
                                if(neighbor(x+1,y,1)){
                                    bs=1;
                                }
                                if(neighbor(x,y-1,1)){
                                    bs=1;
                                }
                                if(neighbor(x,y+1,1)){
                                    bs=1;
                                }
                                //for white
                                if(neighbor(x-1,y,2)){
                                    ws=1;
                                }
                                if(neighbor(x+1,y,2)){
                                    ws=1;
                                }
                                if(neighbor(x,y-1,2)){
                                    ws=1;
                                }
                                if(neighbor(x,y+1,2)){
                                    ws=1;
                                }
                            }
                            if(bs==1 && ws==0){
                                scoreb=TerNelements+scoreb;
                            }
                            if(bs==0 && ws==1){
                                scorew=TerNelements+scorew;
                            }


                        }
        }
    }
    calcul_number_stones();
    score_du_black=capture_w+blacksnumber+scoreb;
    score_du_white=6+capture_b+whitesnumber+scorew;

    printf("\t\t\t\t\t\t\t\t\t\t\t\t                     -----------------------------------------\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t                    |   Blacks stones : %d White stones : %d    |\n",blacksnumber,whitesnumber);
    printf("\t\t\t\t\t\t\t\t\t\t\t\t                    |   Captured by Black : %d  By white : %d   |\n",capture_w,capture_b);
    printf("\t\t\t\t\t\t\t\t\t\t\t\t                    |   score black == %d | score white == %d.5 |\n",score_du_black,score_du_white);
    printf("\t\t\t\t\t\t\t\t\t\t\t\t                     -----------------------------------------\n");
}


void calcul_number_stones(){
    blacksnumber=0;
    whitesnumber=0;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]==1){
                blacksnumber++;
            }
            if(board[i][j]==2){
                whitesnumber++;
            }
        }
    }
}


void affichage(int board[9][9]){

    printf("\n\n\n");
    color(30,0);
    printf("\t\t\t\t\t\t\t --------------------- \n");
    printf("\t\t\t\t\t\t\t| PRESS 90 TO PASS !! |\n");
    printf("\t\t\t\t\t\t\t --------------------- \n");
    color(7,0);
    printf("\n\n\n");
    //printf("\t\t\t\t\t");
    printf("\t\t\t\t   0        1       2       3       4       5       6       7      8 \n");
    //printf("\n\n\n");
    for(int i=0;i<9;i++){
            printf("\t\t\t\t");
            printf("%d  ",i);
            for(int j=0;j<8;j++){
                cellcolor(board[i][j]);
                printf("------",board[i][j]);
            }
            //printf("%d",board[i][8]);
            cellcolor(board[i][8]);
            if(i!=8){
            printf("\n\t\t\t\t   |        |       |       |       |       |       |       |       | \n");
            printf("\t\t\t\t   |        |       |       |       |       |       |       |       | \n");
            }

        }
        printf("\n");
    calcul_territory();
    printf("\n");
}






//POUR REFRECHE DATA
void clear_visited(bool visited[9][9],int group[80][2]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            visited[i][j]=false;
            ter_visited[i][j]=false;
        }}
    for(int i=0;i<9*9;i++){
        group[i][0]=-1;
        group[i][1]=-1;
    }
    Nelements=0;
}


void affichage_group(int group[80][2]){
        for(int j=0;j<80 && group[j][0]!=-1;j++){
            printf("(%d,%d)",group[j][0],group[j][1]);
        }
}




void update_previous_board() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            prev_board[i][j] = board[i][j];
        }
    }
}

// LA REGLE DE KO


bool is_ko() {
    // Compare the current board with the two previous boards.
    bool match1 = true, match2 = true;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != prev_board2[i][j]) {
                match2 = false;
            }
        }
    }

    // If the current board matches one of the previous boards, return true.
    if (match2) {
        return true;
    } else {
        return false;
    }
}


void update_previous_boards(){
    // Shift the current board to prev_board1 and the previous board to prev_board2.
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            prev_board2[i][j] = prev_board1[i][j];
            prev_board1[i][j] = board[i][j];
        }
    }
}


void back_up_board(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            board[i][j]=prev_board1[i][j];
        }
    }
}
void back_up_board_suicide(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            board[i][j]=prev_board2[i][j];
        }
    }
}

void check_ko(){
    if(is_ko()){
        //printf("that's ko!!!!!\n");
        system("pause");
        back_up_board();
        player_vs_player();
    }
    else{
        update_previous_boards();
    }
}





void player_vs_player(){
    int black_score=0;
    int white_score=0;
    clear_visited(visited,group);
    int x,y;
    int player=1;
    int enemy=2;
    int flag=0;
    bool captured_accured=false;
    bool flag_captured_accured;
    int number_of_capturedEl=0;
    while(1){
        //backup_board();
        tryagain:
        number_of_capturedEl=0;
        captured_accured=false;
        clear_visited(visited,group);
        system("cls");
        affichage(board);
        if(player==1){
            color(12,0);
            printf("\t\t\t\t\t\t\t -------------\n");
            printf("\t\t\t\t\t\t\t|Player 1 turn| \n");
            printf("\t\t\t\t\t\t\t -------------\n");
            color(7,0);
        }
        else{
            color(11,0);
            printf("\t\t\t\t\t\t\t -------------\n");
            printf("\t\t\t\t\t\t\t|Player 2 turn| \n");
            printf("\t\t\t\t\t\t\t -------------\n");
            color(7,0);
        }
        printf("\t\t\t\t\t\t\tligne : ");

        scanf("%d",&x);
        if(flag==1 && x==90){
            finish();
        }
        if(x==90){
            flag=1;
            goto pass;
        }
        else{
            flag=0;
        }
        printf("\t\t\t\t\t\t\tcolone : ");
        scanf("%d",&y);
        /*backup_board();*/
        //check_move(x,y,player,enemy);
        if(board[x][y]==0 ){
        board[x][y]=player;
        //update_previous_boards();
        }
        else{
            color(0,4);
            printf("\n\t\t\t\t\t\tillegale move enemy is here\n");
            color(7,0);
            system("pause");
            goto tryagain;
        }
        // BLOCK 1
        clear_visited(visited,group);
        findGroup(x-1,y,enemy,group);
        captured_accured=capture_group(group);
        if(captured_accured){
        number_of_capturedEl+=Nelements;
        }

        clear_visited(visited,group);
        findGroup(x+1,y,enemy,group);
        captured_accured=capture_group(group);
        if(captured_accured){
        number_of_capturedEl+=Nelements;
        }


        clear_visited(visited,group);
        findGroup(x,y-1,enemy,group);
        captured_accured=capture_group(group);
        if(captured_accured){
        number_of_capturedEl+=Nelements;
        }


        clear_visited(visited,group);
        findGroup(x,y+1,enemy,group);
        captured_accured=capture_group(group);
        if(captured_accured){
        number_of_capturedEl+=Nelements;
        }

        // CE BLOCK EST POUR CAPTURER LE GROUP QU'ESTAIT ENTOURER
        //check_move(x,y,player,enemy);
        clear_visited(visited,group);
        findGroup(x,y,player,group);
        //check_ko();
        //CE WHILE EST POUR STOPPER LE SUICIDE
        //capture_group(group);
        bool capture_test=capture_group(group);
        printf("\ncapture test = %d\n", capture_test);
        if(capture_test || is_ko()==true){
            if(capture_test){
                color(0,4);
                printf("\t\t\t\t\t\t\t ---------------------------------  \n");
                printf("\t\t\t\t\t\t\t|  Illegal move that's a suicide  | ");color(7,0);printf("\n");color(0,4);
                printf("\t\t\t\t\t\t\t ---------------------------------  ");
                //printf("\n\t\t\t\t\t\tillegal move that's a suicide :)\n");
                color(7,0);
                printf("\n");
                printf(" ");
                back_up_board();
                }
            if (is_ko()==true){
                color(0,4);
                color(0,4);
                printf("\t\t\t\t\t\t\t ---------------  \n");
                printf("\t\t\t\t\t\t\t|  That's a ko  | ");color(7,0);printf("\n");color(0,4);
                printf("\t\t\t\t\t\t\t ---------------  ");
                //printf("\n\t\t\t\t\t\tillegal move that's a suicide :)\n");
                color(7,0);
                printf("\n");
                printf(" ");
                //printf("\n\t\t\t\t\t\tthat's a ko\n");
                color(7,0);
                printf(" ");
                back_up_board();
                }
            color(7,0);
            system("pause");
            goto tryagain;
        }
        update_previous_boards();
        system("pause");
        pass:
        if(player==1){

            capture_w+=number_of_capturedEl;

            player=2;
            enemy=1;
        }
        else{

            capture_b+=number_of_capturedEl;

            player=1;
            enemy=2;
        }
    }
}



int check_move(int x,int y,int player,int enemy){
    if(board[x][y]!=enemy ){
        board[x][y]=player;
        //update_previous_boards();
    }
    else{
        int a,b;
        printf("illegale move enemy is here");
        system("pause");

        player_vs_player();
    }
}

void player_vs_easy_computer(){
    system("cls");
    srand( time(NULL) );
    int play=rand()%2;
    int enemy=1;
    int player=play%2+1;
    int round=0;
    if(play%2==0){
        enemy=2;
        youwillbegan();
        system("pause");
        random_play_with_computer(player,enemy,round);
    }
    else{
        thecomputerwillbegan();
        system("pause");
        random_play_with_computer(player,enemy,round+1);
    }
    system("pause");
}

int numbercapturedEl=0;
bool pass_for_computer=false;
bool captured_accured=false;
void easy_play_with_computer(int player,int enemy,int round){
    clear_visited(visited,group);
    int x,y;
    affichage(board);
    if(round%2==0){
        pass_for_computer=false;
        tryagain:
        numbercapturedEl=0;
        captured_accured=false;
        clear_visited(visited,group);
        //system("cls");
        if(player==1){
            printf("\t\t\t\t\t\t\tPlayer 1 turn \n");
        }
        else{
            printf("\t\t\t\t\t\t\tPlayer 2 turn \n");
        }
        printf("ligne : \n");

        scanf("%d",&x);
        /*if(flag==1 && x==90){
            finish();
        }*/
        if(x==90){
            pass_for_computer=true;
            goto passc;
        }
        printf("colone : \n");
        scanf("%d",&y);
        /*backup_board();*/
        //check_move(x,y,player,enemy);
        if(board[x][y]==0 ){
          board[x][y]=player;
        //update_previous_boards();
        }
        else{
            printf("illegale move enemy is here");
            system("pause");
            goto tryagain;
        }
        // BLOCK 1
        clear_visited(visited,group);
        findGroup(x-1,y,enemy,group);
        captured_accured=capture_group(group);
        if(captured_accured){
        numbercapturedEl+=Nelements;
        }

        clear_visited(visited,group);
        findGroup(x+1,y,enemy,group);
        captured_accured=capture_group(group);
        if(captured_accured){
        numbercapturedEl+=Nelements;
        }


        clear_visited(visited,group);
        findGroup(x,y-1,enemy,group);
        captured_accured=capture_group(group);
        if(captured_accured){
        numbercapturedEl+=Nelements;
        }


        clear_visited(visited,group);
        findGroup(x,y+1,enemy,group);
        captured_accured=capture_group(group);
        if(captured_accured){
        numbercapturedEl+=Nelements;
        }

        // CE BLOCK EST POUR CAPTURER LE GROUP QU'ESTAIT ENTOURER
        //check_move(x,y,player,enemy);
        clear_visited(visited,group);
        findGroup(x,y,player,group);
        //check_ko();
        //CE WHILE EST POUR STOPPER LE SUICIDE
        //capture_group(group);
        bool capture_test=capture_group(group);
        printf("\ncapture test = %d\n", capture_test);
        if(capture_test || is_ko()==true){
            if(capture_test){
                printf("illegal move that's a suicide :)\n");
                back_up_board();
                }
            if (is_ko()==true){
                printf("that's a ko");
                back_up_board();
                }
            system("pause");
            goto tryagain;
        }
        update_previous_boards();
        system("pause");
        if(player==1){
            capture_w+=numbercapturedEl;
            printf("%d",capture_w);
            system("pause");
        }
        else{
            capture_b+=numbercapturedEl;
        }
        calcul_territory();
        }
    else{
            passc:
            if(pass_for_computer==true){
                printf("\n%d %d\n",score_du_black,score_du_white);
                system("pause");
                if(score_du_black>score_du_white+20 || score_du_white>score_du_black+20){
                    finish();
                }
            }
            calcul_territory();
            check_move_computer(player,enemy);
        }
    random_play_with_computer(player,enemy,round+1);
}


//int numbercapturedEl=0;
//bool captured_accured=false;
//bool pass_for_computer=false;
void random_play_with_computer(int player,int enemy,int round){
    clear_visited(visited,group);
    int x,y;
    system("cls");
    affichage(board);
    if(round%2==0){
        pass_for_computer=false;
        tryagain:
        numbercapturedEl=0;
        captured_accured=false;
        clear_visited(visited,group);
        system("cls");
        affichage(board);
        if(player==1){
            color(12,0);
            printf("\t\t\t\t\t\t\t ------------\n");
            printf("\t\t\t\t\t\t\t| YOUR TURN  | \n");
            printf("\t\t\t\t\t\t\t ------------\n");
            color(7,0);
        }
        else{
            color(11,0);
            printf("\t\t\t\t\t\t\t ------------\n");
            printf("\t\t\t\t\t\t\t| YOUR TURN  | \n");
            printf("\t\t\t\t\t\t\t ------------\n");
            color(7,0);
        }
        printf("ligne : \n");

        scanf("%d",&x);
        /*if(flag==1 && x==90){
            finish();
        }*/
        if(x==90){
            pass_for_computer=true;
            goto passc;
        }
        printf("colone : \n");
        scanf("%d",&y);
        /*backup_board();*/
        //check_move(x,y,player,enemy);
        if(board[x][y]==0 ){
        board[x][y]=player;
        //update_previous_boards();
        }
        else{
            printf("illegale move enemy is here");
            system("pause");
            goto tryagain;
        }
        // BLOCK 1
        clear_visited(visited,group);
        findGroup(x-1,y,enemy,group);
        captured_accured=capture_group(group);
        if(captured_accured){
        numbercapturedEl+=Nelements;
        }

        clear_visited(visited,group);
        findGroup(x+1,y,enemy,group);
        captured_accured=capture_group(group);
        if(captured_accured){
        numbercapturedEl+=Nelements;
        }


        clear_visited(visited,group);
        findGroup(x,y-1,enemy,group);
        captured_accured=capture_group(group);
        if(captured_accured){
        numbercapturedEl+=Nelements;
        }


        clear_visited(visited,group);
        findGroup(x,y+1,enemy,group);
        captured_accured=capture_group(group);
        if(captured_accured){
        numbercapturedEl+=Nelements;
        }

        // CE BLOCK EST POUR CAPTURER LE GROUP QU'ESTAIT ENTOURER
        //check_move(x,y,player,enemy);
        clear_visited(visited,group);
        findGroup(x,y,player,group);
        //check_ko();
        //CE WHILE EST POUR STOPPER LE SUICIDE
        //capture_group(group);
        bool capture_test=capture_group(group);
        printf("\ncapture test = %d\n", capture_test);
        if(capture_test || is_ko()==true){
            if(capture_test){
                printf("illegal move that's a suicide :)\n");
                back_up_board();
                }
            if (is_ko()==true){
                printf("that's a ko");
                back_up_board();
                }
            system("pause");
            goto tryagain;
        }
        update_previous_boards();
        system("pause");
        pass:
        if(player==1){
            capture_w+=numbercapturedEl;
            printf("%d",capture_w);
            system("pause");
        }
        else{
            capture_b+=numbercapturedEl;
        }}
    else{
            passc:
            if(pass_for_computer==true){
                printf("\n\t\t\t\t YOU MADE A PASS NOW THE COMPUTER WILL DECIDE IF HE WANT TO PASS %d %d\n",score_du_black,score_du_white);
                system("pause");
                if(score_du_black>score_du_white+20 || score_du_white>score_du_black+20){
                    printf("\t\t\t\t THE COMPUTER ALSO MADE A PASS\n");
                    system("cls");
                    finish();
                }
                else{
                    printf("\t\t\t\t THE COMPUTER REJECTED TO PASS\n");
                    system("cls");
                    pass_for_computer=false;
                    goto passe_rejected;
                }
            }
            calcul_territory();
            check_move_computer(player,enemy);
        }
    passe_rejected:
    random_play_with_computer(player,enemy,round+1);
}

void check_ko_computer(int player,int enemy){
    if(is_ko()){
        color(0,4);
        printf("\n\nthat's ko!!!!!\n\n");
        system("pause");
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                board[i][j]=board_backup[i][j];
            }
        }
        check_move_computer(player,enemy);
    }
    else{
        update_previous_boards();
    }
}
bool black_list_ilegal_move[9][9];//dans cette list on va enregistrer les positions ilegals qu'on a deja trouver pour les éviter


int check_move_computer(int player,int enemy){
    tryagain:
    srand( time(NULL) );
    int x=rand()%9;
    int y=rand()%9;
    tsumo2_x=x;
    tsumo2_y=y;
    int flag=0;// on veut pas redonner une valeur aleatoire a x et y si on n'a pas trouvé une position vide
    //alors on va parcourir due a ce position pour trouver une position vide

    for(int i=x;i<9 && flag==0;i++){
    for(int j=y;j<9 && flag==0;j++){
    if(board[i][j]==0 && board[i][j]!=player && black_list_ilegal_move[i][j]==false){
        board[i][j]=enemy;
        x=i;
        y=j;
        flag=1;}}}
    if(flag==0){
    for(int i=x;i>=0 && flag==0;i--){
    for(int j=y;j>=0 && flag==0;j--){
    if(board[i][j]==0 && board[i][j]!=player  && black_list_ilegal_move[i][j]==false){
    board[i][j]=enemy;
    flag=1;
    x=i;
    y=j;
    }}}}
        clear_visited(visited,group);
        findGroup(x-1,y,player,group);
        capture_group(group);

        clear_visited(visited,group);
        findGroup(x+1,y,player,group);
        capture_group(group);

        clear_visited(visited,group);
        findGroup(x,y-1,player,group);
        capture_group(group);

        clear_visited(visited,group);
        findGroup(x,y+1,player,group);
        capture_group(group);
        // CE BLOCK EST POUR CAPTURER LE GROUP QU'ESTAIT ENTOURER
        clear_visited(visited,group);
        findGroup(x,y,enemy,group);
        bool capture_test=capture_group(group);
        //check_ko_computer(player,enemy);
        if(capture_test || is_ko()==true){
            black_list_ilegal_move[x][y]=true;
            if(capture_test){
                back_up_board();
                goto tryagain;
                }
            if (is_ko()==true){
                back_up_board();
                goto tryagain;
                }
            //check_move_computer(player,enemy);
    }
    update_previous_boards();
}





void evaluate_board(){

}


void black_list(){
 for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
        black_list_ilegal_move[i][j]=false;
    }
 }
}

void youwillbegan(){
    color(12,0);
    printf("\n\n\n");
    printf("\t\t\t\t_|      _|     _|_|     _|    _|       _|          _|   _|_|_|   _|         _|             _|_|_|     _|_|_|_|     _|_|_|     _|_|     _|      _|  \n");
    printf("\t\t\t\t  _|  _|     _|    _|   _|    _|       _|          _|     _|     _|         _|             _|    _|   _|         _|         _|    _|   _|_|    _|  \n");
    printf("\t\t\t\t    _|       _|    _|   _|    _|       _|    _|    _|     _|     _|         _|             _|_|_|     _|_|_|     _|  _|_|   _|_|_|_|   _|  _|  _|  \n");
    printf("\t\t\t\t    _|       _|    _|   _|    _|         _|  _|  _|       _|     _|         _|             _|    _|   _|         _|    _|   _|    _|   _|    _|_|  \n");
    printf("\t\t\t\t    _|         _|_|       _|_|             _|  _|       _|_|_|   _|_|_|_|   _|_|_|_|       _|_|_|     _|_|_|_|     _|_|_|   _|    _|   _|      _|  \n");
    printf("\n\n\n");
    color(7,0);
}
void thecomputerwillbegan(){
    color(11,0);
    printf("\n\n\n");
    printf("\t\t\t\t _|_|_|       _|_|_|       _|          _|   _|_|_|   _|         _|             _|_|_|     _|_|_|_|     _|_|_|     _|_|     _|      _|  \n");
    printf("\t\t\t\t _|    _|   _|             _|          _|     _|     _|         _|             _|    _|   _|         _|         _|    _|   _|_|    _|  \n");
    printf("\t\t\t\t _|_|_|     _|             _|    _|    _|     _|     _|         _|             _|_|_|     _|_|_|     _|  _|_|   _|_|_|_|   _|  _|  _|  \n");
    printf("\t\t\t\t _|         _|               _|  _|  _|       _|     _|         _|             _|    _|   _|         _|    _|   _|    _|   _|    _|_|  \n");
    printf("\t\t\t\t _|           _|_|_|           _|  _|       _|_|_|   _|_|_|_|   _|_|_|_|       _|_|_|     _|_|_|_|     _|_|_|   _|    _|   _|      _|  \n");
    printf("\n\n\n");
    color(7,0);
}


void computer_medium_version_choice(){
    system("cls");
    black_list();
    srand( time(NULL) );
    int play=rand()%2;
    int enemy=1;
    int player=play%2+1;
    int round=0;
    if(play%2==0){
        enemy=2;
        youwillbegan();
        system("pause");
        /*board[1][0]=enemy;
        board[8][1]=enemy;
        board[8][7]=enemy;
        board[0][1]=player;
        board[0][2]=player;
        board[0][3]=enemy;
        board[1][1]=enemy;
        board[1][2]=enemy;*/
        computer_medium_version(player,enemy,round);
    }
    else{
        thecomputerwillbegan();
        system("pause");
        /*board[1][0]=enemy;
        board[8][1]=enemy;
        board[8][7]=enemy;
        board[0][1]=enemy;
        board[0][2]=enemy;
        board[0][3]=player;
        board[1][1]=player;
        board[1][2]=player;*/
        computer_medium_version(player,enemy,round+1);
    }
    system("pause");
    /*int first_to_play=rand()%2;
    if(first_to_play==0){
        system("cls");
        printf("\n\t\t\t\t\t\tYOU WILL BEGAN :)\n");
    }
    else{
        system("cls");
        printf("\n\t\t\t\t\t\tTHE COMPUTER WILL BEGAN :)\n");
    }*/

}


void computer_medium_version(player,enemy,round){
    clear_visited(visited,group);
    int x,y;
    system("cls");
    affichage(board);
    if(round%2==0){
        if(round%3==0){
            black_list();
        }
        pass_for_computer=false;
        tryagain:
        numbercapturedEl=0;
        captured_accured=false;
        clear_visited(visited,group);
        system("cls");
        affichage(board);
        if(player==1){
            color(12,0);
            printf("\t\t\t\t\t\t\t -------------\n");
            printf("\t\t\t\t\t\t\t|  YOUR TURN  | \n");
            printf("\t\t\t\t\t\t\t -------------\n");
            color(7,0);
        }
        else{
            color(11,0);
            printf("\t\t\t\t\t\t\t -------------\n");
            printf("\t\t\t\t\t\t\t|  YOUR TURN  | \n");
            printf("\t\t\t\t\t\t\t -------------\n");
            color(7,0);
        }
        printf("\t\t\t\t\t\t\tLigne : ");
        scanf("%d",&x);
        /*if(flag==1 && x==90){
            finish();
        }*/
        if(x==90){
            pass_for_computer=true;
            goto passc;
        }
        printf("\t\t\t\t\t\t\tColone : ");
        scanf("%d",&y);

        /*backup_board();*/
        //check_move(x,y,player,enemy);
        if(board[x][y]==0 ){
        board[x][y]=player;
        //update_previous_boards();
        }
        else{
                color(11,0);
            printf("\t\t\t\t\t\t\t -------------------------------\n");
            printf("\t\t\t\t\t\t\t|  Illegale move enemy is here  | \n");
            printf("\t\t\t\t\t\t\t -------------------------------\n");
            color(7,0);
            //printf("illegale move enemy is here");
            system("pause");
            goto tryagain;
        }
        // BLOCK 1
        clear_visited(visited,group);
        findGroup(x-1,y,enemy,group);
        captured_accured=capture_group(group);
        if(captured_accured){
        numbercapturedEl+=Nelements;
        }

        clear_visited(visited,group);
        findGroup(x+1,y,enemy,group);
        captured_accured=capture_group(group);
        if(captured_accured){
        numbercapturedEl+=Nelements;
        }


        clear_visited(visited,group);
        findGroup(x,y-1,enemy,group);
        captured_accured=capture_group(group);
        if(captured_accured){
        numbercapturedEl+=Nelements;
        }


        clear_visited(visited,group);
        findGroup(x,y+1,enemy,group);
        captured_accured=capture_group(group);
        if(captured_accured){
        numbercapturedEl+=Nelements;
        }

        // CE BLOCK EST POUR CAPTURER LE GROUP QU'ESTAIT ENTOURER
        //check_move(x,y,player,enemy);
        clear_visited(visited,group);
        findGroup(x,y,player,group);
        //check_ko();
        //CE WHILE EST POUR STOPPER LE SUICIDE
        //capture_group(group);
        bool capture_test=capture_group(group);
        printf("\ncapture test = %d\n", capture_test);
        if(capture_test || is_ko()==true){
            if(capture_test){
                color(0,4);
                printf("\t\t\t\t\t\t\t ---------------------------------  \n");
                printf("\t\t\t\t\t\t\t|  Illegal move that's a suicide  | ");color(7,0);printf("\n");color(0,4);
                printf("\t\t\t\t\t\t\t ---------------------------------  ");
                //printf("\n\t\t\t\t\t\tillegal move that's a suicide :)\n");
                color(7,0);
                //printf("illegal move that's a suicide :)\n");
                back_up_board();
                }
            if (is_ko()==true){
                color(0,4);
                printf("\t\t\t\t\t\t\t ---------------  \n");
                printf("\t\t\t\t\t\t\t|  That's a ko  | ");color(7,0);printf("\n");color(0,4);
                printf("\t\t\t\t\t\t\t ---------------  ");
                color(7,0);
                //printf("that's a ko");
                back_up_board();
                }
            system("pause");
            goto tryagain;
        }
        update_previous_boards();
        system("pause");
        pass:
        if(player==1){
            capture_w+=numbercapturedEl;
            printf("%d",capture_w);
            system("pause");
        }
        else{
            capture_b+=numbercapturedEl;
        }}
    else{

            /*
            printf("\n\t\t\t\t YOU MADE A PASS NOW THE COMPUTER WILL DECIDE IF HE WANT TO PASS %d %d\n",score_du_black,score_du_white);
                system("pause");
                if(score_du_black>score_du_white+20 || score_du_white>score_du_black+20){
                    printf("\t\t\t\t THE COMPUTER ALSO MADE A PASS\n");
                    system("cls");
                    finish();
                }
                else{
                    printf("\t\t\t\t THE COMPUTER REJECTED TO PASS\n");
                    system("cls");
                    pass_for_computer=false;
                    goto passe_rejected;

            */
            passc:
            if(pass_for_computer==true){
                printf("\n\t\t\t\t YOU MADE A PASS NOW THE COMPUTER WILL DECIDE IF HE WANT TO PASS\n");
                //printf("\n%d %d\n",score_du_black,score_du_white);
                system("pause");
                if(score_du_black>score_du_white+20 || score_du_white>score_du_black+20){
                    color(0,2);
                    printf("\t\t\t\t\t\t THE COMPUTER ALSO MADE A PASS");
                    color(7,0);
                    printf("\n");
                    system("pause");
                    finish();
                }
                else{
                    color(0,4);
                    printf("\t\t\t\t\t\t THE COMPUTER REJECTED TO PASS");
                    color(7,0);
                    printf("\n");
                    system("pause");
                    pass_for_computer=false;
                    goto passe_rejected;
                }
            }
            //calcul_territory();
            check_move_computer_medium(player,enemy);
        }
    passe_rejected:
    computer_medium_version(player,enemy,round+1);
}



int check_move_computer_medium(int player,int enemy){
    int t=tsume2(enemy,player);
    if(t==0){
        t=tsume3(enemy,player);
        if(t==0){
            t=tsume1(enemy,player);
            if(t==0){
                check_move_computer(player,enemy);
            }
        }
    }
    /*int t=tsume2(enemy,player);
    printf("\n***%d***\n",t);
    system("cls");
    if(t==0){
    tsume1(enemy,player);}*/
    int flag=0;
    int x,y;
    x=tsumo2_x;
    y=tsumo2_y;

    // on veut pas redonner une valeur aleatoire a x et y si on n'a pas trouvé une position vide
    //alors on va parcourir due a ce position pour trouver une position vide

    /*for(int i=x;i<8 && flag==0;i++){
    for(int j=y;j<9 && flag==0;j++){
    if(board[i][j]==0 && board[i][j]!=player){
        board[i][j]=enemy;
        x=i;
        y=j;
        flag=1;}}}
    if(flag==0){
    for(int i=x;i>=0 && flag==0;i--){
    for(int j=y;j>=0 && flag==0;j--){
    if(board[i][j]==0 && board[i][j]!=player){
    board[i][j]=enemy;
    flag=1;
    x=i;
    y=j;
    }}}}*/
        clear_visited(visited,group);
        findGroup(x-1,y,player,group);
        capture_group(group);

        clear_visited(visited,group);
        findGroup(x+1,y,player,group);
        capture_group(group);

        clear_visited(visited,group);
        findGroup(x,y-1,player,group);
        capture_group(group);

        clear_visited(visited,group);
        findGroup(x,y+1,player,group);
        capture_group(group);
        // CE BLOCK EST POUR CAPTURER LE GROUP QU'ESTAIT ENTOURER
        clear_visited(visited,group);
        findGroup(x,y,enemy,group);
        bool capture_test=capture_group(group);
        //check_ko_computer(player,enemy);
        if(capture_test || is_ko()==true){
            if(capture_test){
                back_up_board();
                check_move_computer(player,enemy);
                //check_move_computer_medium(player,enemy);
                }
            if (is_ko()==true){
                back_up_board();
                check_move_computer(player,enemy);
                //check_move_computer_medium(player,enemy);
                }
            //check_move_computer(player,enemy);
    }
    update_previous_boards();
}





int corners[2][24][2]={{{2,0},{2,1},{2,2},{2,3},{2,4},{2,5},{1,3},{1,4},{1,5},{0,3},{0,4},{0,5},{3,0},{3,1},{3,2},{3,3},{3,4},{3,5},{4,0},{4,1},{4,2},{4,3},{4,4},{4,5}},{{2,4},{2,5},{2,6},{2,7},{2,8},{2,3},{1,4},{1,5},{1,6},{0,4},{0,5},{0,6},{3,4},{3,5},{3,6},{3,7},{3,8},{3,3},{4,3},{4,4},{4,5},{4,6},{4,7},{4,8}}};




int tsume1(int enemy,int player){
    int x,y;
    int flag=0;
    for(int i=0;i<2 && flag==0;i++){
            for(int j=0;j<24;j++){
                x=corners[i][j][0];
                y=corners[i][j][1];
                if(board[x][y]==0 && black_list_ilegal_move[x][y]!=true){
                    black_list_ilegal_move[x][y]=true;
                    board[x][y]=enemy;
                    tsumo2_x=x;
                    tsumo2_y=y;
                    flag=1;
                    return flag;
                }
            }
    }
    check_move_computer(player,enemy);
    return flag;
}


int grouptsumo[81][2];

bool visitedTsumo[9][9];



int nm_grp=0;

void findGroupT(int x, int y, int color,int grouptsumo[81][2]) {
    if (x < 0 || x >= 9 || y < 0 || y >= 9) // VIRIFICATION DE LA VALIDITE DU POSITION
        return;
    if (visitedTsumo[x][y] || board[x][y] != color) // EST CE QUE LA POSITION EST DE LA MEME COLOR ET EST CE QU'ELLE N'EST PAS VISITE
        return;
    visitedTsumo[x][y] = true; // APRES LA VIRRIFICATION DES CONDITIONS EN MARQUE LA POSITION COMME VISITE ET ON L'AJOUTE A SON GROUP
    grouptsumo[nm_grp][0]=x;
    grouptsumo[nm_grp][1]=y;
    nm_grp++;//ON ACCREMENTE LE NOMBRE DES ELEMENTS DU GROUPE
    findGroupT(x-1, y, color,grouptsumo);
    findGroupT(x+1, y, color,grouptsumo);
    findGroupT(x, y-1, color,grouptsumo);
    findGroupT(x, y+1, color,grouptsumo);
}

bool valid_position(int x,int y){
    if(x<=8 && x>=0 && y<=8 && y>=0){
        return true;
    }
    return false;
}


bool liberties_already_counted[9][9];

int numb_liberties(int grouptsumo[81][2]) {
    int num_liberties = 0;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            liberties_already_counted[i][j]=false;
        }
    }
    for (int i = 0; i < nm_grp; i++) {
        int x = grouptsumo[i][0];
        int y = grouptsumo[i][1];
        if (valid_position(x-1,y) && liberties_already_counted[x-1][y]==false &&  board[x-1][y] == 0) {liberties_already_counted[x-1][y]=true;num_liberties++;tsumo2_x=x-1;tsumo2_y=y;}
        if (valid_position(x+1,y) && liberties_already_counted[x+1][y]==false && board[x+1][y] == 0) {liberties_already_counted[x+1][y]=true;num_liberties++;tsumo2_x=x+1;tsumo2_y=y;}
        if (valid_position(x,y-1) && liberties_already_counted[x][y-1]==false && board[x][y-1] == 0) {liberties_already_counted[x][y-1]=true;num_liberties++;tsumo2_x=x;tsumo2_y=y-1;}
        if (valid_position(x,y+1) && liberties_already_counted[x][y+1]==false && board[x][y+1] == 0) {liberties_already_counted[x][y+1]=true;num_liberties++;tsumo2_x=x;tsumo2_y=y+1;}
    }
    return num_liberties;
}

void clear_visited_for_tsumo(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            visitedTsumo[i][j]=false;
        }}
    for(int i=0;i<81;i++){
        grouptsumo[i][0]=-1;
        grouptsumo[i][1]=-1;
    }
    nm_grp=0;
}

int capture_this_group(color){
    board[tsumo2_x][tsumo2_y]=color;
    black_list_ilegal_move[tsumo2_x][tsumo2_y]=true;
    return 1;
}

int tsume2(int enemy,int player) {
    clear_visited_for_tsumo();
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            if (board[x][y] == player && visitedTsumo[x][y]!=true) {
                nm_grp = 0;
                findGroupT(x, y, player, grouptsumo);
                int num_liberties = numb_liberties(grouptsumo);
                if (num_liberties == 1) {
                    if( black_list_ilegal_move[tsumo2_x][tsumo2_y]!=true){
                    capture_this_group(enemy);
                    clear_visited_for_tsumo();
                    return 1;}
                    }
                }
            }
        }
    clear_visited_for_tsumo();
    return 0;
}

int survive_this_group(int enemy,int player){
    int x,y;
    for(int i=0;i<nm_grp;i++){
        x=grouptsumo[i][0];
        y=grouptsumo[i][1];
        if(valid_position(x-1,y) && board[x-1][y]==0){board[x-1][y]=enemy;tsumo2_x=x-1;tsumo2_y=y;black_list_ilegal_move[x-1][y]=true;return 1;}
        if(valid_position(x+1,y) && board[x+1][y]==0){board[x+1][y]=enemy;tsumo2_x=x+1;tsumo2_y=y;black_list_ilegal_move[x+1][y]=true;return 1;}
        if(valid_position(x,y-1) && board[x][y-1]==0){board[x][y-1]=enemy;tsumo2_x=x;tsumo2_y=y-1;black_list_ilegal_move[x][y-1]=true;return 1;}
        if(valid_position(x,y+1) && board[x][y+1]==0){board[x][y+1]=enemy;tsumo2_x=x;tsumo2_y=y+1;black_list_ilegal_move[x][y+1]=true;return 1;}
    }
    return 0;
}

int tsume3(int enemy,int player){
    clear_visited_for_tsumo();
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            if (board[x][y] == enemy && visitedTsumo[x][y]!=true) {
                nm_grp = 0;
                findGroupT(x, y, enemy, grouptsumo);
                int num_liberties = numb_liberties(grouptsumo);
                if (num_liberties == 1) {
                    survive_this_group(enemy,player);
                    clear_visited_for_tsumo();
                    return 1;
                    }
                }
            }
        }
    clear_visited_for_tsumo();
    return 0;
}




void make_random_move(int color) {
    srand(time(NULL)); // seed the random number generator
    int x, y;
    do {
        // select a random position on the board
        x = rand() % 9;
        y = rand() % 9;
    } while (board[x][y] != 0); // keep selecting positions until an empty one is found

    board[x][y] = color; // place a stone of the given color at the selected position
}

void replay(){
    initial_prevs();
    score_du_black=0;
    score_du_white=0;
    capture_b=0;
    capture_w=0;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            board[i][j]=0;
            prev_board[i][j]=0;
        }
    }
}


int main(){
    initial_prevs();
    replay();
    first_interface();
}
