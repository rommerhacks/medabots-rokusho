	.syntax unified

	thumb_func_start sub_08071D84
sub_08071D84: @ 0x08071D84
	push {r4, lr}
	ldr r2, _08071DA0 @ =0x03002C30
	movs r0, #0x82
	lsls r0, r0, #1
	adds r3, r2, r0
	ldrh r0, [r3]
	movs r4, #0
	ldrsh r1, [r3, r4]
	cmp r1, #0x35
	bgt _08071DA4
	adds r0, #2
	strh r0, [r3]
	b _08071DF4
	.align 2, 0
_08071DA0: .4byte 0x03002C30
_08071DA4:
	cmp r1, #0x39
	bgt _08071DAE
	adds r0, #1
	strh r0, [r3]
	b _08071DF4
_08071DAE:
	movs r0, #0x8d
	lsls r0, r0, #1
	adds r4, r2, r0
	ldrh r0, [r4]
	cmp r0, #0x1f
	bhi _08071DC0
	adds r0, #1
	strh r0, [r4]
	b _08071DF4
_08071DC0:
	movs r3, #0x81
	lsls r3, r3, #1
	adds r1, r2, r3
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0x44
	bgt _08071DF0
	movs r0, #8
	bl clear_sprite_entry
	movs r0, #0x54
	bl play_sound_effect
	movs r0, #0
	strh r0, [r4]
	ldr r1, _08071DEC @ =0x03001800
	ldrb r0, [r1, #0x10]
	adds r0, #1
	strb r0, [r1, #0x10]
	movs r0, #1
	b _08071DF6
	.align 2, 0
_08071DEC: .4byte 0x03001800
_08071DF0:
	subs r0, r2, #4
	strh r0, [r1]
_08071DF4:
	movs r0, #0
_08071DF6:
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
