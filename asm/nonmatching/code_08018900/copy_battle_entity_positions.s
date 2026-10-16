	.syntax unified

	thumb_func_start copy_battle_entity_positions
	.global copy_battle_entity_positions
copy_battle_entity_positions: @ 0x0801BB7C
	push {r4, r5, r6, r7, lr}
	movs r5, #0
	ldr r1, _0801BBB8 @ =0x03001800
	ldr r0, _0801BBBC @ =0x03002C30
	movs r2, #0x9e
	lsls r2, r2, #1
	adds r4, r1, r2
	ldr r3, _0801BBC0 @ =0x00001742
	adds r2, r0, r3
	adds r3, r1, #0
	movs r7, #0x9f
	lsls r7, r7, #1
	movs r6, #0x80
	lsls r6, r6, #1
_0801BB98:
	ldrh r0, [r2]
	strh r0, [r4]
	ldrh r0, [r2, #2]
	subs r0, #4
	adds r1, r3, r7
	strh r0, [r1]
	adds r4, #4
	adds r2, r2, r6
	adds r3, #4
	adds r5, #1
	cmp r5, #5
	bls _0801BB98
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801BBB8: .4byte 0x03001800
_0801BBBC: .4byte 0x03002C30
_0801BBC0: .4byte 0x00001742
	.syntax divided
