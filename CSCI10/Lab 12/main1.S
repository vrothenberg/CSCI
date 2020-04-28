// Lab 11 -- push button, pt 1
//
// Programmer name: Vince Rothenberg
// Date completed: 21 Apr 20

.syntax unified
.cpu cortex-m4
.fpu vfp

.section .data
// no variables

.section .text
.global vtable
.global reset_handler

.equ RCC_AHB1ENR,       0x40023830      // peripheral clock enable register

// STM32F401RE -- GPIOA registers (user LED is PA5)
.equ GPIOA_MODER,       0x40020000      // port A direction/mode register
.equ GPIOA_ODR,         0x40020014      // port A output data register

// STM32F401RE -- GPIOC registers (user button is PC13)
.equ GPIOC_MODER,       0x40020800      // 1. port C direction/mode register
.equ GPIOC_IDR,         0x40020810      // 2. port C input data register
.equ GPIOC_PUPDR,       0x4002080C      // 3. port C pull-up/pull-down register
.equ GPIOC_OTYPER,      0x40020804      // 4. port C output type

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
  // Enable the GPIOA and GPIOC clocks
  ldr		r3, =RCC_AHB1ENR
  ldr		r2, [r3]
  orr		r2, 0x5                  // Bit 0 = GPIOA, Bit 2 = GPIOC
  str		r2, [r3]

  // Load the address of GPIOA_MODER into r2
  ldr		r2, =GPIOA_MODER
  // Load the current value of GPIOA_MODER into r3
  ldr		r3, [r2]
  // Configure PA5 for output (01)
  orr		r3, r3, 0x400
  // Overwrite GPIOA_MODER
  str		r3, [r2]

  // 5.  Complete these steps:
  // 5a. Load the address of GPIOC_MODER into r2 -- 2 bits per pin
  ldr r2, =GPIOC_MODER
  // 5b. Load the current value of GPIOC_MODER into r3
  ldr r3, [r2]
  // 5c. Configure PC13 for input (00)
  ldr r4, =0xC000000
  bic r3, r4
  // 5d. Overwrite GPIOC_MODER
  str r3, [r2]


  // 6.  Complete these steps:
  // 6a. Load the address of GPIOC_PUPDR into r2 -- 2 bits per pin
  ldr r2, =GPIOC_PUPDR
  // 6b. Load the current value of GPIOC_PUPDR into r3
  ldr r3, [r2]
  // 6c. Configure PC13 as pull-down (10)
  ldr r4, =0x8000000
  orr r3, r4
  // 6d. Overwrite GPIOC_PUPDR
  str r3, [r2]

  // 7.  Complete these steps:
  // 7a. Load the address of GPIOC_OTYPER into r2 -- 1 bit per pin
  ldr r2, =GPIOC_OTYPER
  // 7b. Load the current value of GPIOC_OTYPER into r3
  ldr r3, [r2]
  // 7c. Configure PC13 as push-pull (0)
  bic r3, 0x2000
  // 7d. Overwrite GPIOC_OTYPER
  str r3, [r2]

  // Load the address of GPIOA_ODR into r2
  ldr 	r2, =GPIOA_ODR

  // Load the address of GPIOC_IDR into r4
  ldr 	r4, =GPIOC_IDR

  // Use r6 as a BUTTON pressed/not-pressed flag
  // (1=pressed, 0=not-pressed)
  mov   r6, 0x0

main_loop:

  // Load current value of GPIOC_IDR into r5
  ldr   r5, [r4]

  // If bit 13 of GPIOC_IDR bit 13 is set, button is pressed
  // 8.  Complete these steps:
  // 8a. TST r5 to see if pin 13 is set
  tst r5, 0x2000
  // 8b. ITE on equals
  ite eq
  // 8c. MOV 1 to r6 if equals
  moveq r6, 1
  // 8D. MOV 0 to r6 if not equals
  movne r6, 0

  // Load current value of GPIOA_ODR into r3
  ldr   r3, [r2]

  // If r6=on/true, turn on GPIOA bit 5, else turn off GPIOA bit 5
  // 9.  Complete these steps:
  // 9a. TEQ r6 and 1
  teq r6, 1
  // 9b. ITE on equals
  ite eq
  // 9c. ORR to enable pin 5 in GPIOA_ODR on equals
  // ---- ---- --10 0000
  orreq r3, 0x20
  // 9d. BIC pin 5 in GPIOA_ODR if not equals
  bicne r3, 0x20

  str   r3, [r2]

	// Repeat forever
	b		main_loop

.size reset_handler, .-reset_handler
