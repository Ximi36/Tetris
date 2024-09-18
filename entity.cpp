#include "../include/entity.h"

entity::entity(Cell position) : position{position}
{
    srand(time(0));
    type = static_cast<piece_type>(rand() % 7);
}