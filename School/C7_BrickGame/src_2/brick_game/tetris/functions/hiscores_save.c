#include <errno.h>
#include <stdio.h>

/**
 * @ingroup Functions_for_save_end_load_high_scores
 * @brief Функции сохранения результатов игры
 * @param[in] char* Имя файла
 * @param[in] int* Указатель на число
 * @return Код ошибки: Согласно errno
 */
int hi_scores_save(char *filename, int *hi_score) {
  if (!filename || !hi_score) return EINVAL;

  int code = 0;

  FILE *file = NULL;
  file = fopen(filename, "wb");

  code = (file == NULL) * EACCES;

  if (!code) {
    int count = 0;
    count = fwrite(hi_score, sizeof(int), 1, file);
    code = (count == 0) * EBADF;
  }

  if (file) fclose(file);

  return code;
}