	.syntax unified

	thumb_func_start sub_0800F148
sub_0800F148: @ 0x0800F148
	push {lr}
	sub sp, #0xc
	ldr r2, _0800F168 @ =0x0300058C
	ldrb r1, [r2, #1]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0800F174
	ldr r0, _0800F16C @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x3e
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800F170
	movs r0, #3
	b _0800F172
	.align 2, 0
_0800F168: .4byte 0x0300058C
_0800F16C: .4byte 0x03000440
_0800F170:
	subs r0, #1
_0800F172:
	strb r0, [r1]
_0800F174:
	ldrb r1, [r2, #1]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0800F198
	ldr r0, _0800F190 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x3e
	ldrb r0, [r1]
	cmp r0, #3
	bne _0800F194
	movs r0, #0
	b _0800F196
	.align 2, 0
_0800F190: .4byte 0x03000440
_0800F194:
	adds r0, #1
_0800F196:
	strb r0, [r1]
_0800F198:
	ldrb r1, [r2, #1]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _0800F1A6
	movs r0, #0
	b _0800F204
_0800F1A6:
	movs r0, #2
	bl play_sound_effect
	ldr r2, _0800F20C @ =0x03000440
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
	ldr r1, _0800F210 @ =0x083B4AE0
	adds r0, r2, #0
	adds r0, #0x3e
	ldrb r0, [r0]
	adds r0, #0x59
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [sp]
	ldr r0, _0800F214 @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp, #4]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #8]
	movs r0, #0xa
	movs r1, #2
	movs r2, #0x10
	movs r3, #0
	bl write_tilemap_rect
	bl sub_0800EC44
	bl sub_0800ED10
	bl sub_0800EDA0
	bl sub_0800EE34
	bl load_overworld_sprite_by_direction
	movs r0, #1
_0800F204:
	add sp, #0xc
	pop {r1}
	bx r1
	.align 2, 0
_0800F20C: .4byte 0x03000440
_0800F210: .4byte 0x083B4AE0
_0800F214: .4byte 0x04000008
	.syntax divided
