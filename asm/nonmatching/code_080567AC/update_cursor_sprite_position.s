	.syntax unified

	thumb_func_start update_cursor_sprite_position
update_cursor_sprite_position: @ 0x08057EDC
	push {r4, lr}
	ldr r0, _08057F54 @ =0x030064A0
	mov ip, r0
	adds r0, #0x67
	ldrb r0, [r0]
	movs r1, #4
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x1a
	movs r1, #8
	ands r1, r0
	cmp r1, #0
	beq _08057EF8
	rsbs r3, r3, #0
_08057EF8:
	ldr r2, _08057F58 @ =0x03002C30
	mov r0, ip
	adds r0, #0x6c
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r1, r3, #0
	adds r1, #8
	adds r0, r0, r1
	ldr r3, _08057F5C @ =0x00001FC2
	adds r1, r2, r3
	movs r3, #0
	strh r0, [r1]
	mov r0, ip
	adds r0, #0x6d
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, #8
	ldr r4, _08057F60 @ =0x00001FC4
	adds r1, r2, r4
	strh r0, [r1]
	ldr r0, _08057F64 @ =0x00001FC6
	adds r1, r2, r0
	ldr r0, _08057F68 @ =0x00000307
	strh r0, [r1]
	adds r4, #6
	adds r1, r2, r4
	movs r0, #0xe
	strb r0, [r1]
	ldr r1, _08057F6C @ =0x00001FDC
	adds r0, r2, r1
	strb r3, [r0]
	ldr r3, _08057F70 @ =0x00001FC8
	adds r0, r2, r3
	movs r1, #1
	strb r1, [r0]
	subs r4, #1
	adds r0, r2, r4
	strb r1, [r0]
	ldr r0, _08057F74 @ =0x00001FCB
	adds r2, r2, r0
	movs r0, #0xff
	strb r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08057F54: .4byte 0x030064A0
_08057F58: .4byte 0x03002C30
_08057F5C: .4byte 0x00001FC2
_08057F60: .4byte 0x00001FC4
_08057F64: .4byte 0x00001FC6
_08057F68: .4byte 0x00000307
_08057F6C: .4byte 0x00001FDC
_08057F70: .4byte 0x00001FC8
_08057F74: .4byte 0x00001FCB
	.syntax divided
