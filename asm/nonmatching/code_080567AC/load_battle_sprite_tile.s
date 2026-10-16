	.syntax unified

	thumb_func_start load_battle_sprite_tile
load_battle_sprite_tile: @ 0x08059774
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov r8, r0
	adds r7, r2, #0
	mov sl, r3
	cmp r1, #0
	ble _080597E6
	ldr r6, _080597F8 @ =0x040000D4
	ldr r4, _080597FC @ =0x030057A0
	ldr r0, _08059800 @ =0x03002C30
	mov sb, r0
	adds r5, r1, #0
_08059794:
	mov r1, r8
	ldrb r0, [r1]
	lsls r0, r0, #5
	ldr r1, _08059804 @ =0x080ACB7C
	adds r0, r0, r1
	str r0, [r6]
	ldrb r0, [r4, #0x13]
	lsls r0, r0, #5
	ldr r1, _08059808 @ =0x06017A00
	adds r0, r0, r1
	str r0, [r6, #4]
	ldr r0, _0805980C @ =0x84000008
	str r0, [r6, #8]
	ldr r0, [r6, #8]
	ldrb r0, [r4, #0x13]
	adds r2, r0, #0
	adds r2, #0x99
	movs r1, #1
	str r1, [sp]
	ldr r1, _08059810 @ =0x0000C004
	movs r3, #0xe
	bl init_battle_sprite_entry_08048818
	ldrb r0, [r4, #0x13]
	lsls r0, r0, #6
	add r0, sb
	strh r7, [r0, #2]
	ldrb r0, [r4, #0x13]
	lsls r0, r0, #6
	add r0, sb
	mov r1, sl
	strh r1, [r0, #4]
	adds r7, #8
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	movs r0, #1
	add r8, r0
	subs r5, #1
	cmp r5, #0
	bne _08059794
_080597E6:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080597F8: .4byte 0x040000D4
_080597FC: .4byte 0x030057A0
_08059800: .4byte 0x03002C30
_08059804: .4byte 0x080ACB7C
_08059808: .4byte 0x06017A00
_0805980C: .4byte 0x84000008
_08059810: .4byte 0x0000C004
	.syntax divided
