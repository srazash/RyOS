#include "print.h"

const static size_t NUM_COLS = 80;
const static size_t NUM_ROWS = 25;

struct Char {
    uint8_t character;
    uint8_t colour;
};

struct Char* buffer = (struct Char*) 0xb8000;
size_t col = 0;
size_t row = 0;
uint8_t colour = PRINT_COLOUR_WHITE | PRIT_COLOUR_WHITE << 4;

voud print_clear() {
    for (size_t i = 0, )
}