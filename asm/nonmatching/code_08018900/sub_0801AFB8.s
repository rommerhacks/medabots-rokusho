	.syntax unified

	thumb_func_start sub_0801AFB8
	.global sub_0801AFB8
sub_0801AFB8: @ 0x0801AFB8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0801AFF4 @ =0x03001800
	adds r2, r0, #0
	adds r2, #0x51
	ldrb r0, [r2]
	cmp r0, #0
	beq _0801AFFC
	ldr r1, _0801AFF8 @ =0x03000590
	lsls r0, r4, #8
	adds r0, r0, r1
	adds r1, r0, #0
	adds r1, #0xc1
	ldrb r0, [r1]
	cmp r0, #0
	beq _0801AFFC
	subs r0, #1
	strb r0, [r1]
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	adds r0, r4, #0
	bl draw_medaforce_gauge_bar
	adds r0, r4, #0
	bl draw_medaforce_gauge_value
	movs r0, #0
	b _0801AFFE
	.align 2, 0
_0801AFF4: .4byte 0x03001800
_0801AFF8: .4byte 0x03000590
_0801AFFC:
	movs r0, #1
_0801AFFE:
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
