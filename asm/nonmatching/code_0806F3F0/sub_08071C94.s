	.syntax unified

	thumb_func_start sub_08071C94
sub_08071C94: @ 0x08071C94
	push {r4, r5, lr}
	ldr r3, _08071CB0 @ =0x03002C30
	adds r2, r3, #0
	adds r2, #0x84
	ldrh r1, [r2]
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r0, #0x3d
	bgt _08071CB4
	adds r1, #2
	strh r1, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	b _08071D08
	.align 2, 0
_08071CB0: .4byte 0x03002C30
_08071CB4:
	cmp r0, #0x41
	bgt _08071CC2
	adds r1, #1
	strh r1, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	b _08071D08
_08071CC2:
	adds r4, r3, #0
	adds r4, #0x9a
	ldrh r0, [r4]
	cmp r0, #0x1f
	bhi _08071CD2
	adds r0, #1
	strh r0, [r4]
	b _08071D0A
_08071CD2:
	adds r2, r3, #0
	adds r2, #0x82
	ldrh r1, [r2]
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmp r0, #0x40
	bgt _08071D00
	movs r0, #6
	bl clear_sprite_entry
	movs r0, #0x54
	bl play_sound_effect
	movs r0, #0
	strh r0, [r4]
	ldr r1, _08071CFC @ =0x03001800
	ldrb r0, [r1, #0x10]
	adds r0, #1
	strb r0, [r1, #0x10]
	movs r0, #1
	b _08071D0C
	.align 2, 0
_08071CFC: .4byte 0x03001800
_08071D00:
	subs r1, #4
	strh r1, [r2]
	adds r0, r3, #0
	adds r0, #0x42
_08071D08:
	strh r1, [r0]
_08071D0A:
	movs r0, #0
_08071D0C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
