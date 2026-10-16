	.syntax unified

	thumb_func_start reset_bot_status_and_init_palette_transfers
	.global reset_bot_status_and_init_palette_transfers
reset_bot_status_and_init_palette_transfers: @ 0x0801B5FC
	push {r4, r5, r6, lr}
	sub sp, #0x14
	ldr r1, _0801B668 @ =0x03000590
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r1, r0, #0
	adds r1, #0xbc
	movs r4, #0
	strb r4, [r1]
	adds r0, #0xbd
	ldrb r2, [r0]
	movs r1, #0xe5
	ands r1, r2
	strb r1, [r0]
	str r4, [sp]
	ldr r6, _0801B66C @ =0x030018A8
	ldr r5, _0801B670 @ =0x05000008
	mov r0, sp
	adds r1, r6, #0
	adds r2, r5, #0
	bl CpuSet
	str r4, [sp, #4]
	add r0, sp, #4
	adds r1, r6, #0
	adds r1, #0x20
	adds r2, r5, #0
	bl CpuSet
	str r4, [sp, #8]
	add r0, sp, #8
	adds r1, r6, #0
	adds r1, #0x40
	ldr r2, _0801B674 @ =0x05000004
	bl CpuSet
	str r4, [sp, #0xc]
	add r0, sp, #0xc
	adds r1, r6, #0
	adds r1, #0x50
	adds r2, r5, #0
	bl CpuSet
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r6, #0
	adds r1, #0xbc
	ldr r2, _0801B678 @ =0x05000001
	bl CpuSet
	add sp, #0x14
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801B668: .4byte 0x03000590
_0801B66C: .4byte 0x030018A8
_0801B670: .4byte 0x05000008
_0801B674: .4byte 0x05000004
_0801B678: .4byte 0x05000001
	.syntax divided
