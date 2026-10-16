	.syntax unified

	thumb_func_start setup_scene_with_bg_and_sprites
	.global setup_scene_with_bg_and_sprites
setup_scene_with_bg_and_sprites: @ 0x080446B4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x3c
	mov ip, r0
	ldr r0, [sp, #0x5c]
	ldr r4, [sp, #0x60]
	ldr r5, [sp, #0x64]
	ldr r7, [sp, #0x68]
	ldr r6, [sp, #0x70]
	mov r8, r6
	ldr r6, [sp, #0x74]
	mov sb, r6
	ldr r6, [sp, #0x78]
	mov sl, r6
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp, #0x24]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp, #0x28]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r3, [sp, #0x2c]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x30]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x34]
	lsls r5, r5, #0x10
	lsrs r2, r5, #0x10
	ldr r0, [sp, #0x6c]
	lsls r6, r0, #0x18
	lsrs r6, r6, #0x18
	str r6, [sp, #0x38]
	mov r1, r8
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x18
	mov r4, sb
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	mov sb, r4
	mov r6, sl
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	mov r8, r6
	cmp r7, #1
	beq _0804472C
	cmp r7, #1
	blo _08044728
	cmp r7, #2
	beq _08044730
	cmp r7, #3
	beq _08044736
	b _0804473A
_08044728:
	movs r7, #0x64
	b _0804473A
_0804472C:
	movs r7, #0xc8
	b _0804473A
_08044730:
	movs r7, #0x96
	lsls r7, r7, #1
	b _0804473A
_08044736:
	movs r7, #0xc8
	lsls r7, r7, #1
_0804473A:
	cmp r3, #0
	bne _08044742
	movs r3, #1
	b _08044744
_08044742:
	movs r3, #2
_08044744:
	movs r5, #0
	mov r0, sb
	cmp r0, #1
	bne _0804474E
	movs r5, #4
_0804474E:
	ldr r1, _080447D0 @ =0x02026000
	mov r4, ip
	lsls r0, r4, #6
	add r0, ip
	lsls r0, r0, #4
	ldr r6, _080447D4 @ =0x020260D0
	adds r0, r0, r6
	str r0, [r1, #8]
	ldr r4, _080447D8 @ =0x03002414
	ldr r0, [r4]
	ldr r6, _080447DC @ =0x00000B84
	adds r0, r0, r6
	ldr r6, [sp, #0x2c]
	str r6, [sp]
	ldr r6, [sp, #0x30]
	str r6, [sp, #4]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	str r2, [sp, #8]
	ldr r6, [sp, #0x34]
	lsls r2, r6, #0x10
	asrs r2, r2, #0x10
	str r2, [sp, #0xc]
	str r7, [sp, #0x10]
	ldr r2, [sp, #0x38]
	str r2, [sp, #0x14]
	orrs r3, r5
	str r3, [sp, #0x18]
	mov r6, r8
	str r6, [sp, #0x1c]
	ldr r2, [sp, #0x24]
	ldr r3, [sp, #0x28]
	bl setup_scene_bg_layers_and_sprites
	mov r0, sb
	cmp r0, #2
	bne _080447BE
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x20]
	ldr r1, [r4]
	ldr r2, _080447DC @ =0x00000B84
	adds r1, r1, r2
	ldr r2, _080447E0 @ =0x01000100
	add r0, sp, #0x20
	bl CpuFastSet
	ldr r0, [r4]
	ldr r6, _080447E4 @ =0x00001094
	adds r0, r0, r6
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r4]
	ldr r2, _080447E8 @ =0x00001095
	adds r0, r0, r2
	strb r1, [r0]
_080447BE:
	add sp, #0x3c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080447D0: .4byte 0x02026000
_080447D4: .4byte 0x020260D0
_080447D8: .4byte 0x03002414
_080447DC: .4byte 0x00000B84
_080447E0: .4byte 0x01000100
_080447E4: .4byte 0x00001094
_080447E8: .4byte 0x00001095
	.syntax divided
