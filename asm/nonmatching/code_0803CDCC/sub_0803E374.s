	.syntax unified

	thumb_func_start sub_0803E374
sub_0803E374: @ 0x0803E374
	push {r4, lr}
	bl sub_0803E894
	bl draw_battle_bg1_tilemap_row
	ldr r4, _0803E3B8 @ =0x03000440
	adds r1, r4, #0
	adds r1, #0x86
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bl sub_0803EE10
	adds r4, #0x9c
	ldrb r0, [r4]
	cmp r0, #1
	bne _0803E3C4
	ldr r1, _0803E3BC @ =0x03001800
	ldr r2, _0803E3C0 @ =0x000001A5
	adds r0, r1, r2
	ldrb r0, [r0]
	movs r3, #0xd1
	lsls r3, r3, #1
	adds r2, r1, r3
	movs r4, #0xcd
	lsls r4, r4, #1
	adds r1, r1, r4
	ldrb r2, [r2]
	adds r1, r1, r2
	ldrb r1, [r1]
	movs r2, #1
	bl medapart_add_quantity
	b _0803E3E4
	.align 2, 0
_0803E3B8: .4byte 0x03000440
_0803E3BC: .4byte 0x03001800
_0803E3C0: .4byte 0x000001A5
_0803E3C4:
	ldr r1, _0803E420 @ =0x03001800
	movs r2, #0xd2
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrb r0, [r0]
	movs r3, #0xd1
	lsls r3, r3, #1
	adds r2, r1, r3
	movs r4, #0xcd
	lsls r4, r4, #1
	adds r1, r1, r4
	ldrb r2, [r2]
	adds r1, r1, r2
	ldrb r1, [r1]
	bl sub_080421B4
_0803E3E4:
	ldr r2, _0803E424 @ =0x083BB9CC
	ldr r1, _0803E420 @ =0x03001800
	ldr r3, _0803E428 @ =0x000001A5
	adds r0, r1, r3
	ldrb r0, [r0]
	movs r4, #0xd1
	lsls r4, r4, #1
	adds r3, r1, r4
	subs r4, #8
	adds r1, r1, r4
	ldrb r3, [r3]
	adds r1, r1, r3
	lsls r0, r0, #2
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ldr r1, _0803E42C @ =0x030004DE
	movs r2, #0xf
	bl memcpy_bytes_08041D04
	ldr r1, _0803E430 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803E420: .4byte 0x03001800
_0803E424: .4byte 0x083BB9CC
_0803E428: .4byte 0x000001A5
_0803E42C: .4byte 0x030004DE
_0803E430: .4byte 0x0300137C
	.syntax divided
