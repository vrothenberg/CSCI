// Lab 6 -- blink
//
// Programmer name: Vince Rothenberg
// Date completed:  27 February 2020

.syntax unified
.cpu cortex-m4
.fpu vfp

.section .data
// no variables

.section .text
.global vtable
.global reset_handler

// Permanent GPIO addresses
.equ RCC_AHB1ENR,       0x40023830      // peripheral clock enable register
// STM32F401RE -- LED output is PA5
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

	// 1. SET BIT 0 IN REGISTER r2
  orr   r2, r2, #1
	str		r2, [r3]

	// Configure pin A5 for output
	ldr		r3, =GPIOA_MODER
	ldr		r2, [r3]

	// 2. SET BIT 10 IN REGISTER r2
  orr   r2, r2, #0x400
	str		r2, [r3]

	// Load the address then value for the GPIOA output data register
	ldr 	r3, =GPIOA_ODR
	ldr		r2, [r3]

main_loop:
	// 3. INVERT BIT 5 IN REGISTER r2 TO TOGGLE THE LED CONNECTED TO PA5
  eor r2, r2, #0x20

  // Overwrite GPIOA_ODR with the updated pin value
	str		r2, [r3]

	// Delay loop
	mov		r4, 0xFF000
_delay:
	nop
	subs	r4, 1
	bne		_delay

	// Repeat forever
	b		main_loop

.size reset_handler, .-reset_handler
