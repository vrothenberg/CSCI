// Lab 9 -- add/sub/branch; blink external
//
// Programmer name: Vince Rothenberg
// Date completed:  07 April 20

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
  // 01 on the output pins
  // ---- ---- ---- 0101 0101 0100 0000 0000
  ldr r4, =0x55400

	// 2. Use the value in r4 to set the bits in r2
  orr r2, r4
	str		r2, [r3]

	// Load the address and content for the GPIOA output data register
	ldr 	r3, =GPIOA_ODR
	ldr		r2, [r3]

	// 3. Initialize a counter register (r5 recommended) starting at #1
  mov r5, #1

main_loop:
	// USE cmp and branching instructions to implement the following

	// 4. r5 == 1; toggle A9 on, then branch to _start_delay
  cmp r5, 1
  bne _case_two
  // ---- 0010 0000 0000
  eor r2, 0x200
  str r2, [r3]
  b _start_delay


	// 5. r5 == 2; toggle A8 on, then branch to _start_delay
_case_two:
  cmp r5, 2
  bne _case_three
  // ---- 0001 0000 0000
  eor r2, 0x100
  str r2, [r3]
  b _start_delay


	// 6. r5 == 3; toggle A7 on, then branch to _start_delay
_case_three:
  cmp r5, 3
  bne _case_four
  // ---- 0000 1000 0000
  eor r2, 0x80
  str r2, [r3]
  b _start_delay


	// 7. r5 == 4; toggle A6 on, then branch to _start_delay
_case_four:
  cmp r5, 4
  bne _case_five
  // ---- 0000 0100 0000
  eor r2, 0x40
  str r2, [r3]
  b   _start_delay


	// 8. r5 == 5; toggle A5 on, then branch to _start_delay
_case_five:
  cmp r5, 5
  bne _bigger_than_five
  // ---- 0000 0010 0000
  eor r2, 0x20
  str r2, [r3]
  b   _start_delay

	// 9a. r5 > 5;  reset r5 to 0
_bigger_than_five:
  mov r5, 0

	// 9b. EXTRA CHALLENGE -- TOGGLE all pins off on counter reset
  // ---- 0011 1110 0000
  bic r2, 0x3E0
  str r2, [r3]

_start_delay:

	// 10. Increment the counter (r5 recommended) here
  add r5, 1

	mov		r4, 0xFF000
// Delay loop
_delay:
	nop
	subs	r4, 1
	bne		_delay

	// Repeat forever
	b		main_loop

.size reset_handler, .-reset_handler
