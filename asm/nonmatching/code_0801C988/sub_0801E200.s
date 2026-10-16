	.syntax unified

	thumb_func_start sub_0801E200
sub_0801E200: @ 0x0801E200
	push {r4, lr}
	sub sp, #4
	movs r4, #0
	str r4, [sp]
	ldr r1, _0801E238 @ =0x03002C30
	ldr r2, _0801E23C @ =0x01000800
	mov r0, sp
	bl CpuFastSet
	bl sub_08035C70
	bl init_battle_scene_backgrounds
	bl sub_080361A8
	ldr r0, _0801E240 @ =0x03000440
	adds r0, #0x84
	strb r4, [r0]
	ldr r1, _0801E244 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801E238: .4byte 0x03002C30
_0801E23C: .4byte 0x01000800
_0801E240: .4byte 0x03000440
_0801E244: .4byte 0x03001800
	.syntax divided
