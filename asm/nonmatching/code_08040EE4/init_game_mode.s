	.syntax unified

	thumb_func_start init_game_mode
	.global init_game_mode
init_game_mode: @ 0x08044C38
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_08043CA8
	ldr r4, _08044C78 @ =0x0300047C
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0
	bl sub_0803F624
	adds r0, r4, #0
	adds r0, #0x14
	movs r1, #0x14
	movs r2, #0
	bl sub_0803F624
	adds r0, r4, #0
	adds r0, #0x4d
	movs r2, #0
	movs r1, #1
	strb r1, [r0]
	adds r0, #4
	strb r2, [r0]
	cmp r5, #1
	beq _08044C94
	cmp r5, #1
	blo _08044C7C
	cmp r5, #2
	beq _08044CAC
	cmp r5, #3
	beq _08044CB4
	b _08044CC8
	.align 2, 0
_08044C78: .4byte 0x0300047C
_08044C7C:
	movs r1, #4
	strb r1, [r4]
	ldr r0, _08044C8C @ =0x0300178C
	str r2, [r0]
	ldr r0, _08044C90 @ =0x03002B8C
	str r1, [r0]
	b _08044CC4
	.align 2, 0
_08044C8C: .4byte 0x0300178C
_08044C90: .4byte 0x03002B8C
_08044C94:
	movs r0, #4
	strb r0, [r4]
	ldr r0, _08044CA4 @ =0x0300178C
	str r2, [r0]
	ldr r1, _08044CA8 @ =0x03002B8C
	movs r0, #5
	b _08044CC2
	.align 2, 0
_08044CA4: .4byte 0x0300178C
_08044CA8: .4byte 0x03002B8C
_08044CAC:
	adds r0, r4, #0
	adds r0, #0xfc
	strb r2, [r0]
	b _08044CBA
_08044CB4:
	adds r0, r4, #0
	adds r0, #0xfc
	strb r1, [r0]
_08044CBA:
	ldr r0, _08044CD0 @ =0x0300178C
	str r2, [r0]
	ldr r1, _08044CD4 @ =0x03002B8C
	movs r0, #0xa
_08044CC2:
	str r0, [r1]
_08044CC4:
	ldr r0, _08044CD8 @ =0x0300137C
	str r2, [r0]
_08044CC8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08044CD0: .4byte 0x0300178C
_08044CD4: .4byte 0x03002B8C
_08044CD8: .4byte 0x0300137C
	.syntax divided
