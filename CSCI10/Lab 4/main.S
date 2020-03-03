// Lab 4 -- first ARM program
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

.type vtable, %object
vtable:
    .word _estack
    .word reset_handler
.size vtable, .-vtable

// The Reset handler. Called on reset.
.type reset_handler, %function
reset_handler:

  // Set the stack pointer to the end of the stack.
  ldr  r0, =_estack
  mov  sp, r0

  // Set some values. When we see these values
  // in our debugger, we'll know that our program
  // is loaded on the chip and working.

  // mov destination, source
  mov  r0, 1
  mov  r1, 0xBEEF // 4 hex digits or less, use mov
  // ldr destination, source
  ldr  r1, =0xFACEFACE // 5 hex digits or more, use ldr, =

  main_loop:
    // Add 1 to register 'r0'.
    // Increments counter
    add r0, 1

    // Loop back if r0 < 10
    // do while i < 10 loop 
    cmp  r0, 10
    blo  main_loop

.size reset_handler, .-reset_handler
