	.syntax unified

	thumb_func_start sub_08070F34
sub_08070F34: @ 0x08070F34
	push {lr}
	ldr r0, _08070F74 @ =0x03002C30
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08070F70
	movs r0, #0x16
	movs r1, #0x27
	bl sound_channel_stop_0807175C
	movs r0, #0x17
	movs r1, #0x33
	bl sound_channel_stop_0807175C
	movs r0, #0x18
	movs r1, #0x45
	movs r2, #8
	bl sound_channel_set_note
	movs r0, #7
	movs r1, #0x18
	movs r2, #0x60
	bl sub_08071C40
	ldr r1, _08070F78 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08070F70:
	pop {r0}
	bx r0
	.align 2, 0
_08070F74: .4byte 0x03002C30
_08070F78: .4byte 0x0300137C
	.syntax divided
