	.syntax unified

	thumb_func_start sub_08028B58
sub_08028B58: @ 0x08028B58
	push {r4, r5, r6, lr}
	movs r5, #0
	movs r4, #0
	ldr r6, _08028B9C @ =0x030018D2
_08028B60:
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _08028B78
	adds r0, r4, #0
	adds r0, #0x21
	movs r1, #0
	bl advance_sprite_anim_frame
	cmp r0, #0
	beq _08028B78
	movs r5, #1
_08028B78:
	adds r4, #1
	cmp r4, #2
	bls _08028B60
	cmp r5, #0
	beq _08028B94
	ldr r0, _08028BA0 @ =0x03000440
	adds r0, #0x86
	movs r1, #0x3c
	strh r1, [r0]
	ldr r1, _08028BA4 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08028B94:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08028B9C: .4byte 0x030018D2
_08028BA0: .4byte 0x03000440
_08028BA4: .4byte 0x03001800
	.syntax divided
