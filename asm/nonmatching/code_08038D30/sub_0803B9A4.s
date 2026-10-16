	.syntax unified

	thumb_func_start sub_0803B9A4
sub_0803B9A4: @ 0x0803B9A4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	ldr r0, _0803B9C8 @ =0x0300056F
	ldrb r2, [r0]
	lsls r0, r2, #6
	ldr r3, _0803B9CC @ =0x03002C30
	adds r1, r0, r3
	ldrh r0, [r1, #0x30]
	adds r6, r0, #0
	cmp r6, #0
	beq _0803B9D0
	subs r0, #1
	strh r0, [r1, #0x30]
	b _0803BB94
	.align 2, 0
_0803B9C8: .4byte 0x0300056F
_0803B9CC: .4byte 0x03002C30
_0803B9D0:
	adds r5, r2, #0
	cmp r5, #1
	bne _0803BAC8
	ldr r7, _0803BAA4 @ =0x03001800
	movs r4, #0xff
	adds r4, r4, r7
	mov sl, r4
	ldrb r1, [r4]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _0803BA82
	movs r0, #0
	bl get_active_bot_part_index_and_load_values
	ldr r0, _0803BAA8 @ =0x03001864
	ldrb r1, [r0]
	ldr r3, _0803BAAC @ =0x03001865
	ldrb r2, [r3]
	ldr r4, _0803BAB0 @ =0x03001866
	ldrb r4, [r4]
	mov ip, r4
	ldr r3, _0803BAB4 @ =0x03001867
	ldrb r0, [r3]
	str r0, [sp]
	ldr r4, _0803BAB8 @ =0x03001954
	movs r3, #0
	ldrsh r0, [r4, r3]
	str r0, [sp, #4]
	ldr r4, _0803BABC @ =0x03001956
	movs r3, #0
	ldrsh r0, [r4, r3]
	str r0, [sp, #8]
	movs r4, #0x3c
	adds r4, r4, r7
	mov r8, r4
	ldrb r0, [r4]
	adds r0, #2
	str r0, [sp, #0xc]
	movs r0, #4
	mov sb, r0
	str r0, [sp, #0x10]
	str r6, [sp, #0x14]
	str r6, [sp, #0x18]
	str r6, [sp, #0x1c]
	movs r3, #0x8a
	lsls r3, r3, #1
	adds r4, r7, r3
	ldrb r0, [r4]
	str r0, [sp, #0x20]
	movs r0, #0
	mov r3, ip
	bl init_scene_with_bg_and_palette
	ldr r0, _0803BAA8 @ =0x03001864
	ldrb r1, [r0]
	ldr r2, _0803BAAC @ =0x03001865
	ldrb r2, [r2]
	mov ip, r2
	ldr r3, _0803BAB0 @ =0x03001866
	ldrb r3, [r3]
	str r3, [sp, #0x24]
	ldr r2, _0803BAB4 @ =0x03001867
	ldrb r0, [r2]
	str r0, [sp]
	ldr r3, _0803BAB8 @ =0x03001954
	movs r2, #0
	ldrsh r0, [r3, r2]
	str r0, [sp, #4]
	ldr r3, _0803BABC @ =0x03001956
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
_0803BA82:
	mov r2, sl
	ldrb r1, [r2]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r2]
	ldr r3, _0803BAC0 @ =0x0300056F
	ldrb r0, [r3]
	lsls r0, r0, #6
	ldr r4, _0803BAC4 @ =0x03002C30
	adds r0, r0, r4
	adds r0, #0x2c
	ldrb r0, [r0]
	movs r5, #0x89
	lsls r5, r5, #1
	adds r1, r7, r5
	b _0803BB7E
	.align 2, 0
_0803BAA4: .4byte 0x03001800
_0803BAA8: .4byte 0x03001864
_0803BAAC: .4byte 0x03001865
_0803BAB0: .4byte 0x03001866
_0803BAB4: .4byte 0x03001867
_0803BAB8: .4byte 0x03001954
_0803BABC: .4byte 0x03001956
_0803BAC0: .4byte 0x0300056F
_0803BAC4: .4byte 0x03002C30
_0803BAC8:
	ldr r7, _0803BBA4 @ =0x03001800
	ldr r0, _0803BBA8 @ =0x030018FF
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803BB62
	movs r0, #1
	bl get_active_bot_part_index_and_load_values
	ldr r2, _0803BBAC @ =0x03001864
	ldrb r1, [r2]
	ldr r3, _0803BBB0 @ =0x03001865
	ldrb r2, [r3]
	ldr r4, _0803BBB4 @ =0x03001866
	ldrb r3, [r4]
	ldr r5, _0803BBB8 @ =0x03001867
	ldrb r0, [r5]
	str r0, [sp]
	ldr r4, _0803BBBC @ =0x03001958
	movs r5, #0
	ldrsh r0, [r4, r5]
	str r0, [sp, #4]
	ldr r4, _0803BBC0 @ =0x0300195A
	movs r5, #0
	ldrsh r0, [r4, r5]
	str r0, [sp, #8]
	ldr r4, _0803BBC4 @ =0x0300183C
	ldrb r0, [r4]
	adds r0, #2
	str r0, [sp, #0xc]
	movs r5, #8
	str r5, [sp, #0x10]
	movs r4, #1
	str r4, [sp, #0x14]
	str r6, [sp, #0x18]
	str r4, [sp, #0x1c]
	ldr r6, _0803BBC8 @ =0x00000115
	adds r6, r6, r7
	mov sl, r6
	ldrb r0, [r6]
	str r0, [sp, #0x20]
	movs r0, #1
	bl init_scene_with_bg_and_palette
	ldr r0, _0803BBAC @ =0x03001864
	ldrb r1, [r0]
	ldr r3, _0803BBB0 @ =0x03001865
	ldrb r2, [r3]
	ldr r5, _0803BBB4 @ =0x03001866
	ldrb r3, [r5]
	ldr r6, _0803BBB8 @ =0x03001867
	ldrb r0, [r6]
	str r0, [sp]
	ldr r5, _0803BBBC @ =0x03001958
	movs r6, #0
	ldrsh r0, [r5, r6]
	str r0, [sp, #4]
	ldr r5, _0803BBC0 @ =0x0300195A
	movs r6, #0
	ldrsh r0, [r5, r6]
	str r0, [sp, #8]
	ldr r5, _0803BBC4 @ =0x0300183C
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
_0803BB62:
	ldr r5, _0803BBA8 @ =0x030018FF
	ldrb r1, [r5]
	movs r0, #0xfd
	ands r0, r1
	strb r0, [r5]
	ldr r6, _0803BBCC @ =0x0300056F
	ldrb r0, [r6]
	lsls r0, r0, #6
	ldr r1, _0803BBD0 @ =0x03002C30
	adds r0, r0, r1
	adds r0, #0x2c
	ldrb r0, [r0]
	ldr r2, _0803BBD4 @ =0x00000113
	adds r1, r7, r2
_0803BB7E:
	strb r0, [r1]
	ldr r1, _0803BBD0 @ =0x03002C30
	ldr r0, _0803BBD8 @ =0x03000440
	ldr r3, _0803BBDC @ =0x0000012F
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r0, r0, r1
	adds r0, #0x29
	movs r1, #1
	strb r1, [r0]
_0803BB94:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803BBA4: .4byte 0x03001800
_0803BBA8: .4byte 0x030018FF
_0803BBAC: .4byte 0x03001864
_0803BBB0: .4byte 0x03001865
_0803BBB4: .4byte 0x03001866
_0803BBB8: .4byte 0x03001867
_0803BBBC: .4byte 0x03001958
_0803BBC0: .4byte 0x0300195A
_0803BBC4: .4byte 0x0300183C
_0803BBC8: .4byte 0x00000115
_0803BBCC: .4byte 0x0300056F
_0803BBD0: .4byte 0x03002C30
_0803BBD4: .4byte 0x00000113
_0803BBD8: .4byte 0x03000440
_0803BBDC: .4byte 0x0000012F
	.syntax divided
