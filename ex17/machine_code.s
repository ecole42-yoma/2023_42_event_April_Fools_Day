
.data
machine_code:
  .byte 0xef, 0xbd, 0x94, 0xef, 0xbd, 0x93, 0xe2, 0x80, 0x88, 0xe2, 0x80, 0x83, 0xef, 0xbd, 0x85, 0xef, 0xbd, 0x89, 0xef, 0xbd, 0x86, 0xef, 0xbd, 0x95, 0xef, 0xbd, 0x85, 0xef, 0xbd, 0x94, 0xe2, 0x80, 0x81, 0xe2, 0x80, 0x80, 0xef, 0xbc, 0xb0, 0xef, 0xbd, 0x89, 0xef, 0xbd, 0x99, 0xef, 0xbd, 0x95, 0xe2, 0x80, 0x88, 0xef, 0xbd, 0x94, 0xe2, 0x80, 0x88, 0xef, 0xbd, 0x89, 0xef, 0xbd, 0x8f, 0xe2, 0x80, 0x87, 0xd1, 0x81, 0xe2, 0x85, 0xb0, 0xef, 0xbd, 0x81, 0xef, 0xbd, 0x85, 0xef, 0xbd, 0x94, 0xef, 0xbd, 0x89

.text
.globl _main
_main:
 jmp machine_code
