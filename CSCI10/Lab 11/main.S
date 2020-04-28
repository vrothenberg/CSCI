// Lab 11 -- MUL/DIV/MLS (evens and odds)
//
// Programmer name: Vince Rothenberg
// Date completed:  16 April 20

.syntax unified
.cpu cortex-m4
.fpu vfp

.section .data
// no variables

.section .text
.global vtable
.global reset_handler

.equ RCC_AHB1ENR,       0x40023830      // reset and clock control enable register

// STM32F401RE -- GPIOA registers
.equ GPIOA_MODER,       0x40020000      // port A direction/mode register
.equ GPIOA_ODR,         0x40020014      // port A output data register

// STM32F401RE -- GPIOB registers
.equ GPIOB_MODER,       0x40020400      // port B direction/mode register
.equ GPIOB_ODR,         0x40020414      // port B output data register

// STM32F401RE -- GPIOC registers
.equ GPIOC_MODER,       0x40020800      // port C direction/mode register
.equ GPIOC_ODR,         0x40020814      // port C output data register

.type vtable, %object
vtable:
    .word _estack
    .word reset_handler
.size vtable, .-vtable

// The Reset handler. Called on reset.
.type reset_handler, %function
reset_handler:
  // Set the stack pointer to the end of the stack.
  ldr		r0, =_estack
  mov		sp, r0

_start:
  // Enable the GPIOA, GPIOB, and GPIOC clocks
  ldr		r3, =RCC_AHB1ENR
  ldr		r2, [r3]
  orr		r2, r2, 0x7 // 0111
  str		r2, [r3]

  // Load the address of GPIOA_MODER into r2
  ldr		r2, =GPIOA_MODER
  ldr		r3, [r2]
  // PA5/D13, PA6/D12, PA7/D11, PA8/D7, PA9/D8 for output
  ldr   r4, =0x55400 // ---- ---- ---- 0101 0101 0100 0000 0000
  orr		r3, r3, r4
  str		r3, [r2]

  // Load the address of GPIOB_MODER into r2
  ldr		r2, =GPIOB_MODER
  ldr   r3, [r2]
  // PB8/D15, PB9/D14, PB10/D6 for output
  ldr   r4, =0x150000 // ---- ---- 0001 0101 0000 0000 0000 0000, ldr =0x for 32 bit
  orr   r3, r3, r4
  // Store GPIOB_MODER pin settings
  str		r3, [r2]

  // Load the address of GPIOC_MODER into r2
  ldr		r2, =GPIOC_MODER
  ldr   r3, [r2]
  // PC2, PC3, PC10 for output
  ldr   r4, =0x100050 // ---- ---- 0001 0000 0000 0000 0101 0000
  orr   r3, r3, r4
  // Store GPIOC_MODER pin settings
  str		r3, [r2]

  // Load the address of GPIOA_ODR into r2
  ldr 	r2, =GPIOA_ODR

  // Load the address of GPIOB_ODR into r4
  ldr 	r4, =GPIOB_ODR

  // Load the address of GPIOC_ODR into r6
  ldr   r6, =GPIOC_ODR

  // Use r8 as a counter/display value; start at 1, count
  // up to 100. At 100, reset the counter to 1.
  mov   r8, 0x1

main_loop:
  // Zero out display
  // Zero out GPIOA
  ldr   r3, [r2]
  bic   r3, 0x3E0 // ---- 0011 1110 0000
  str   r3, [r2]
  // Zero out GPIOB
  ldr   r5, [r4]
  bic   r5, 0x700 // ---- 0111 0000 0000
  str   r5, [r4]
  // Zero out GPIOC
  ldr   r7, [r6]
  ldr   r9, =0x40C // ---- 0100 0000 1100
  bic   r7, r9
  str   r7, [r6]

  // Display 8-bit binary value of r6 using PA5, PA6, PA7, PA8, PA9,
  // PB8, PB9, PB10 (A5 is least significant bit)

  // 1. Use TST, IT, and conditional ORR instructions to test value in r8 --
  //    enable appropriate GPIOA and  GPIOB bits to show r6 value as binary
  //    These are the green LEDs:
  //    Bit 0 = A5, Bit 1 = A6, Bit 2 = A7, Bit 3 = A8, Bit 4 = A9,
  //    Bit 5 = B8, Bit 6 = B9, Bit 7 = B10
  tst   r8, 0x1 // 0000 0001
  it    ne
  orrne r3, 0x20 // 0010 0000

  tst   r8, 0x2 // 0000 0010
  it    ne
  orrne r3, 0x40 // 0100 0000

  tst   r8, 0x4
  it    ne
  orrne r3, 0x80 // 1000 0000

  tst   r8, 0x8
  it    ne
  orrne r3, 0x100   // 0001 0000 0000

  tst   r8, 0x10
  it    ne
  orrne r3, 0x200  // 0010 0000 0000

  tst   r8, 0x20
  it    ne
  orrne r5, 0x100

  tst   r8, 0x40
  it    ne
  orrne r5, 0x200

  tst   r8, 0x80
  it    ne
  orrne r5, 0x400

  // Display EVEN/ODD using a 4-pin LED wired to PC2, PC3, PC10 --
  // choose different colors for EVEN and ODD

  // 2. If r8 is ODD, toggle on PC2, PC3 or PC10.
  //    Else toggle on a different pin (PC2, PC3, or PC10).
  // 1010100101010101011 odd
  // 0000101010100010100 even
  tst    r8, 0x1
  ite    ne
  orrne  r7, 0x4 // 0100 0000 0000 -- PC10
  orreq  r7, 0x8  // 0000 0000 1000 -- PC3




  // show bits
  str   r3, [r2]
  str   r5, [r4]
  str   r7, [r6]

  // counter
  add   r8, 1

  // 3. If r8 == 100, reset r8 to 1
  teq   r8, 100
  it    eq
  moveq r8, 1

  ldr     r9, =0x1B7740
_delay:
  nop
  subs	r9, 1
  bne		_delay

  // Repeat forever
  b		main_loop

.size reset_handler, .-reset_handler
