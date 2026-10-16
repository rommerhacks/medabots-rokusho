	.syntax unified

	thumb_func_start sub_08071E80
sub_08071E80: @ 0x08071E80
	push {lr}
	ldr r2, _08071EE8 @ =0x03002C30
	ldrh r1, [r2, #0x1a]
	adds r0, r1, #1
	strh r0, [r2, #0x1a]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08071EA4
	ldrh r0, [r2, #4]
	adds r0, #1
	strh r0, [r2, #4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08071EA4
	movs r0, #0x59
	bl play_sound_effect
_08071EA4:
	ldr r2, _08071EE8 @ =0x03002C30
	ldrh r0, [r2, #0x1a]
	lsrs r0, r0, #2
	movs r1, #3
	ands r0, r1
	ldr r1, _08071EEC @ =0x0000050F
	adds r0, r0, r1
	strh r0, [r2, #6]
	movs r1, #4
	ldrsh r0, [r2, r1]
	cmp r0, #0x3f
	ble _08071EE2
	movs r0, #7
	bl play_sound_effect
	ldr r0, _08071EF0 @ =0x0300700C
	ldr r3, _08071EF4 @ =0x0202FA00
	str r3, [r0]
	ldr r2, _08071EF8 @ =0x03001800
	movs r0, #0
	strb r0, [r2, #0x11]
	ldr r1, _08071EFC @ =0x040000D4
	ldr r0, _08071F00 @ =0x05000200
	str r0, [r1]
	str r3, [r1, #4]
	ldr r0, _08071F04 @ =0x84000080
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldrb r0, [r2, #0x10]
	adds r0, #1
	strb r0, [r2, #0x10]
_08071EE2:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08071EE8: .4byte 0x03002C30
_08071EEC: .4byte 0x0000050F
_08071EF0: .4byte 0x0300700C
_08071EF4: .4byte 0x0202FA00
_08071EF8: .4byte 0x03001800
_08071EFC: .4byte 0x040000D4
_08071F00: .4byte 0x05000200
_08071F04: .4byte 0x84000080
	.syntax divided
