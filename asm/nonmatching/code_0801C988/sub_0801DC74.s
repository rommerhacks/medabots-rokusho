	.syntax unified

	thumb_func_start sub_0801DC74
sub_0801DC74: @ 0x0801DC74
	push {r4, r5, lr}
	ldr r0, _0801DC88 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x84
	ldrb r0, [r1]
	cmp r0, #0x1e
	beq _0801DC8C
	adds r0, #1
	strb r0, [r1]
	b _0801DD08
	.align 2, 0
_0801DC88: .4byte 0x03000440
_0801DC8C:
	movs r0, #0x21
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r2, _0801DD10 @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r1, r2, r0
	movs r3, #0
	ldr r0, _0801DD14 @ =0x0000C624
	strh r0, [r1]
	ldr r1, _0801DD18 @ =0x0000085C
	adds r0, r2, r1
	strb r3, [r0]
	ldr r4, _0801DD1C @ =0x03001800
	adds r3, r4, #0
	adds r3, #0xde
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r5, #0xb2
	lsls r5, r5, #5
	adds r0, r0, r5
	adds r0, r0, r2
	ldrh r1, [r0, #2]
	ldr r5, _0801DD20 @ =0x00000842
	adds r0, r2, r5
	strh r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r1, #0xb2
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r0, [r0, #4]
	subs r0, #4
	ldr r3, _0801DD24 @ =0x00000844
	adds r1, r2, r3
	strh r0, [r1]
	adds r5, #8
	adds r1, r2, r5
	movs r0, #6
	strb r0, [r1]
	ldr r1, _0801DD28 @ =0x00000848
	adds r0, r2, r1
	movs r1, #0x80
	strb r1, [r0]
	adds r3, #5
	adds r0, r2, r3
	strb r1, [r0]
	adds r5, #1
	adds r2, r2, r5
	movs r0, #0xf0
	strb r0, [r2]
	ldr r0, _0801DD2C @ =0x083B5F80
	ldr r0, [r0, #0x70]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	adds r4, #0xaa
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_0801DD08:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801DD10: .4byte 0x03002C30
_0801DD14: .4byte 0x0000C624
_0801DD18: .4byte 0x0000085C
_0801DD1C: .4byte 0x03001800
_0801DD20: .4byte 0x00000842
_0801DD24: .4byte 0x00000844
_0801DD28: .4byte 0x00000848
_0801DD2C: .4byte 0x083B5F80
	.syntax divided
