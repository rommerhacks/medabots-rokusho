	.syntax unified

	thumb_func_start sub_08070EE4
sub_08070EE4: @ 0x08070EE4
	push {lr}
	ldr r0, _08070F28 @ =0x03002C30
	ldr r1, _08070F2C @ =0x000002A2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08070F22
	movs r0, #0x16
	movs r1, #0x2d
	movs r2, #8
	bl sound_channel_set_note
	movs r0, #0x17
	movs r1, #0x36
	movs r2, #8
	bl sound_channel_set_note
	movs r0, #5
	movs r1, #0x16
	movs r2, #0x48
	bl sub_08071C40
	movs r0, #6
	movs r1, #0x17
	movs r2, #0x48
	bl sub_08071C40
	ldr r1, _08070F30 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08070F22:
	pop {r0}
	bx r0
	.align 2, 0
_08070F28: .4byte 0x03002C30
_08070F2C: .4byte 0x000002A2
_08070F30: .4byte 0x0300137C
	.syntax divided
