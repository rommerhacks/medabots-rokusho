	.syntax unified

	thumb_func_start sub_08072010
sub_08072010: @ 0x08072010
	push {lr}
	sub sp, #0x24
	ldr r2, _0807202C @ =0x03002C30
	adds r0, r2, #0
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08072030
	adds r1, r2, #0
	adds r1, #0x44
	movs r0, #0xc8
	b _08072036
	.align 2, 0
_0807202C: .4byte 0x03002C30
_08072030:
	adds r1, r2, #0
	adds r1, #0x44
	movs r0, #0x42
_08072036:
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0x5a
	ldrh r1, [r0]
	adds r2, r1, #1
	strh r2, [r0]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0x1f
	bls _0807209E
	movs r0, #1
	bl sub_0806B584
	bl init_scene_buffers_080445F4
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x20]
	ldr r1, _080720A8 @ =0x040000D4
	add r0, sp, #0x20
	str r0, [r1]
	ldr r0, _080720AC @ =0x03002414
	ldr r0, [r0]
	ldr r2, _080720B0 @ =0x00000B84
	adds r0, r0, r2
	str r0, [r1, #4]
	ldr r0, _080720B4 @ =0x85000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0x2a
	str r0, [sp]
	movs r0, #0x40
	str r0, [sp, #4]
	movs r0, #0x42
	str r0, [sp, #8]
	movs r0, #2
	str r0, [sp, #0xc]
	movs r0, #8
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	str r0, [sp, #0x18]
	str r0, [sp, #0x1c]
	movs r1, #0x2a
	movs r2, #0x2a
	movs r3, #0x2a
	bl setup_scene_with_bg_and_sprites
	ldr r1, _080720B8 @ =0x03001800
	ldrb r0, [r1, #0x10]
	adds r0, #1
	strb r0, [r1, #0x10]
_0807209E:
	movs r0, #0
	add sp, #0x24
	pop {r1}
	bx r1
	.align 2, 0
_080720A8: .4byte 0x040000D4
_080720AC: .4byte 0x03002414
_080720B0: .4byte 0x00000B84
_080720B4: .4byte 0x85000100
_080720B8: .4byte 0x03001800
	.syntax divided
