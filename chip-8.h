/* chip-8.h */
#include <stdint.h>


#define S_WIDTH 640
#define S_HEIGHT 320
#define MEM_SIZE 0x1000
#define START_ADDR 0x200 /* Where programs start in RAM */
#define TOTAL_RAM 4096
#define RAM_LIMIT 0xE8F /* RAM limit for user programs */

typedef struct
{
    uint8_t video[64 * 32];
    uint8_t memory[MEM_SIZE];
    uint8_t V[0x10];
    uint16_t i_register;
    uint16_t pc; /* Program counter */
    uint16_t sp; /* Stack pointer */
   /* TODO: Add SDL delay timer & sound timer */
    uint16_t stack[0x10]; /* TODO: Move it to memory */
    uint8_t key[0x10]; /* Implement as bitmap? */

} chp8_t;

chp8_t * init_chip();
uint8_t chip_rand();
void execute(uint16_t op);

static const uint8_t fontset[] = {
  0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
  0x20, 0x60, 0x20, 0x20, 0x70, // 1
  0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
  0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
  0x90, 0x90, 0xF0, 0x10, 0x10, // 4
  0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
  0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
  0xF0, 0x10, 0x20, 0x40, 0x40, // 7
  0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
  0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
  0xF0, 0x90, 0xF0, 0x90, 0x90, // A
  0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
  0xF0, 0x80, 0x80, 0x80, 0xF0, // C
  0xE0, 0x90, 0x90, 0x90, 0xE0, // D
  0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
  0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};
