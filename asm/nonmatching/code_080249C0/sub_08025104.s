	.syntax unified

	thumb_func_start sub_08025104
sub_08025104: @ 0x08025104
	push {r4, r5, r6, lr}
	movs r0, #0x21
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r5, _0802516C @ =0x03000590
	ldr r6, _08025170 @ =0x03001800
	adds r4, r6, #0
	adds r4, #0x88
	ldrb r0, [r4]
	lsls r0, r0, #8
	adds r0, r0, r5
	adds r0, #0xc9
	movs r2, #0
	movs r1, #0x2c
	strb r1, [r0]
	ldrb r0, [r4]
	lsls r0, r0, #8
	adds r0, r0, r5
	adds r0, #0xca
	strb r2, [r0]
	adds r0, r6, #0
	adds r0, #0xe8
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl sub_08036E54
	ldrb r1, [r4]
	lsls r1, r1, #8
	adds r1, r1, r5
	adds r1, #0xcb
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0xec
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl sub_08036E54
	ldrb r1, [r4]
	lsls r1, r1, #8
	adds r1, r1, r5
	adds r1, #0xcc
	strb r0, [r1]
	adds r1, r6, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802516C: .4byte 0x03000590
_08025170: .4byte 0x03001800
_08025174:
	.byte 0x04, 0x49, 0x0A, 0x1C, 0xA6, 0x32, 0x33, 0x20, 0x10, 0x70, 0xAA, 0x31
	.byte 0x08, 0x78, 0x01, 0x30, 0x08, 0x70, 0x70, 0x47, 0x00, 0x18, 0x00, 0x03
	.syntax divided
