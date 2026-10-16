	.syntax unified

	thumb_func_start sub_0804D760
sub_0804D760: @ 0x0804D760
	push {r4, lr}
	movs r0, #8
	bl read_map_script_bytes
	ldr r0, _0804D790 @ =0x03006474
	ldr r3, _0804D794 @ =0x030064A0
	movs r1, #0x52
	adds r1, r1, r3
	mov ip, r1
	ldrb r1, [r1]
	adds r2, r1, #1
	mov r4, ip
	strb r2, [r4]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x15
	adds r3, #0x12
	adds r1, r1, r3
	movs r2, #8
	bl memcpy_u8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804D790: .4byte 0x03006474
_0804D794: .4byte 0x030064A0
_0804D798:
	.byte 0x02, 0x48, 0x03, 0x49, 0x40, 0x18, 0x01, 0x21
	.byte 0x01, 0x70, 0x70, 0x47, 0xE0, 0x57, 0x00, 0x03, 0x89, 0x0C, 0x00, 0x00
	.syntax divided
