#include "test.h"

namespace s21 {

TEST(SnakeTest, Tests) {
    s21::SnakeGame game;

    s21::GameInfo& game_info = game.updateCurrentState();
    EXPECT_TRUE(game_info.level == 1);
    delete &game_info;

    EXPECT_FALSE(game.game_lost());
    EXPECT_FALSE(game.game_won());

    game.userInput(s21::UserAction_t::Start, false);

    for (int i = 0; i < 15; ++i) {
        game.userInput(s21::UserAction_t::Action, false);
    }

    EXPECT_TRUE(game.game_lost());
    EXPECT_FALSE(game.game_won());

    game.initialize_game();

    game.userInput(s21::UserAction_t::Start, false);
    game.userInput(s21::UserAction_t::Action, false);
    game.userInput(s21::UserAction_t::Right, false);
    game.userInput(s21::UserAction_t::Action, false);
    game.userInput(s21::UserAction_t::Down, false);
    game.userInput(s21::UserAction_t::Action, false);
    game.userInput(s21::UserAction_t::Left, false);
    game.userInput(s21::UserAction_t::Action, false);
    game.userInput(s21::UserAction_t::Up, false);
    game.userInput(s21::UserAction_t::Action, false);

    game.userInput(s21::UserAction_t::Pause, false);
    EXPECT_TRUE((int)game.get_time_left() == -1);
    s21::GameInfo& game_info_2 = game.updateCurrentState();
    EXPECT_TRUE(game_info.level == 1);
    delete &game_info_2;
    game.userInput(s21::UserAction_t::Pause, false);

    game.update_level_and_max_score();

    game.userInput(s21::UserAction_t::Action, true);
    s21::GameInfo& game_info_3 = game.updateCurrentState();
    EXPECT_TRUE(game_info.speed == MIN_SPEED);
    delete &game_info_3;
}

TEST(TetrisTest, Tests) {
    s21::TetrisGame game;

    for (int i = 1; i < 5; ++i) {
        for (int k = 0; k < i; ++k) {
            for (int j = 0; j < FIELD_W; ++j) {
                game.field_points.push_back({j, k});
            }
        }
        game.consume_rows();
    }

    s21::GameInfo& game_info_1 = game.updateCurrentState();
    delete &game_info_1;

    game.userInput(s21::UserAction_t::Start, false);
    s21::GameInfo& game_info_2 = game.updateCurrentState();
    delete &game_info_2;

    game.userInput(s21::UserAction_t::Left, false);
    s21::GameInfo& game_info_3 = game.updateCurrentState();
    delete &game_info_3;

    game.userInput(s21::UserAction_t::Right, false);
    s21::GameInfo& game_info_4 = game.updateCurrentState();
    delete &game_info_4;

    game.userInput(s21::UserAction_t::Action, false);
    s21::GameInfo& game_info_5 = game.updateCurrentState();
    delete &game_info_5;

    game.userInput(s21::UserAction_t::Pause, false);
    s21::GameInfo& game_info_6 = game.updateCurrentState();
    delete &game_info_6;
    EXPECT_TRUE(game.get_time_left() == -1);

    game.userInput(s21::UserAction_t::Pause, false);
    s21::GameInfo& game_info_7 = game.updateCurrentState();
    delete &game_info_7;

    for (int i = 0; i < 10; ++i) {
        game.userInput(s21::UserAction_t::Left, false);
    }

    game.userInput(s21::UserAction_t::Action, false);

    for (int i = 0; i < 80; ++i) {
        game.userInput(s21::UserAction_t::Down, false);
    }

    game.score = 15000;
    game.update_level_and_max_score();
    EXPECT_TRUE(game.level == MAX_LEVEL);
    EXPECT_TRUE(game.get_max_score() == 15000);

    game.userInput(s21::UserAction_t::Down, true);
    game.userInput(s21::UserAction_t::Down, true);
    EXPECT_TRUE(game.speed == MIN_SPEED);
}

}  // namespace s21

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}