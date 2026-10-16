	.syntax unified

	thumb_func_start sub_0805BFDC
sub_0805BFDC: @ 0x0805BFDC
	push {lr}
	sub sp, #8
	movs r0, #0
	str r0, [sp, #4]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	ldr r2, _0805C024 @ =0x01006000
	add r0, sp, #4
	bl CpuFastSet
	bl sub_080415BC
	bl sub_08059D04
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r0, #0x60
	strh r0, [r1]
	ldr r0, _0805C028 @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x50
	movs r3, #1
	rsbs r3, r3, #0
	movs r1, #0xc0
	str r1, [sp]
	movs r1, #0x10
	movs r2, #0
	bl init_blend_effect
	ldr r1, _0805C02C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_0805C024: .4byte 0x01006000
_0805C028: .4byte 0x03006F74
_0805C02C: .4byte 0x0300137C
	.syntax divided
