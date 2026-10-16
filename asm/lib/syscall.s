	.include "asm/macros.inc"

	.syntax unified

	.text


	thumb_func_start CpuFastSet
	.global CpuFastSet
CpuFastSet: @ 0x0807CB50
	svc #0xc
	bx lr

	thumb_func_start CpuSet
	.global CpuSet
CpuSet: @ 0x0807CB54
	svc #0xb
	bx lr

	thumb_func_start Div
	.global Div
Div: @ 0x0807CB58
	svc #6
	bx lr

	thumb_func_start DivArm
	.global DivArm
DivArm: @ 0x0807CB5C
	svc #7
	bx lr

	thumb_func_start Mod
	.global Mod
Mod: @ 0x0807CB60
	svc #6
	adds r0, r1, #0
	bx lr
	.align 2, 0

	thumb_func_start LZ77UnCompVram
	.global LZ77UnCompVram
LZ77UnCompVram: @ 0x0807CB68
	svc #0x12
	bx lr

	thumb_func_start LZ77UnCompWram
	.global LZ77UnCompWram
LZ77UnCompWram: @ 0x0807CB6C
	svc #0x11
	bx lr

	thumb_func_start ObjAffineSet
	.global ObjAffineSet
ObjAffineSet: @ 0x0807CB70
	svc #0xf
	bx lr

	thumb_func_start Sqrt
	.global Sqrt
Sqrt: @ 0x0807CB74
	svc #8
	bx lr

	thumb_func_start VBlankIntrWait
	.global VBlankIntrWait
VBlankIntrWait: @ 0x0807CB78
	movs r2, #0
	svc #5
	bx lr
	.align 2, 0
