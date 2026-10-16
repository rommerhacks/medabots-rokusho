	.syntax unified

	thumb_func_start sub_08005000
	.global sub_08005000
sub_08005000: @ 0x08005000
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	movs r5, #0
	movs r0, #0xa0
	lsls r0, r0, #0x14
	mov r8, r0
	movs r7, #0xa
	ldr r6, _08005054 @ =0x083AC43B
	ldr r1, _08005058 @ =0x0300049E
	mov sb, r1
_0800501A:
	ldr r0, _0800505C @ =0x030017A0
	lsls r1, r5, #3
	adds r3, r1, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _08005064
	ldrb r0, [r3, #3]
	ldrb r1, [r3, #4]
	ldrb r2, [r3, #5]
	ldrb r3, [r3, #6]
	str r5, [sp]
	str r7, [sp, #4]
	ldrb r4, [r6]
	str r4, [sp, #8]
	ldrb r4, [r6, #1]
	str r4, [sp, #0xc]
	mov r4, sb
	ldrb r4, [r4]
	str r4, [sp, #0x10]
	movs r4, #1
	str r4, [sp, #0x14]
	ldr r4, _08005060 @ =0x083AC432
	adds r4, r5, r4
	ldrb r4, [r4]
	str r4, [sp, #0x18]
	bl init_battle_medabot_sprites
	b _0800506E
	.align 2, 0
_08005054: .4byte 0x083AC43B
_08005058: .4byte 0x0300049E
_0800505C: .4byte 0x030017A0
_08005060: .4byte 0x083AC432
_08005064:
	mov r1, r8
	lsrs r0, r1, #0x18
	movs r1, #4
	bl clear_sprite_table_mask
_0800506E:
	movs r4, #0x80
	lsls r4, r4, #0x13
	add r8, r4
	adds r7, #4
	adds r6, #2
	adds r5, #1
	cmp r5, #8
	bls _0800501A
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
