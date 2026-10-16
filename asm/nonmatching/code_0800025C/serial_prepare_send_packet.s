	.syntax unified

	thumb_func_start serial_prepare_send_packet
serial_prepare_send_packet: @ 0x080022DC
	push {r4, r5, lr}
	movs r5, #0
	ldr r4, _08002320 @ =0x03005170
	ldr r2, [r4, #0x1c]
	ldrb r1, [r4, #0xb]
	strb r1, [r2]
	ldr r3, [r4, #0x1c]
	ldrb r1, [r4, #2]
	ldrb r2, [r4, #3]
	eors r1, r2
	strb r1, [r3, #1]
	ldr r1, [r4, #0x1c]
	strh r5, [r1, #2]
	ldr r1, [r4, #0x1c]
	adds r1, #4
	ldr r2, _08002324 @ =0x04000001
	bl CpuSet
	movs r2, #0
	ldr r1, [r4, #0x1c]
_08002304:
	ldrh r0, [r1]
	adds r5, r5, r0
	adds r1, #2
	adds r2, #1
	cmp r2, #3
	bls _08002304
	ldr r0, [r4, #0x1c]
	mvns r1, r5
	strh r1, [r0, #2]
	movs r0, #1
	strb r0, [r4, #4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08002320: .4byte 0x03005170
_08002324: .4byte 0x04000001
	.syntax divided
