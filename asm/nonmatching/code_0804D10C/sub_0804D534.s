	.syntax unified

	thumb_func_start sub_0804D534
sub_0804D534: @ 0x0804D534
	push {r4, lr}
	movs r0, #8
	bl read_map_script_bytes
	ldr r4, _0804D584 @ =0x03006474
	ldr r2, _0804D588 @ =0x030064A0
	adds r3, r2, #0
	adds r3, #0x52
	ldrb r1, [r3]
	adds r0, r1, #1
	strb r0, [r3]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x15
	adds r2, #0x12
	adds r1, r1, r2
	adds r0, r4, #0
	movs r2, #8
	bl memcpy_u8
	bl read_map_script_byte
	subs r2, r4, #2
	movs r1, #0
	strb r0, [r2]
	adds r0, r4, #0
	subs r0, #0xb
	strb r1, [r0]
	subs r4, #1
	strb r1, [r4]
	ldr r1, _0804D58C @ =0x083D20AC
	ldrb r0, [r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804D584: .4byte 0x03006474
_0804D588: .4byte 0x030064A0
_0804D58C: .4byte 0x083D20AC
_0804D590:
	.byte 0x02, 0x48, 0x03, 0x49, 0x40, 0x18, 0x01, 0x21, 0x01, 0x70, 0x70, 0x47, 0xE0, 0x57, 0x00, 0x03
	.byte 0x89, 0x0C, 0x00, 0x00
	.syntax divided
