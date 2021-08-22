#include <vector>
#include <iostream>
#include <string>

constexpr int max_buffer = 3;

constexpr char blackPiece = 'O';
constexpr char whitePiece = '@';
constexpr char emptyPiece = ' ';

class Board
{

protected:

    enum class Piece { black=blackPiece, white=whitePiece, empty=emptyPiece };
    std::vector<std::vector<Piece>> m_board;

    const std::vector<char> topBar = {'1','2','3','4','5','6','7','8'};
    const std::vector<char> sideBar = {'A','B','C','D','E','F','G','H'};

    // Initialize board object
    // Protected to prevent instantiation outside of game
    Board(const bool mod=0);

public:

    // Generic check function
    bool check(int i, int j, int del_i, int del_j, Piece p, bool firstPass=0);

    // Piece placement function
    bool place(int i, int j, Piece p);
    
    // Print board
    void print();

};


class Game: public Board
{

private:

    std::string m_name1;
    std::string m_name2;
    bool whiteTurn{ true };
    bool gameOn{ true };

public:

    Game(const std::string& name1="Player 1", const std::string& name2="Player 2");

    void round();

    bool start();

};
