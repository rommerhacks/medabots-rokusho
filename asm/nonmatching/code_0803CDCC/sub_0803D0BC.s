	.syntax unified

	thumb_func_start sub_0803D0BC
sub_0803D0BC: @ 0x0803D0BC
	push {r4, r5, r6, lr}
	ldr r2, _0803D104 @ =0x083B5F80
	ldr r6, _0803D108 @ =0x03002C30
	ldr r0, _0803D10C @ =0x03000440
	ldr r1, _0803D110 @ =0x0000012F
	adds r5, r0, r1
	ldrb r1, [r5]
	lsls r0, r1, #6
	adds r0, r0, r6
	adds r0, #0x2d
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl process_sprite_anim_commands
	ldrb r4, [r5]
	lsls r0, r4, #6
	adds r1, r0, r6
	adds r0, r1, #0
	adds r0, #0x23
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803D12A
	adds r2, r1, #0
	adds r2, #0x26
	ldrb r3, [r1, #8]
	ldrb r0, [r2]
	cmp r3, r0
	bhi _0803D114
	adds r0, r4, #0
	movs r1, #1
	bl clear_sprite_table_mask
	b _0803D154
	.align 2, 0
_0803D104: .4byte 0x083B5F80
_0803D108: .4byte 0x03002C30
_0803D10C: .4byte 0x03000440
_0803D110: .4byte 0x0000012F
_0803D114:
	subs r0, r3, r0
	strb r0, [r1, #8]
	ldrb r0, [r5]
	lsls r0, r0, #6
	adds r0, r0, r6
	adds r2, r0, #0
	adds r2, #0x26
	ldrb r1, [r0, #9]
	ldrb r2, [r2]
	subs r1, r1, r2
	b _0803D152
_0803D12A:
	ldrb r2, [r1, #8]
	cmp r2, #0x40
	bne _0803D138
	adds r1, #0x29
	movs r0, #0
	strb r0, [r1]
	b _0803D154
_0803D138:
	adds r0, r1, #0
	adds r0, #0x26
	ldrb r0, [r0]
	adds r0, r2, r0
	strb r0, [r1, #8]
	ldrb r0, [r5]
	lsls r0, r0, #6
	adds r0, r0, r6
	adds r1, r0, #0
	adds r1, #0x26
	ldrb r1, [r1]
	ldrb r2, [r0, #9]
	adds r1, r1, r2
_0803D152:
	strb r1, [r0, #9]
_0803D154:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
