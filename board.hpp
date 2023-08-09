#ifndef BOARD_H
# define BOARD_H

#include <iostream>
#include <string>

class Board
{
    public:
        Board(int n);
        ~Board();
        bool checkCol();
        bool checkLine();
        bool checkDiag();
        bool checkUpper();
        bool checkDown();
        bool allCheck();

        void setCell(int c, int l, int piece);
        int getCell(int c, int l);
        int getSize();
        void display();
        bool isSafe(int c, int l);
    
    private:
        int **tab;
        int size;
        Board();
};

#endif