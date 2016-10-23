// 25.02.2016
#include "Bug.h"

Bug:: Bug (World* aWorld, int xcoord, int ycoord): Organism(aWorld, xcoord, ycoord)
{
    eatTicks = 0;
    lifeTime = 0;
}

Bug:: ~Bug() {}

void Bug:: move()
{
    lifeTime++;

    if (y+1 <= (WORLDSIZE - 1) && world->getAt(x, y+1) != NULL && world->getAt(x, y+1)->getType() == ANT)
    {
        world->setAt(x, y, NULL);
        delete world->getAt(x, y+1);
        movesTo(x, y+1);
        eatTicks = 0;
    }

    else if (y-1 >= 0 && world->getAt(x, y-1) != NULL && world->getAt(x, y-1)->getType() == ANT)
    {
        world->setAt(x, y, NULL);
        delete world->getAt(x, y-1);
        movesTo(x, y-1);
        eatTicks = 0;
    }

    else if (x-1 >= 0 && world->getAt(x-1, y) != NULL && world->getAt(x-1, y)->getType() == ANT)
    {
        world->setAt(x, y, NULL);
        delete world->getAt(x-1, y);
        movesTo(x-1, y);
        eatTicks = 0;
    }

    else if (x+1 <= (WORLDSIZE - 1) && world->getAt(x+1, y) != NULL && world->getAt(x+1, y)->getType() == ANT)
    {
        world->setAt(x, y, NULL);
        delete world->getAt(x+1, y);
        movesTo(x+1, y);
        eatTicks = 0;
    }

    else
    {
        moveRandomly();
        eatTicks ++;
    }

}

void Bug:: breed()
{
    if (breedTicks >= BREED_BUGS - 1)
        breedAtAdjacentCell();

    else if (lifeTime > 0)
         breedTicks++;
}


OrganismType Bug:: getType() const
{
    return BUG;
}


char Bug:: representation() const
{
    return('X');
}


bool Bug:: isDead() const
{
    return (eatTicks >= STARVE_BUGS);

}


void Bug:: generateOffspring(int whereX, int whereY)
{
    Organism* bug = new Bug(world, whereX, whereY);
    world->setAt(whereX, whereY, bug);
}
