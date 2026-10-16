	.syntax unified

	thumb_func_start count_active_battle_bots
	.global count_active_battle_bots
count_active_battle_bots: @ 0x08014E94
	push {r4, lr}
	movs r1, #0
	movs r2, #0
	ldr r3, _08014EC4 @ =0x03001800
	adds r4, r3, #0
	adds r4, #0x41
_08014EA0:
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _08014EAA
	adds r2, #1
_08014EAA:
	adds r1, #1
	cmp r1, #2
	bls _08014EA0
	adds r0, r3, #0
	adds r0, #0x5a
	strb r2, [r0]
	ldrb r1, [r3, #2]
	adds r0, #1
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08014EC4: .4byte 0x03001800
	.syntax divided
