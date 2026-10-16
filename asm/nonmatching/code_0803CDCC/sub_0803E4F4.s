	.syntax unified

	thumb_func_start sub_0803E4F4
sub_0803E4F4: @ 0x0803E4F4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	bl sub_08043CA8
	movs r5, #0x80
	lsls r5, r5, #0x13
	ldrh r1, [r5]
	ldr r0, _0803E5E0 @ =0x0000E0FF
	ands r0, r1
	strh r0, [r5]
	ldr r6, _0803E5E4 @ =0x04000008
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r0, r1, #0
	strh r0, [r6]
	ldr r2, _0803E5E8 @ =0x0400000A
	mov r8, r2
	ldr r1, _0803E5EC @ =0x00001801
	adds r0, r1, #0
	strh r0, [r2]
	adds r2, #2
	mov sb, r2
	ldr r1, _0803E5F0 @ =0x00001902
	adds r0, r1, #0
	strh r0, [r2]
	adds r2, #2
	mov sl, r2
	ldr r1, _0803E5F4 @ =0x00001B03
	adds r0, r1, #0
	strh r0, [r2]
	movs r7, #0
	str r7, [sp, #8]
	ldr r1, _0803E5F8 @ =0x05000120
	ldr r4, _0803E5FC @ =0x01000008
	add r0, sp, #8
	adds r2, r4, #0
	bl CpuFastSet
	ldr r0, _0803E600 @ =0x11111111
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	ldr r1, _0803E604 @ =0x06004120
	adds r2, r4, #0
	bl CpuFastSet
	ldrh r0, [r6]
	str r0, [sp]
	ldr r4, _0803E608 @ =0x00009209
	str r4, [sp, #4]
	movs r0, #0x20
	movs r1, #0x20
	movs r2, #0
	movs r3, #0
	bl vram_fill_tilemap_rect
	mov r2, r8
	ldrh r0, [r2]
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0x20
	movs r1, #0x20
	movs r2, #0
	movs r3, #0
	bl vram_fill_tilemap_rect
	mov r1, sb
	ldrh r0, [r1]
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0x20
	movs r1, #0x20
	movs r2, #0
	movs r3, #0
	bl vram_fill_tilemap_rect
	mov r2, sl
	ldrh r0, [r2]
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0x20
	movs r1, #0x20
	movs r2, #0
	movs r3, #0
	bl vram_fill_tilemap_rect
	str r7, [sp, #0x10]
	add r0, sp, #0x10
	ldr r1, _0803E60C @ =0x03002C30
	ldr r2, _0803E610 @ =0x01000800
	bl CpuFastSet
	ldrh r0, [r5]
	movs r2, #0xfb
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r5]
	movs r0, #5
	movs r1, #0x3f
	movs r2, #0x20
	bl set_blend_effect_mode
	ldr r1, _0803E614 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803E5E0: .4byte 0x0000E0FF
_0803E5E4: .4byte 0x04000008
_0803E5E8: .4byte 0x0400000A
_0803E5EC: .4byte 0x00001801
_0803E5F0: .4byte 0x00001902
_0803E5F4: .4byte 0x00001B03
_0803E5F8: .4byte 0x05000120
_0803E5FC: .4byte 0x01000008
_0803E600: .4byte 0x11111111
_0803E604: .4byte 0x06004120
_0803E608: .4byte 0x00009209
_0803E60C: .4byte 0x03002C30
_0803E610: .4byte 0x01000800
_0803E614: .4byte 0x0300137C
	.syntax divided
