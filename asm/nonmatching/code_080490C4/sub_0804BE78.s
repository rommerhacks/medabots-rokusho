	.syntax unified

	thumb_func_start sub_0804BE78
sub_0804BE78: @ 0x0804BE78
	push {r4, r5, r6, r7, lr}
	bl read_map_script_byte
	ldr r3, _0804BECC @ =0x030057E0
	ldr r1, _0804BED0 @ =0x00000C94
	adds r6, r3, r1
	strb r0, [r6]
	ldr r4, _0804BED4 @ =0x00000CB4
	adds r0, r3, r4
	ldrb r0, [r0]
	lsls r5, r0, #3
	adds r4, r5, r3
	ldr r7, _0804BED8 @ =0x000005DE
	adds r0, r4, r7
	ldrh r2, [r0]
	ldr r0, _0804BEDC @ =0x00000FFF
	ldr r7, _0804BEE0 @ =0x00000C8E
	adds r1, r3, r7
	ands r0, r2
	ldrh r1, [r1]
	cmp r0, r1
	bne _0804BEC4
	movs r1, #0xbc
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x1b
	lsrs r0, r0, #3
	movs r4, #0xc4
	lsls r4, r4, #0x16
	adds r0, r0, r4
	lsrs r0, r0, #0x18
	ldrb r1, [r6]
	ldr r7, _0804BEE4 @ =0x000005DC
	adds r2, r3, r7
	adds r2, r5, r2
	bl set_sprite_anim_and_store
_0804BEC4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804BECC: .4byte 0x030057E0
_0804BED0: .4byte 0x00000C94
_0804BED4: .4byte 0x00000CB4
_0804BED8: .4byte 0x000005DE
_0804BEDC: .4byte 0x00000FFF
_0804BEE0: .4byte 0x00000C8E
_0804BEE4: .4byte 0x000005DC
	.syntax divided
