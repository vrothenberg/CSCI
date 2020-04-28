// Lab 10 -- IT/TST/TEQ/conditional instructions
//
// Programmer name: Vince Rothenberg
// Date completed:  09 Apr 20

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

// 1. port B direction/mode register
.equ GPIOB_MODER,       0x40020400

// 2. port B output data register
.equ GPIOB_ODR,         0x40020414

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
  // Enable the GPIOA and GPIOB clocks
  ldr		r3, =RCC_AHB1ENR
  ldr		r2, [r3]

  // 3. Bit 0 = GPIOA, Bit 1 = GPIOB
  // 0000
  // DCBA
  orr		r2, 0x3
  str		r2, [r3]

  // Load the address of GPIOA_MODER into r2
  ldr		r2, =GPIOA_MODER
  ldr		r3, [r2]
  // A5/D13, A6/D12, A7/D11, A8/D7, A9/D8 for output
  ldr   r4, =0x55400

  orr		r3, r3, r4
  str		r3, [r2]

  // Load the address of GPIOB_MODER into r4
  ldr		r4, =GPIOB_MODER
  ldr   r5, [r4]
  // B8/D15, B9/D14, B10/D6, B6/D10 for output

  // 4. Enable appropriate pins for output
  // ---- ---- 0001 0101 0001 0000 0000 0000
  ldr   r6, =0x151000

  orr   r5, r6
  str		r5, [r4]

  // Load the address of GPIOA_ODR into r2
  ldr 	r2, =GPIOA_ODR

  // Load the address of GPIOB_ODR into r4
  ldr 	r4, =GPIOB_ODR

  // Use r6 as a counter/display value; start at 127
  // (max signed 8-bit integer)
  // mov   r6, 127
  mov   r6, 127  // change back to 127 later

  // Use r7 to track counting up (1) or counting down (0)
  // Start in counting down mode
  mov   r7, 0
  main_loop:
  // Zero out display
  // r3 for GPIOA bits

  // 5. BIC to clear appropriate bits in r3
  // ---- 0011 1110 0000
  bic   r3, 0x3E0

  str   r3, [r2]
  // r5 for GPIOB bits

  // 6. BIC to clear appropriate bits in r5
  // ---- 0111 0100 0000
  bic   r5, 0x740
  str   r5, [r4]

  // pause briefly before displaying the next value
  // experiment with this value to get the pause timing you prefer
  ldr     r8, =0x1FFFFF
_clear_delay:
  nop
  subs	r8, 1
  bne		_clear_delay

  // Display 8-bit binary value of r6 using A5, A6, A7, A8, A9,
  // B8, B9, B10 (A5 is least significant bit)

  // 7. Use TST, IT, and conditional ORR instructions to test value in r6 --
  //    enable appropriate GPIOA and  GPIOB bits to show r6 value as binary
  //    These are the green LEDs:
  //    Bit 0 = A5, Bit 1 = A6, Bit 2 = A7, Bit 3 = A8, Bit 4 = A9,
  //    Bit 5 = B8, Bit 6 = B9, Bit 7 = B10

  // r6 has a value between -128 and 127

  tst   r6, 0x1 // Bit 0 A5, if 0001 is set then
  it    ne
  orrne r3, 0x20 // turn on led pin A5

  // Ex: when r6 is 3 -> 0000 0011
  tst   r6, 0x2 // Bit 1 A6
  // if then, ne means is equal..
  it    ne
  orrne r3, 0x40 // ---- ---- 0100 0000

  tst   r6, 0x4 // Bit 2 A7
  it    ne
  orrne r3, 0x80 // ---- ---- 1000 0000

  tst   r6, 0x8 // Bit 3 A8
  it    ne
  orrne r3, 0x100 // ---- 0001 0000 0000

  tst   r6, 0x10 // Bit 4 A9
  it    ne
  orrne r3, 0x200 // ---- 0010 0000 0000

  tst   r6, 0x20 // Bit 5 B8
  it    ne
  orrne r5, 0x100  // ---- 0001 0000 0000

  tst   r6, 0x40 // Bit 6 B9
  it    ne
  orrne r5, 0x200  // ---- 0010 0000 0000

  tst   r6, 0x80 // Bit 7 B10
  it    ne
  orrne r5, 0x400   // ---- 0100 0000 0000

  // 8. Use CMP, IT, and conditional ORR instruction
  //    If r6 is negative, toggle on B6
  //    B6 is red LED
  cmp   r6, 0
  it    lt
  orrlt r5, 0x40 // ---- ---- 01000 0000 (B6)

  // 9. Use CMP, ITE, and conditional ADD/SUB to increment/decrement r6
  //    if r7 = 0, SUB; if r7 = 1, ADD
  cmp   r7, 0
  ite   eq
  subeq r6, 1
  addne r6, 1


  // test -- turn everything on
  // orr r3, 0x3E0
  // orr r5, 0x740

  // show bits
  // A pins
  str   r3, [r2]
  // B pins
  str   r5, [r4]

  // 10. Use TEQ, ITE/IT, and conditional MOV instructions
  //     If r6 == -128, switch to count up mode
  //     Else if r6 == 127, switch to count down mode
  mov   r9, -128
  teq   r6, r9
  it    eq
  moveq r7, 1

  teq   r6, 127
  it    eq
  moveq r7, 0

  // pause briefly resturning to the top of the loop
  // experiment with this value to get the pause timing you prefer
  ldr     r8, =0x7FFFF
_delay:
	nop
	subs	r8, 1
	bne		_delay

	// Repeat forever
	b		main_loop

.size reset_handler, .-reset_handler
