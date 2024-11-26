#include <QApplication>
#include <iostream>
#include <string>

#include "brick_game/snake/snake_game.h"
#include "brick_game/tetris/tetris_game.h"
#include "cli_controller.h"
#include "desktop_controller.h"
#include "gui/cli/cli_view.h"
#include "gui/desktop/desktop_view.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <game> <interface>\n";
        std::cerr << "Games: tetris, snake\n";
        std::cerr << "Interfaces: cli, desktop\n";
        return 1;
    }

    std::string game = argv[1];
    std::string interface = argv[2];

    if (game == "snake") {
        if (interface == "cli") {
            s21::SnakeGame model;
            s21::CLIView view;
            s21::CLIController controller(model, view);
            controller.run();
        } else if (interface == "desktop") {
            QApplication app(argc, argv);
            s21::SnakeGame model;
            s21::DesktopView view;
            s21::DesktopControllerSnake controller(model, view);
            app.exec();
        } else {
            std::cerr << "Invalid interface: " << interface << "\n";
            return 1;
        }
    } else if (game == "tetris") {
        if (interface == "cli") {
            s21::TetrisGame model;
            s21::CLIView view;
            s21::CLIController controller(model, view);
            controller.run();
        } else if (interface == "desktop") {
            QApplication app(argc, argv);
            s21::TetrisGame model;
            s21::DesktopView view;
            s21::DesktopControllerTetris controller(model, view);
            app.exec();
        } else {
            std::cerr << "Invalid interface: " << interface << "\n";
            return 1;
        }
    }

    else {
        std::cerr << "Invalid game: " << game << "\n";
        return 1;
    }

    return 0;
}
