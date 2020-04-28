// 4. implement macro
.macro delay
  // Delay loop

.endm

// 5. implement macro
.macro fizz
  // turn on A5,A6,A7,A8 (r3)

  // turn on PC2 (r7)

.endm

// 6. implement macro
.macro buzz
  // turn on A9 (r3)

  // turn on B8,B9,B10 (r5)

  // turn on PC3 (r7)

.endm

// 7. implement macro
.macro fizzbuzz
  // turn on A5,A6,A7,A8,A9 (r3)

  // turn on B8,B9,B10 (r5)

  // turn on PC10 (r7)

.endm

// 8. implement macro
.macro value
  // Test value in r8, turn on appropriate LEDs
  // (A5, A6, A7, A8, A9, B8, B9, B10)
  // GPIOA value in r3, GPIOB value in r5
  // A5 is the least significant bit (0-bit)
.endm
