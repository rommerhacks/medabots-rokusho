	.syntax unified

	thumb_func_start sub_080272EC
sub_080272EC: @ 0x080272EC
	push {lr}
	ldr r0, _08027328 @ =0x083B5F80
	movs r1, #0xb4
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x21
	bl process_sprite_anim_commands
	ldr r0, _0802732C @ =0x03002C30
	ldr r1, _08027330 @ =0x00000862
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _08027322
	ldr r0, _08027334 @ =0x03000440
	adds r0, #0x86
	movs r1, #0
	strh r1, [r0]
	movs r0, #0x73
	bl play_sound_effect
	ldr r1, _08027338 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08027322:
	pop {r0}
	bx r0
	.align 2, 0
_08027328: .4byte 0x083B5F80
_0802732C: .4byte 0x03002C30
_08027330: .4byte 0x00000862
_08027334: .4byte 0x03000440
_08027338: .4byte 0x03001800
	.syntax divided
