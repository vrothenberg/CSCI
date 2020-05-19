// Lab 16 -- array algorithms
//
// Programmer name: Vince Rothenberg
// Date completed:  19 May 20

.syntax unified
.cpu cortex-m4
.fpu vfp

.include "config.S"
.include "macros.S"

.section .data
  mode:         .word 0
  seed:         .word 0
  offset:       .word 0
  max:          .word 0
  min:          .word 0
  average:      .word 0
  numbers_len:  .word 10
  numbers:      .skip 40

.section .text
.global vtable
.global reset_handler
.global pin0_handler
.global pin1_handler

.equ RCC_AHB1ENR,       0x40023830      // reset and clock control enable register

// STM32F401RE -- GPIOA registers
.equ GPIOA_MODER,       0x40020000      // port A direction/mode register
.equ GPIOA_ODR,         0x40020014      // port A output data register
.equ GPIOA_PUPDR,       0x4002000C      // port A pull-up/pull-down register
.equ GPIOA_OTYPER,      0x40020004      // port A output type

// STM32F401RE -- GPIOB registers
.equ GPIOB_MODER,       0x40020400      // port B direction/mode register
.equ GPIOB_ODR,         0x40020414      // port B output data register

// STM32F401RE -- GPIOC registers
.equ GPIOC_MODER,       0x40020800      // port C direction/mode register
.equ GPIOC_ODR,         0x40020814      // port C output data register

// STM32F401RE -- external interrupt registers
.equ RCC_APB2ENR,       0x40023844      // syscfg clock
.equ SYSCFG_EXTICR,     0x40013808      // syscfg external interrupt config register
.equ EXTI_RTSR,         0x40013C08      // EXTI rising edge trigger register
.equ EXTI_FTSR,         0x40013C0C      // EXTI falling edge trigger register
.equ EXTI_IMR,          0x40013C00      // EXTI falling edge trigger register
.equ EXTI_PR,           0x40013C14      // EXTI pending register

// STM32F401RE -- NVIC registers
.equ NVIC_ISER0,        0xE000E100      // set interrupt enable register
.equ NVIC_ICER0,        0xE000E180      // clear interrupt enable register
.equ NVIC_ICPR0,        0xE000E280      // interrupt clear pending register
.equ NVIC_ISPR0,        0xE000E200      // interrupt set pending register
.equ NVIC_IPR1,         0xE000E404      // interrupt priority register

// TIMER -- to provide reasonable seed value for RNG
.equ RCC_APB1ENR,         0x40023840
.equ TIM2_CR1,            0x40000000
.equ TIM2_PSC,            0x40000028
.equ TIM2_ARR,            0x4000002C
.equ TIM2_CNT,            0x40000024

// RNG constants
.equ BSD_RNG_MULTIPLIER,  0x41C64E6D
.equ BSD_RNG_INCREMENT,   0x3039
.equ RNG_RAND_MAX,        0xFF

// See page 372 of STM32F4 Reference Manual
.type vtable, %object
vtable:
    .word _estack
    .word reset_handler // Reset 0x04
    .word 0 // NMI 0x08
    .word 0 // HardFault 0x0C
    .word 0 // MemManage 0x10
    .word 0 // BusFault 0x14
    .word 0 // UsageFault 0x18
    .word 0 // Reserved 0x1C
    .word 0 // Reserved 0x20
    .word 0 // Reserved 0x24
    .word 0 // Reserved 0x28
    .word 0 // SVCall 0x2C
    .word 0 // Debug Monitor 0x30
    .word 0 // Reserved 0x34
    .word 0 // PendSV 0x38
    .word 0 // SysTick 0x3C
    .word 0 // WWDG 0x40
    .word 0 // PVD 0x44
    .word 0 // TAMP_STAMP 0x48
    .word 0 // RTC_WKUP 0x4C
    .word 0 // FLASH 0x50
    .word 0 // RCC 0x54
    .word pin0_handler // EXTI0 0x58, IRQ6
    .word pin1_handler // EXTI1 0x5C, IRQ7
.size vtable, .-vtable

// The Reset handler. Called on reset.
.type reset_handler, %function
reset_handler:
  initram

  // Set the stack pointer to the end of the stack.
  ldr		r0, =_estack
  mov		sp, r0
  b     _start
.size reset_handler, .-reset_handler

// Called when button connected to PA0 pressed.
.type pin0_handler, %function
pin0_handler:
  debounce

  // Clear the pending register
  ldr   r0, =EXTI_PR
  ldr   r1, [r0]
  orr   r1, 0x1
  str   r1, [r0]

  increment_mode mode

  bx    lr
.size pin0_handler, .-pin0_handler

// Called when button connected to PA1 pressed.
.type pin1_handler, %function
pin1_handler:
  debounce

  // Clear the pending register
  ldr   r0, =EXTI_PR
  ldr   r1, [r0]
  orr   r1, 0x2
  str   r1, [r0]

  decrement_mode mode

  bx    lr
.size pin1_handler, .-pin1_handler

_start:
  configure_interrupts
  configure_gpio

  // get_seed seed

  // 1. skip

  // 2. skip

  // Populate array
  populate_array numbers

  compute_max numbers, numbers_len, offset, max
  compute_min numbers, numbers_len, offset, min
  compute_average numbers, numbers_len, offset, average

_main_loop:

  clearbits
  display_mode mode

  ldr   r0, =mode
  ldr   r1, [r0]

_mode_0: // cycle display all values
  teq   r1, #0
  it    ne
  bne   _mode_1
  display_array numbers, numbers_len, offset
  b     _end_mode

_mode_1: // display min value
  teq   r1, 1
  it    ne
  bne   _mode_2
  showvar min
  b     _end_mode

_mode_2: // display max value
  teq   r1, 2
  it    ne
  bne   _mode_3
  showvar max
  b     _end_mode

_mode_3: // display average value
  teq   r1, 3
  it    ne
  bne   _end_mode
  showvar average

_end_mode:

	// Repeat forever
	b		_main_loop
