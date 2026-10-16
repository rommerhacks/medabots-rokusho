	.syntax unified

	thumb_func_start sub_08015F90
sub_08015F90: @ 0x08015F90
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r1, _08015FEC @ =0x03002C30
	lsls r0, r5, #6
	adds r4, r0, r1
	ldr r0, _08015FF0 @ =0x0000C604
	strh r0, [r4]
	ldr r0, _08015FF4 @ =0x03001800
	adds r0, #0x81
	ldrb r0, [r0]
	subs r6, r5, r0
	cmp r6, #5
	bls _08015FB8
	adds r6, #6
_08015FB8:
	ldr r0, _08015FF8 @ =0x083AD370
	adds r0, r6, r0
	ldrb r1, [r0]
	movs r0, #0x80
	str r0, [sp]
	movs r7, #8
	str r7, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	add r0, sp, #0xc
	movs r2, #0x18
	movs r3, #0x78
	bl compute_polar_to_screen_position
	ldr r0, [sp, #0xc]
	strh r0, [r4, #2]
	asrs r0, r0, #0x10
	strh r0, [r4, #4]
	ldr r2, _08015FFC @ =0x0000060C
	adds r1, r5, r2
	strh r1, [r4, #6]
	cmp r0, #0x87
	ble _08016000
	strb r7, [r4, #0xa]
	b _0801600C
	.align 2, 0
_08015FEC: .4byte 0x03002C30
_08015FF0: .4byte 0x0000C604
_08015FF4: .4byte 0x03001800
_08015FF8: .4byte 0x083AD370
_08015FFC: .4byte 0x0000060C
_08016000:
	cmp r0, #0x77
	ble _08016008
	movs r0, #9
	b _0801600A
_08016008:
	movs r0, #0xa
_0801600A:
	strb r0, [r4, #0xa]
_0801600C:
	ldr r1, _08016060 @ =0x03002C30
	lsls r0, r5, #6
	adds r0, r0, r1
	mov ip, r0
	movs r3, #0
	strb r3, [r0, #0x1c]
	movs r4, #4
	ldrsh r0, [r0, r4]
	movs r1, #0x90
	subs r0, r1, r0
	lsrs r2, r0, #0x1f
	adds r0, r0, r2
	asrs r0, r0, #1
	movs r2, #0x40
	subs r0, r2, r0
	mov r5, ip
	strb r0, [r5, #9]
	movs r4, #4
	ldrsh r0, [r5, r4]
	subs r1, r1, r0
	lsrs r0, r1, #0x1f
	adds r1, r1, r0
	asrs r1, r1, #1
	subs r2, r2, r1
	strb r2, [r5, #8]
	ldrb r0, [r5, #4]
	subs r0, #0x70
	strb r0, [r5, #0xb]
	ldr r0, _08016064 @ =0x083AD370
	adds r0, r6, r0
	ldrb r1, [r0]
	mov r0, ip
	adds r0, #0x20
	strb r1, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08016060: .4byte 0x03002C30
_08016064: .4byte 0x083AD370
	.syntax divided
