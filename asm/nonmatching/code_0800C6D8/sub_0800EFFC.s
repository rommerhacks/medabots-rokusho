	.syntax unified

	thumb_func_start sub_0800EFFC
sub_0800EFFC: @ 0x0800EFFC
	push {lr}
	ldr r2, _0800F01C @ =0x03001798
	ldrb r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0800F028
	ldr r0, _0800F020 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x40
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800F024
	movs r0, #3
	b _0800F026
	.align 2, 0
_0800F01C: .4byte 0x03001798
_0800F020: .4byte 0x03000440
_0800F024:
	subs r0, #1
_0800F026:
	strb r0, [r1]
_0800F028:
	ldrb r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0800F04C
	ldr r0, _0800F044 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x40
	ldrb r0, [r1]
	cmp r0, #3
	bne _0800F048
	movs r0, #0
	b _0800F04A
	.align 2, 0
_0800F044: .4byte 0x03000440
_0800F048:
	adds r0, #1
_0800F04A:
	strb r0, [r1]
_0800F04C:
	ldrb r1, [r2]
	movs r0, #0xc0
	ands r0, r1
	cmp r0, #0
	bne _0800F05A
	movs r0, #0
	b _0800F082
_0800F05A:
	movs r0, #2
	bl play_sound_effect
	ldr r2, _0800F088 @ =0x03000440
	adds r0, r2, #0
	adds r0, #0x3f
	ldrb r0, [r0]
	adds r1, r2, #0
	adds r1, #0x40
	lsls r0, r0, #2
	ldrb r1, [r1]
	adds r0, r0, r1
	adds r1, r2, #0
	adds r1, #0x3d
	strb r0, [r1]
	bl sub_0800EFB0
	bl load_overworld_sprite_by_direction
	movs r0, #1
_0800F082:
	pop {r1}
	bx r1
	.align 2, 0
_0800F088: .4byte 0x03000440
	.syntax divided
