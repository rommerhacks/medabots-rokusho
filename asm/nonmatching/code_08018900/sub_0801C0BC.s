	.syntax unified

	thumb_func_start sub_0801C0BC
	.global sub_0801C0BC
sub_0801C0BC: @ 0x0801C0BC
	push {r4, lr}
	ldr r1, _0801C0E4 @ =0x03001800
	adds r2, r1, #0
	adds r2, #0xa2
	strb r0, [r2]
	ldr r2, _0801C0E8 @ =0x083AD400
	adds r4, r1, #0
	adds r4, #0xa1
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl _call_via_r0
	ldrb r0, [r4]
	cmp r0, #3
	beq _0801C0EC
	movs r0, #0
	b _0801C0F2
	.align 2, 0
_0801C0E4: .4byte 0x03001800
_0801C0E8: .4byte 0x083AD400
_0801C0EC:
	movs r0, #0
	strb r0, [r4]
	movs r0, #1
_0801C0F2:
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
