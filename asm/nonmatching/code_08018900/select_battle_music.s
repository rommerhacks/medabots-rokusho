	.syntax unified

	thumb_func_start select_battle_music
	.global select_battle_music
select_battle_music: @ 0x08018A54
	push {lr}
	ldr r0, _08018A68 @ =0x03000440
	adds r0, #0x89
	ldrb r0, [r0]
	cmp r0, #1
	bne _08018A6C
	movs r0, #9
	bl play_song
	b _08018AA6
	.align 2, 0
_08018A68: .4byte 0x03000440
_08018A6C:
	ldr r0, _08018A88 @ =0x030057E0
	ldr r1, _08018A8C @ =0x00000C2E
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0
	beq _08018A98
	cmp r1, #0x10
	bne _08018A90
	movs r0, #0xc
	bl play_song
	b _08018AA6
	.align 2, 0
_08018A88: .4byte 0x030057E0
_08018A8C: .4byte 0x00000C2E
_08018A90:
	movs r0, #0xd
	bl play_song
	b _08018AA6
_08018A98:
	ldr r1, _08018AAC @ =0x083AD3B0
	ldr r0, _08018AB0 @ =0x03000B94
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	bl play_song
_08018AA6:
	pop {r0}
	bx r0
	.align 2, 0
_08018AAC: .4byte 0x083AD3B0
_08018AB0: .4byte 0x03000B94
	.syntax divided
