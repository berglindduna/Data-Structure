// 25.02.2016
#ifndef ANT_H
#define ANT_H

#include "Organism.h"
#include "World.h"
#include <stddef.h>

// Ant behaviour:
//      Move: Every time step, randomly try to make one move UP, DOWN, LEFT or RIGHT.
//            If the cell in the selected direction is occupied or would move the ant ...
//         ... off the grid, then the ant stays in the current cell.
//      Breed: If an ant survives for three time steps, then at the end of the third time step ...
//          ...the ant will breed.  This is simulated by creating one new ant in an empty ...
//          ... adjacent cell (found in the order UP, DOWN, LEFT or RIGHT).  If all adjacent ...
//          ... cells are occupied, breeding cannot occur in the current time step and will ...
//          ... be tried in the following time steps, until successful. When an offspring is ...
//          ... produced, the ant cannot produce an offspring until three more steps have elapsed.
// Ants move after the bugs.

class Ant: public Organism
{
    public:
        Ant (World* aWorld, int xcoord, int ycoord); //constructor
        ~Ant(); // destructor
        void move(); // move one time step forward
        void breed(); // the ant breeds if he can
        OrganismType getType() const; //return Organism type
        char representation() const; // return 'o'

    protected:
        void generateOffspring(int whereX, int whereY); // generate offspring
        int lifeTime; // how old is the ant ?

    private:
};

#endif // ANT_H











