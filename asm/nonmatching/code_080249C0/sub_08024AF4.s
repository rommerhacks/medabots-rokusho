	.syntax unified

	thumb_func_start sub_08024AF4
sub_08024AF4: @ 0x08024AF4
	push {r4, r5, r6, lr}
	movs r0, #0x21
	movs r1, #1
	bl clear_sprite_table_mask
	ldr r4, _08024B6C @ =0x03002C30
	movs r0, #0x88
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r5, #0
	ldr r0, _08024B70 @ =0x0000C404
	strh r0, [r1]
	ldr r1, _08024B74 @ =0x0000089C
	adds r0, r4, r1
	strb r5, [r0]
	ldr r2, _08024B78 @ =0x03001800
	adds r3, r2, #0
	adds r3, #0x88
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r6, #0xba
	lsls r6, r6, #5
	adds r0, r0, r6
	adds r0, r0, r4
	ldrh r1, [r0, #2]
	ldr r6, _08024B7C @ =0x00000882
	adds r0, r4, r6
	strh r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r4
	ldrh r0, [r0, #4]
	subs r0, #4
	ldr r3, _08024B80 @ =0x00000884
	adds r1, r4, r3
	strh r0, [r1]
	adds r6, #8
	adds r1, r4, r6
	movs r0, #7
	strb r0, [r1]
	ldr r0, _08024B84 @ =0x0000088B
	adds r1, r4, r0
	movs r0, #0xe0
	strb r0, [r1]
	ldr r1, _08024B88 @ =0x000008A3
	adds r0, r4, r1
	strb r5, [r0]
	adds r2, #0x8b
	ldrb r0, [r2]
	cmp r0, #1
	beq _08024B90
	cmp r0, #2
	beq _08024BA0
	adds r3, #2
	adds r1, r4, r3
	ldr r0, _08024B8C @ =0x00004E01
	b _08024BA6
	.align 2, 0
_08024B6C: .4byte 0x03002C30
_08024B70: .4byte 0x0000C404
_08024B74: .4byte 0x0000089C
_08024B78: .4byte 0x03001800
_08024B7C: .4byte 0x00000882
_08024B80: .4byte 0x00000884
_08024B84: .4byte 0x0000088B
_08024B88: .4byte 0x000008A3
_08024B8C: .4byte 0x00004E01
_08024B90:
	ldr r6, _08024B98 @ =0x00000886
	adds r1, r4, r6
	ldr r0, _08024B9C @ =0x00004E02
	b _08024BA6
	.align 2, 0
_08024B98: .4byte 0x00000886
_08024B9C: .4byte 0x00004E02
_08024BA0:
	ldr r0, _08024BC0 @ =0x00000886
	adds r1, r4, r0
	ldr r0, _08024BC4 @ =0x00004E03
_08024BA6:
	strh r0, [r1]
	movs r0, #0x6a
	bl play_sound_effect
	ldr r1, _08024BC8 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08024BC0: .4byte 0x00000886
_08024BC4: .4byte 0x00004E03
_08024BC8: .4byte 0x03001800
	.syntax divided
