#include <vector>
#include <iostream>
#include <string>

constexpr char blackPiece = 'O';
constexpr char whitePiece = '@';
constexpr char emptyPiece = ' ';

class Board
{

protected:

    enum class Piece { black=blackPiece, white=whitePiece, empty=emptyPiece };

    std::vector<std::vector<Piece>> m_board;
    int m_emptyTiles{ (8*8)-4 };
    int m_blackTiles{2};
    int m_whiteTiles{2};

    const std::vector<char> topBar = {'1','2','3','4','5','6','7','8'};
    const std::vector<char> sideBar = {'A','B','C','D','E','F','G','H'};

    Board(const bool mod=0);

public:

    bool check(int i, int j, int del_i, int del_j, Piece p, bool firstPass=0);
    bool place(int i, int j, Piece p);
    void print();

};