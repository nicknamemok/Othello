#include <vector>
#include <iostream>
#include <string>

class Game: public Board
{

private:

    std::string m_name1;
    std::string m_name2;
    bool whiteTurn{ true };
    bool gameOn{ true };

public:

    Game(const std::string& name1="Player 1", const std::string& name2="Player 2");

    void validateInput(int& letter, int& number);
    void round();
    bool start();

};

class TestClass: public Board
{

public:

    TestClass();
    test1();

};
