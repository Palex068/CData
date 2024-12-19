/*!
\file
\brief Заголовочный файл с объявлениями функций связанных с парсингом обьекта и
положением обьекта в осях координат
*/

#ifndef SRC_VIEWER_H
#define SRC_VIEWER_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

#define EPS 1e-6
#define __format_vertexes "v %lf %lf %lf"

/**
 * @brief перечисления осей координат, их минимальных и максимальных значений
 * @param xAxis - ось X
 * @param yAxis - ось Y
 * @param zAxis - ось Z
 */
enum Axis { xAxis, yAxis, zAxis };
enum position { xAxisMIN, xAxisMAX, yAxisMIN, yAxisMAX, zAxisMIN, zAxisMAX };

/**
 * @brief структура обьекта: вершины, линии, массив значений осей координат
 * @param positions строка с элементами
 * @param count_of_vertexes указатель на строку содержащюю параметр x
 * @return  стек с элементами
 */
typedef struct data {
  double positions[6];
  unsigned long long count_of_vertexes;
  unsigned int count_of_edges;
  double *vertexes;
  unsigned int *edges;
} object_t;

/**
 * @brief Перемещение обьекта по осям координат
 *
 * @param A обьект
 * @param number шаг перемещения
 * @param axis ось координат
 */
void moving_object_t(object_t *A, double number, int axis);

/**
 * @brief Зум(изменение масштаба обьекта относительно камеры)
 *
 * @param A обьект
 * @param number шаг масштабирования
 */

void zoom_object_t(object_t *A, double number);

/**
 * @brief Дефолтное значение размера обькета относительно виджета
 *
 * @param object обьект
 * @return масштаб
 */

double normalization_object_t(object_t *object);

/**
 * @brief Вращение обьекта по осям координат относительно точки(центра),
 * заданной в centralize_object_t
 *
 * @param A обьект
 * @param angle значение для вращения
 * @param axis ось координат
 */
void rotation_object_t(object_t *A, double angle, int axis);

/**
 * @brief Центрование обьекта
 *
 * @param object обьект
 */
void centralize_object_t(object_t *object);

/**
 * @brief Иницилизация структуры объекта
 * @details Обнуление указателей и счетчиков, выделение место для
 * вершин и рёбер. А так же выставление значений по умолчанию для
 * массива максимальных и минимальных значений осей.
 * @param data_object Структура объекта
 * @return Возвращает код успеха где 0 - успех, 1 - не успех.
 */
int init_object_t(object_t *data_object);

/**
 * @brief Функция парсинга объекта
 * @details Функция обрабатывает значение файла объекта, считывая построчно
 * каждую строку проверяет начало, валидатные строки "v " и "f ".
 * Где "v " это вершина, а "f " это полигон.
 * @param data_object Структура объекта
 * @param file_name Путь к файлу объекта
 * @return Возвращает код успеха где 0 - успех, 1 - не успех.
 */
int parsing_object_t(object_t *data_object, char *file_name);

int parsing_edges(object_t *data_object, char *input_line,
                  unsigned int *countEdgesInMalloc);

int parsing_vertexes(object_t *data_object, char *input_line,
                     unsigned int current_vertex,
                     unsigned int *countVertexesInMalloc);

/**
 * @brief Удаление объекта
 * @details Очистка выделенной памяти и обнуление счетчиков.
 * @param data_object Структура объекта
>>>>>>> develop
 */
void remove_object_t(object_t *data_object);

#ifdef __cplusplus
}
#endif

#endif  //  SRC_VIEWER_H
