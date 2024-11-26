#ifndef DESKTOP_VIEW_H
#define DESKTOP_VIEW_H

#include <QKeyEvent>
#include <QMainWindow>
#include <QTimer>
#include <QWidget>

#include "../../game_params.h"
#include "./ui_desktop_view.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class DesktopView;
}
QT_END_NAMESPACE

namespace s21 {

struct DesktopInput {
    DesktopInput(UserAction_t action, bool hold);

    UserAction_t action_;
    bool hold_;
};

class DesktopView : public QMainWindow {
    Q_OBJECT

   public:
    DesktopView(QWidget *parent = nullptr);
    ~DesktopView();

    void render(GameInfo &game_info);
    DesktopInput get_input();

   signals:
    void key_pressed(DesktopInput);
    void terminate_game_pressed();

   private slots:
    void handleKeyPress();

   private:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

    Ui::DesktopView *ui;
    QTimer key_delay_timer;
    int last_key;
    UserAction_t action;
    bool hold_;
};

}  // namespace s21

#endif  // DESKTOP_VIEW_H