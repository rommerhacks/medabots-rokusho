	.syntax unified

	thumb_func_start sub_08070F7C
sub_08070F7C: @ 0x08070F7C
	push {lr}
	ldr r0, _08070FB8 @ =0x03002C30
	movs r1, #0xc4
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08070FB2
	movs r0, #0x18
	movs r1, #0x3f
	movs r2, #0xc
	bl sound_channel_set_note
	movs r0, #0x19
	movs r1, #0x4e
	movs r2, #8
	bl sound_channel_set_note
	movs r0, #6
	movs r1, #0x19
	movs r2, #0x60
	bl sub_08071C40
	ldr r1, _08070FBC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08070FB2:
	pop {r0}
	bx r0
	.align 2, 0
_08070FB8: .4byte 0x03002C30
_08070FBC: .4byte 0x0300137C
	.syntax divided
