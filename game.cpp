#include "..\include\game.h"
#include <math.h>

Game::Game() : score{0}, during_the_game{true} {}

void Game::start_game()
{
    do
    {
        system("cls");
        board = new Board(20, 20);
        game_running();
        delete board;
    } while (do_you_want_to_play_again());
}

void Game::game_running()
{
    while (!is_game_over())
    {
        iterator = 0;

        // current_tile = tiles(Cell((board->get_width() - 1) / 2, board->get_height(), 'X', 'X'));
        V2 structure_setup;
        structure_setup.x = (board->get_width() - 1) / 2;
        structure_setup.y = board->get_height();
        Cell object_setup;
        object_setup = structure_setup;
        current_tile = tiles(object_setup);

        while (!hit_built_cells_down())
        {
            iterator = 1 - iterator;
            fall_speed = 100;
            clear_console();
            if (iterator)
            {
                current_tile.fall_down();
            }
            score += pow(board->remove_row(), 2) * 100;
            board->refresh_board();
            refresh_every_cells();
            draw_the_board();
            game_control();
            Sleep(fall_speed);
        }
    }
}

bool Game::hit_built_cells_down()
{
    auto temporary_tile = current_tile;
    temporary_tile.fall_down();

    for (const auto &next_tile : temporary_tile.get_shape())
    {
        if (next_tile.get_y() == 0)
        {
            board->insert_to_built_cells(current_tile.get_shape());
            return true;
        }

        for (const auto &built_tiles : board->get_built_cells())
        {
            if (next_tile == built_tiles)
            {
                board->insert_to_built_cells(current_tile.get_shape());
                return true;
            }
        }
    }

    return false;
}

void Game::clear_console()
{
    COORD mouse;
    mouse.X = 0;
    mouse.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mouse);
    // system(" ");
    // std::cout << "\033[J\033[0m";
}

void Game::refresh_every_cells()
{
    every_cells = board->get_all_cells();
    for (auto &temp_every_cells : every_cells)
    {
        for (auto temp_tile : current_tile.get_shape())
        {
            if (temp_every_cells == temp_tile)
            {
                temp_every_cells = temp_tile;
            }
        }
    }
    set_border_type();
}

void Game::draw_the_board()
{
    for (int i = board->get_height() - 1; i >= 0; i--)
    {
        for (int j = 0; j < board->get_width(); j++)
        {
            auto drawing = std::find(every_cells.begin(), every_cells.end(), Cell(j, i));
            if (i == board->get_height() - 1 || i == 0)
            {
                std::cout << "\033[32m" << drawing->get_block_1() << "\033[0m";
                // std::cout << drawing->get_block_1();
            }
            else
            {
                switch (drawing->get_block_2())
                {
                case '|':
                    std::cout << "\033[32m" << *drawing << "\033[0m";
                    break;
                case 'O':
                    std::cout << "\033[33m" << *drawing << "\033[0m";
                    break;
                case 'X':
                    std::cout << "\033[31m" << *drawing << "\033[0m";
                    break;
                default:
                    std::cout << drawing->get_block_2(); // << ' ';
                }
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n\nPunkty:" << score << "\n";
}

void Game::game_control()
{
    if (GetAsyncKeyState(VK_LEFT))
    {
        auto temporary_tile = current_tile;
        temporary_tile.move(left);
        if (check_collision(temporary_tile))
        {
            current_tile.move(left);
            // is_any_key_pressed = true;
        }
    }
    else if (GetAsyncKeyState(VK_RIGHT))
    {
        auto temporary_tile = current_tile;
        temporary_tile.move(right);
        if (check_collision(temporary_tile))
        {
            current_tile.move(right);
            // is_any_key_pressed = true;
        }
    }
    else if (GetAsyncKeyState(VK_UP))
    {
        auto temporary_tile = current_tile;
        temporary_tile.rotate();
        if (check_collision(temporary_tile))
        {
            current_tile.rotate();
            // is_any_key_pressed = true;
        }
    }
    else if (GetAsyncKeyState(VK_DOWN))
    {
        iterator = 0;
        fall_speed = 10;
        // is_any_key_pressed = true;
    }

    else if (GetAsyncKeyState('P') && is_any_key_pressed == true)
    {
        std::cout << "Pauza."
                  << "\n";
        system("pause");
        system("cls");
    }

    is_any_key_pressed = true;
}

bool Game::check_collision(tiles tile)
{
    for (const auto &temp_tile : tile.get_shape())
    {
        if (temp_tile.get_x() == 0 || temp_tile.get_x() == (board->get_width() - 1))
        {
            return false;
        }

        for (const auto &temp_built_cells : board->get_built_cells())
        {
            if (temp_built_cells == temp_tile)
            {
                return false;
            }
        }
    }

    return true;
}

void Game::set_border_type()
{
    for (auto &temp_cell : every_cells)
    {
        if (temp_cell.get_x() == 0 || temp_cell.get_y() == 0 || temp_cell.get_x() == board->get_width() - 1 || temp_cell.get_y() == board->get_height() - 1)
        {
            temp_cell.set_block_1('-');
            temp_cell.set_block_2('|');
        }
    }
}

bool Game::is_game_over()
{
    for (const auto &temp_cell : board->get_built_cells())
    {
        if (temp_cell.get_y() >= board->get_height() - 2)
        {
            clear_console();
            draw_the_board();
            return true;
        }
    }
    return false;
}

bool Game::do_you_want_to_play_again()
{
    std::cout << "GAME OVER"
              << "\n";
    std::cout << "Czy chcesz zagrac jeszcze raz? (t/n)"
              << "\n";
    char answer;
    bool request = false;

    do
    {
        std::cin >> answer;

        if (answer == 't')
        {
            return true;
        }
        else if (answer == 'n')
        {
            return false;
        }
        else
        {
            std::cout << "Niepoprawna odpowiedz. Sprobuj jeszcze raz."
                      << "\n";

            request = true;
        }
    } while (request);
    return false;
}

Game::~Game()
{
    every_cells.clear();
}