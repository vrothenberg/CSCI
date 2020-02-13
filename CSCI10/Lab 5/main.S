// Lab 5 -- load/store/mov
//
// Programmer name: Vince Rothenberg
// Date completed:  6 February 2020

.syntax unified
.cpu cortex-m4
.fpu vfp

.macro initram
  // copy data from flash to RAM
  ldr   r0, =flash_sdata
  ldr   r1, =ram_sdata
  ldr   r2, =data_size

  copy:
    ldrb  r4, [r0], #1
    strb  r4, [r1], #1
    subs  r2, r2, #1
    bne   copy
.endm

.section .data
xvar: .word 10
yvar: .word 20

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
  initram

  // Set the stack pointer to the end of the stack.
  ldr  r0, =_estack
  mov  sp, r0

  // Load the address of xvar into REGISTER r0
  ldr   r0, =xvar

  // 1. LOAD THE ADDRESS OF yvar INTO REGISTER r2

  // Initialize r5 (loop counter)
  mov   r5, 1
  main_loop:

    // Dereference r0 to get the value of xvar, load into r1
    ldr   r1, [r0]

    // 2. DEREFERENCE r2 TO GET THE VALUE OF yvar, LOAD INTO r3

    // Store the value from register r3 into xvar, by dereferencing r0
    str   r3, [r0]

    // 3. STORE THE VALUE FROM REGISTER r1 INTO yvar, BY DEREFERENCING r2

    // Increment r5 (loop counter)
    add   r5, 1

    b     main_loop
.size reset_handler, .-reset_handler
