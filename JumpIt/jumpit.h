// 18.02.2016
// Programming Projects 14.9
// Problem Solving With C++, 8th edition, Walter Savitch

// The game of Jump It consists of a board with n positive integers in a row except for the first column, which always contains 0.
// These numbers represent the cost to enter each column.
// The object of the game is to move from the first column to the last column with the lowest cost.
// The number in each column represents the cost to enter that column.
// You always start the game in the first column and have two types of moves.
// You can either move to the adjacent column or jump over the adjacent column to land two columns over.
// The cost of a game is the sum of the costs of the columns visited.

// Write a recursive solution to this problem that computes the lowest cost of the game and outputs this value for an arbitrarily large game board ...
// ... represented as an array.
// The program has to output the lowest cost of the sequence.

#ifndef JUMPIT_H_INCLUDED
#define JUMPIT_H_INCLUDED

int jumpIt(const int board[], int startIndex, int endIndex);

#endif // JUMPIT_H_INCLUDED
