#include "..\include\Cell.h"

Cell::Cell(int x, int y, char block_1, char block_2) : x{x}, y{y}, block_1{block_1}, block_2{block_2} {}

Cell Cell ::copy_cell(int copied_x, int copied_y) const
{
    return Cell(x + copied_x, y + copied_y, block_1, block_2);
}

void Cell::move_cell(int move_x, int move_y)
{
    x += move_x;
    y += move_y;
}

void Cell::set_coordinates(int new_x, int new_y)
{
    x = new_x;
    y = new_y;
}

bool Cell::operator==(const Cell &object) const
{
    return (x == object.get_x() && y == object.get_y());
}