	.syntax unified

	thumb_func_start init_scene_with_bg_and_palette
	.global init_scene_with_bg_and_palette
init_scene_with_bg_and_palette: @ 0x080447EC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x60]
	ldr r4, [sp, #0x64]
	ldr r5, [sp, #0x68]
	ldr r7, [sp, #0x6c]
	ldr r6, [sp, #0x74]
	mov r8, r6
	ldr r6, [sp, #0x78]
	mov sb, r6
	ldr r6, [sp, #0x7c]
	mov sl, r6
	ldr r6, [sp, #0x80]
	mov ip, r6
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp, #0x28]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp, #0x2c]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r3, [sp, #0x30]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x34]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x38]
	lsls r5, r5, #0x10
	lsrs r2, r5, #0x10
	ldr r0, [sp, #0x70]
	lsls r6, r0, #0x18
	lsrs r6, r6, #0x18
	str r6, [sp, #0x3c]
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
	mov r0, ip
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r7, #1
	beq _08044870
	cmp r7, #1
	blo _0804486A
	cmp r7, #2
	beq _08044876
	cmp r7, #3
	beq _0804487E
	b _08044884
_0804486A:
	adds r7, r0, #0
	adds r7, #0x64
	b _08044884
_08044870:
	adds r7, r0, #0
	adds r7, #0xc8
	b _08044884
_08044876:
	movs r1, #0x96
	lsls r1, r1, #1
	adds r7, r0, r1
	b _08044884
_0804487E:
	movs r4, #0xc8
	lsls r4, r4, #1
	adds r7, r0, r4
_08044884:
	cmp r3, #0
	bne _0804488C
	movs r3, #1
	b _0804488E
_0804488C:
	movs r3, #2
_0804488E:
	movs r5, #0
	mov r6, sb
	cmp r6, #1
	bne _08044898
	movs r5, #4
_08044898:
	ldr r1, _08044918 @ =0x02026000
	ldr r4, [sp, #0x24]
	lsls r0, r4, #6
	adds r0, r0, r4
	lsls r0, r0, #4
	ldr r6, _0804491C @ =0x020260D0
	adds r0, r0, r6
	str r0, [r1, #8]
	ldr r4, _08044920 @ =0x03002414
	ldr r0, [r4]
	ldr r6, _08044924 @ =0x00000B84
	adds r0, r0, r6
	ldr r6, [sp, #0x30]
	str r6, [sp]
	ldr r6, [sp, #0x34]
	str r6, [sp, #4]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	str r2, [sp, #8]
	ldr r6, [sp, #0x38]
	lsls r2, r6, #0x10
	asrs r2, r2, #0x10
	str r2, [sp, #0xc]
	str r7, [sp, #0x10]
	ldr r2, [sp, #0x3c]
	str r2, [sp, #0x14]
	orrs r3, r5
	str r3, [sp, #0x18]
	mov r6, r8
	str r6, [sp, #0x1c]
	ldr r2, [sp, #0x28]
	ldr r3, [sp, #0x2c]
	bl setup_scene_bg_layers_and_sprites
	mov r0, sb
	cmp r0, #2
	bne _08044908
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x20]
	ldr r1, [r4]
	ldr r2, _08044924 @ =0x00000B84
	adds r1, r1, r2
	ldr r2, _08044928 @ =0x01000100
	add r0, sp, #0x20
	bl CpuFastSet
	ldr r0, [r4]
	ldr r6, _0804492C @ =0x00001094
	adds r0, r0, r6
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r4]
	ldr r2, _08044930 @ =0x00001095
	adds r0, r0, r2
	strb r1, [r0]
_08044908:
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08044918: .4byte 0x02026000
_0804491C: .4byte 0x020260D0
_08044920: .4byte 0x03002414
_08044924: .4byte 0x00000B84
_08044928: .4byte 0x01000100
_0804492C: .4byte 0x00001094
_08044930: .4byte 0x00001095
	.syntax divided
