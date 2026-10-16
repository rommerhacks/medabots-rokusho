	.syntax unified

	thumb_func_start decompress_and_write_tilemap
	.global decompress_and_write_tilemap
decompress_and_write_tilemap: @ 0x0805B8E8
	push {r4, r5, r6, r7, lr}
	adds r5, r1, #0
	ldr r4, _0805B94C @ =0x02030000
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r7, [r4]
	ldr r0, _0805B950 @ =0x02030004
	ldr r6, [r0]
	adds r4, #0x10
	lsrs r0, r5, #8
	movs r1, #0x1f
	ands r0, r1
	lsls r0, r0, #0xb
	movs r1, #0xc0
	lsls r1, r1, #0x13
	adds r2, r0, r1
	movs r0, #0xc0
	lsls r0, r0, #8
	ands r0, r5
	lsrs r0, r0, #0xe
	movs r1, #1
	ands r0, r1
	movs r5, #0x20
	cmp r0, #0
	beq _0805B91E
	movs r5, #0x40
_0805B91E:
	movs r0, #0
	cmp r0, r6
	bge _0805B944
_0805B924:
	movs r1, #0
	adds r3, r0, #1
	cmp r1, r5
	bge _0805B93E
_0805B92C:
	cmp r1, r7
	bge _0805B936
	ldrh r0, [r4]
	strh r0, [r2]
	adds r4, #2
_0805B936:
	adds r2, #2
	adds r1, #1
	cmp r1, r5
	blt _0805B92C
_0805B93E:
	adds r0, r3, #0
	cmp r0, r6
	blt _0805B924
_0805B944:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805B94C: .4byte 0x02030000
_0805B950: .4byte 0x02030004
	.syntax divided
