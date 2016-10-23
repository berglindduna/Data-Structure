// 18.02.2016
#include <iostream>
#include "jumpit.h"
#include <algorithm>

using namespace std;

int jumpIt(const int board[], int startIndex, int endIndex)
{
    int a,b;

    if (startIndex < endIndex-2)
    {
        a = jumpIt(board, startIndex+1, endIndex);
        b = jumpIt(board, startIndex+2, endIndex);

        if (a < b)
            return (board[startIndex] + a);

        else
            return (board[startIndex] + b);
    }

    else
        return (board[startIndex] + board[endIndex]);
}
