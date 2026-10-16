	.syntax unified

	thumb_func_start load_medapart_sprite_by_slot
load_medapart_sprite_by_slot: @ 0x0800F440
	push {r4, r5, lr}
	sub sp, #0x14
	ldr r1, _0800F470 @ =0x03000440
	adds r0, r1, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0800F500
	ldr r3, _0800F474 @ =0x02026000
	ldr r0, _0800F478 @ =0x020260D0
	str r0, [r3, #8]
	adds r0, r1, #0
	adds r0, #0x3e
	ldrb r0, [r0]
	cmp r0, #1
	beq _0800F49C
	cmp r0, #1
	bgt _0800F47C
	cmp r0, #0
	beq _0800F486
	b _0800F5FC
	.align 2, 0
_0800F470: .4byte 0x03000440
_0800F474: .4byte 0x02026000
_0800F478: .4byte 0x020260D0
_0800F47C:
	cmp r0, #2
	beq _0800F4B4
	cmp r0, #3
	beq _0800F4CC
	b _0800F5FC
_0800F486:
	ldr r0, _0800F494 @ =0x03002414
	ldr r0, [r0]
	ldr r2, _0800F498 @ =0x00000B84
	adds r0, r0, r2
	adds r1, #0x3d
	ldrb r2, [r1]
	b _0800F548
	.align 2, 0
_0800F494: .4byte 0x03002414
_0800F498: .4byte 0x00000B84
_0800F49C:
	ldr r0, _0800F4AC @ =0x03002414
	ldr r0, [r0]
	ldr r2, _0800F4B0 @ =0x00000B84
	adds r0, r0, r2
	adds r1, #0x3d
	ldrb r2, [r1]
	b _0800F57A
	.align 2, 0
_0800F4AC: .4byte 0x03002414
_0800F4B0: .4byte 0x00000B84
_0800F4B4:
	ldr r0, _0800F4C4 @ =0x03002414
	ldr r0, [r0]
	ldr r2, _0800F4C8 @ =0x00000B84
	adds r0, r0, r2
	adds r1, #0x3d
	ldrb r2, [r1]
	b _0800F5AE
	.align 2, 0
_0800F4C4: .4byte 0x03002414
_0800F4C8: .4byte 0x00000B84
_0800F4CC:
	ldr r0, _0800F4F8 @ =0x03002414
	ldr r0, [r0]
	ldr r2, _0800F4FC @ =0x00000B84
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
	movs r1, #5
	str r1, [sp, #0x10]
	adds r1, r3, #0
	movs r3, #3
	bl load_sprite_animation_by_type
	b _0800F5FC
	.align 2, 0
_0800F4F8: .4byte 0x03002414
_0800F4FC: .4byte 0x00000B84
_0800F500:
	adds r4, r1, #0
	adds r4, #0x3d
	ldrb r0, [r4]
	adds r5, r1, #0
	adds r5, #0x3e
	ldrb r1, [r5]
	bl sub_08042114
	cmp r0, #0
	beq _0800F5FC
	ldr r3, _0800F52C @ =0x02026000
	ldr r0, _0800F530 @ =0x020260D0
	str r0, [r3, #8]
	ldrb r0, [r5]
	cmp r0, #1
	beq _0800F570
	cmp r0, #1
	bgt _0800F534
	cmp r0, #0
	beq _0800F53E
	b _0800F5FC
	.align 2, 0
_0800F52C: .4byte 0x02026000
_0800F530: .4byte 0x020260D0
_0800F534:
	cmp r0, #2
	beq _0800F5A4
	cmp r0, #3
	beq _0800F5D4
	b _0800F5FC
_0800F53E:
	ldr r0, _0800F568 @ =0x03002414
	ldr r0, [r0]
	ldr r1, _0800F56C @ =0x00000B84
	adds r0, r0, r1
	ldrb r2, [r4]
_0800F548:
	movs r1, #0x3c
	str r1, [sp]
	movs r1, #0x32
	str r1, [sp, #4]
	movs r1, #0xe1
	lsls r1, r1, #1
	str r1, [sp, #8]
	movs r1, #8
	str r1, [sp, #0xc]
	movs r1, #5
	str r1, [sp, #0x10]
	adds r1, r3, #0
	movs r3, #0
	bl load_sprite_animation_by_type
	b _0800F5FC
	.align 2, 0
_0800F568: .4byte 0x03002414
_0800F56C: .4byte 0x00000B84
_0800F570:
	ldr r0, _0800F59C @ =0x03002414
	ldr r0, [r0]
	ldr r2, _0800F5A0 @ =0x00000B84
	adds r0, r0, r2
	ldrb r2, [r4]
_0800F57A:
	movs r1, #0x28
	str r1, [sp]
	movs r1, #0x3c
	str r1, [sp, #4]
	movs r1, #0xe1
	lsls r1, r1, #1
	str r1, [sp, #8]
	movs r1, #8
	str r1, [sp, #0xc]
	movs r1, #5
	str r1, [sp, #0x10]
	adds r1, r3, #0
	movs r3, #1
	bl load_sprite_animation_by_type
	b _0800F5FC
	.align 2, 0
_0800F59C: .4byte 0x03002414
_0800F5A0: .4byte 0x00000B84
_0800F5A4:
	ldr r0, _0800F5CC @ =0x03002414
	ldr r0, [r0]
	ldr r1, _0800F5D0 @ =0x00000B84
	adds r0, r0, r1
	ldrb r2, [r4]
_0800F5AE:
	movs r1, #0x28
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0xe1
	lsls r1, r1, #1
	str r1, [sp, #8]
	movs r1, #8
	str r1, [sp, #0xc]
	movs r1, #6
	str r1, [sp, #0x10]
	adds r1, r3, #0
	movs r3, #2
	bl load_sprite_animation_by_type
	b _0800F5FC
	.align 2, 0
_0800F5CC: .4byte 0x03002414
_0800F5D0: .4byte 0x00000B84
_0800F5D4:
	ldr r0, _0800F604 @ =0x03002414
	ldr r0, [r0]
	ldr r2, _0800F608 @ =0x00000B84
	adds r0, r0, r2
	ldrb r2, [r4]
	movs r1, #0x1e
	str r1, [sp]
	movs r1, #0x32
	str r1, [sp, #4]
	movs r1, #0xe1
	lsls r1, r1, #1
	str r1, [sp, #8]
	movs r1, #8
	str r1, [sp, #0xc]
	movs r1, #5
	str r1, [sp, #0x10]
	adds r1, r3, #0
	movs r3, #3
	bl load_sprite_animation_by_type
_0800F5FC:
	add sp, #0x14
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800F604: .4byte 0x03002414
_0800F608: .4byte 0x00000B84
	.syntax divided
