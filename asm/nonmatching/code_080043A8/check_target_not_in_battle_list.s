	.syntax unified

	thumb_func_start check_target_not_in_battle_list
check_target_not_in_battle_list: @ 0x08007440
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	cmp r3, #0
	bne _0800744E
	b _0800746E
_0800744A:
	movs r0, #0
	b _08007470
_0800744E:
	movs r2, #0
	cmp r2, r3
	bhs _0800746E
	ldr r5, _08007478 @ =0x03001841
	movs r6, #0xf
	ldr r0, _0800747C @ =0x03000491
	ldrb r4, [r0]
_0800745C:
	adds r0, r2, r5
	ldrb r1, [r0]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, r4
	beq _0800744A
	adds r2, #1
	cmp r2, r3
	blo _0800745C
_0800746E:
	movs r0, #1
_08007470:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08007478: .4byte 0x03001841
_0800747C: .4byte 0x03000491
	.syntax divided
