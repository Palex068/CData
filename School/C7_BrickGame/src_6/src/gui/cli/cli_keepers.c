#include "../../../includes/brick_game/v1/gui/cli.h"

void CLI_sliInfoKeeper(GS_cli_t **cli) {
  static GS_cli_t *temp_cli = NULL;

  if (cli) {
    if (*cli) {
      temp_cli = *cli;
    } else {
      *cli = temp_cli;
    }
  }
}
