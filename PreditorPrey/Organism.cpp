// 25.02.2016
#include "Organism.h"
#include "World.h"
#include <iostream>

// Create an organism at the given coordinates in the given world
Organism::Organism (World* aWorld, int xcoord, int ycoord)
{
    world = aWorld;
    x = xcoord;
    y = ycoord;
    breedTicks = 0;
    moved = false;
    world->setAt(x, y, this);
}

void Organism::setMoved (bool hasMoved)
{   // flags the organism as moved or not
    moved = hasMoved;
}

bool Organism::hasMoved() const
{  // has the organism moved or not?
    return moved;
}

// Makes a random move by calling movesTo().  Called by move() in the subclasses
void Organism::moveRandomly()
{
        Move theMove = world->randomMove();
        if (theMove == UP)
        {
            if (y+1 <= (WORLDSIZE -1) && world->getAt(x, y+1) == NULL)
                movesTo(x, y+1);
        }

        else if (theMove == DOWN)
        {
            if (y-1 >= 0 && world->getAt(x, y-1) == NULL)
                movesTo(x, y-1);
        }

        else if (theMove == RIGHT)
        {
            if (x+1 <= (WORLDSIZE-1) && world->getAt(x+1, y) == NULL)
                movesTo(x+1, y);
        }

        else if (theMove == LEFT)
        {
            if (x-1 >= 0 && world->getAt(x-1, y) == NULL)
                movesTo(x-1, y);
        }
}


void Organism::movesTo (int xNew, int yNew) // moves the organism from coordinates (x,y) to (xNew,yNew)
{
    world->setAt(xNew, yNew, this);
    world->setAt(x, y, NULL);

    x = xNew;
    y = yNew;

    setMoved(true);
}


void Organism::breedAtAdjacentCell()
{ // breeds an organism at an adjacent cell
	// Tries to produce one new organism in UP, DOWN, LEFT, or RIGHT cell (in that order)
	// Makes sure not to breed off the grid
    // This method calls the generateOffspring() method

    if (y+1 <= (WORLDSIZE - 1) && world->getAt(x, y+1) == NULL)
    {
        generateOffspring(x, y+1);
        breedTicks = 0;
    }

    else if (y-1 >= 0 && world->getAt(x, y-1) == NULL)
    {
        generateOffspring(x, y-1);
        breedTicks = 0;
    }

    else if (x-1 >= 0 && world->getAt(x-1, y) == NULL)
    {
        generateOffspring(x-1, y);
        breedTicks = 0;
    }

    else if (x+1 <= (WORLDSIZE - 1) && world->getAt(x+1, y) == NULL)
    {
        generateOffspring(x+1, y);
        breedTicks = 0;
    }

}


bool Organism::isDead() const
{ // Returns true if organism is dead, false otherwise.
    return false;
}
