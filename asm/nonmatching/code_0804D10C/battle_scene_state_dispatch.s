	.syntax unified

	thumb_func_start battle_scene_state_dispatch
battle_scene_state_dispatch: @ 0x08050B7C
	push {lr}
	ldr r0, _08050BCC @ =0x03005350
	movs r1, #0xea
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0x3f
	ands r1, r0
	cmp r1, #0xd
	beq _08050B94
	cmp r1, #0x16
	bne _08050BA8
_08050B94:
	ldr r0, _08050BD0 @ =0x030057E0
	ldr r1, _08050BD4 @ =0x00000C5B
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	movs r0, #0
	bl sub_08052BA0
	bl update_bg_scroll_offsets_a
_08050BA8:
	bl battle_sequence_dispatch
	cmp r0, #4
	bne _08050C40
	ldr r0, _08050BCC @ =0x03005350
	movs r1, #0xea
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0x3f
	ands r1, r0
	cmp r1, #0x16
	bhi _08050C38
	lsls r0, r1, #2
	ldr r1, _08050BD8 @ =_08050BDC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08050BCC: .4byte 0x03005350
_08050BD0: .4byte 0x030057E0
_08050BD4: .4byte 0x00000C5B
_08050BD8: .4byte _08050BDC
_08050BDC: @ jump table
	.4byte _08050C3C @ case 0
	.4byte _08050C38 @ case 1
	.4byte _08050C38 @ case 2
	.4byte _08050C38 @ case 3
	.4byte _08050C38 @ case 4
	.4byte _08050C38 @ case 5
	.4byte _08050C38 @ case 6
	.4byte _08050C38 @ case 7
	.4byte _08050C38 @ case 8
	.4byte _08050C38 @ case 9
	.4byte _08050C38 @ case 10
	.4byte _08050C38 @ case 11
	.4byte _08050C38 @ case 12
	.4byte _08050C3C @ case 13
	.4byte _08050C38 @ case 14
	.4byte _08050C3C @ case 15
	.4byte _08050C3C @ case 16
	.4byte _08050C38 @ case 17
	.4byte _08050C38 @ case 18
	.4byte _08050C3C @ case 19
	.4byte _08050C38 @ case 20
	.4byte _08050C38 @ case 21
	.4byte _08050C3C @ case 22
_08050C38:
	bl init_battle_sprites
_08050C3C:
	movs r0, #1
	b _08050C42
_08050C40:
	movs r0, #0
_08050C42:
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
