	.syntax unified

	thumb_func_start sub_0800E4F8
sub_0800E4F8: @ 0x0800E4F8
	push {r4, r5, lr}
	sub sp, #0x10
	bl load_medapart_sprite_by_slot
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	ldr r0, _0800E520 @ =0x03000440
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #4
	bls _0800E514
	b _0800E632
_0800E514:
	lsls r0, r0, #2
	ldr r1, _0800E524 @ =_0800E528
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0800E520: .4byte 0x03000440
_0800E524: .4byte _0800E528
_0800E528: @ jump table
	.4byte _0800E53C @ case 0
	.4byte _0800E548 @ case 1
	.4byte _0800E5BA @ case 2
	.4byte _0800E600 @ case 3
	.4byte _0800E53C @ case 4
_0800E53C:
	ldr r1, _0800E544 @ =0x0300137C
	movs r0, #0
	str r0, [r1]
	b _0800E632
	.align 2, 0
_0800E544: .4byte 0x0300137C
_0800E548:
	ldr r1, _0800E570 @ =0x03000430
	movs r0, #0
	str r0, [r1]
	ldr r1, _0800E574 @ =0x03002B8C
	movs r0, #3
	str r0, [r1]
	ldr r1, _0800E578 @ =0x0300137C
	movs r0, #0x10
	str r0, [r1]
	ldr r2, _0800E57C @ =0x03000440
	adds r0, r2, #0
	adds r0, #0x3e
	ldrb r0, [r0]
	cmp r0, #1
	beq _0800E596
	cmp r0, #1
	bgt _0800E580
	cmp r0, #0
	beq _0800E58A
	b _0800E632
	.align 2, 0
_0800E570: .4byte 0x03000430
_0800E574: .4byte 0x03002B8C
_0800E578: .4byte 0x0300137C
_0800E57C: .4byte 0x03000440
_0800E580:
	cmp r0, #2
	beq _0800E5A2
	cmp r0, #3
	beq _0800E5AE
	b _0800E632
_0800E58A:
	adds r0, r2, #0
	adds r0, #0x3d
	ldrb r1, [r0]
	adds r0, #0x5b
	strb r1, [r0]
	b _0800E632
_0800E596:
	adds r0, r2, #0
	adds r0, #0x3d
	ldrb r1, [r0]
	adds r0, #0x5c
	strb r1, [r0]
	b _0800E632
_0800E5A2:
	adds r0, r2, #0
	adds r0, #0x3d
	ldrb r1, [r0]
	adds r0, #0x5d
	strb r1, [r0]
	b _0800E632
_0800E5AE:
	adds r0, r2, #0
	adds r0, #0x3d
	ldrb r1, [r0]
	adds r0, #0x5e
	strb r1, [r0]
	b _0800E632
_0800E5BA:
	movs r4, #0
	str r4, [sp]
	ldr r1, _0800E5EC @ =0x05000200
	ldr r5, _0800E5F0 @ =0x01000080
	mov r0, sp
	adds r2, r5, #0
	bl CpuFastSet
	str r4, [sp, #4]
	add r0, sp, #4
	movs r1, #0xa0
	lsls r1, r1, #0x13
	adds r2, r5, #0
	bl CpuFastSet
	ldr r0, _0800E5F4 @ =0x03000430
	str r4, [r0]
	ldr r1, _0800E5F8 @ =0x03002B8C
	movs r0, #6
	str r0, [r1]
	ldr r1, _0800E5FC @ =0x0300137C
	movs r0, #0x65
	str r0, [r1]
	b _0800E632
	.align 2, 0
_0800E5EC: .4byte 0x05000200
_0800E5F0: .4byte 0x01000080
_0800E5F4: .4byte 0x03000430
_0800E5F8: .4byte 0x03002B8C
_0800E5FC: .4byte 0x0300137C
_0800E600:
	movs r4, #0
	str r4, [sp, #8]
	add r0, sp, #8
	ldr r1, _0800E63C @ =0x05000200
	ldr r5, _0800E640 @ =0x01000080
	adds r2, r5, #0
	bl CpuFastSet
	str r4, [sp, #0xc]
	add r0, sp, #0xc
	movs r1, #0xa0
	lsls r1, r1, #0x13
	adds r2, r5, #0
	bl CpuFastSet
	ldr r0, _0800E644 @ =0x03000430
	str r4, [r0]
	ldr r1, _0800E648 @ =0x0300178C
	movs r0, #2
	str r0, [r1]
	ldr r1, _0800E64C @ =0x03002B8C
	movs r0, #0x19
	str r0, [r1]
	ldr r0, _0800E650 @ =0x0300137C
	str r4, [r0]
_0800E632:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800E63C: .4byte 0x05000200
_0800E640: .4byte 0x01000080
_0800E644: .4byte 0x03000430
_0800E648: .4byte 0x0300178C
_0800E64C: .4byte 0x03002B8C
_0800E650: .4byte 0x0300137C
	.syntax divided
