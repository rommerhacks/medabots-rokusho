	.syntax unified

	thumb_func_start sub_08071D14
sub_08071D14: @ 0x08071D14
	push {r4, lr}
	ldr r2, _08071D2C @ =0x03002C30
	adds r3, r2, #0
	adds r3, #0xc4
	ldrh r0, [r3]
	movs r4, #0
	ldrsh r1, [r3, r4]
	cmp r1, #0x35
	bgt _08071D30
	adds r0, #2
	strh r0, [r3]
	b _08071D7C
	.align 2, 0
_08071D2C: .4byte 0x03002C30
_08071D30:
	cmp r1, #0x39
	bgt _08071D3A
	adds r0, #1
	strh r0, [r3]
	b _08071D7C
_08071D3A:
	adds r4, r2, #0
	adds r4, #0xda
	ldrh r0, [r4]
	cmp r0, #0x1f
	bhi _08071D4A
	adds r0, #1
	strh r0, [r4]
	b _08071D7C
_08071D4A:
	adds r1, r2, #0
	adds r1, #0xc2
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0x37
	ble _08071D78
	movs r0, #7
	bl clear_sprite_entry
	movs r0, #0x54
	bl play_sound_effect
	movs r0, #0
	strh r0, [r4]
	ldr r1, _08071D74 @ =0x03001800
	ldrb r0, [r1, #0x10]
	adds r0, #1
	strb r0, [r1, #0x10]
	movs r0, #1
	b _08071D7E
	.align 2, 0
_08071D74: .4byte 0x03001800
_08071D78:
	adds r0, r2, #4
	strh r0, [r1]
_08071D7C:
	movs r0, #0
_08071D7E:
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
