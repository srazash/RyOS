#include "print.h"

void kernel_main() {
    print_clear();
    print_set_colour(PRINT_COLOUR_LIGHT_GRAY, PRINT_COLOUR_BLUE);
    print_str("RyOS64 v0.0.3");
    print_newline();
    print_str("OK, baby!");
}