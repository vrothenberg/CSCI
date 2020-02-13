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
  mov  r0, 1
  ldr  r1, =0xFACEFACE

  main_loop:
    // Add 1 to register 'r0'.
    add r0, 1

    // Loop back if r0 < 10
    cmp  r0, 10
    blo  main_loop

.size reset_handler, .-reset_handler
