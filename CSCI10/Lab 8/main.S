// Lab 8 -- add/sub
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

main_loop:
  // Part 1: Using ADD
	// r0 -- Rd for add
  // r1, r2, imm -- values to add

  // 1. mov immediate value 0 to r0
  mov r0, 0
  // 2. r0 = r0 + 1
  add r0, r0, 1
  // r0 = 1
  // 3. mov immediate value 2 to r1
  mov r1, 2
  // 4. r0 = r0 + r1
  add r0, r1
  // r0 = 1 + 2 = 3
  // 5. mov immediate value 3 to r2
  mov r2, 3
  // 6. r0 = r1 + r2
  add r0, r1, r2
  // 7. The value in r0 is now __0x5__


  // Part 2: Using SUB
  // r3 -- Rd for sub
  // r4, r5, imm -- values to sub

  // 1. mov immediate value 9 to r3
  mov r3, 9
  // 2. r3 = r3 - 1
  sub r3, r3, 1
  // 3. mov immediate value 4 to r4
  mov r4, 4
  // 4. r3 = r3 + r4
  add r3, r3, r4
  // 5. mov immediate value 2 to r5
  mov r5, 2
  // 6. r3 = r4 - r5
  sub r3, r4, r5
  r3 =  4 - 2
  // 7. The value in r3 is now __0x2__

  // Part 3: Using ADDS
	// r0 -- Rd for adds

  // 1. mov immediate value 0xFFFFFFFF to r0
  // mov can only do 4 nibbles
  // ldr for 8 nibbles
  ldr r0, =0xFFFFFFFF
  // 2. r0 = r0 + 1
  adds r0, r0, 1
  // PSR 6 = 0110
  // 3. What PSR status bit will be set? __Zero and Carry__
  // 4. The value in r0 is now _0x0_

  // Part 4: Using SUBS
	// r3 -- Rd for subs
  // r1, r2, imm -- values to add

  // 1. mov immediate value 0 to r3
  mov r3, 0
  // 2. r3 = r3 - 1
  subs r3, r3, 1
  // xPSR is 0x8 = 1000 N, Z, C, V
  // 3. What PSR status bit will be set? _Negative_

  // 4. The value in r3 is now _0xFFFFFFFF / -1_

	// Repeat forever
	b		main_loop

.size reset_handler, .-reset_handler
