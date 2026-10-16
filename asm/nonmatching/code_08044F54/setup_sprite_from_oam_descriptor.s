	.syntax unified

	thumb_func_start setup_sprite_from_oam_descriptor
setup_sprite_from_oam_descriptor: @ 0x0804545C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	mov sb, r0
	adds r4, r1, #0
	mov r8, r3
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	ldr r1, [r4]
	lsls r0, r1, #0x1a
	lsrs r0, r0, #0x1e
	lsls r0, r0, #0xe
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x1e
	lsls r1, r1, #0x1e
	bl sub_08044E64
	adds r6, r0, #0
	add r1, sp, #0x18
	lsrs r0, r6, #0x10
	strh r0, [r1]
	adds r0, r1, #0
	strh r6, [r0, #2]
	ldrh r1, [r0]
	ldrh r0, [r0, #2]
	adds r6, r1, #0
	muls r6, r0, r6
	ldrb r1, [r4]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _080454A2
	lsrs r6, r6, #1
_080454A2:
	ldr r4, [r4]
	lsls r3, r4, #0x14
	lsrs r0, r3, #0x1c
	adds r1, r6, #0
	muls r1, r0, r1
	lsls r5, r4, #0x10
	lsrs r0, r5, #0x1c
	adds r6, r1, #0
	muls r6, r0, r6
	lsls r1, r4, #0x1a
	lsrs r1, r1, #0x1e
	lsls r1, r1, #0xe
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x1e
	lsls r2, r2, #0x1e
	lsrs r3, r3, #0x1c
	adds r5, r0, #0
	str r5, [sp]
	lsls r4, r4, #0x1c
	lsrs r4, r4, #0x1c
	str r4, [sp, #4]
	str r7, [sp, #8]
	str r6, [sp, #0xc]
	ldr r0, _080454EC @ =0x02030000
	str r0, [sp, #0x10]
	mov r0, r8
	str r0, [sp, #0x14]
	mov r0, sb
	bl decompress_and_load_sprite_tiles
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080454EC: .4byte 0x02030000
	.syntax divided
