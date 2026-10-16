	.include "asm/macros.inc"
	.syntax unified
	.text

@ libgcc interworking call veneers (_call_via_rN)

	thumb_func_start _call_via_r0
_call_via_r0: @ 0x0807CB80
	bx r0
	nop

	thumb_func_start _call_via_r1
_call_via_r1: @ 0x0807CB84
	bx r1
	nop

	thumb_func_start _call_via_r2
_call_via_r2: @ 0x0807CB88
	bx r2
	nop

	thumb_func_start _call_via_r3
_call_via_r3: @ 0x0807CB8C
	bx r3
	nop

	thumb_func_start _call_via_r4
_call_via_r4: @ 0x0807CB90
	bx r4
	nop

	thumb_func_start _call_via_r5
_call_via_r5: @ 0x0807CB94
	bx r5
	nop

	thumb_func_start _call_via_r6
_call_via_r6: @ 0x0807CB98
	bx r6
	nop

	thumb_func_start _call_via_r7
_call_via_r7: @ 0x0807CB9C
	bx r7
	nop

	thumb_func_start _call_via_r8
_call_via_r8: @ 0x0807CBA0
	bx r8
	nop

	thumb_func_start _call_via_r9
_call_via_r9: @ 0x0807CBA4
	bx r9
	nop

	thumb_func_start _call_via_r10
_call_via_r10: @ 0x0807CBA8
	bx r10
	nop

	thumb_func_start _call_via_r11
_call_via_r11: @ 0x0807CBAC
	bx r11
	nop

	thumb_func_start _call_via_r12
_call_via_r12: @ 0x0807CBB0
	bx r12
	nop

	thumb_func_start _call_via_sp
_call_via_sp: @ 0x0807CBB4
	bx sp
	nop

	thumb_func_start _call_via_lr
_call_via_lr: @ 0x0807CBB8
	bx lr
	nop

