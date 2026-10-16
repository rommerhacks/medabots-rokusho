	.syntax unified

	thumb_func_start sub_08011DE4
sub_08011DE4: @ 0x08011DE4
	push {r4, lr}
	ldr r0, _08011E0C @ =0x030057E0
	ldr r1, _08011E10 @ =0x000007FE
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #3
	ldr r1, _08011E14 @ =0x083BEA90
	adds r0, r0, r1
	ldr r4, _08011E18 @ =0x0300052E
	adds r1, r4, #0
	movs r2, #2
	bl memcpy_bytes_08041D04
	ldr r0, _08011E1C @ =0x03001800
	ldrb r1, [r4, #1]
	adds r0, #0x38
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08011E0C: .4byte 0x030057E0
_08011E10: .4byte 0x000007FE
_08011E14: .4byte 0x083BEA90
_08011E18: .4byte 0x0300052E
_08011E1C: .4byte 0x03001800
	.syntax divided
