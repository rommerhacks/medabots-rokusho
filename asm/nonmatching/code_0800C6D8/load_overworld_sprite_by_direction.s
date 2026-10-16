	.syntax unified

	thumb_func_start load_overworld_sprite_by_direction
load_overworld_sprite_by_direction: @ 0x0800F300
	push {r4, lr}
	sub sp, #0x18
	ldr r4, _0800F320 @ =0x02026000
	ldr r0, _0800F324 @ =0x020260D0
	str r0, [r4, #8]
	ldr r1, _0800F328 @ =0x03000440
	adds r0, r1, #0
	adds r0, #0x3e
	ldrb r3, [r0]
	cmp r3, #1
	beq _0800F36C
	cmp r3, #1
	bgt _0800F32C
	cmp r3, #0
	beq _0800F336
	b _0800F3FA
	.align 2, 0
_0800F320: .4byte 0x02026000
_0800F324: .4byte 0x020260D0
_0800F328: .4byte 0x03000440
_0800F32C:
	cmp r3, #2
	beq _0800F3A0
	cmp r3, #3
	beq _0800F3D0
	b _0800F3FA
_0800F336:
	ldr r0, _0800F364 @ =0x03002414
	ldr r0, [r0]
	ldr r2, _0800F368 @ =0x00000B84
	adds r0, r0, r2
	adds r1, #0x3d
	ldrb r2, [r1]
	movs r1, #0x3c
	str r1, [sp]
	movs r1, #0x32
	str r1, [sp, #4]
	movs r1, #0xe1
	lsls r1, r1, #1
	str r1, [sp, #8]
	movs r1, #8
	str r1, [sp, #0xc]
	movs r1, #1
	str r1, [sp, #0x10]
	adds r1, r4, #0
	movs r3, #0
	bl load_sprite_animation_by_type
	b _0800F3FA
	.align 2, 0
_0800F364: .4byte 0x03002414
_0800F368: .4byte 0x00000B84
_0800F36C:
	ldr r0, _0800F398 @ =0x03002414
	ldr r0, [r0]
	ldr r2, _0800F39C @ =0x00000B84
	adds r0, r0, r2
	adds r1, #0x3d
	ldrb r2, [r1]
	movs r1, #0x28
	str r1, [sp]
	movs r1, #0x3c
	str r1, [sp, #4]
	movs r1, #0xe1
	lsls r1, r1, #1
	str r1, [sp, #8]
	movs r1, #8
	str r1, [sp, #0xc]
	str r3, [sp, #0x10]
	adds r1, r4, #0
	movs r3, #1
	bl load_sprite_animation_by_type
	b _0800F3FA
	.align 2, 0
_0800F398: .4byte 0x03002414
_0800F39C: .4byte 0x00000B84
_0800F3A0:
	ldr r0, _0800F3C8 @ =0x03002414
	ldr r0, [r0]
	ldr r2, _0800F3CC @ =0x00000B84
	adds r0, r0, r2
	adds r1, #0x3d
	ldrb r2, [r1]
	movs r1, #0x28
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0xe1
	lsls r1, r1, #1
	str r1, [sp, #8]
	movs r1, #8
	str r1, [sp, #0xc]
	str r3, [sp, #0x10]
	adds r1, r4, #0
	movs r3, #2
	bl load_sprite_animation_by_type
	b _0800F3FA
	.align 2, 0
_0800F3C8: .4byte 0x03002414
_0800F3CC: .4byte 0x00000B84
_0800F3D0:
	ldr r0, _0800F42C @ =0x03002414
	ldr r0, [r0]
	ldr r2, _0800F430 @ =0x00000B84
	adds r0, r0, r2
	adds r1, #0x3d
	ldrb r2, [r1]
	movs r1, #0x1e
	str r1, [sp]
	movs r1, #0x32
	str r1, [sp, #4]
	movs r1, #0xe1
	lsls r1, r1, #1
	str r1, [sp, #8]
	movs r1, #8
	str r1, [sp, #0xc]
	movs r1, #1
	str r1, [sp, #0x10]
	adds r1, r4, #0
	movs r3, #3
	bl load_sprite_animation_by_type
_0800F3FA:
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x14]
	ldr r4, _0800F42C @ =0x03002414
	ldr r1, [r4]
	ldr r0, _0800F430 @ =0x00000B84
	adds r1, r1, r0
	ldr r2, _0800F434 @ =0x01000100
	add r0, sp, #0x14
	bl CpuFastSet
	ldr r0, [r4]
	ldr r1, _0800F438 @ =0x00001094
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r4]
	ldr r2, _0800F43C @ =0x00001095
	adds r0, r0, r2
	strb r1, [r0]
	add sp, #0x18
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800F42C: .4byte 0x03002414
_0800F430: .4byte 0x00000B84
_0800F434: .4byte 0x01000100
_0800F438: .4byte 0x00001094
_0800F43C: .4byte 0x00001095
	.syntax divided
