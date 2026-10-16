	.syntax unified

	thumb_func_start sub_0801C154
	.global sub_0801C154
sub_0801C154: @ 0x0801C154
	push {r4, lr}
	ldr r1, _0801C174 @ =0x083AD410
	ldr r0, _0801C178 @ =0x03001800
	adds r4, r0, #0
	adds r4, #0x9c
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	ldrb r0, [r4]
	cmp r0, #4
	beq _0801C17C
	movs r0, #0
	b _0801C182
	.align 2, 0
_0801C174: .4byte 0x083AD410
_0801C178: .4byte 0x03001800
_0801C17C:
	movs r0, #0
	strb r0, [r4]
	movs r0, #1
_0801C182:
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
