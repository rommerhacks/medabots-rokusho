	.syntax unified

	thumb_func_start sub_080393EC
sub_080393EC: @ 0x080393EC
	push {r4, lr}
	bl sub_0803D424
	ldr r1, _08039428 @ =0x03002C30
	adds r1, #0x29
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bge _08039410
	adds r4, r1, #0
_08039400:
	bl battle_advance_sequence_counter
	bl sub_0803D424
	strb r0, [r4]
	lsls r0, r0, #0x18
	cmp r0, #0
	blt _08039400
_08039410:
	ldr r1, _0803942C @ =0x083AF740
	ldr r0, _08039428 @ =0x03002C30
	adds r0, #0x29
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08039428: .4byte 0x03002C30
_0803942C: .4byte 0x083AF740
_08039430:
	.byte 0x03, 0x48, 0x2A, 0x30, 0x01, 0x21, 0x01, 0x70, 0x02, 0x48, 0xB5, 0x30, 0x01, 0x70, 0x70, 0x47
	.byte 0x30, 0x2C, 0x00, 0x03, 0x00, 0x18, 0x00, 0x03
	.syntax divided
