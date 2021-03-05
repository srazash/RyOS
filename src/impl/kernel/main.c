#include "print.h"

void kernel_main() {
    print_clear();
    print_set_colour(PRINT_COLOUR_LIGHT_GRAY, PRINT_COLOUR_BLUE);
    print_str("RyOS64: OK, baby!");
}