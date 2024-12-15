#ifndef C8_3DVIEWER_V1_0_1_MODEL_LOADING_H
#define C8_3DVIEWER_V1_0_1_MODEL_LOADING_H

#include "s21_3dviewer.h"

/**
 * @brief Function runner for parsing object files and writing to an object with
 * data.
 * @param filename pointer to a string with the file name
 * @param data pointer to an object with data
 * @return status code: 0 - OK, 1 - ERROR
 */
int parse_obj_file(char *filename, obj_data *data);

/**
 * @brief Allocates memory inside the object with data for data from the object
 * file.
 * @param data pointer to an object with data
 * @return status code: 0 - OK, 1 - ERROR
 */
int memory_allocation(obj_data *data);

/**
 * @brief Counts vertices and vertex indices in an object file, in order to
 * allocate memory for them later.
 * @param file pointer to obj file
 * @param data pointer to an object with data
 */
void count_vertices_and_indices(FILE *file, obj_data *data);

int my_getline(char **line, size_t *len, FILE *fp);

/**
 * @brief Free memory in a data object.
 * @param data pointer to an object with data
 */
void data_destructor(obj_data *data);

/**
 * @brief Reads vertices and vertex indices from a file and writes them to an
 * object.
 * @param file pointer to obj file
 * @param data pointer to an object with data
 * @return status code: 0 - OK, 1 - ERROR
 */
int parse_vertices_and_indices(FILE *file, obj_data *data);

/**
 * @brief A debugging helper function for printing an object with a date.
 * @param data pointer to an object with data
 */
void print_data(obj_data *data);

#endif  // C8_3DVIEWER_V1_0_1_MODEL_LOADING_H
