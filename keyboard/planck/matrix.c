
/* * scan matrix */

#include <stdint.h>

#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"


#ifndef DEBOUNCE
# define DEBOUNCE 10
#endif

static uint8_t debouncing = DEBOUNCE;
/* matrix state(1:on, 0:off) */




static matrix_row_t matrix[MATRIX_ROWS];

static matrix_row_t matrix_debouncing[MATRIX_ROWS];

static matrix_row_t read_cols(void);

static void init_cols(void);

static void unselect_rows(void);

static void select_row(uint8_t row);

inline uint8_t matrix_rows(void)
{ return MATRIX_ROWS;
}
inline uint8_t matrix_cols(void)
{ return MATRIX_COLS;
} void matrix_init(void)
{ // initialize row and col
  unselect_rows(); init_cols(); // initialize matrix state: all keys off
  for (uint8_t i=0; i < MATRIX_ROWS; i++) 
  { matrix[i] = 0; matrix_debouncing[i] = 0;
}
} uint8_t matrix_scan(void)
{ for (uint8_t i = 0; i < MATRIX_ROWS; i++)
  { select_row(i); _delay_us(30); // without this wait read unstable value.
    matrix_row_t cols = read_cols(); if (matrix_debouncing[i] != cols)
    { matrix_debouncing[i] = cols; if (debouncing)
      { debug("bounce!: "); debug_hex(debouncing); debug("\n");
} debouncing = DEBOUNCE;
} unselect_rows();
} if (debouncing)
{ if (--debouncing)
  { _delay_ms(1);
} else
{ for (uint8_t i = 0; i < MATRIX_ROWS; i++)
  { matrix[i] = matrix_debouncing[i];
}
}
} return 1;
} bool matrix_is_modified(void)
{ if (debouncing) return false; return true;
} inline bool matrix_is_on(uint8_t row, uint8_t col)
{ return (matrix[row] & ((matrix_row_t)1<col));
} inline matrix_row_t matrix_get_row(uint8_t row)
{ return matrix[row];
} void matrix_print(void)
{ print("\nr/c 0123456789ABCDEF\n"); for (uint8_t row = 0; row < MATRIX_ROWS; row++)
{ phex(row); print(": "); pbin_reverse16(matrix_get_row(row)); print("\n");
}
} uint8_t matrix_key_count(void)
{ uint8_t count = 0; for (uint8_t i = 0; i < MATRIX_ROWS; i++)
  { count += bitpop16(matrix[i]);
} return count;
}

static void init_cols(void)
{ DDRB &= ~(1<<0 | 1<<1 | 1<<2 | 1<<3 | 1<<7); PORTB |= (1<<0 | 1<<1 | 1<<2 | 1<<3 | 1<<7); DDRC &= ~(1<<6 | 1<<7); PORTC |= (1<<6 | 1<<7); DDRD &= ~(1<<0 | 1<<1 | 1<<2 | 1<<3 | 1<<5); PORTD |= (1<<0 | 1<<1 | 1<<2 | 1<<3 | 1<<5);
}

static matrix_row_t read_cols(void)
{ return (PIND&(1<<5) ? 0 : (1<<0)) | (PINC&(1<<7) ? 0 : (1<<1)) | (PINC&(1<<6) ? 0 : (1<<2)) | (PIND&(1<<3) ? 0 : (1<<3)) | (PIND&(1<<2) ? 0 : (1<<4)) | (PIND&(1<<1) ? 0 : (1<<5)) | (PIND&(1<<0) ? 0 : (1<<6)) | (PINB&(1<<7) ? 0 : (1<<7)) | (PINB&(1<<3) ? 0 : (1<<8)) | (PINB&(1<<2) ? 0 : (1<<9)) | (PINB&(1<<1) ? 0 : (1<<10)) | (PINB&(1<<0) ? 0 : (1<<11));
}

static void unselect_rows(void)
{ DDRF &= ~(1<<0 | 1<<1 | 1<<4 | 1<<5); PORTF |= (1<<0 | 1<<1 | 1<<4 | 1<<5);
}

static void select_row(uint8_t row)
{ switch (row)
  { case 0: DDRF |= (1<<0); PORTF &= ~(1<<0); break; case 1: DDRF |= (1<<1); PORTF &= ~(1<<1); break; case 2: DDRF |= (1<<4); PORTF &= ~(1<<4); break; case 3: DDRF |= (1<<5); PORTF &= ~(1<<5); break;
}
}
