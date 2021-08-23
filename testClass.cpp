#include <vector>
#include <iostream>
#include <string>
#include "boardClass.h"
#include "testClass.h"

TestClass::TestClass()
    : Board{} { reset(); }

void TestClass::reset()
{
    m_board[3][3] = m_board[4][4] = m_board[3][4] = m_board[4][3] = Piece::empty;
}

bool TestClass::test1()
{
    m_board[5][0] = m_board[6][0] = m_board[7][0] = Piece::black;
    m_board[5][1] = m_board[6][1] = m_board[7][1] = Piece::white;

    place(7,2,Piece::black);

    return(m_board[6][1] == Piece::black && m_board[7][1] == Piece::black);

}

bool TestClass::runAllTests()
{
    if(test1() { return 1; }
    return 0;
}