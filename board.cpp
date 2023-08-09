#include "board.hpp"

Board::Board(int n)
{
    tab = new int*[n];
    for (int i = 0; i < n ; i++)
    {
        tab[i] = new int[n];
        for (int j = 0 ; j < n ; j++)
            tab[i][j] = 0;
    }
    this->size = n;
}

Board::~Board() {}

bool Board::checkCol()
{
    int queens;

    for (int c = 0 ; c < this->size ; c++)
    {
        queens = 0;
        for (int l = 0 ; l < this->size ; l++)
        {
            if (tab[c][l] == 'N')
                queens++;
        }
        if (queens > 1)
            return (false);
    }
    return (true);
}

bool Board::checkLine()
{
    int queens;

    for (int l = 0 ; l < this->size ; l++)
    {
        queens = 0;
        for (int c = 0 ; c < this->size ; c++)
        {
            if (tab[c][l] == 'N')
                queens++;
        }
        if (queens > 1)
            return (false);
    }
    return (true);
}

bool Board::checkUpper()
{
    int queens;
    
    for (int i = 0 ; i < this->size ; i++)
    {
        queens = 0;
        for (int c = 0, l = i ; c < this->size && l < this->size ; c++, l++)
        {
            if (tab[c][l] == 'N')
                queens++;
        }
        if (queens > 1)
            return (false);
        queens = 0;
        for (int c = 0, l = i ; c < this->size && l >= 0; c++, l--)
        {
            if (tab[c][l] == 'N')
                queens++;
        }
        if (queens > 1)
            return (false);
    }
    return (true);
}

bool Board::checkDown()
{
    int queens;
    
    for (int i = 0 ; i < this->size ; i++)
    {
        queens = 0;
        for (int c = this->size - 1, l = i ; c >= 0 && l < this->size ; c--, l++)
        {
            if (tab[c][l] == 'N')
                queens++;
        }
        if (queens > 1)
            return (false);
        queens = 0;
        for (int c = this->size - 1, l = i ; c >= 0 && l >= 0; c--, l--)
        {
            if (tab[c][l] == 'N')
                queens++;
        }
        if (queens > 1)
            return (false);
    }
    return (true);
}

bool Board::checkDiag()
{
    if (!checkUpper() || !checkDown())
        return (false);
    return (true);
}
bool Board::allCheck()
{
    if (!checkDiag() || !checkCol() || !checkLine())
        return (false);
    return (true);
}

void Board::setCell(int c, int l, int piece)
{
    this->tab[c][l] = piece;
}

int Board::getCell(int c, int l)
{
    return (this->tab[c][l]);
}

int Board::getSize()
{
    return (this->size);
}

void Board::display()
{
    for (int j = 0 ; j < this->size ; j++)
    {
        for (int i = 0 ; i < this->size ; i++)
            std::cout << (this->tab[j][i] == 'N' ? 'N' : '.') << " ";
        std::cout << std::endl;
    }
}

bool Board::isSafe(int c, int l)
{
    setCell(c, l, 'N');
    if (allCheck())
    {
        setCell(c, l, 0);
        return (true);
    }
    setCell(c, l, 0);
    return (false);
}