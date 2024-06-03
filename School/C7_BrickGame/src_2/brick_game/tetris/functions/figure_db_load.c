#include <dirent.h>
#include <errno.h>
#include <malloc.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "game_t.h"
#include "tetris.h"

/**
 * @ingroup Functions_for_manage_figures_DB
 * @brief Функция загрузки фигур в БД
 * @param[in] const char * Имя директории
 * @param[in] figures_db_t* Указатель на БД фигур
 * @return Код ошибки: Согласно errno
 */
int figure_db_load(const char *dir, figures_db_t *db) {
  int code = 0;
  DIR *directory = NULL;
  char *fullpath = NULL;

  code = (dir == NULL || db == NULL) * EINVAL;

  if (!code) {
    directory = opendir(dir);
    code = (directory == NULL) * ENOENT;
  }

  if (!code) {
    size_t pathlen = strlen(dir);
    fullpath = malloc(sizeof(char) * (pathlen + FILENAME_MAX));
    code = (fullpath == NULL) * ENOMEM;
  }

  if (!code) {
    unsigned increment = 0;
    short regular_file_t = 8;
    struct dirent *dir_entry = NULL;
    FILE *file = NULL;
    while (!code && (dir_entry = readdir(directory)) != NULL) {
      if (dir_entry->d_type == regular_file_t &&
          strstr(dir_entry->d_name, ".tet")) {
        strcpy(fullpath, dir);
        strcat(fullpath, dir_entry->d_name);
        file = fopen(fullpath, "r");
        code = (file == NULL) * EACCES;
        if (!code) code = figure_db_insert(db, increment);
        if (!code) {
          db->figures[increment] = figure_load(file);
          db->figures[increment]->id = increment;
          db->count = increment + 1;
          increment++;
        }
        if (file) fclose(file);
      }
    }
    closedir(directory);
  }
  if (fullpath) free(fullpath);

  return code;
}
