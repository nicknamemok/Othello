#include <vector>
#include <iostream>
#include <string>
#include "boardClass.h"
#include "gameClass.h"

Game::Game(const std::string& name1, const std::string& name2)
    : m_name1{ name1}, m_name2{ name2 }, Board{} {}

void Game::validateInput(int& letter, int& number)
{
    std::string input;
    
    do{
        std::cout << (whiteTurn ? m_name1 : m_name2) << (whiteTurn ? "'s (White)" : "'s (Black)") << " turn!\nYour move (Letter first)? ";
        std::cin >> input;
        letter = input[0]-'a' < 0 ? input[0]-'A' : input[0]-'a';
        number = input[1] - '1';
    } while( number < 0 || number > 8 || letter < 0 || letter > 8 || input.size() != 2 );
}

void Game::round()
{

    int letter, number;

    do
    {
        
        print();
        validateInput(letter, number);

    }while( !place(letter, number, whiteTurn ? Piece::white : Piece::black) );


};


bool Game::start()
{
    bool gameOn{ true };
    std::string str( 100, '\n' );
    std::cout << str;
    std::cout << "Welcome to Othello!\n";
    while(m_emptyTiles > 0)
    {

        /*
        if(possibleMoves()) { round(); }
        else { std::cout << "No possible moves, turn auto-passed!\n"; }
        */

        round();
        whiteTurn = !whiteTurn;
    }

}

TestClass::TestClass()
    : Board{}
{
    m_board[3][3] = m_board[4][4] = m_board[3][4] = m_board[4][3] = Piece::empty;
}

TestClass::test1()
{
    m_board[5][0] = m_board[6][0] = m_board[7][0] = Piece::black;
    m_board[5][1] = m_board[6][1] = m_board[7][1] = Piece::white;

    print();
    std::cout << "\n";
    place(7,2,Piece::black);
    print();
}