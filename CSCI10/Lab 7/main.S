// Lab 7 -- blink more
//
// Programmer name: Vince Rothenberg
// Date completed:  5 Mar 2020

.syntax unified
.cpu cortex-m4
.fpu vfp

.section .data
// no variables

.section .text
.global vtable
.global reset_handler

.equ RCC_AHB1ENR,       0x40023830      // peripheral clock enable register
.equ GPIOA_MODER,       0x40020000      // port A direction/mode register
.equ GPIOA_ODR,         0x40020014      // port A output data register

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
	// Enable the GPIOA clock
	ldr		r3, =RCC_AHB1ENR
	ldr		r2, [r3]

  // 1. ENABLE GPIOA CLOCK IN RCC_AHB1ENR BY UPDATING VALUE IN r2
  orr   r2, 0x1
	str		r2, [r3]

	// Load the address then value for the GPIOA mode register
	ldr		r3, =GPIOA_MODER
	ldr		r2, [r3]

  // 2. SET FOR OUTPUT THE GPIOA PINS ASSOCIATED WITH
  //    D13, D12, D11, D7, in GPIOA_MODER BY UPDATING r2
  orr   r2, 0x15400
	str		r2, [r3]

	// Load the address and content for the GPIOA output data register
	ldr 	r3, =GPIOA_ODR
	ldr		r2, [r3]

  // 3. SET THE BITS IN GPIOA ASSOCIATED WITH D13, D11 in GPIOA_ODR
  //    BY UPDATING r2
  orr   r2, 0xA0
  str   r2, [r3]


  // 4. CLEAR THE BITS IN GPIOA ASSOCIATED WITH D12, D7 in GPIOA_ODR
  //    BY UPDATING r2
  bic   r2, 0x140 // PA6 and PA8
  str   r2, [r3]

main_loop:

  // 5. INVERT THE BITS IN GPIOA ASSOCIATED WITH D13, D12, D11, D7 in GPIOA_ODR
  eor   r2, 0x1E0 // PA5,6,7,
	str		r2, [r3]

	// Delay loop
	mov		r4, 0xFF000
_delay:
	nop
	subs	r4, 1
	bne		_delay

	# Repeat forever
	b		main_loop

.size reset_handler, .-reset_handler
