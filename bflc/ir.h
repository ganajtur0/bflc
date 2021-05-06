#ifndef BFLC_IR_H
#define BFLC_IR_H

#include <stdint.h>
#include <stddef.h>

#define IR_BLOCK 16

#define INSTR_PTRINC 1
#define INSTR_PTRDEC 2
#define INSTR_CELINC 3
#define INSTR_CELDEC 4
#define INSTR_JMPBEG 5
#define INSTR_JMPEND 6

typedef struct {
    uint8_t instr;
    uint32_t line;
    uint32_t column;
    size_t offset;
} instr_t;

typedef struct {
    instr_t *instrs;
    size_t len;
} ir_t;

void ir_init(ir_t *ir, size_t min);

void ir_reset(ir_t *ir, size_t min);

void ir_ensure(ir_t *ir, size_t len);

void ir_free(ir_t *ir);

#endif
