// Lab 9 -- add/sub/branch; blink external
//
// Programmer name: Vince Rothenberg
// Date completed:  02 April 20

.syntax unified
.cpu cortex-m4
.fpu vfp

.section .data
// no variables

.section .text
.global vtable
.global reset_handler

.equ RCC_AHB1ENR,       0x40023830      // peripheral clock enable register

// STM32F401RE -- using PA pins
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
	orr		r2, 0x00000001			// bit 0 is GPIOA clock on
	str		r2, [r3]

	// Configure pins A5, A6, A7, A8, A9 for output
	ldr		r3, =GPIOA_MODER
	ldr		r2, [r3]

  // 1. Use ldr to load pin settings (A5, A6, A7, A8, A9 for output) into r4
  // MODER -> ---- 0000 0000 0101 0101 0100 0000 0000
  ldr r4, =0x55400

  // 2. Use the value in r4 to set the bits in r2
  orr r2, r4

	str		r2, [r3]

	// Load the address and content for the GPIOA output data register
	ldr 	r3, =GPIOA_ODR
	ldr		r2, [r3]

main_loop:
	// 3. Toggle the LEDs on pins GPIO A5, A6, A7, A8, A9
  // ODR -> ---- 0011 1110 0000
  eor r2, 0x3E0

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
