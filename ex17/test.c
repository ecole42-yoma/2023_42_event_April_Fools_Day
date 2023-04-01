#include <unistd.h>
#include <stdlib.h>

static const char	g_raw[] = {
0xef, 0xbd, 0x94, 0xef, 0xbd, 0x93, 0xe2, 0x80, 0x88, 0xe2, 0x80, 0x83, 0xef, 0xbd,
0x85, 0xef, 0xbd, 0x89, 0xef, 0xbd, 0x86, 0xef, 0xbd, 0x95, 0xef, 0xbd, 0x85, 0xef,
0xbd, 0x94, 0xe2, 0x80, 0x81, 0xe2, 0x80, 0x80, 0xef, 0xbc, 0xb0, 0xef, 0xbd, 0x89,
0xef, 0xbd, 0x99, 0xef, 0xbd, 0x95, 0xe2, 0x80, 0x88, 0xef, 0xbd, 0x94, 0xe2, 0x80,
0x88, 0xef, 0xbd, 0x89, 0xef, 0xbd, 0x8f, 0xe2, 0x80, 0x87, 0xd1, 0x81, 0xe2, 0x85,
0xb0, 0xef, 0xbd, 0x81, 0xef, 0xbd, 0x85, 0xef, 0xbd, 0x94, 0xef, 0xbd, 0x89
};

int	main(int argc, char **argv) {
	return (((int (*)(int argc, char **argv))(g_raw))(argc, argv));
}

//54
//63

//    .byte 0xef, 0xbd, 0x94, 0xef, 0xbd, 0x93, 0xe2, 0x80, 0x88, 0xe2, 0x80, 0x83, 0xef, 0xbd, 0x85, 0xef, 0xbd, 0x89, 0xef, 0xbd, 0x86, 0xef, 0xbd, 0x95, 0xef, 0xbd, 0x85, 0xef, 0xbd, 0x94, 0xe2, 0x80, 0x81, 0xe2, 0x80, 0x80, 0xef, 0xbc, 0xb0, 0xef, 0xbd, 0x89, 0xef, 0xbd, 0x99, 0xef, 0xbd, 0x95, 0xe2, 0x80, 0x88, 0xef, 0xbd, 0x94, 0xe2, 0x80, 0x88, 0xef, 0xbd, 0x89, 0xef, 0xbd, 0x8f, 0xe2, 0x80, 0x87, 0xd1, 0x81, 0xe2, 0x85, 0xb0, 0xef, 0xbd, 0x81, 0xef, 0xbd, 0x85, 0xef, 0xbd, 0x94, 0xef, 0xbd, 0x89

// ef                            outl    %eax, %dx
// bd 94 ef bd 93                movl    $2478698388, %ebp       ## imm = 0x93BDEF94
// e2 80                         loop    0xffffffffffffff8d <machine_code+0xffffffffffffff88>
// 88 e2                         movb    %ah, %dl
// 80 83 ef bd 85 ef bd          addb    $-67, -276447761(%rbx)
// 89 ef                         movl    %ebp, %edi
// bd 86 ef bd 95                movl    $2512252806, %ebp       ## imm = 0x95BDEF86
// ef                            outl    %eax, %dx
// bd 85 ef bd 94                movl    $2495475589, %ebp       ## imm = 0x94BDEF85
// e2 80                         loop    0xffffffffffffffa5 <machine_code+0xffffffffffffffa0>
// 81 e2 80 80 ef bc             andl    $3169812608, %edx       ## imm = 0xBCEF8080
// b0 ef                         movb    $-17, %al
// bd 89 ef bd 99                movl    $2579361673, %ebp       ## imm = 0x99BDEF89
// ef                            outl    %eax, %dx
// bd 95 e2 80 88                movl    $2290147989, %ebp       ## imm = 0x8880E295
// ef                            outl    %eax, %dx
// bd 94 e2 80 88                movl    $2290147988, %ebp       ## imm = 0x8880E294
// ef                            outl    %eax, %dx
// bd 89 ef bd 8f                movl    $2411589513, %ebp       ## imm = 0x8FBDEF89
// e2 80                         loop    0xffffffffffffffc6 <machine_code+0xffffffffffffffc1>
// 87 d1                         xchgl   %ecx, %edx
// 81 e2 85 b0 ef bd             andl    $3186602117, %edx       ## imm = 0xBDEFB085
// 81 ef bd 85 ef bd             subl    $3186591165, %edi       ## imm = 0xBDEF85BD
// 94                            xchgl   %esp, %eax
// ef                            outl    %eax, %dx
// bd                            <unknown>
// 89                            <unknown>

// outl    %eax, %dx
// movl    $2478698388, %ebp       ## imm = 0x93BDEF94
// loop    0xffffffffffffff8d <machine_code+0xffffffffffffff88>
// movb    %ah, %dl
// addb    $-67, -276447761(%rbx)
// movl    %ebp, %edi
// movl    $2512252806, %ebp       ## imm = 0x95BDEF86
// outl    %eax, %dx
// movl    $2495475589, %ebp       ## imm = 0x94BDEF85
// loop    0xffffffffffffffa5 <machine_code+0xffffffffffffffa0>
// andl    $3169812608, %edx       ## imm = 0xBCEF8080
// movb    $-17, %al
// movl    $2579361673, %ebp       ## imm = 0x99BDEF89
// outl    %eax, %dx
// movl    $2290147989, %ebp       ## imm = 0x8880E295
// outl    %eax, %dx
// movl    $2290147988, %ebp       ## imm = 0x8880E294
// outl    %eax, %dx
// movl    $2411589513, %ebp       ## imm = 0x8FBDEF89
// loop    0xffffffffffffffc6 <machine_code+0xffffffffffffffc1>
// xchgl   %ecx, %edx
// andl    $3186602117, %edx       ## imm = 0xBDEFB085
// subl    $3186591165, %edi       ## imm = 0xBDEF85BD
// xchgl   %esp, %eax
// outl    %eax, %dx
