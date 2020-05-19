.macro decrement_mode mode_var
  // 8. Decrement the mode_var
  //    Do not decrement mode_var below 0
  push {r0-r1}

  ldr   r0, =\mode_var
  ldr   r1, [r0]

  cmp   r1, 0
  it    hi
  subhi r1, 1

  str   r1, [r0]

  pop {r0-r1}
.endm

.macro increment_mode mode_var
  // 9. Increment the mode_var
  //    Do not increment mode_var above 3
  push {r0-r1}

  ldr   r0, =\mode_var
  ldr   r1, [r0]

  cmp   r1, 3
  it    lo
  addlo r1, 1

  str   r1, [r0]

  pop {r0-r1}
.endm

.macro populate_array array_var
  // 10. Populate array with the following values,
  //     in the given order : 5, 7, 3, 9, 1, 10, 2, 8, 4, 6
  push {r0-r1}

  ldr   r0, =\array_var

  mov   r1, 5
  str   r1, [r0, #0]

  mov   r1, 7
  str   r1, [r0, #4]

  mov   r1, 3
  str   r1, [r0, #8]

  mov   r1, 9
  str   r1, [r0, #12]

  mov   r1, 1
  str   r1, [r0, #16]

  mov   r1, 10
  str   r1, [r0, #20]

  mov   r1, 2
  str   r1, [r0, #24]

  mov   r1, 8
  str   r1, [r0, #28]

  mov   r1, 4
  str   r1, [r0, #32]

  mov   r1, 6
  str   r1, [r0, #36]

  pop {r0-r1}
.endm

.macro display_mode mode_var
  push  {r0-r3}

  ldr   r0, =\mode_var
  ldr   r1, [r0]

  ldr   r2, =GPIOC_ODR
  ldr   r3, [r2]

  bic   r3, 0xC

_mode_0\@:
  // nothing to display

_mode_1\@:
  teq   r1, #1
  it    ne
  bne   _mode_2\@
  orr   r3, 0x8

_mode_2\@:
  teq   r1, 2
  it    ne
  bne   _mode_3\@
  orr   r3, 0x4

_mode_3\@:
  teq   r1, 3
  it    ne
  bne   _end_mode\@
  orr   r3, 0xC

_end_mode\@:
  str   r3, [r2]

  pop   {r0-r3}
.endm

.macro debounce
  push  {r0}

  mov		r0, 0xFF000
  _debounce\@:
    nop
    subs	r0, 1
    bne		_debounce\@

  pop   {r0}
.endm

.macro display_array array_var, array_len_var, offset_var
  push  {r0-r2}

  ldr   r0, =\array_len_var
  ldr   r1, [r0]
  reset_offset \offset_var, 0
_print_array\@:
  clearbits
  showbits \array_var, \offset_var
  delay
  increment_offset \offset_var, 1
  ldr   r0, =\offset_var
  ldr   r2, [r0]
  teq   r1, r2
  it    ne
  bne   _print_array\@

  pop   {r0-r2}
.endm

.macro clearbits
  // 11. Clear PA5, PA6, PA7, PA8, PA9
  //     Clear PB8, PB9, PB10
  push {r0-r1}

  ldr   r0, =GPIOA_ODR
  ldr   r1, [r0]
  bic   r1, 0x3E0 // ---- 0011 1110 0000
  str   r1, [r0]

  ldr   r0, =GPIOB_ODR
  ldr   r1, [r0]
  bic   r1, 0x700 // ---- 0111 ---- ----
  str   r1, [r0]

  pop {r0-r1}
.endm

.macro reset_offset offset_var, val
  // 12. Set offset_var = val
  push {r0-r2}

  ldr   r0, =\offset_var
  ldr   r1, [r0]

  mov   r2, \val
  mov   r1, r2

  str   r1, [r0]

  pop {r0-r2}
.endm

.macro increment_offset offset_var, amt
  // 13. Increment offset_var += amt
  push {r0-r2}

  ldr   r0, =\offset_var
  ldr   r1, [r0]

  mov   r2, \amt
  add   r1, r2

  str   r1, [r0]

  pop {r0-r2}
.endm

.macro showbits array_var, offset_var
  push    {r0-r3}

  ldr     r1, =\array_var
  ldr     r2, =\offset_var
  ldr     r3, [r2]

  // 14. Use scaled index to load array value into r0
  //     r1 = base address
  //     r3 = index
  //     use lsl to scale to 4-bytes
  ldr   r0, [r1, r3, lsl #2]

  // GPIOA
  ldr     r1, =GPIOA_ODR
  ldr     r2, [r1]
  // A5
  tst     r0, 0x1
  it      ne
  orrne   r2, 0x20
  // A6
  tst     r0, 0x2
  it      ne
  orrne   r2, 0x40
  // A7
  tst     r0, 0x4
  it      ne
  orrne   r2, 0x80
  // A8
  tst     r0, 0x8
  it      ne
  orrne   r2, 0x100
  // A9
  tst     r0, 0x10
  it      ne
  orrne   r2, 0x200

  str     r2, [r1]

  // GPIOB
  ldr     r1, =GPIOB_ODR
  ldr     r2, [r1]
  // B8
  tst     r0, 0x20
  it      ne
  orrne   r2, 0x100
  // B9
  tst     r0, 0x40
  it      ne
  orrne   r2, 0x200
  // B10
  tst     r0, 0x80
  it      ne
  orrne   r2, 0x400

  str     r2, [r1]

  pop     {r0-r3}
.endm

.macro delay
  push    {r8}

  ldr     r8, =0x1B7740
  delay_\@:
  nop
  subs	r8, #1 // 1 clock cycle
  bne		delay_\@ // 3 clock cycles

  pop   {r8}
.endm

.macro initram
  push  {r0-r4}
  // copy data from flash to RAM
  ldr   r0, =flash_sdata
  ldr   r1, =ram_sdata
  ldr   r2, =data_size

  copy:
    ldrb  r4, [r0], 1
    strb  r4, [r1], 1
    subs  r2, r2, 1
    bne   copy

  pop   {r0-r4}
.endm
