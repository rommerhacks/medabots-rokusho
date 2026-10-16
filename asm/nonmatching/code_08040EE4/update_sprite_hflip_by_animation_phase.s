	.syntax unified

	thumb_func_start update_sprite_hflip_by_animation_phase
update_sprite_hflip_by_animation_phase: @ 0x08041B1C
	push {r4, lr}
	ldr r3, _08041B48 @ =0x03000440
	adds r0, r3, #0
	adds r0, #0x84
	ldrb r1, [r0]
	adds r4, r3, #0
	cmp r1, #0x1e
	beq _08041B78
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08041B54
	ldr r2, _08041B4C @ =0x03002C30
	adds r0, r3, #0
	adds r0, #0x2b
	ldrb r1, [r0]
	lsls r1, r1, #6
	adds r1, r1, r2
	ldrh r2, [r1]
	ldr r0, _08041B50 @ =0x0000BFFF
	ands r0, r2
	b _08041B6A
	.align 2, 0
_08041B48: .4byte 0x03000440
_08041B4C: .4byte 0x03002C30
_08041B50: .4byte 0x0000BFFF
_08041B54:
	ldr r2, _08041B74 @ =0x03002C30
	adds r0, r3, #0
	adds r0, #0x2b
	ldrb r1, [r0]
	lsls r1, r1, #6
	adds r1, r1, r2
	ldrh r2, [r1]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r3, #0
	orrs r0, r2
_08041B6A:
	strh r0, [r1]
	adds r1, r4, #0
	adds r1, #0x84
	b _08041B94
	.align 2, 0
_08041B74: .4byte 0x03002C30
_08041B78:
	ldr r0, _08041BA0 @ =0x03002C30
	adds r1, r3, #0
	adds r1, #0x2b
	ldrb r1, [r1]
	lsls r1, r1, #6
	adds r1, r1, r0
	ldrh r2, [r1]
	movs r4, #0x80
	lsls r4, r4, #7
	adds r0, r4, #0
	orrs r0, r2
	strh r0, [r1]
	adds r1, r3, #0
	adds r1, #0x29
_08041B94:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08041BA0: .4byte 0x03002C30
	.syntax divided
