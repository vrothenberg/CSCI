.macro configure_interrupts
  push  {r0-r1}

  // Enable the GPIOA clock
  ldr   r0, =RCC_AHB1ENR
  ldr   r1, [r0]
  orr   r1, 0x1
  str   r1, [r0]

  // Enable SYSCFGGEN in APB2ENR (bit 14, tech ref manual pg 211)
  ldr   r0, =RCC_APB2ENR
  ldr   r1, [r0]
  orr   r1, 0x4000
  str   r1, [r0]

  // Load the address of GPIOA_MODER
  ldr   r0, =GPIOA_MODER
  ldr   r1, [r0]
  // PA0/A0, PA1/A1 for input
  bic   r1, 0xF
  // Write these pin settings
  str   r1, [r0]

  // Load the address of GPIOA_PUPDR -- 2 bits per pin
  ldr   r0, =GPIOA_PUPDR
  // Load the current value of GPIOA_PUPDR
  ldr   r1, [r0]
  // Configure PA0 and PA1 as pull-down (10)
  orr   r1, 0xA
  // Overwrite GPIOA_PUPDR
  str   r1, [r0]

  // Load the address of GPIOA_OTYPER -- 1 bit per pin
  ldr   r0, =GPIOA_OTYPER
  // Load the current value of GPIOA_OTYPER
  ldr   r1, [r0]
  // Configure PA0 and PA1 as push-pull (0)
  bic   r1, 0x3
  // Overwrite GPIOA_OTYPER
  str   r1, [r0]

  // Configure SYSCFG_EXTICR
  ldr   r0, =SYSCFG_EXTICR
  ldr   r1, [r0]
  // Clear pins 0 and 1 (bits 0-3, 4-7)
  // This also sets EXTI0 and EXTI1 to PA pins
  bic   r1, 0xFF
  str   r1, [r0]

  // Enable rising edge trigger for EXTI0 and EXTI1
  ldr   r0, =EXTI_RTSR
  ldr   r1, [r0]
  orr   r1, 0x3
  str   r1, [r0]

  // Disable falling edge trigger for EXTI0 and EXTI1
  ldr   r0, =EXTI_FTSR
  ldr   r1, [r0]
  bic   r1, 0x3
  str   r1, [r0]

  // Enable EXTI0 and EXTI1 interrupt
  ldr   r0, =EXTI_IMR
  ldr   r1, [r0]
  orr   r1, 0x3
  str   r1, [r0]

  // Set EXTI0 and EXTI1 interrupt priority to 1
  ldr   r0, =NVIC_IPR1
  ldr   r1, [r0]
  ldr   r2, =#0xFFFF0000
  bic   r1, r2
  ldr   r2, =#0x10100000
  orr   r1, r2
  str   r1, [r0]

  // Set interrupt enable for IRQ6 and IRQ7
  ldr   r0, =NVIC_ISER0
  ldr   r1, [r0]
  orr   r1, 0xC0
  str   r1, [r0]

  pop   {r0-r1}
.endm

.macro configure_gpio
  push  {r0-r1}
  // Enable the GPIOC clock
  ldr   r0, =RCC_AHB1ENR
  ldr   r1, [r0]
  orr   r1, 0x4
  str   r1, [r0]

  // Configure GPIOC MODER pins
  ldr   r0, =GPIOC_MODER
  ldr   r1, [r0]
  // C2, C3 for output
  orr   r1, 0x50
  str   r1, [r0]

  pop   {r0-r1}
.endm
