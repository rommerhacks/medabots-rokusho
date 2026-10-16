	.syntax unified

	thumb_func_start sub_08029178
sub_08029178: @ 0x08029178
	push {r4, r5, r6, r7, lr}
	movs r5, #0
	ldr r7, _080291CC @ =0x083B600C
	movs r6, #0x84
	lsls r6, r6, #0x16
_08029182:
	ldr r0, [r7]
	adds r4, r5, #0
	adds r4, #0x21
	lsrs r1, r6, #0x18
	bl process_sprite_anim_commands
	adds r0, r4, #0
	bl update_sprite_animation_position
	movs r0, #0x80
	lsls r0, r0, #0x11
	adds r6, r6, r0
	adds r5, #1
	cmp r5, #4
	bls _08029182
	ldr r0, _080291D0 @ =0x03002C30
	ldr r1, _080291D4 @ =0x00000862
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _080291C6
	movs r0, #0x21
	movs r1, #5
	bl clear_battle_sprite_slot
	ldr r0, _080291D8 @ =0x03000440
	adds r0, #0x86
	movs r1, #0x3c
	strh r1, [r0]
	ldr r1, _080291DC @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_080291C6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080291CC: .4byte 0x083B600C
_080291D0: .4byte 0x03002C30
_080291D4: .4byte 0x00000862
_080291D8: .4byte 0x03000440
_080291DC: .4byte 0x03001800
	.syntax divided
