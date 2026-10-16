	.syntax unified

	thumb_func_start sub_08012024
	.global sub_08012024
sub_08012024: @ 0x08012024
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	movs r0, #0
	mov r8, r0
	ldr r0, _08012090 @ =0x03001800
	ldrb r1, [r0, #2]
	cmp r8, r1
	bhs _08012082
	mov sb, r0
	ldr r7, _08012094 @ =0x083ACEE4
	movs r6, #0x28
	mov r5, sb
	adds r5, #4
_08012044:
	ldrb r0, [r5]
	ldrb r1, [r5, #1]
	ldrb r2, [r5, #2]
	ldrb r3, [r5, #3]
	mov r4, r8
	str r4, [sp]
	str r6, [sp, #4]
	ldrb r4, [r7]
	str r4, [sp, #8]
	ldrb r4, [r7, #1]
	str r4, [sp, #0xc]
	movs r4, #1
	str r4, [sp, #0x10]
	str r4, [sp, #0x14]
	movs r4, #0
	str r4, [sp, #0x18]
	bl init_battle_medabot_sprites
	adds r0, r6, #0
	movs r1, #8
	bl battle_sprite_set_palette_index
	adds r7, #2
	adds r6, #4
	adds r5, #0xc
	movs r0, #1
	add r8, r0
	mov r1, sb
	ldrb r1, [r1, #2]
	cmp r8, r1
	blo _08012044
_08012082:
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08012090: .4byte 0x03001800
_08012094: .4byte 0x083ACEE4
	.syntax divided
