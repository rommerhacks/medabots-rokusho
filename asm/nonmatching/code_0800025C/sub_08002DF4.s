	.syntax unified

	thumb_func_start sub_08002DF4
sub_08002DF4: @ 0x08002DF4
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0xc
	ldr r1, _08002EAC @ =0x03000440
	adds r0, r1, #0
	adds r0, #0x8e
	ldrb r0, [r0]
	cmp r0, #2
	beq _08002E30
	adds r4, r1, #0
	adds r4, #0x84
	ldrb r0, [r4]
	cmp r0, #0x10
	bhi _08002E30
	adds r1, r0, #0
	lsls r1, r1, #1
	ldr r2, _08002EB0 @ =0x00001FFF
	movs r0, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r1, [r4]
	lsls r1, r1, #1
	ldr r2, _08002EB4 @ =0x0000FFFF
	movs r0, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_08002E30:
	ldr r0, _08002EAC @ =0x03000440
	adds r5, r0, #0
	adds r5, #0x88
	ldrb r1, [r5]
	movs r2, #0x12
	subs r2, r2, r1
	ldr r4, _08002EB8 @ =0x083B4AE0
	adds r0, #0x8e
	ldrb r1, [r0]
	movs r0, #0xd
	muls r0, r1, r0
	adds r0, #0x1f
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	str r0, [sp]
	ldr r0, _08002EBC @ =0x04000008
	mov r8, r0
	ldrh r0, [r0]
	str r0, [sp, #4]
	movs r6, #0
	str r6, [sp, #8]
	movs r0, #0xc
	movs r1, #2
	movs r3, #0
	bl write_tilemap_rect
	ldrb r0, [r5]
	movs r2, #0x1e
	subs r2, r2, r0
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r4, r4, r1
	ldr r0, [r4]
	str r0, [sp]
	mov r1, r8
	ldrh r0, [r1]
	str r0, [sp, #4]
	str r6, [sp, #8]
	movs r0, #1
	movs r1, #2
	movs r3, #0
	bl write_tilemap_rect
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x13
	bne _08002E9E
	ldr r1, _08002EC0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08002E9E:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08002EAC: .4byte 0x03000440
_08002EB0: .4byte 0x00001FFF
_08002EB4: .4byte 0x0000FFFF
_08002EB8: .4byte 0x083B4AE0
_08002EBC: .4byte 0x04000008
_08002EC0: .4byte 0x0300137C
	.syntax divided
