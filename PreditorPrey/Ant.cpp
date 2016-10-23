// 25.02.2016
#include "Ant.h"

Ant:: Ant (World* aWorld, int xcoord, int ycoord): Organism(aWorld, xcoord, ycoord)
{
    lifeTime = 0;
}

Ant:: ~Ant() {}

void Ant:: move()
{
    lifeTime++;
    moveRandomly();
}

void Ant:: breed()
{
    if (breedTicks >= BREED_ANTS-1)
        breedAtAdjacentCell();

    else if (lifeTime > 0)
        breedTicks ++;
}

OrganismType Ant:: getType() const
{
    return ANT;
}

char Ant:: representation() const
{
    return('o');
}

void Ant:: generateOffspring(int whereX, int whereY)
{
    Organism* ant = new Ant(world, whereX, whereY);
    world->setAt(whereX, whereY, ant);
}
