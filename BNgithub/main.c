
#include <stdio.h>
#include <windows.h>

#define SIZE 10
#define STLC 218 // ┌, Single Top Left Corner
#define STRC 191 // ┐, Single Top Right Corner
#define SBLC 192 // └, Single Bottom Left Corner
#define SBRC 217 // ┘, Single Bottom Right Corner
#define SVSB 179 // │, Single Vertical Simple Border
#define SVRB 180 // ┤, Single Vertical Right Border
#define SVLB 195 // ├, Single Vertical Left Border
#define SHSB 196 // ─, Single Horizontal Simple Border
#define SHBB 193 // ┴, Single Horizontal Bottom Border
#define SHTB 194 // ┬, Single Horizontal Top Border
#define SC   197 // ┼, Single Center
#define CUBE 219


int grille[10][10] = {{13, 0,  0,  0, 0,  0, 0,  0, 0, 0},
                      {3,  0,  0,  1, 0,  0, 9,  0, 0, 0},
                      {3,  0,  0,  0, 0,  0, 0,  0, 0, 0},
                      {0,  22, 22, 0, 0,  0, 0,  0, 0, 0},
                      {0,  0,  0,  0, 1,  0, 0,  0, 0, 0},
                      {0,  0,  0,  0, -1, 0, 0,  0, 0, 0},
                      {0,  0,  0,  0, -1, 0, -1, 0, 0, 0},
                      {0,  0,  0,  0, -1, 0, 0,  0, 0, 0},
                      {0,  0,  0,  0, -1, 0, 0,  0, 0, 0},
                      {0,  0,  0,  0, 0,  0, 0,  0, 0, 0}};

//Bataille navale
//Pedro Pinto
//07.03.2019
void topborder(int top) {
    printf("     A   B   C   D   E   F   G   H   I   J     \n");
    printf("   %c", STLC);             //┌
    for (int row = 0; row < top - 1; row++) {
        printf("%c%c%c%c", SHSB, SHSB, SHSB, SHTB);         //9x ─┬
    }
    printf("%c%c%c%c\n", SHSB, SHSB, SHSB, STRC);// ─┐
}

void horizontalborder(int horizon) {
    printf("   %c", SVLB);           //\n├
    for (int row = 0; row < horizon - 1; row++) {
        printf("%c%c%c%c", SHSB, SHSB, SHSB, SC);       //9x ─┼
    }
    printf("%c%c%c%c\n", SHSB, SHSB, SHSB, SVRB);     //─┤
}

void botborder(int bot) {
    printf("   %c", SBLC);                    //\n puis └
    for (int row = 0; row < bot - 1; row++) {
        printf("%c%c%c%c", SHSB, SHSB, SHSB, SHBB);         //─┴
    }
    printf("%c%c%c%c\n", SHSB, SHSB, SHSB, SBRC);              //─┘
}

void Verticalborder(int vertical, int num) {

    printf("%2d %c", num, SVSB);                    //\n puis └
    for (int row = 0; row < vertical; row++) {

        char carAFF = ' ';
        if (grille[num - 1][row] > 10) {
            carAFF = 'X';
        }
        if (grille[num - 1][row] > 20) {
            carAFF = CUBE;
        }
        if (grille[num - 1][row] == -1) {
            carAFF = 'O';
        }
        printf(" %c %c", carAFF, SVSB);         //─┴
    }
    printf("\n");              //─┘
}

int main() {
    int top;
    int vertical;
    int horizon;
    int bot;
    int jouer;
    char tir = 5;
    printf(
            "\n"
            "        __[]__\n"
            "     __|_o_o_o\\__\n"
            "     \\\"\"\"\"\"\"\"\"\"\"/\n"
            "      \\. ..  . /\n"
            " ^^^^^^^^^^^^^^^^^^^^");                    // ASCII art bateau
    printf("\nVoici le jeu de la Bataille navale\n\n\n ");      //introduction




    printf("Voulez vous jouer ?\n");
    printf("Tappez 1 pour lancer votre partie\n");
    printf("Tappez 2 afficher les regles et apprendre a jouer\n");
    printf("Tappez 0 pour quiter le jeu\n");
    scanf("%d", &jouer);
    switch (jouer) {
        case 1:
            printf("Voila votre grille choisicez votre cible\n");
            topborder(SIZE);
            for (int row = 0; row < SIZE; row++) {          //Grille
                if (row > 0)//first line
                {
                    horizontalborder(SIZE);

                }
                Verticalborder(SIZE, row + 1);
            }
            botborder(SIZE);
            break;
        case 2:
            printf("\nRegle de la Bataille navale\n"                    //REGLERS !!
                   "On vous proposera une grille de jeu numerotee de 1 a 10 horizontalement et\nde A a J verticalement avec les bateaux suivants deja place.\n"
                   "1 croiseur (4 cases)\n"
                   "1 contre torpilleur (3 cases)\n"
                   "1 torpilleur (2 cases)\n");
            printf("vous devez a present tirer sur la grile adverse et tenter de toucher ces bateaux");
            printf("le premier joueur a elliminer tous les bateaux advers gagne le combat");
            printf("Tous a vos postes COMBAT!!\n\n");
            break;
        default:                                                        //Fin/quiter
            printf("Vous avez quiter ou mis un chiffre invalide\n");
            break;
    }

    SetConsoleOutputCP(65001); // For accented characters
    printf("\n\n\n");
    SetConsoleOutputCP(437); // For semi-graphic characters
    printf("Vos bateaux sont prets faite feu ! ! !");
    printf("donnez-moi vos coordonnees");
    scanf("%d", &tir);
int hit[5]={0,0,0,0,0};

int col=-48;
int row=-88;
}