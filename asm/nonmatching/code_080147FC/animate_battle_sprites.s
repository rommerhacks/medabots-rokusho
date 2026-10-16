	.syntax unified

	thumb_func_start animate_battle_sprites
	.global animate_battle_sprites
animate_battle_sprites: @ 0x080164F4
	push {r4, r5, r6, lr}
	ldr r1, _08016548 @ =0x083AD382
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r6, [r0]
	movs r4, #0
	cmp r4, r6
	bhs _08016540
	ldr r0, _0801654C @ =0x03002C30
	ldr r1, _08016550 @ =0x00000F06
	adds r2, r0, r1
_0801650A:
	ldrb r0, [r2, #0x1e]
	movs r5, #0x16
	cmp r0, #0
	beq _08016514
	movs r5, #0x12
_08016514:
	ldrb r1, [r2, #0x1b]
	adds r1, #1
	strb r1, [r2, #0x1b]
	movs r3, #3
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	bne _08016538
	ldrb r0, [r2, #0x1c]
	adds r0, #1
	ands r0, r3
	strb r0, [r2, #0x1c]
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r1, r3, #0
	orrs r0, r1
	adds r0, r5, r0
	strh r0, [r2]
_08016538:
	adds r2, #0x40
	adds r4, #1
	cmp r4, r6
	blo _0801650A
_08016540:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08016548: .4byte 0x083AD382
_0801654C: .4byte 0x03002C30
_08016550: .4byte 0x00000F06
	.syntax divided
