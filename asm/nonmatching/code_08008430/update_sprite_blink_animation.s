	.syntax unified

	thumb_func_start update_sprite_blink_animation
update_sprite_blink_animation: @ 0x0800B79C
	push {r4, lr}
	ldr r3, _0800B7C4 @ =0x03002C30
	ldr r1, _0800B7C8 @ =0x000001E7
	adds r0, r3, r1
	ldrb r1, [r0]
	mov ip, r3
	cmp r1, #0x1e
	beq _0800B7EC
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800B7D0
	movs r4, #0xe0
	lsls r4, r4, #1
	adds r2, r3, r4
	ldrh r1, [r2]
	ldr r0, _0800B7CC @ =0x0000BFFF
	ands r0, r1
	b _0800B7E0
	.align 2, 0
_0800B7C4: .4byte 0x03002C30
_0800B7C8: .4byte 0x000001E7
_0800B7CC: .4byte 0x0000BFFF
_0800B7D0:
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r2, r3, r0
	ldrh r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r3, #0
	orrs r0, r1
_0800B7E0:
	strh r0, [r2]
	ldr r1, _0800B7E8 @ =0x000001E7
	add r1, ip
	b _0800B802
	.align 2, 0
_0800B7E8: .4byte 0x000001E7
_0800B7EC:
	movs r4, #0xe0
	lsls r4, r4, #1
	adds r2, r3, r4
	ldrh r1, [r2]
	movs r4, #0x80
	lsls r4, r4, #7
	adds r0, r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _0800B810 @ =0x000001E9
	adds r1, r3, r0
_0800B802:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800B810: .4byte 0x000001E9
	.syntax divided
