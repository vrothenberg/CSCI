.macro delay

  // Use the stack to preserve/restore
  // any registers used in this macro.

.endm

// Populate array with "random-ish" numbers
// between -128 and 127.
.macro resetArray

  // Use the stack to preserve/restore
  // any registers used in this macro.

.endm

// Clear all of the display bits in GPIOA and GPIOB.
.macro clearbits

  // Use the stack to preserve/restore
  // any registers used in this macro.

.endm

// Display a value in binary using GPIOA and GPIOB.
.macro showbits value

  // Use the stack to preserve/restore
  // any registers used in this macro.

.endm

.macro initram
  // copy data from flash to RAM
  ldr   r0, =flash_sdata
  ldr   r1, =ram_sdata
  ldr   r2, =data_size

  copy:
    ldrb  r4, [r0], 1
    strb  r4, [r1], 1
    subs  r2, r2, 1
    bne   copy
.endm
