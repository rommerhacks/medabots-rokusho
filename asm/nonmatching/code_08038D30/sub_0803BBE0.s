	.syntax unified

	thumb_func_start sub_0803BBE0
sub_0803BBE0: @ 0x0803BBE0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	ldr r0, _0803BC04 @ =0x03002C30
	ldr r1, _0803BC08 @ =0x0300056F
	ldrb r4, [r1]
	lsls r1, r4, #6
	adds r1, r1, r0
	ldrh r3, [r1, #0x30]
	adds r6, r3, #0
	cmp r6, #0
	beq _0803BC0C
	subs r0, r3, #1
	strh r0, [r1, #0x30]
	b _0803BDF6
	.align 2, 0
_0803BC04: .4byte 0x03002C30
_0803BC08: .4byte 0x0300056F
_0803BC0C:
	adds r5, r4, #0
	cmp r5, #1
	beq _0803BC14
	b _0803BD14
_0803BC14:
	ldr r7, _0803BCEC @ =0x03001800
	ldr r2, _0803BCF0 @ =0x0000015F
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803BC22
	b _0803BDD8
_0803BC22:
	movs r3, #0xff
	adds r3, r3, r7
	mov sl, r3
	ldrb r1, [r3]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _0803BCCC
	movs r0, #0
	bl get_active_bot_part_index_and_load_values
	ldr r4, _0803BCF4 @ =0x03001864
	ldrb r1, [r4]
	ldr r0, _0803BCF8 @ =0x03001865
	ldrb r2, [r0]
	ldr r3, _0803BCFC @ =0x03001866
	ldrb r3, [r3]
	mov ip, r3
	ldr r4, _0803BD00 @ =0x03001867
	ldrb r0, [r4]
	str r0, [sp]
	ldr r3, _0803BD04 @ =0x03001954
	movs r4, #0
	ldrsh r0, [r3, r4]
	str r0, [sp, #4]
	ldr r3, _0803BD08 @ =0x03001956
	movs r4, #0
	ldrsh r0, [r3, r4]
	str r0, [sp, #8]
	movs r0, #0x3c
	adds r0, r0, r7
	mov r8, r0
	ldrb r0, [r0]
	adds r0, #2
	str r0, [sp, #0xc]
	movs r3, #4
	mov sb, r3
	str r3, [sp, #0x10]
	str r6, [sp, #0x14]
	str r6, [sp, #0x18]
	str r6, [sp, #0x1c]
	movs r0, #0x8a
	lsls r0, r0, #1
	adds r4, r7, r0
	ldrb r0, [r4]
	str r0, [sp, #0x20]
	movs r0, #0
	mov r3, ip
	bl init_scene_with_bg_and_palette
	ldr r2, _0803BCF4 @ =0x03001864
	ldrb r1, [r2]
	ldr r3, _0803BCF8 @ =0x03001865
	ldrb r3, [r3]
	mov ip, r3
	ldr r0, _0803BCFC @ =0x03001866
	ldrb r0, [r0]
	str r0, [sp, #0x24]
	ldr r2, _0803BD00 @ =0x03001867
	ldrb r0, [r2]
	str r0, [sp]
	ldr r3, _0803BD04 @ =0x03001954
	movs r2, #0
	ldrsh r0, [r3, r2]
	str r0, [sp, #4]
	ldr r3, _0803BD08 @ =0x03001956
	movs r2, #0
	ldrsh r0, [r3, r2]
	str r0, [sp, #8]
	mov r3, r8
	ldrb r0, [r3]
	adds r0, #2
	str r0, [sp, #0xc]
	mov r0, sb
	str r0, [sp, #0x10]
	str r6, [sp, #0x14]
	str r5, [sp, #0x18]
	str r6, [sp, #0x1c]
	ldrb r0, [r4]
	str r0, [sp, #0x20]
	movs r0, #0
	mov r2, ip
	ldr r3, [sp, #0x24]
	bl init_scene_with_bg_and_palette
_0803BCCC:
	mov r2, sl
	ldrb r1, [r2]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r2]
	ldr r3, _0803BD0C @ =0x0300056F
	ldrb r0, [r3]
	lsls r0, r0, #6
	ldr r4, _0803BD10 @ =0x03002C30
	adds r0, r0, r4
	adds r0, #0x2c
	ldrb r0, [r0]
	movs r5, #0x89
	lsls r5, r5, #1
	adds r1, r7, r5
	b _0803BDD6
	.align 2, 0
_0803BCEC: .4byte 0x03001800
_0803BCF0: .4byte 0x0000015F
_0803BCF4: .4byte 0x03001864
_0803BCF8: .4byte 0x03001865
_0803BCFC: .4byte 0x03001866
_0803BD00: .4byte 0x03001867
_0803BD04: .4byte 0x03001954
_0803BD08: .4byte 0x03001956
_0803BD0C: .4byte 0x0300056F
_0803BD10: .4byte 0x03002C30
_0803BD14:
	ldr r7, _0803BE08 @ =0x03001800
	movs r1, #0xb0
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803BDD8
	ldr r2, _0803BE0C @ =0x030018FF
	ldrb r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803BDBA
	movs r0, #1
	bl get_active_bot_part_index_and_load_values
	ldr r3, _0803BE10 @ =0x03001864
	ldrb r1, [r3]
	ldr r4, _0803BE14 @ =0x03001865
	ldrb r2, [r4]
	ldr r5, _0803BE18 @ =0x03001866
	ldrb r3, [r5]
	ldr r4, _0803BE1C @ =0x03001867
	ldrb r0, [r4]
	str r0, [sp]
	ldr r5, _0803BE20 @ =0x03001958
	movs r4, #0
	ldrsh r0, [r5, r4]
	str r0, [sp, #4]
	ldr r5, _0803BE24 @ =0x0300195A
	movs r4, #0
	ldrsh r0, [r5, r4]
	str r0, [sp, #8]
	ldr r5, _0803BE28 @ =0x0300183C
	ldrb r0, [r5]
	adds r0, #2
	str r0, [sp, #0xc]
	movs r0, #8
	str r0, [sp, #0x10]
	movs r4, #1
	str r4, [sp, #0x14]
	str r6, [sp, #0x18]
	str r4, [sp, #0x1c]
	ldr r5, _0803BE2C @ =0x00000115
	adds r5, r5, r7
	mov sl, r5
	ldrb r0, [r5]
	str r0, [sp, #0x20]
	movs r0, #1
	bl init_scene_with_bg_and_palette
	ldr r6, _0803BE10 @ =0x03001864
	ldrb r1, [r6]
	ldr r0, _0803BE14 @ =0x03001865
	ldrb r2, [r0]
	ldr r5, _0803BE18 @ =0x03001866
	ldrb r3, [r5]
	ldr r6, _0803BE1C @ =0x03001867
	ldrb r0, [r6]
	str r0, [sp]
	ldr r5, _0803BE20 @ =0x03001958
	movs r6, #0
	ldrsh r0, [r5, r6]
	str r0, [sp, #4]
	ldr r5, _0803BE24 @ =0x0300195A
	movs r6, #0
	ldrsh r0, [r5, r6]
	str r0, [sp, #8]
	ldr r5, _0803BE28 @ =0x0300183C
	ldrb r0, [r5]
	adds r0, #2
	str r0, [sp, #0xc]
	movs r6, #8
	str r6, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	mov r4, sl
	ldrb r0, [r4]
	str r0, [sp, #0x20]
	movs r0, #1
	bl init_scene_with_bg_and_palette
_0803BDBA:
	ldr r5, _0803BE0C @ =0x030018FF
	ldrb r1, [r5]
	movs r0, #0xfd
	ands r0, r1
	strb r0, [r5]
	ldr r6, _0803BE30 @ =0x0300056F
	ldrb r0, [r6]
	lsls r0, r0, #6
	ldr r1, _0803BE34 @ =0x03002C30
	adds r0, r0, r1
	adds r0, #0x2c
	ldrb r0, [r0]
	ldr r2, _0803BE38 @ =0x00000113
	adds r1, r7, r2
_0803BDD6:
	strb r0, [r1]
_0803BDD8:
	ldr r3, _0803BE3C @ =0x03000440
	ldr r4, _0803BE40 @ =0x0000012F
	adds r0, r3, r4
	ldrb r0, [r0]
	lsls r0, r0, #6
	ldr r5, _0803BE34 @ =0x03002C30
	adds r1, r0, r5
	adds r0, r1, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803BDF6
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
_0803BDF6:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803BE08: .4byte 0x03001800
_0803BE0C: .4byte 0x030018FF
_0803BE10: .4byte 0x03001864
_0803BE14: .4byte 0x03001865
_0803BE18: .4byte 0x03001866
_0803BE1C: .4byte 0x03001867
_0803BE20: .4byte 0x03001958
_0803BE24: .4byte 0x0300195A
_0803BE28: .4byte 0x0300183C
_0803BE2C: .4byte 0x00000115
_0803BE30: .4byte 0x0300056F
_0803BE34: .4byte 0x03002C30
_0803BE38: .4byte 0x00000113
_0803BE3C: .4byte 0x03000440
_0803BE40: .4byte 0x0000012F
	.syntax divided
