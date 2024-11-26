#include "desktop_view.h"

namespace s21 {

DesktopView::DesktopView(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::DesktopView) {
    ui->setupUi(this);

    this->setFocus();

    connect(&key_delay_timer, &QTimer::timeout, this,
            &DesktopView::handleKeyPress);
    key_delay_timer.setSingleShot(true);

    this->show();
}

void DesktopView::render(GameInfo &game_info) {
    QGridLayout *field_layout =
        centralWidget()->findChild<QGridLayout *>("field_layout");

    if (game_info.field != nullptr) {
        for (int i = 0; i < FIELD_H; ++i) {
            for (int j = 0; j < FIELD_W; ++j) {
                QLayoutItem *item =
                    field_layout->itemAtPosition(FIELD_H - i - 1, j);
                QWidget *widget = item->widget();
                widget->setStyleSheet("background-color: white;");
            }
        }

        for (int i = 0; i < FIELD_H; ++i) {
            for (int j = 0; j < FIELD_W; ++j) {
                if (game_info.field[j][i] == 1) {
                    QLayoutItem *item =
                        field_layout->itemAtPosition(FIELD_H - i - 1, j);
                    QWidget *widget = item->widget();
                    widget->setStyleSheet("background-color: black;");
                }
            }
        }
    }

    QLCDNumber *level = this->findChild<QLCDNumber *>("level_num");
    level->display(game_info.level);

    QLCDNumber *score = this->findChild<QLCDNumber *>("score_num");
    score->display(game_info.score);

    QLCDNumber *max_score = this->findChild<QLCDNumber *>("max_score_num");
    max_score->display(game_info.max_score);

    QLCDNumber *speed = this->findChild<QLCDNumber *>("speed_num");
    speed->display(game_info.speed);

    QLabel *pause_text = this->findChild<QLabel *>("pause_text");
    if (game_info.pause == 1) {
        pause_text->setText(
            "<html><head/><body><p>GAME PAUSED</p><p>press P to "
            "resume</p></body></html>");
    } else {
        pause_text->setText("");
    }

    if (game_info.next != nullptr) {
        QLabel *next_text = this->findChild<QLabel *>("next_text");
        next_text->setText("NEXT:");

        QGridLayout *next_layout =
            centralWidget()->findChild<QGridLayout *>("next_layout");

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                QLayoutItem *item = next_layout->itemAtPosition(4 - i - 1, j);
                QWidget *widget = item->widget();

                if (game_info.next[j][i] == 1) {
                    widget->setStyleSheet("background-color: white;");
                } else {
                    widget->setStyleSheet("background-color: transparent;");
                }
            }
        }
    }
}

void DesktopView::keyPressEvent(QKeyEvent *event) {
    last_key = event->key();
    hold_ = true;
    key_delay_timer.start(DESKTOP_HOLD_TIMEOUT);
}

void DesktopView::keyReleaseEvent(QKeyEvent *event) {
    if (event->key() == last_key) {
        hold_ = false;
    }
}

void DesktopView::handleKeyPress() {
    if (last_key == Qt::Key_Right) {
        action = UserAction_t::Right;
        emit key_pressed(DesktopInput(action, hold_));
    } else if (last_key == Qt::Key_Left) {
        action = UserAction_t::Left;
        emit key_pressed(DesktopInput(action, hold_));
    } else if (last_key == Qt::Key_Up) {
        action = UserAction_t::Up;
        emit key_pressed(DesktopInput(action, hold_));
    } else if (last_key == Qt::Key_Down) {
        action = UserAction_t::Down;
        emit key_pressed(DesktopInput(action, hold_));
    } else if (last_key == Qt::Key_Space) {
        action = UserAction_t::Action;
        emit key_pressed(DesktopInput(action, hold_));
    } else if (last_key == Qt::Key_Escape) {
        action = UserAction_t::Terminate;
        emit terminate_game_pressed();
    } else if (last_key == Qt::Key_S) {
        action = UserAction_t::Start;
        emit key_pressed(DesktopInput(action, hold_));
    } else if (last_key == Qt::Key_P) {
        action = UserAction_t::Pause;
        emit key_pressed(DesktopInput(action, hold_));
    }
}

DesktopInput DesktopView::get_input() { return DesktopInput(action, hold_); }

DesktopView::~DesktopView() { delete ui; }

DesktopInput::DesktopInput(UserAction_t action, bool hold)
    : action_(action), hold_(hold) {}

}  // namespace s21
