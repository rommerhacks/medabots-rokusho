	.syntax unified

	thumb_func_start serial_link_init
	.global serial_link_init
serial_link_init: @ 0x080020C8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	ldr r5, _08002158 @ =0x04000208
	movs r2, #0
	strh r2, [r5]
	ldr r4, _0800215C @ =0x04000200
	ldrh r1, [r4]
	ldr r0, _08002160 @ =0x0000FF3F
	ands r0, r1
	strh r0, [r4]
	movs r0, #1
	mov r8, r0
	strh r0, [r5]
	ldr r0, _08002164 @ =0x04000134
	strh r2, [r0]
	ldr r2, _08002168 @ =0x04000128
	movs r1, #0x80
	lsls r1, r1, #6
	adds r0, r1, #0
	strh r0, [r2]
	ldrh r0, [r2]
	ldr r3, _0800216C @ =0x00004003
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r6, #0
	str r6, [sp]
	ldr r7, _08002170 @ =0x03005170
	ldr r2, _08002174 @ =0x05000036
	mov r0, sp
	adds r1, r7, #0
	bl CpuSet
	ldr r0, _08002178 @ =link_buffer_swap_arm
	ldr r1, _0800217C @ =0x03005250
	ldr r2, _08002180 @ =0x04000010
	bl CpuSet
	ldr r0, _08002184 @ =serial_multiplayer_transfer_handler
	ldr r1, _08002188 @ =0x03005050
	ldr r2, _0800218C @ =0x04000048
	bl CpuSet
	movs r0, #6
	str r0, [r7, #0x14]
	str r0, [r7, #0x18]
	adds r0, r7, #0
	adds r0, #0x30
	str r0, [r7, #0x1c]
	adds r0, #0xc
	str r0, [r7, #0x20]
	adds r0, #0xc
	str r0, [r7, #0x24]
	adds r0, #0x30
	str r0, [r7, #0x28]
	adds r0, #0x30
	str r0, [r7, #0x2c]
	strh r6, [r5]
	ldrh r0, [r4]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r4]
	mov r0, r8
	strh r0, [r5]
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08002158: .4byte 0x04000208
_0800215C: .4byte 0x04000200
_08002160: .4byte 0x0000FF3F
_08002164: .4byte 0x04000134
_08002168: .4byte 0x04000128
_0800216C: .4byte 0x00004003
_08002170: .4byte 0x03005170
_08002174: .4byte 0x05000036
_08002178: .4byte link_buffer_swap_arm
_0800217C: .4byte 0x03005250
_08002180: .4byte 0x04000010
_08002184: .4byte serial_multiplayer_transfer_handler
_08002188: .4byte 0x03005050
_0800218C: .4byte 0x04000048
	.syntax divided
