	.syntax unified

	thumb_func_start sub_0805E310
sub_0805E310: @ 0x0805E310
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	ldr r1, _0805E420 @ =0x0400000A
	ldr r0, _0805E424 @ =0x00001F05
	strh r0, [r1]
	ldr r4, _0805E428 @ =0x0400000C
	subs r0, #0xff
	strh r0, [r4]
	ldr r5, _0805E42C @ =0x0400000E
	subs r0, #0xff
	strh r0, [r5]
	ldr r0, _0805E430 @ =0x08794E6C
	ldrh r1, [r1]
	bl decompress_and_write_tilemap
	ldr r0, _0805E434 @ =0x0879514C
	ldrh r1, [r4]
	bl decompress_and_write_tilemap
	ldr r0, _0805E438 @ =0x08795418
	ldrh r1, [r5]
	bl decompress_and_write_tilemap
	ldr r0, _0805E43C @ =0x08793628
	ldr r5, _0805E440 @ =0x02030000
	adds r1, r5, #0
	bl dma3_copy_or_decompress
	adds r4, r0, #0
	ldr r1, _0805E444 @ =0x06004000
	lsls r2, r4, #0xa
	lsrs r2, r2, #0xb
	adds r0, r5, #0
	bl CpuSet
	ldr r0, _0805E448 @ =0x03006F74
	ldr r1, [r0]
	lsrs r0, r4, #5
	subs r0, #1
	movs r5, #0
	strh r0, [r1, #0x36]
	ldr r0, _0805E44C @ =0x084C21BC
	ldr r1, _0805E444 @ =0x06004000
	adds r4, r4, r1
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r4, #0
	bl CpuSet
	str r5, [sp]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	ldr r4, _0805E450 @ =0x01000080
	mov r0, sp
	adds r2, r4, #0
	bl CpuFastSet
	str r5, [sp, #4]
	add r0, sp, #4
	ldr r1, _0805E454 @ =0x05000200
	adds r2, r4, #0
	bl CpuFastSet
	ldr r0, _0805E458 @ =0x08784DA4
	ldr r1, _0805E45C @ =0x06010000
	bl lz_decompress_dispatch
	ldr r0, _0805E460 @ =0x084C6A98
	ldr r1, _0805E464 @ =0x06017400
	bl lz_decompress_dispatch
	movs r1, #0
	ldr r2, _0805E468 @ =0x03002C30
	movs r7, #0xc0
	lsls r7, r7, #8
	movs r6, #2
	movs r4, #0xe
	adds r5, r2, #0
	movs r3, #8
_0805E3B2:
	lsls r0, r1, #6
	adds r0, r0, r2
	strh r7, [r0]
	strb r6, [r0, #0x1c]
	strb r4, [r0, #0xa]
	strh r3, [r0, #6]
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #1
	bls _0805E3B2
	ldrh r1, [r5]
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r2, #0
	movs r2, #0
	orrs r0, r1
	strh r0, [r5]
	movs r3, #0xa0
	lsls r3, r3, #3
	adds r4, r5, r3
	movs r3, #0x80
	lsls r3, r3, #8
	strh r3, [r4]
	ldr r6, _0805E46C @ =0x0000051C
	adds r1, r5, r6
	movs r0, #2
	strb r0, [r1]
	ldr r1, _0805E470 @ =0x00000502
	adds r0, r5, r1
	movs r1, #0x10
	strh r1, [r0]
	subs r6, #0x18
	adds r0, r5, r6
	strh r1, [r0]
	ldr r1, _0805E474 @ =0x0000050A
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #2
	adds r1, r5, r6
	movs r0, #0x23
	strh r0, [r1]
	ldr r0, _0805E478 @ =0x03000584
	ldrb r0, [r0]
	cmp r0, #0
	bne _0805E47C
	movs r0, #0x80
	lsls r0, r0, #7
	adds r1, r0, #0
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r4]
	ldr r1, _0805E448 @ =0x03006F74
	mov ip, r1
	b _0805E4CA
	.align 2, 0
_0805E420: .4byte 0x0400000A
_0805E424: .4byte 0x00001F05
_0805E428: .4byte 0x0400000C
_0805E42C: .4byte 0x0400000E
_0805E430: .4byte gUnk_08794E6C
_0805E434: .4byte gUnk_0879514C
_0805E438: .4byte gUnk_08795418
_0805E43C: .4byte gUnk_08793628
_0805E440: .4byte 0x02030000
_0805E444: .4byte 0x06004000
_0805E448: .4byte 0x03006F74
_0805E44C: .4byte gUnk_084C21BC
_0805E450: .4byte 0x01000080
_0805E454: .4byte 0x05000200
_0805E458: .4byte gUnk_08784DA4
_0805E45C: .4byte 0x06010000
_0805E460: .4byte gUnk_084C6A98
_0805E464: .4byte 0x06017400
_0805E468: .4byte 0x03002C30
_0805E46C: .4byte 0x0000051C
_0805E470: .4byte 0x00000502
_0805E474: .4byte 0x0000050A
_0805E478: .4byte 0x03000584
_0805E47C:
	ldr r3, _0805E58C @ =0x03006F74
	ldr r2, [r3]
	ldr r1, _0805E590 @ =0x03000BE0
	ldr r0, _0805E594 @ =0x030017EC
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r0, r0, r1
	ldrb r0, [r0, #1]
	lsls r0, r0, #2
	adds r0, #1
	ldrh r1, [r2, #0x36]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	movs r2, #0xc0
	lsls r2, r2, #0x17
	orrs r2, r1
	lsrs r2, r2, #0x10
	ldr r0, _0805E598 @ =0x0400000A
	ldrh r0, [r0]
	lsrs r0, r0, #8
	movs r1, #0x1f
	ands r0, r1
	lsls r0, r0, #0xb
	ldr r1, _0805E59C @ =0x060000C4
	adds r4, r0, r1
	strh r2, [r4]
	ldr r6, _0805E5A0 @ =0x060000C6
	adds r4, r0, r6
	adds r1, r2, #1
	strh r1, [r4]
	ldr r1, _0805E5A4 @ =0x06000104
	adds r4, r0, r1
	adds r1, r2, #2
	strh r1, [r4]
	adds r6, #0x40
	adds r4, r0, r6
	adds r2, #3
	strh r2, [r4]
	mov ip, r3
_0805E4CA:
	movs r1, #0
	ldr r0, _0805E5A8 @ =0x0300137C
	mov r8, r0
	ldr r7, _0805E5AC @ =0x03002C30
	movs r6, #0x80
	lsls r6, r6, #8
	movs r4, #2
	movs r3, #0xe
	movs r2, #5
_0805E4DC:
	adds r0, r1, #2
	lsls r0, r0, #6
	adds r0, r0, r7
	strh r6, [r0]
	strb r4, [r0, #0x1c]
	strb r3, [r0, #0xa]
	strh r2, [r0, #6]
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #1
	bls _0805E4DC
	adds r1, r5, #0
	adds r1, #0xc0
	ldrh r2, [r1]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r3, #0
	movs r3, #0
	movs r4, #0
	orrs r0, r2
	strh r0, [r1]
	mov r6, ip
	ldr r0, [r6]
	strb r3, [r0, #0xd]
	ldr r0, [r6]
	strb r3, [r0, #0xe]
	ldr r0, [r6]
	str r4, [r0, #8]
	ldrb r3, [r0, #0xd]
	lsls r3, r3, #3
	adds r3, #0x14
	strh r3, [r5, #2]
	ldrb r2, [r0, #0xe]
	lsls r2, r2, #4
	ldr r0, [r0, #8]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	adds r0, #0x40
	adds r2, r2, r0
	strh r2, [r5, #4]
	adds r0, r5, #0
	adds r0, #0x42
	strh r3, [r0]
	ldr r0, [r6]
	ldrb r2, [r0, #0xe]
	lsls r2, r2, #4
	ldr r0, [r0, #8]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	subs r0, #0x50
	subs r2, r2, r0
	adds r0, r5, #0
	adds r0, #0x44
	strh r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0xc0
	lsls r0, r0, #8
	strh r0, [r1]
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #2
	strb r0, [r1]
	movs r3, #0x85
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r0, #0xe
	strb r0, [r1]
	movs r6, #0x83
	lsls r6, r6, #1
	adds r1, r5, r6
	movs r0, #0x26
	strh r0, [r1]
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805E58C: .4byte 0x03006F74
_0805E590: .4byte 0x03000BE0
_0805E594: .4byte 0x030017EC
_0805E598: .4byte 0x0400000A
_0805E59C: .4byte 0x060000C4
_0805E5A0: .4byte 0x060000C6
_0805E5A4: .4byte 0x06000104
_0805E5A8: .4byte 0x0300137C
_0805E5AC: .4byte 0x03002C30
	.syntax divided
