	.syntax unified

	thumb_func_start sub_0800A960
	.global sub_0800A960
sub_0800A960: @ 0x0800A960
	push {r4, lr}
	ldr r4, _0800A988 @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x46
	ldrb r0, [r0]
	cmp r0, #0
	beq _0800A990
	cmp r0, #1
	beq _0800A9C4
	ldr r0, _0800A98C @ =0x03000BE0
	adds r1, r4, #0
	adds r1, #0x3d
	ldrb r1, [r1]
	lsls r1, r1, #6
	adds r1, r1, r0
	ldrb r0, [r1, #5]
	cmp r0, #0x3b
	bhi _0800A9F8
_0800A984:
	movs r0, #0x34
	b _0800AA12
	.align 2, 0
_0800A988: .4byte 0x03000440
_0800A98C: .4byte 0x03000BE0
_0800A990:
	ldr r0, _0800A9BC @ =0x03000BE0
	adds r1, r4, #0
	adds r1, #0x3d
	ldrb r1, [r1]
	lsls r1, r1, #6
	adds r1, r1, r0
	ldrb r0, [r1, #5]
	cmp r0, #9
	bls _0800A984
	ldrb r1, [r1, #1]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldr r1, _0800A9C0 @ =0x083B7E0C
	adds r0, r0, r1
	adds r4, #0xee
	adds r1, r4, #0
	movs r2, #3
	bl memcpy_bytes_08041D04
	ldrb r0, [r4]
	b _0800AA12
	.align 2, 0
_0800A9BC: .4byte 0x03000BE0
_0800A9C0: .4byte 0x083B7E0C
_0800A9C4:
	ldr r0, _0800A9F0 @ =0x03000BE0
	adds r1, r4, #0
	adds r1, #0x3d
	ldrb r1, [r1]
	lsls r1, r1, #6
	adds r1, r1, r0
	ldrb r0, [r1, #5]
	cmp r0, #0x1d
	bls _0800A984
	ldrb r1, [r1, #1]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldr r1, _0800A9F4 @ =0x083B7E0C
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0xee
	movs r2, #3
	bl memcpy_bytes_08041D04
	adds r0, r4, #0
	adds r0, #0xef
	b _0800AA10
	.align 2, 0
_0800A9F0: .4byte 0x03000BE0
_0800A9F4: .4byte 0x083B7E0C
_0800A9F8:
	ldrb r1, [r1, #1]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldr r1, _0800AA18 @ =0x083B7E0C
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0xee
	movs r2, #3
	bl memcpy_bytes_08041D04
	adds r0, r4, #0
	adds r0, #0xf0
_0800AA10:
	ldrb r0, [r0]
_0800AA12:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0800AA18: .4byte 0x083B7E0C
	.syntax divided
