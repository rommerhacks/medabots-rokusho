	.syntax unified

	thumb_func_start sub_0802B388
sub_0802B388: @ 0x0802B388
	push {r4, r5, r6, r7, lr}
	movs r6, #0
	movs r5, #0
	movs r4, #0
	ldr r7, _0802B3C4 @ =0x030018D2
_0802B392:
	adds r0, r4, r7
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802B3AA
	adds r5, #1
	adds r0, r4, #0
	adds r0, #0x21
	bl move_sprite_toward_target
	cmp r0, #0
	beq _0802B3AA
	adds r6, #1
_0802B3AA:
	adds r4, #1
	cmp r4, #2
	bls _0802B392
	cmp r6, r5
	bne _0802B3BE
	ldr r1, _0802B3C8 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802B3BE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802B3C4: .4byte 0x030018D2
_0802B3C8: .4byte 0x03001800
	.syntax divided
