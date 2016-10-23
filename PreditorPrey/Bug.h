// 25.02.2016
#ifndef BUG_H
#define BUG_H

#include "Organism.h"
#include "World.h"
#include <stddef.h>

// Bug behaviour:
//      Move: Every time step, if there is an adjacent cell occupied by an ant ...
//         ...(found in the order UP, DOWN, LEFT or RIGHT) then the bug will move ...
//         ...to that cell and eat the ant (which is then removed from the grid of cells).
//            Otherwise, the bug moves according to the same rules as the ant.
//            Note that a bug cannot eat other bugs.
//      Breed: If a bug survives for eight time steps, then at the end of the time ...
//          ...step it will spawn off a new bug in the same manner as the ant.
//      Starve: If a bug has not eaten an ant within the last three time steps, then ...
//          ...at the end of the third time step it will starve and die.
//              The bug should then be removed from the grid of cells.
// Bugs move before the ants.

class Bug: public Organism
{
    public:
        Bug (World* aWorld, int xcoord, int ycoord); //constructor
        ~Bug(); //destructor
        void move(); //move one time step
        void breed(); //breed if the ant can
        OrganismType getType() const; //get Organism type
        char representation() const; // return 'X'
        bool isDead() const; // is the bug dead ?

    protected:
        void generateOffspring(int whereX, int whereY); // generate offspring
        int eatTicks; // How long has it been since the bug has eaten an ant?
        int lifeTime; // How long has the bug been alive ?

    private:
};

#endif // BUG_H




