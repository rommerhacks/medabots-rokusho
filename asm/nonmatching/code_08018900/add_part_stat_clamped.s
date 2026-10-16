	.syntax unified

	thumb_func_start add_part_stat_clamped
add_part_stat_clamped: @ 0x08018F0C
	push {r4, lr}
	adds r4, r2, #0
	ldr r3, _08018F34 @ =0x03000590
	lsls r2, r1, #1
	adds r2, r2, r1
	lsls r2, r2, #3
	lsls r0, r0, #8
	adds r2, r2, r0
	adds r2, r2, r3
	adds r3, r2, #0
	adds r3, #0x59
	ldrb r1, [r3]
	adds r1, r1, r4
	adds r2, #0x4c
	ldrb r0, [r2]
	cmp r1, r0
	bhi _08018F38
	strb r1, [r3]
	adds r0, r4, #0
	b _08018F42
	.align 2, 0
_08018F34: .4byte 0x03000590
_08018F38:
	subs r1, r1, r0
	strb r0, [r3]
	lsls r0, r1, #8
	subs r1, r4, r1
	adds r0, r0, r1
_08018F42:
	pop {r4}
	pop {r1}
	bx r1
_08018F48:
	.byte 0x00, 0x22, 0x04, 0x49, 0x00, 0x02, 0x09, 0x18
	.byte 0xA1, 0x31, 0x08, 0x78, 0x00, 0x28, 0x03, 0xD0, 0x50, 0x1C, 0x06, 0xE0, 0x90, 0x05, 0x00, 0x03
	.byte 0x18, 0x39, 0x01, 0x32, 0x03, 0x2A, 0xF4, 0xD9, 0x00, 0x20, 0x70, 0x47
	.syntax divided
