	.syntax unified

	thumb_func_start hw_reset_init
	.global hw_reset_init
hw_reset_init: @ 0x080004E0
	push {r4, lr}
	sub sp, #0xc
	ldr r1, _0800052C @ =0x04000208
	movs r0, #0
	strh r0, [r1]
	movs r4, #0
	str r4, [sp]
	movs r1, #0x80
	lsls r1, r1, #0x12
	ldr r2, _08000530 @ =0x01010000
	mov r0, sp
	bl CpuFastSet
	str r4, [sp, #4]
	add r0, sp, #4
	movs r1, #0xc0
	lsls r1, r1, #0x12
	ldr r2, _08000534 @ =0x01001F40
	bl CpuFastSet
	bl clear_oam
	str r4, [sp, #8]
	add r0, sp, #8
	movs r4, #0xa0
	lsls r4, r4, #0x13
	ldr r2, _08000538 @ =0x01000100
	adds r1, r4, #0
	bl CpuFastSet
	ldr r1, _0800053C @ =0x00007FFF
	adds r0, r1, #0
	strh r0, [r4]
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800052C: .4byte 0x04000208
_08000530: .4byte 0x01010000
_08000534: .4byte 0x01001F40
_08000538: .4byte 0x01000100
_0800053C: .4byte 0x00007FFF
	.syntax divided
