// Lab 13 -- MUL/DIV/MLS (FizzBuzz)
//
// Programmer name: __________
// Date completed:  __________

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

// Include all macros
.include "macros.S"

_start:
	// Enable the GPIOA and GPIOB clocks
	ldr		r3, =RCC_AHB1ENR
	ldr		r2, [r3]
	orr		r2, 0x7
	str		r2, [r3]

	// Load the address of GPIOA_MODER into r2
  ldr		r2, =GPIOA_MODER
	ldr		r3, [r2]
  // A5/D13, A6/D12, A7/D11, A8/D7, A9/D8 for output
  ldr   r4, =0x55400
	orr		r3, r4
	str		r3, [r2]

  // Load the address of GPIOB_MODER into r4
	ldr		r2, =GPIOB_MODER
  ldr   r3, [r2]
  // B8/D15, B9/D14, B10/D6, B6/D10 for output
  ldr   r4, =0x151000
  orr   r3, r4
  // Store GPIOB_MODER pin settings
	str		r3, [r2]

  // Load the address of GPIOC_MODER into r2
	ldr		r2, =GPIOC_MODER
  ldr   r3, [r2]
  // PC2, PC3, PC10 for output
  ldr   r4, =0x100050
  orr   r3, r4
  // Store GPIOC_MODER pin settings
	str		r3, [r2]

	// Load the address of GPIOA_ODR into r2
	ldr 	r2, =GPIOA_ODR

  // Load the address of GPIOB_ODR into r4
	ldr 	r4, =GPIOB_ODR

  // Load the address of GPIOB_ODR into r6
	ldr 	r6, =GPIOC_ODR

  // Use r8 as a counter/display value; start at 1, count
  // up to 100. At 100, reset the counter to 1.
  mov   r8, 0x1

main_loop:
  // Zero out display
  ldr   r3, [r2]
  bic   r3, 0x3E0
  str   r3, [r2]
  ldr   r5, [r4]
  bic   r5, 0x700
  str   r5, [r4]
  ldr   r7, [r6]
  ldr   r9, =0x40C
  bic   r7, r9
  str   r7, [r6]

  // 1. FizzBuzz -- perform logic and call appropriate macros
  //    (FizzBuzz) If r8%15 == 0, call fizzbuzz macro
  //    (Fizz) Else if r8%3 == 0, call fizz macro
  //    (Buzz) Else if r8%5 == 0, call buzz macro
  //    (Value) Else call value macro

end_:
  // counter
  add     r8, 1

  // show bits
  str     r3, [r2]
  str     r5, [r4]
  str     r7, [r6]

  // 2. If r8 == 100, reset r8 to 1

  // 3. call delay macro

	// Repeat forever
	b		main_loop

.size reset_handler, .-reset_handler
