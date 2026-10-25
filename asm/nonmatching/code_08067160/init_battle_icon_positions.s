	.syntax unified

	thumb_func_start init_battle_icon_positions
init_battle_icon_positions: @ 0x08069B2C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	movs r4, #4
	str r4, [sp]
	movs r0, #0
	movs r1, #0x2c
	movs r2, #0x22
	movs r3, #0
	bl sub_08069A68
	movs r5, #0x20
	rsbs r5, r5, #0
	str r4, [sp]
	movs r0, #1
	adds r1, r5, #0
	movs r2, #0x22
	movs r3, #0
	bl sub_08069A68
	str r4, [sp]
	movs r0, #2
	adds r1, r5, #0
	movs r2, #0x22
	movs r3, #0
	bl sub_08069A68
	movs r6, #4
	str r6, [sp]
	movs r0, #3
	movs r1, #0x2c
	movs r2, #0x3a
	movs r3, #0
	bl sub_08069A68
	str r4, [sp]
	movs r0, #4
	adds r1, r5, #0
	movs r2, #0x3a
	movs r3, #0
	bl sub_08069A68
	str r4, [sp]
	movs r0, #5
	adds r1, r5, #0
	movs r2, #0x3a
	movs r3, #0
	bl sub_08069A68
	str r4, [sp]
	movs r0, #6
	movs r1, #0x2c
	movs r2, #0x52
	movs r3, #0
	bl sub_08069A68
	str r4, [sp]
	movs r0, #7
	adds r1, r5, #0
	movs r2, #0x52
	movs r3, #0
	bl sub_08069A68
	str r4, [sp]
	movs r0, #8
	adds r1, r5, #0
	movs r2, #0x52
	movs r3, #0
	bl sub_08069A68
	movs r6, #0
	movs r4, #3
_08069BBE:
	adds r0, r6, #0
	adds r0, #0x14
	str r4, [sp]
	movs r1, #0xcc
	lsls r1, r1, #8
	movs r2, #0x88
	lsls r2, r2, #1
	movs r3, #0xd
	bl init_battle_sprite_entry_08048818
	adds r6, #1
	cmp r6, #8
	ble _08069BBE
	ldr r0, _08069C44 @ =0x0850DEF8
	mov r8, r0
	ldr r0, _08069C48 @ =0x03002C30
	ldr r1, _08069C4C @ =0x0000FFE0
	mov ip, r1
	movs r2, #0xd0
	lsls r2, r2, #3
	adds r7, r0, r2
	movs r1, #0xb8
	lsls r1, r1, #3
	adds r5, r0, r1
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r1, r0, r2
	adds r2, #0x80
	adds r4, r0, r2
	subs r2, #0x40
	adds r3, r0, r2
	adds r2, r1, #0
	movs r6, #2
_08069C00:
	movs r0, #0x2c
	strh r0, [r2, #2]
	mov r0, ip
	strh r0, [r3, #2]
	strh r0, [r4, #2]
	movs r0, #0x2d
	strh r0, [r1, #4]
	movs r0, #0x45
	strh r0, [r5, #4]
	movs r0, #0x5d
	strh r0, [r7, #4]
	adds r7, #0x40
	adds r5, #0x40
	adds r1, #0x40
	adds r4, #0xc0
	adds r3, #0xc0
	adds r2, #0xc0
	subs r6, #1
	cmp r6, #0
	bge _08069C00
	ldr r1, _08069C50 @ =0x040000D4
	mov r2, r8
	str r2, [r1]
	ldr r0, _08069C54 @ =0x05000200
	str r0, [r1, #4]
	ldr r0, _08069C58 @ =0x84000040
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08069C44: .4byte gUnk_0850DEF8
_08069C48: .4byte 0x03002C30
_08069C4C: .4byte 0x0000FFE0
_08069C50: .4byte 0x040000D4
_08069C54: .4byte 0x05000200
_08069C58: .4byte 0x84000040
	.syntax divided
