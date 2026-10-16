	.syntax unified

	thumb_func_start sub_0801E830
sub_0801E830: @ 0x0801E830
	push {r4, lr}
	ldr r4, _0801E85C @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x8b
	ldrb r1, [r0]
	movs r0, #0xa
	bl sub_080366DC
	cmp r0, #0
	beq _0801E856
	ldr r0, _0801E860 @ =0x03000440
	adds r0, #0x86
	movs r1, #0x3c
	strh r1, [r0]
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0801E856:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801E85C: .4byte 0x03001800
_0801E860: .4byte 0x03000440
	.syntax divided
