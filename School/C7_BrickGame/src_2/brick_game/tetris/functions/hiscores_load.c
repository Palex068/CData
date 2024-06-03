#include <errno.h>
#include <stdio.h>

/**
 * @ingroup Functions_for_save_end_load_high_scores
 * @brief Функции загрузки результатов игры
 * @param[in] char* Имя файла
 * @param[in] int* Указатель на число
 * @return Код ошибки: Согласно errno
 */
int hi_scores_load(char *filename, int *hi_score) {
  if (!filename || !hi_score) return EINVAL;

  int code = 0;

  int temp = 0;
  FILE *file = NULL;
  file = fopen(filename, "rb");

  code = (file == NULL) * EACCES;

  if (!code) {
    int count = 0;
    count = fread(&temp, sizeof(int), 1, file);
    code = (count == 0) * EINVAL;
  }

  if (!code) *hi_score = temp;

  if (file) fclose(file);

  return code;
}