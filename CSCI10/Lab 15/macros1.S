.macro decrement_mode mode_var
  // 4. Decrement the mode_var
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
  // 5. Increment the mode_var
  //    Do not increment mode_var above 3
  push  {r0-r1}

  ldr   r0, =\mode_var
  ldr   r1, [r0]

  cmp   r1, 3
  it    lo
  addlo r1, 1

  str   r1, [r0]

  pop   {r0-r1}
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
  // 6. If mode_var == 1, turn on PC2
  teq   r1, 1
  it    eq
  orreq r3, 0x4 // ---- ---- ---- 0100

_mode_2\@:
  // 7. If mode_var == 2, turn on PC3
  teq   r1, 2
  it    eq
  orreq r3, 0x8 // ---- ---- ---- 1000

_mode_3\@:
  // 8. If mode_var == 3, turn on PC2 and PC3
  teq   r1, 3
  it    eq
  orreq r3, 0xC // ---- ---- ---- 1100

_end_mode\@:
  str   r3, [r2]

  pop   {r0-r3}
.endm

.macro debounce
  push  {r0}

  mov   r0, 0xFF000
  _debounce\@:
    nop
    subs  r0, 1
    bne   _debounce\@

  pop   {r0}
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
