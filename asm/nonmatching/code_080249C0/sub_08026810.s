	.syntax unified

	thumb_func_start sub_08026810
sub_08026810: @ 0x08026810
	push {r4, r5, r6, r7, lr}
	movs r0, #0x21
	movs r1, #2
	bl clear_battle_sprite_slot
	ldr r5, _08026874 @ =0x083BB9CC
	ldr r6, _08026878 @ =0x03001800
	ldr r1, _0802687C @ =0x00000133
	adds r0, r6, r1
	ldrb r0, [r0]
	adds r7, r6, #0
	adds r7, #0xa7
	lsls r0, r0, #2
	ldrb r1, [r7]
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r0, [r0]
	ldr r4, _08026880 @ =0x030004DE
	adds r1, r4, #0
	movs r2, #0xf
	bl memcpy_bytes_08041D04
	movs r1, #0x8d
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrb r0, [r0]
	lsls r0, r0, #2
	ldrb r7, [r7]
	adds r0, r0, r7
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r0, [r0]
	adds r4, #0x14
	adds r1, r4, #0
	movs r2, #0xf
	bl memcpy_bytes_08041D04
	adds r1, r6, #0
	adds r1, #0xa6
	movs r0, #0x2f
	strb r0, [r1]
	adds r1, #4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08026874: .4byte 0x083BB9CC
_08026878: .4byte 0x03001800
_0802687C: .4byte 0x00000133
_08026880: .4byte 0x030004DE
	.syntax divided
