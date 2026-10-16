	.syntax unified

	thumb_func_start sub_08026284
sub_08026284: @ 0x08026284
	push {r4, lr}
	ldr r0, _080262E4 @ =0x083B5F80
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x21
	bl process_sprite_anim_commands
	ldr r3, _080262E8 @ =0x03002C30
	ldr r2, _080262EC @ =0x00000862
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _080262DC
	ldr r4, _080262F0 @ =0x00000848
	adds r0, r3, r4
	movs r1, #0x80
	strb r1, [r0]
	subs r2, #0x19
	adds r0, r3, r2
	strb r1, [r0]
	subs r4, #2
	adds r1, r3, r4
	ldr r0, _080262F4 @ =0x00005604
	strh r0, [r1]
	ldr r2, _080262F8 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0x87
	ldrb r0, [r0]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r3
	ldrh r0, [r0, #4]
	subs r0, #4
	subs r4, #2
	adds r1, r3, r4
	strh r0, [r1]
	adds r2, #0xaa
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
_080262DC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080262E4: .4byte 0x083B5F80
_080262E8: .4byte 0x03002C30
_080262EC: .4byte 0x00000862
_080262F0: .4byte 0x00000848
_080262F4: .4byte 0x00005604
_080262F8: .4byte 0x03001800
	.syntax divided
