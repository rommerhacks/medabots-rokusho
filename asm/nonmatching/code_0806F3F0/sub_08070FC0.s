	.syntax unified

	thumb_func_start sub_08070FC0
sub_08070FC0: @ 0x08070FC0
	push {lr}
	ldr r0, _08070FE4 @ =0x03002C30
	movs r1, #0xcc
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08070FE0
	movs r0, #0x19
	movs r1, #0x4b
	bl sound_channel_stop_0807175C
	ldr r1, _08070FE8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08070FE0:
	pop {r0}
	bx r0
	.align 2, 0
_08070FE4: .4byte 0x03002C30
_08070FE8: .4byte 0x0300137C
	.syntax divided
