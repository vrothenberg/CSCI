.macro compute_min array_var, array_len_var, offset_var, min_var
  // 3. Complete this macro to compute and store minimum
  //    value in array to variable min_var

  // min = arr[0]
  // for i = 1; i < length(arr); i++ {
  //   if arr[i] < min {
  //     min = arr[i]
  //   }
  // }

  push {r0-r5}

  ldr   r0, =\array_var
  ldr   r1, [r0] // r1 (min) = arr[0]

  reset_offset \offset_var, #1 // i = 1
_for_min_loop:
  ldr   r2, =\offset_var
  ldr   r3, [r2] // r3 is now the current value of i
  ldr   r4, [r0, r3, lsl #2] // r4 is now arr[i]

  cmp   r4, r1 // if r4 < r1 (min) ?
  it    lo
  movlo r1, r4 // r1 (min) = r4 (arr[i])

  increment_offset \offset_var, #1 // i++

  ldr   r2, =\offset_var
  ldr   r3, [r2] // r3 is i

  ldr   r4, =\array_len_var
  ldr   r5, [r4] // r5 is length(arr)

  teq   r3, r5 // if r3 (i) != r5 (length of array)
  it    ne
  bne   _for_min_loop

  // if we get here the loop has ended
  ldr   r0, =\min_var
  str   r1, [r0] // min = r1

  pop {r0-r5}
.endm

.macro compute_max array_var, array_len_var, offset_var, max_var
  // 4. Complete this macro to compute and store maximum
  //    value in array to variable max_var


    // max = arr[0]
    // for i = 1; i < length(arr); i++ {
    //   if arr[i] > min {
    //     min = arr[i]
    //   }
    // }

    push {r0-r5}

    ldr   r0, =\array_var
    ldr   r1, [r0] // r1 (max) = arr[0]

    reset_offset \offset_var, #1 // i = 1
  _for_max_loop:
    ldr   r2, =\offset_var
    ldr   r3, [r2] // r3 is now the current value of i
    ldr   r4, [r0, r3, lsl #2] // r4 is now arr[i]

    cmp   r4, r1 // if r4 > r1 (max) ?
    it    hi
    movhi r1, r4 // r1 (max) = r4 (arr[i])

    increment_offset \offset_var, #1 // i++

    ldr   r2, =\offset_var
    ldr   r3, [r2] // r3 is i

    ldr   r4, =\array_len_var
    ldr   r5, [r4] // r5 is length(arr)

    teq   r3, r5 // if r3 (i) != r5 (length of array)
    it    ne
    bne   _for_max_loop

    // if we get here the loop has ended

    ldr r0, =\max_var
    str r1, [r0]

    pop {r0-r5}
.endm

.macro compute_average array_var, array_len_var, offset_var, average_var
  // 5. Complete this macro to compute and store average
  //    value of array to variable average_var

  // sum = arr[0]
  // for i = 1; i < length(arr); i++ {
  //   sum += arr[i]
  // }
  // avg = sum / length(arr)

  push {r0-r5}

  ldr   r0, =\array_var
  ldr   r1, [r0] // r1 (sum) = arr[0]

  reset_offset \offset_var, #1 // i = 1
_for_average_loop:
  ldr   r2, =\offset_var
  ldr   r3, [r2] // r3 is now the current value of i
  ldr   r4, [r0, r3, lsl #2] // r4 is now arr[i]

  add   r1, r4

  increment_offset \offset_var, #1 // i++

  ldr   r2, =\offset_var
  ldr   r3, [r2] // r3 is i

  ldr   r4, =\array_len_var
  ldr   r5, [r4] // r5 is length(arr)

  teq   r3, r5 // if r3 (i) != r5 (length of array)
  it    ne
  bne   _for_average_loop

  // if we get here the loop has ended



  ldr   r0, =\average_var
  udiv  r1, r1, r5
  str   r1, [r0]

  pop {r0-r5}
.endm

.macro decrement_mode mode_var
  // 6. Decrement mode_var by 1. Do not go below 0.
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
  // 7. Increment mode_var by 1. Do not go above 3.
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
  // 8. Populate array with the following values,
  //    in the given order : 5, 7, 3, 9, 1, 10, 2, 8, 4, 6
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

_mode_0\@:
  teq   r1, #0
  it    eq
  beq   _end_mode\@

_mode_1\@:
  teq   r1, #1
  it    ne
  bne   _mode_2\@
  orr   r3, 0x8
  b     _end_mode\@

_mode_2\@:
  teq   r1, #2
  it    ne
  bne   _mode_3\@
  orr   r3, 0x4
  b     _end_mode\@

_mode_3\@:
  teq   r1, #3
  it    ne
  bne   _end_mode\@
  orr   r3, 0xC

_end_mode\@:
  str   r3, [r2]

  pop   {r0-r3}
.endm

.macro debounce
  push  {r0}

  mov		r0, #0xFF000
  _debounce\@:
    nop
    subs	r0, #1
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
  display_offset \array_var, \offset_var
  delay
  increment_offset \offset_var, 1
  ldr   r0, =\offset_var
  ldr   r2, [r0]
  teq   r1, r2
  it    ne
  bne   _print_array\@

  pop   {r0-r2}
.endm

.macro display_offset array_var, offset_var
  push  {r0-r3}

  ldr   r0, =\array_var
  ldr   r1, =\offset_var
  ldr   r3, [r1]
  ldr   r2, [r0, r3, lsl 2]
  showbits r2

  pop   {r0-r2}
.endm

.macro clearbits
  push  {r0-r1}

  ldr   r0, =GPIOA_ODR
  ldr   r1, [r0]
  bic   r1, 0x3E0
  str   r1, [r0]

  ldr   r0, =GPIOB_ODR
  ldr   r1, [r0]
  bic   r1, 0x740
  str   r1, [r0]

  ldr   r0, =GPIOC_ODR
  ldr   r1, [r0]
  bic   r1, 0xC
  str   r1, [r0]

  pop   {r0-r1}
.endm

.macro reset_offset offset_var, val
  push  {r0-r1}

  ldr   r0, =\offset_var
  mov   r1, \val
  str   r1, [r0]

  pop   {r0-r1}
.endm

.macro increment_offset offset_var, amt
  push  {r0-r2}

  ldr   r0, =\offset_var
  ldr   r1, [r0]
  mov   r2, \amt
  add   r1, r2
  str   r1, [r0]

  pop   {r0-r2}
.endm

.macro showvar var
  push  {r0-r1}

  ldr   r0, =\var
  ldr   r1, [r0]
  showbits r1

  pop   {r0-r1}
.endm

.macro showbits value
  push    {r0-r2}

  mov     r0, \value

  // GPIOA
  ldr     r1, =GPIOA_ODR
  ldr     r2, [r1]
  // A5
  tst     r0, 0x1
  it      ne
  orrne   r2, r2, 0x20
  // A6
  tst     r0, 0x2
  it      ne
  orrne   r2, r2, 0x40
  // A7
  tst     r0, 0x4
  it      ne
  orrne   r2, r2, 0x80
  // A8
  tst     r0, 0x8
  it      ne
  orrne   r2, r2, 0x100
  // A9
  tst     r0, 0x10
  it      ne
  orrne   r2, r2, 0x200

  str     r2, [r1]

  // GPIOB
  ldr     r1, =GPIOB_ODR
  ldr     r2, [r1]
  // B8
  tst     r0, 0x20
  it      ne
  orrne   r2, r2, 0x100
  // B9
  tst     r0, 0x40
  it      ne
  orrne   r2, r2, 0x200
  // B10
  tst     r0, 0x80
  it      ne
  orrne   r2, r2, 0x400

  str     r2, [r1]

  pop     {r0-r2}
.endm

.macro delay
  push    {r8}

  ldr     r8, =0x1B7740
  delay_\@:
  nop
  subs	r8, 1 // 1 clock cycle
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
