	.syntax unified

	thumb_func_start sub_0802DA0C
sub_0802DA0C: @ 0x0802DA0C
	push {r4, r5, r6, r7, lr}
	movs r6, #0
	movs r5, #0
	movs r4, #0
	ldr r7, _0802DA54 @ =0x030018D2
_0802DA16:
	adds r0, r4, r7
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802DA30
	adds r5, #1
	adds r0, r4, #0
	adds r0, #0x24
	movs r1, #0
	bl advance_sprite_anim_frame
	cmp r0, #0
	beq _0802DA30
	adds r6, #1
_0802DA30:
	adds r4, #1
	cmp r4, #2
	bls _0802DA16
	cmp r6, r5
	bne _0802DA4C
	ldr r0, _0802DA58 @ =0x03000440
	adds r0, #0x86
	movs r1, #0x3c
	strh r1, [r0]
	ldr r1, _0802DA5C @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802DA4C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802DA54: .4byte 0x030018D2
_0802DA58: .4byte 0x03000440
_0802DA5C: .4byte 0x03001800
	.syntax divided
