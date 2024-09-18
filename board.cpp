#include "..\include\board.h"

Board::Board(int width, int height)
{
    this->width = new int(width);
    this->height = new int(height);

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            all_cells.push_back(Cell(i, j));
        }
    }
}

void Board::insert_to_built_cells(std::vector<Cell> insert_cells)
{
    built_cells.insert(built_cells.end(), insert_cells.begin(), insert_cells.end());
}

void Board::refresh_board()
{
    for (auto &temp_all_cells : all_cells)
    {
        bool is_built = false;
        for (auto temp_built_cells : built_cells)
        {
            if (temp_all_cells == temp_built_cells)
            {
                is_built = true;
                temp_all_cells = temp_built_cells;
            }
        }
        // temp_all_cells.set_block_1(is_built ? 'O' : ' ');
        temp_all_cells.set_block_2(is_built ? 'O' : ' ');
    }
}

int Board::remove_row()
{
    int removed_rows{0};
    int i{1};
    while (i < *height)
    {

        int built_points_count = std::count_if(built_cells.begin(), built_cells.end(), [i](const Cell &point)
                                               { return (point.get_y() == i); });

        if (built_points_count == (*width - 2))
        {
            removed_rows++;

            // earse-remove idiom
            auto it = std::remove_if(built_cells.begin(), built_cells.end(), [i](Cell point)
                                     { return (point.get_y() == i); });
            built_cells.erase(it, built_cells.end());

            std::for_each(built_cells.begin(), built_cells.end(), [i](Cell &point)
                          {
                if (point.get_y() > i)
                    point.move_cell(0, -1); });
        }
        else
            i++;
    }

    return removed_rows;
}

Board::~Board()
{
    all_cells.clear();
    built_cells.clear();
    delete width;
    delete height;
}