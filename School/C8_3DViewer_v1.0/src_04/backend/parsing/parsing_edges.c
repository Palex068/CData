#include "../3d_viewer.h"

/*!
 * @brief Функция парсинга полигона
 * @details Функция идет до конца входящей строки, пока не упрется в конец.
 * Во время хода ищет цифру, если находит, то смотрит что перед ней было
 * валидатные значения " " или " -", где " " это обычный индекс вершины, а " -"
 * относительный. И далее заносит в правильном для нас виде число в массив.
 * В частности: если число первое то два числа подряд - [0] = 1, [1] = 1;
 * если число не первое то вставляется после последнего, а первое в конец -
 * [0] - 1, [1] = 0, [2] = 0, [3] = 1.
 * @param data_object Структура объекта
 * @param input_line Входящая строка
 * @param countEdgesInMalloc Число выделенного места в массиве
 * @return Возвращает количество вписанных в массив значений.
 * Меньше 6 - не успех.
 */
int parsing_edges(object_t *data_object, char *input_line,
                  unsigned int *countEdgesInMalloc) {
  unsigned int res = 0, buff_facet = 0, increment = 0,
               start_edge = data_object->count_of_edges;
  input_line++;
  while (*input_line != '\n' && *input_line != '\r' && *input_line != 0) {
    while (*input_line != '\n' && *input_line != '\r' && *input_line != 0) {
      input_line++;
      if (*input_line >= '0' && *input_line <= '9' &&
          (*(input_line - 1) == ' ' ||
           (*(input_line - 1) == '-') && (*(input_line - 2) == ' '))) {
        break;
      }
    }
    if (*input_line == '\n' || *input_line == '\r' || *input_line == 0) {
      break;
    }
    buff_facet = 0;
    increment = 0;
    if (sscanf(input_line, "%u%n", &buff_facet, &increment)) {
      res += 2;
      if (res + start_edge > *countEdgesInMalloc) {
        *countEdgesInMalloc *= 1.5;
        unsigned int *tmp = NULL;
        tmp = (unsigned int *)malloc(sizeof(unsigned int) *
                                     (*countEdgesInMalloc));
        if (tmp) {
          for (unsigned int i = 0; i < start_edge + res - 2; i++) {
            tmp[i] = data_object->edges[i];
          }
          free(data_object->edges);
          data_object->edges = NULL;
          data_object->edges = tmp;
        } else {
          res = 0;
        }
      }
      if (res) {
        data_object->edges[start_edge + res - 2] = buff_facet - 1;
        if (res != 2) {  // if not first facet
          data_object->edges[start_edge + res - 3] =
              data_object->edges[start_edge + res - 2];
        }
        data_object->edges[start_edge + res - 1] =
            data_object->edges[start_edge];
        input_line += increment;
      }
    }
    if (!res) {
      break;
    }
  }
  data_object->count_of_edges += res;
  return res;
}
