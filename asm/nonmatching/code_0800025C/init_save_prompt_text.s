	.syntax unified

	thumb_func_start init_save_prompt_text
init_save_prompt_text: @ 0x080026E0
	push {lr}
	ldr r1, _08002724 @ =0x03002B70
	movs r2, #0
	movs r0, #0x17
	strb r0, [r1, #4]
	movs r0, #0x29
	strb r0, [r1, #5]
	movs r0, #0x2c
	strb r0, [r1, #6]
	movs r0, #0x25
	strb r0, [r1, #7]
	strb r2, [r1, #8]
	movs r2, #0x2e
	strb r2, [r1, #9]
	movs r0, #0x1f
	strb r0, [r1, #0xa]
	movs r0, #0x2d
	strb r0, [r1, #0xb]
	strb r2, [r1, #0xc]
	movs r0, #0xfe
	strb r0, [r1, #0xd]
	ldr r0, _08002728 @ =0x083B53F8
	ldr r0, [r0]
	bl run_message
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #1
	bne _0800271E
	ldr r0, _0800272C @ =0x0300137C
	str r1, [r0]
_0800271E:
	pop {r0}
	bx r0
	.align 2, 0
_08002724: .4byte 0x03002B70
_08002728: .4byte 0x083B53F8
_0800272C: .4byte 0x0300137C
	.syntax divided
