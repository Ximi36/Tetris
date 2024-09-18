#include "../include/tiles.h"

tiles::tiles(Cell position) : entity{position}
{
    // srand(time(0));
    // type = static_cast<piece_type>(rand() % 7);

    if (type == t_piece)
        shape = {position, position.copy_cell(1, 0), position.copy_cell(-1, 0), position.copy_cell(0, 1)};
    else if (type == i_piece)
        shape = {position, position.copy_cell(0, -1), position.copy_cell(0, 1), position.copy_cell(0, 2)};
    else if (type == o_piece)
        shape = {position, position.copy_cell(0, 1), position.copy_cell(1, 0), position.copy_cell(1, 1)};
    else if (type == l_piece)
        shape = {position, position.copy_cell(0, 1), position.copy_cell(0, -1), position.copy_cell(1, -1)};
    else if (type == j_piece)
        shape = {position, position.copy_cell(-1, 0), position.copy_cell(0, 1), position.copy_cell(0, 2)};
    else if (type == s_piece)
        shape = {position, position.copy_cell(-1, 0), position.copy_cell(0, 1), position.copy_cell(1, 1)};
    else if (type == z_piece)
        shape = {position, position.copy_cell(1, 0), position.copy_cell(0, 1), position.copy_cell(-1, 1)};
}

void tiles::fall_down()
{
    position + Cell(0, -1);
    for (auto &point : shape)
        point + Cell(0, -1);
}

void tiles::move(enum move_direction dir)
{
    position + Cell(dir, 0);
    for (auto &point : shape)
        point + Cell(dir, 0);
}

void tiles::rotate()
{
    for (auto &point : shape)
    {
        int point_x = point.get_x() - position.get_x();
        int point_y = point.get_y() - position.get_y();
        point.set_coordinates((-1 * point_y) + position.get_x(), point_x + position.get_y());
    }
}