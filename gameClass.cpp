#include <vector>
#include <iostream>
#include <string>
#include "gameClass.h"

Board::Board(const bool mod)
    : m_board{8,std::vector<Piece>(8,Piece::empty)}
    { m_board[3][3] = m_board[4][4] = mod ? Piece::black : Piece::white;
        m_board[3][4] = m_board[4][3] = mod ? Piece::white : Piece::black; }

bool Board::check(int i, int j, int del_i, int del_j, Piece p, bool firstPass)
{
    if ( j >= 7 || j < 0 || i >= 7 || i < 0 ) { return 0; }
    else if ( m_board[i][j] == Piece::empty ) { return 0; }
    else if ( firstPass && m_board[i][j] == p ) { return 0; }
    else if ( !firstPass && m_board[i][j] == p ) { return 1; }
    else if ( ( firstPass && m_board[i][j] != p ) || ( !firstPass && m_board[i][j] != p ) )
    {
        if ( check(i+del_i,j+del_j,del_i,del_j,p) ) { m_board[i][j] = p; }
    }
}

bool Board::place(int i, int j, Piece p)
{
    bool value{ false };

    if( check(i,j+1,0,1,p,true) ) { value = true; }
    if( check(i,j-1,0,-1,p,true) ) { value = true; }
    if( check(i+1,j,1,0,p,true) ) { value = true; }
    if( check(i-1,j,-1,0,p,true) ) { value = true; }
    if( check(i+1,j-1,1,-1,p,true) ) { value = true; }
    if( check(i+1,j+1,1,1,p,true) ) { value = true; }
    if( check(i-1,j-1,-1,-1,p,true) ) { value = true; }
    if( check(i-1,j+1,-1,1,p,true) ) { value = true; }
    
    if( value ) {
        m_board[i][j] = p;
        return 1;
    }else{
        std::cout << "Invalid piece placement. Please try again.\n";
        return 0;
    }
}

void Board::print()
{
    std::cout << "   ";
    for (auto c : topBar) { std::cout << "  " << c << " ";}
    std::cout << "\n";

    for (int i{0}; i<8; ++i)
    {
    std::cout << "   ---------------------------------\n" << sideBar[i] << "  ";
        for (int j{0}; j<8; ++j)
        {
            std::cout << "| " << static_cast<char>(m_board[i][j]) << " ";
        }
        std::cout << "|\n";
    }
    std::cout << "   ---------------------------------\n";
};


Game::Game(const std::string& name1, const std::string& name2)
    : m_name1{ name1}, m_name2{ name2 }, Board{} {}

void Game::round()
{

    char letter;
    int letter2, number;

    do
    {
        // Grabbing player input
        print();
        std::cout << (whiteTurn ? m_name1 : m_name2) << (whiteTurn ? "'s (White)" : "'s (Black)") << " turn!\nLetter? ";
        std::cin >> letter;
        letter2 = letter-'a' < 0 ? letter-'A' : letter-'a';
        std::cout << "Number? ";
        std::cin >> number;
        --number;

        std::string str( 100, '\n' );
        std::cout << str;

    }while( !place(letter2, number, whiteTurn ? Piece::white : Piece::black) );

    /*
    char input[max_buffer];
    std::cin.getline (input, max_buffer,'\n');
    std::cout << input;
    std::cin.clear();
    std::cin.ignore(100,'\n');
    return;
    */

};

bool Game::start()
{
    std::string str( 100, '\n' );
    std::cout << str;
    std::cout << "Welcome to Othello!\n";
    while(gameOn)
    {
        round();
        whiteTurn = !whiteTurn;
    }

}