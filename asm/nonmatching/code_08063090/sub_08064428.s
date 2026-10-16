	.syntax unified

	thumb_func_start sub_08064428
sub_08064428: @ 0x08064428
	push {r4, lr}
	sub sp, #4
	ldr r2, _08064484 @ =0x08485BD8
	ldr r4, _08064488 @ =0x03006F74
	ldr r0, [r4]
	adds r0, #0x7a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0x6c
	cmp r0, #0
	beq _08064442
	movs r1, #0x68
_08064442:
	adds r0, r1, r2
	ldr r0, [r0]
	bl run_message
	cmp r0, #0
	beq _0806447A
	ldr r2, _0806448C @ =0x03005010
	ldr r0, _08064490 @ =0x0000FEFF
	strh r0, [r2, #6]
	ldrh r1, [r2, #0xa]
	cmp r1, r0
	bne _0806447A
	ldrh r0, [r2, #0xe]
	cmp r0, r1
	bne _0806447A
	ldr r1, _08064494 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, [r4]
	adds r0, #0x50
	movs r1, #0xc0
	str r1, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl init_blend_effect
_0806447A:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08064484: .4byte 0x08485BD8
_08064488: .4byte 0x03006F74
_0806448C: .4byte 0x03005010
_08064490: .4byte 0x0000FEFF
_08064494: .4byte 0x0300137C
	.syntax divided
