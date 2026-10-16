	.syntax unified

	thumb_func_start sub_0803E120
sub_0803E120: @ 0x0803E120
	push {lr}
	bl sub_0803E894
	bl draw_battle_bg1_tilemap_row
	ldr r1, _0803E154 @ =0x03000440
	adds r1, #0x86
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r0, _0803E158 @ =0x03001800
	movs r2, #0xd1
	lsls r2, r2, #1
	adds r1, r0, r2
	subs r2, #8
	adds r0, r0, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne _0803E160
	ldr r1, _0803E15C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _0803E164
	.align 2, 0
_0803E154: .4byte 0x03000440
_0803E158: .4byte 0x03001800
_0803E15C: .4byte 0x0300137C
_0803E160:
	ldr r1, _0803E16C @ =0x0300137C
	movs r0, #0x48
_0803E164:
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0803E16C: .4byte 0x0300137C
	.syntax divided
