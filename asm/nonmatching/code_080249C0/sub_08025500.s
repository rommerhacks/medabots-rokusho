	.syntax unified

	thumb_func_start sub_08025500
sub_08025500: @ 0x08025500
	push {lr}
	movs r0, #0x21
	bl move_sprite_toward_target
	cmp r0, #0
	beq _08025536
	ldr r1, _0802555C @ =0x03002C30
	ldr r2, _08025560 @ =0x00000842
	adds r0, r1, r2
	ldrh r2, [r0]
	ldr r3, _08025564 @ =0x00000882
	adds r0, r1, r3
	strh r2, [r0]
	ldr r2, _08025568 @ =0x00000844
	adds r0, r1, r2
	ldrh r0, [r0]
	adds r3, #2
	adds r1, r1, r3
	strh r0, [r1]
	movs r0, #0x2b
	bl play_sound_effect
	ldr r1, _0802556C @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08025536:
	movs r0, #0x21
	bl sub_08037424
	ldr r1, _0802555C @ =0x03002C30
	ldr r2, _08025560 @ =0x00000842
	adds r0, r1, r2
	ldrh r2, [r0]
	ldr r3, _08025564 @ =0x00000882
	adds r0, r1, r3
	strh r2, [r0]
	ldr r2, _08025568 @ =0x00000844
	adds r0, r1, r2
	ldrh r0, [r0]
	adds r3, #2
	adds r1, r1, r3
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0802555C: .4byte 0x03002C30
_08025560: .4byte 0x00000842
_08025564: .4byte 0x00000882
_08025568: .4byte 0x00000844
_0802556C: .4byte 0x03001800
	.syntax divided
