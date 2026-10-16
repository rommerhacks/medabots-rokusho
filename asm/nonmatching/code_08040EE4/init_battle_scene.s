	.syntax unified

	thumb_func_start init_battle_scene
	.global init_battle_scene
init_battle_scene: @ 0x08044BA8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	mov r8, r1
	bl sub_08043CA8
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	ldr r6, _08044BF8 @ =0x03000440
	adds r0, r6, #0
	adds r0, #0x96
	movs r5, #0
	strb r5, [r0]
	ldr r0, _08044BFC @ =0x03000430
	str r5, [r0]
	adds r4, r6, #0
	adds r4, #0x3c
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0
	bl sub_0803F624
	movs r0, #3
	strb r0, [r4]
	adds r0, r6, #0
	adds r0, #0x3d
	mov r1, r8
	strb r1, [r0]
	cmp r7, #1
	beq _08044C08
	cmp r7, #1
	blo _08044C00
	cmp r7, #2
	beq _08044C08
	cmp r7, #3
	beq _08044C08
	b _08044C0E
	.align 2, 0
_08044BF8: .4byte 0x03000440
_08044BFC: .4byte 0x03000430
_08044C00:
	adds r0, r6, #0
	adds r0, #0x3e
	strb r5, [r0]
	b _08044C0E
_08044C08:
	adds r0, r6, #0
	adds r0, #0x3e
	strb r7, [r0]
_08044C0E:
	ldr r1, _08044C2C @ =0x0300178C
	movs r0, #0
	str r0, [r1]
	ldr r1, _08044C30 @ =0x03002B8C
	movs r0, #5
	str r0, [r1]
	ldr r1, _08044C34 @ =0x0300137C
	movs r0, #0x10
	str r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08044C2C: .4byte 0x0300178C
_08044C30: .4byte 0x03002B8C
_08044C34: .4byte 0x0300137C
	.syntax divided
