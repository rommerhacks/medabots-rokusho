	.syntax unified

	thumb_func_start write_tilemap_to_vram_08000E94
write_tilemap_to_vram_08000E94: @ 0x08000E94
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r2, #0
	lsrs r2, r3, #8
	movs r4, #0x1f
	ands r2, r4
	lsls r2, r2, #0xb
	lsls r0, r0, #1
	movs r4, #0xc0
	lsls r4, r4, #0x13
	adds r0, r0, r4
	adds r2, r2, r0
	lsls r1, r1, #6
	adds r2, r2, r1
	mov sb, r2
	adds r2, r5, #0
	adds r2, #0x10
	movs r0, #0xc0
	lsls r0, r0, #8
	ands r0, r3
	lsrs r0, r0, #0xe
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08000ED4
	mov r0, sb
	adds r1, r5, #0
	bl copy_tilemap_with_offset_08000F78
	b _08000F0A
_08000ED4:
	movs r1, #0
	ldr r0, [r5, #4]
	cmp r1, r0
	bhs _08000F0A
	ldr r5, [r5]
	ldr r7, _08000F18 @ =0x03000580
	mov r8, r7
	mov ip, r0
_08000EE4:
	lsls r0, r1, #6
	mov r4, sb
	adds r3, r4, r0
	movs r4, #0
	adds r1, #1
	cmp r4, r5
	bhs _08000F06
	mov r6, r8
_08000EF4:
	ldrh r0, [r6]
	ldrh r7, [r2]
	adds r0, r0, r7
	strh r0, [r3]
	adds r2, #2
	adds r3, #2
	adds r4, #1
	cmp r4, r5
	blo _08000EF4
_08000F06:
	cmp r1, ip
	blo _08000EE4
_08000F0A:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08000F18: .4byte 0x03000580
	.syntax divided
