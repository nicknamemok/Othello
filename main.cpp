#include <vector>
#include <string>
#include <iostream>
#include <string>

constexpr int max_buffer = 3;

constexpr char blackPiece = 'O';
constexpr char whitePiece = '@';
constexpr char emptyPiece = ' ';

class Board
{

// protected:
public:

    enum class Piece { black=blackPiece, white=whitePiece, empty=emptyPiece };
    std::vector<std::vector<Piece>> m_board;

    const std::vector<char> topBar = {'1','2','3','4','5','6','7','8'};
    const std::vector<char> sideBar = {'A','B','C','D','E','F','G','H'};

    // Initialize board object
    // Protected to prevent instantiation outside of game
    Board(const bool mod=0)
        : m_board{8,std::vector<Piece>(8,Piece::empty)}
        { m_board[3][3] = m_board[4][4] = mod ? Piece::black : Piece::white;
          m_board[3][4] = m_board[4][3] = mod ? Piece::white : Piece::black; }


public:

    // Check from one point onwards
    bool check(int i, int j, int del_i, int del_j, Piece p, bool firstPass=0)
    {
        if ( j >= 7 ) { return 0; }
        else if ( m_board[i][j] == Piece::empty ) { return 0; }
        else if ( firstPass && m_board[i][j] == p ) { return 0; }
        else if ( !firstPass && m_board[i][j] == p ) { return 1; }
        else if ( ( firstPass && m_board[i][j] != p ) || ( !firstPass && m_board[i][j] != p ) )
        {
            if ( check(i+del_i,j+del_j,del_i,del_j,p) ) { m_board[i][j] = p; }
        }
    }


    bool place(int i, int j, Piece p)
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
    

    // Print board
    void print()
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

};

class Game: public Board
{

private:

    std::string m_name1;
    std::string m_name2;
    bool whiteTurn{ true };
    bool gameOn{ true };

public:

    Game(const std::string& name1="Player 1", const std::string& name2="Player 2")
        : m_name1{ name1}, m_name2{ name2 }, Board{} {}

    void round()
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

    bool start()
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

};

int main()
{
    Game game{};
    game.start();
    // Board::Piece p{Board::Piece::black};
    // Board::Piece p2{Board::Piece::white};
    // game.checkRight(3,3,p,true);
    // game.print();
    // game.checkRight(4,3,p2,true);
    // game.print();

}