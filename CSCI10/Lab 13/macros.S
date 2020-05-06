// 4. implement macro
.macro delay
  // Delay loop
  ldr     r9, =0x1B7740
_delay:
  nop
  subs	r9, 1
  bne		_delay
.endm

// 5. implement macro
.macro fizz
  // turn on A5,A6,A7,A8 (r3)
  orr   r3, 0x1E0 // 0001 1110 0000

  // turn on PC2 (r7)
  orr   r7, 0x4

.endm

// 6. implement macro
.macro buzz
  // turn on A9 (r3)
  orr   r3, 0x200 // 0010 0000 0000

  // turn on B8,B9,B10 (r5)
  orr   r5, 0x700 // -111 0000 ----

  // turn on PC3 (r7)
  orr   r7, 0x8

.endm

// 7. implement macro
.macro fizzbuzz
  // turn on A5,A6,A7,A8,A9 (r3)
  orr   r3, 0x03E0 // --11 1110 0000

  // turn on B8,B9,B10 (r5)
  orr   r5, 0x700 // -111 0000 ----

  // turn on PC10 (r7)
  orr   r7, 0x400 // -100 ---- ----

.endm

// 8. implement macro
.macro value
  // Test value in r8, turn on appropriate LEDs
  // (A5, A6, A7, A8, A9, B8, B9, B10)
  // GPIOA value in r3, GPIOB value in r5
  // A5 is the least significant bit (0-bit)

  // PA5
  tst   r8, 0x1
  it    ne
  orrne r3, 0x20  // 0010 0000

  // A6
  tst   r8, 0x2
  it    ne
  orrne r3, 0x40

  // A7
  tst   r8, 0x4
  it    ne
  orrne r3, 0x80

  // A8
  tst   r8, 0x8
  it    ne
  orrne r3, 0x100 // 0001 0000 0000

  // A9
  tst   r8, 0x10
  it    ne
  orrne r3, 0x200

  // B8
  tst   r8, 0x20
  it    ne
  orrne r5, 0x100

  // B9
  tst   r8, 0x40 
  it    ne
  orrne r5, 0x200

  // B10
  tst   r8, 0x80
  it    ne
  orrne r5, 0x400


.endm
