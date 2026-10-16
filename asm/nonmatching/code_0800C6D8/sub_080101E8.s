	.syntax unified

	thumb_func_start sub_080101E8
sub_080101E8: @ 0x080101E8
	push {r4, lr}
	ldr r4, _08010220 @ =0x03002C30
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r1, [r0]
	subs r1, #8
	strb r1, [r0]
	ldr r0, _08010224 @ =0x00000109
	adds r2, r4, r0
	ldrb r0, [r2]
	subs r0, #8
	strb r0, [r2]
	lsls r1, r1, #0x18
	cmp r1, #0
	bne _0801021A
	movs r0, #4
	movs r1, #1
	bl clear_sprite_table_mask
	ldr r0, _08010228 @ =0x00000129
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0801021A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08010220: .4byte 0x03002C30
_08010224: .4byte 0x00000109
_08010228: .4byte 0x00000129
	.syntax divided
