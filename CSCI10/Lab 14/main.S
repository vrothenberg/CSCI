// Lab 14 -- arrays, button input (polling)
//
// Programmer name: __________
// Date completed:  __________

.syntax unified
.cpu cortex-m4
.fpu vfp

.include "macros.S"

.section .data
// ensure alignment on 4-byte/word
.balign 4

// 1. Declare an array called "numbers" of 40 bytes
//    (room for 10 integers)


// 2. Add a label called "len" to be used to find end of array

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

// STM32F401RE -- GPIOC registers (user button is PC13)
.equ GPIOC_MODER,       0x40020800      // port C direction/mode register
.equ GPIOC_IDR,         0x40020810      // port C input data register
.equ GPIOC_PUPDR,       0x4002080C      // port C pull-up/pull-down register
.equ GPIOC_OTYPER,      0x40020804      // port C output type

.type vtable, %object
vtable:
    .word _estack
    .word reset_handler
.size vtable, .-vtable

// The Reset handler. Called on reset.
.type reset_handler, %function
reset_handler:
  // call the initram macro
  initram

  // Set the stack pointer to the end of the stack.
  ldr   r0, =_estack
  mov   sp, r0

_start:
  // Enable the GPIOA, GPIOB, and GPIOC clocks
  ldr   r0, =RCC_AHB1ENR
  ldr   r1, [r0]
  orr   r1, 0x7
  str   r1, [r0]

  // Load the address of GPIOA_MODER
  ldr   r0, =GPIOA_MODER
  ldr   r1, [r0]
  // A5/D13, A6/D12, A7/D11, A8/D7, A9/D8 for output
  ldr   r2, =0x55400
  orr   r1, r2
  str   r1, [r0]

  // Load the address of GPIOB_MODER
  ldr   r0, =GPIOB_MODER
  ldr   r1, [r0]
  // B8/D15, B9/D14, B10/D6, B6/D10 for output
  ldr   r2, =0x151000
  orr   r1, r2
  // Store GPIOB_MODER pin settings
  str   r1, [r0]

  // Load the address of GPIOC_MODER -- 2 bits per pin
  ldr   r0, =GPIOC_MODER
  // Load the current value of GPIOC_MODER
  ldr   r1, [r0]
  // Configure PC13 for input (00)
  bic   r1, 0xC000000
  // Overwrite GPIOC_MODER
  str   r1, [r0]

  // Load the address of GPIOC_PUPDR -- 2 bits per pin
  ldr   r0, =GPIOC_PUPDR
  // Load the current value of GPIOC_PUPDR
  ldr   r1, [r0]
  // Configure PC13 as pull-down (10)
  ldr   r2, =0x4000000
  orr   r1, r2
  // Overwrite GPIOC_PUPDR
  str   r1, [r0]

  // Load the address of GPIOC_OTYPER -- 1 bit per pin
  ldr   r0, =GPIOC_OTYPER
  // Load the current value of GPIOC_OTYPER into r3
  ldr   r1, [r0]
  // Configure PC13 as push-pull (0)
  bic   r1, 0x2000
  // Overwrite GPIOC_OTYPER
  str   r1, [r0]

  // 3. Call the resetArray macro

  // 4a. Load the address of the array into a register
  // 4b. Load the first value of the array into a register

main_loop:
  // 5. Call the showbits macro -- pass the register containing
  //    the array value to be displayed

  // Use r6 to flag change in button state
  mov   r6, 0x0
wait_for_release_:
  // Load address of GPIOC_IDR
  ldr   r0, =GPIOC_IDR
  ldr   r1, [r0]
  // If bit 13 of GPIOC_IDR bit 13 is set, button is pressed
  tst   r1, 0x2000
  itt  eq
  moveq r6, 0x1
  beq   debounce_

  b     continue_

debounce_:
  // call delay macro
  delay
  b     wait_for_release_

continue_:
  // 6. If button state changed (r6=0x1), advance to next
  //    item in array

  // 7. If prior operation is now past the end of the array,
  //    reset to base address of array
  //    (HINT: use the "length" label declared at top)


  // 8. Load the next array value into a register
  //    (must be the same register passed to showbits above)

  // 9. Call clearbits to clear the display

  // Repeat forever
  b   main_loop

.size reset_handler, .-reset_handler
