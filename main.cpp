#include "boardClass.h"
#include "gameClass.h"

int main()
{

    std::string name1, name2;

    std::cout << "Enter Player 1's name: ";
    std::cin >> name1;
    std::cout << "Enter Player 2's name: ";
    std::cin >> name2;

    Game game{name1, name2};
    game.start();

    // TestClass test{};
    // test.test1();

}