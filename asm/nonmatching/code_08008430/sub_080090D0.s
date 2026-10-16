	.syntax unified

	thumb_func_start sub_080090D0
sub_080090D0: @ 0x080090D0
	push {lr}
	bl sub_080093F8
	movs r0, #6
	movs r1, #1
	bl clear_sprite_table_mask
	ldr r0, _08009100 @ =0x084E2E58
	ldr r1, _08009104 @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	ldr r1, _08009108 @ =0x03000440
	adds r0, r1, #0
	adds r0, #0x42
	ldrb r0, [r0]
	cmp r0, #1
	beq _08009124
	cmp r0, #1
	bgt _0800910C
	cmp r0, #0
	beq _08009112
	b _0800916A
	.align 2, 0
_08009100: .4byte 0x084E2E58
_08009104: .4byte 0x050003C0
_08009108: .4byte 0x03000440
_0800910C:
	cmp r0, #2
	beq _0800913C
	b _0800916A
_08009112:
	bl sub_0803FB0C
	bl sub_0800A0FC
	ldr r1, _08009120 @ =0x0300137C
	movs r0, #0xb
	b _08009168
	.align 2, 0
_08009120: .4byte 0x0300137C
_08009124:
	bl sub_0803FB0C
	bl sub_0800A0FC
	bl sub_0800A854
	ldr r1, _08009138 @ =0x0300137C
	movs r0, #0x1b
	b _08009168
	.align 2, 0
_08009138: .4byte 0x0300137C
_0800913C:
	adds r2, r1, #0
	adds r2, #0x46
	ldrb r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0800915C
	movs r0, #0x7f
	ands r0, r1
	strb r0, [r2]
	ldr r1, _08009158 @ =0x0300137C
	movs r0, #0x30
	b _08009168
	.align 2, 0
_08009158: .4byte 0x0300137C
_0800915C:
	bl sub_0803FB0C
	bl sub_0800A0FC
	ldr r1, _08009170 @ =0x0300137C
	movs r0, #0x2b
_08009168:
	str r0, [r1]
_0800916A:
	pop {r0}
	bx r0
	.align 2, 0
_08009170: .4byte 0x0300137C
	.syntax divided
