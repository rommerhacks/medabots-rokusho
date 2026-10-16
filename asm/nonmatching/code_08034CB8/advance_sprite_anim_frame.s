	.syntax unified

	thumb_func_start advance_sprite_anim_frame
	.global advance_sprite_anim_frame
advance_sprite_anim_frame: @ 0x08036AC4
	push {r4, lr}
	adds r4, r1, #0
	ldr r1, _08036AE8 @ =0x03002C30
	lsls r0, r0, #6
	adds r3, r0, r1
	ldrh r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08036AE4
	adds r2, r3, #0
	adds r2, #0x23
	ldrb r0, [r2]
	cmp r0, #0x10
	bne _08036AEC
_08036AE4:
	movs r0, #1
	b _08036B10
	.align 2, 0
_08036AE8: .4byte 0x03002C30
_08036AEC:
	ldr r1, _08036B18 @ =0x083AF4A0
	ldrb r0, [r2]
	adds r0, r0, r1
	ldrb r1, [r0]
	ldrh r0, [r3, #4]
	adds r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	strh r0, [r3, #4]
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	cmp r4, #0
	beq _08036B0E
	lsls r0, r0, #2
	adds r0, #0x40
	strb r0, [r3, #9]
_08036B0E:
	movs r0, #0
_08036B10:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08036B18: .4byte 0x083AF4A0
	.syntax divided
