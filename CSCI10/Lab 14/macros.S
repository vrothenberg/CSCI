.macro delay

  // Use the stack to preserve/restore
  // any registers used in this macro.
  push  {r9}

  // Delay loop
  ldr     r9, =0x2B7740
_delay:
  nop
  subs	r9, 1
  bne		_delay

  pop   {r9}


.endm

// Populate array with "random-ish" numbers
// between -128 and 127.
.macro resetArray

  // Use the stack to preserve/restore
  // any registers used in this macro.
  push {r0-r1} // Protects two registers, preserves the original values in the stack

  // Using non-updating indexing
  ldr   r0, =numbers

  mov   r1, -1
  str   r1, [r0, #0]

  mov   r1, 1
  str   r1, [r0, #4]

  mov   r1, -2
  str   r1, [r0, #8]

  mov   r1, 2
  str   r1, [r0, #12]

  mov   r1, -3
  str   r1, [r0, #16]

  mov   r1, 3
  str   r1, [r0, #20]

  mov   r1, -4
  str   r1, [r0, #24]

  mov   r1, 4
  str   r1, [r0, #28]

  mov   r1, -5
  str   r1, [r0, #32]

  mov   r1, 5
  str   r1, [r0, #36]

  pop {r0-r1} // Restores registers to what they were before using stack

.endm

// Clear all of the display bits in GPIOA and GPIOB.
.macro clearbits

  // Use the stack to preserve/restore
  // any registers used in this macro.

  push {r0-r1}

  // A5 ,A6 ,A7 ,A8 ,A9
  // B8 ,B9 ,B10

  ldr   r0, =GPIOA_ODR
  ldr   r1, [r0]
  bic   r1, 0x3E0 // ---- 0011 1110 0000
  str   r1, [r0]

  ldr   r0, =GPIOB_ODR
  ldr   r1, [r0]
  bic   r1, 0x700 // ---- -111 0000 0000
  str   r1, [r0]

  pop {r0-r1}

.endm

// Display a value in binary using GPIOA and GPIOB.
.macro showbits value

  // Use the stack to preserve/restore
  // any registers used in this macro.
  push {r0-r1,r5}

  // A5 (2^0),A6 (2^1),A7 (2^2),A8 (2^3),A9 (2^4)
  // B8 (2^5),B9 (2^6),B10 (2^7)

  mov   r5, \value

  ldr   r0, =GPIOA_ODR
  ldr   r1, [r0]

  tst   r5, 0x1
  it    ne
  orrne r1, 0x20// ---- ---- --10 0000

  tst   r5, 0x2
  it    ne
  orrne r1, 0x40// ---- ---- -100 0000

  tst   r5, 0x4
  it    ne
  orrne r1, 0x80// ---- ---- 1000 0000

  tst   r5, 0x8
  it    ne
  orrne r1, 0x100// ---- ---- ---- ----

  tst   r5, 0x10
  it    ne
  orrne r1, 0x200// ---- ---- ---- ----

  str   r1, [r0]

  ldr   r0, =GPIOB_ODR
  ldr   r1, [r0]

  tst   r5, 0x20
  it    ne
  orrne r1, 0x100// ---- ---- ---- ----

  tst   r5, 0x40
  it    ne
  orrne r1, 0x200// ---- ---- ---- ----

  tst   r5, 0x80
  it    ne
  orrne r1, 0x400// ---- ---- ---- ----

  pop {r0-r1,r5}

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
