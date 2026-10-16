	.syntax unified

	thumb_func_start sub_080215C8
sub_080215C8: @ 0x080215C8
	push {lr}
	ldr r1, _080215F8 @ =0x03002C30
	ldr r0, _080215FC @ =0x00000864
	adds r2, r1, r0
	movs r3, #0
	movs r0, #4
	strb r0, [r2]
	ldr r2, _08021600 @ =0x00000865
	adds r0, r1, r2
	strb r3, [r0]
	movs r0, #0x87
	lsls r0, r0, #4
	adds r1, r1, r0
	strh r3, [r1]
	movs r0, #0x40
	bl play_sound_effect
	ldr r1, _08021604 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080215F8: .4byte 0x03002C30
_080215FC: .4byte 0x00000864
_08021600: .4byte 0x00000865
_08021604: .4byte 0x03001800
	.syntax divided
