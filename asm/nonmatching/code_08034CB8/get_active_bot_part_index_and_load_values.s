	.syntax unified

	thumb_func_start get_active_bot_part_index_and_load_values
	.global get_active_bot_part_index_and_load_values
get_active_bot_part_index_and_load_values: @ 0x08036120
	push {lr}
	cmp r0, #0
	bne _08036158
	ldr r2, _0803613C @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08036140
	adds r0, r2, #0
	adds r0, #0x87
	b _08036188
	.align 2, 0
_0803613C: .4byte 0x03001800
_08036140:
	adds r0, r2, #0
	adds r0, #0xf6
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08036184
	ldr r1, _08036154 @ =0x00000161
	adds r0, r2, r1
	b _08036188
	.align 2, 0
_08036154: .4byte 0x00000161
_08036158:
	ldr r2, _0803617C @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08036194
	adds r0, r2, #0
	adds r0, #0xf6
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08036184
	ldr r1, _08036180 @ =0x00000161
	adds r0, r2, r1
	b _08036188
	.align 2, 0
_0803617C: .4byte 0x03001800
_08036180: .4byte 0x00000161
_08036184:
	adds r0, r2, #0
	adds r0, #0x88
_08036188:
	ldrb r0, [r0]
	adds r1, r2, #0
	adds r1, #0x64
	bl get_bot_part_effective_values
	b _080361A2
_08036194:
	adds r0, r2, #0
	adds r0, #0x87
	ldrb r0, [r0]
	adds r1, r2, #0
	adds r1, #0x64
	bl get_bot_part_effective_values
_080361A2:
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
