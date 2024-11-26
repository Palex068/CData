#ifndef OPTIONS_H
#define OPTIONS_H

#include <QDialog>

#include "QSettings"

namespace Ui {
class options;
}

class options : public QDialog {
  Q_OBJECT

 public:
  explicit options(QWidget *parent = nullptr);
  ~options();
  QSettings *settings;

  int projection_type,        // Тип проекции
      edge_type,              // Тип ребра
      vertex_type;            // Тип вершины
  float background_color[4],  // Цвет фона {red, green, blue}
      edge_color[4],          // Цвет ребра {red, green, blue}
      vertex_color[4],        // Цвет вершины {red, green, blue}
      edge_width,             // Толщина ребра
      vertex_width;           // толщина вершины

 private slots:
  void on_radioButton_central_clicked();
  void saveSettings();
  void loadSettings();

  void on_button_apply_clicked();
  void on_button_cancel_clicked();
  void on_radioButton_parallel_clicked();

  void on_button_background_clicked();

  void on_button_color_vertexes_clicked();
  void on_button_color_edges_clicked();

  void on_horizontalSlider_size_vertexes_sliderMoved(int position);
  void on_horizontalSlider_wigth_edges_sliderMoved(int position);

  void on_radioButton_solid_clicked();
  void on_radioButton_dashed_clicked();

  void on_radioButton_vertex_shere_clicked();
  void on_radioButton_vertex_cube_clicked();
  void on_radioButton_vertex_nope_clicked();

 private:
  Ui::options *ui;
};

#endif  // OPTIONS_H
