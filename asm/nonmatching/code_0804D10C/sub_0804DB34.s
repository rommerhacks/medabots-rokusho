	.syntax unified

	thumb_func_start sub_0804DB34
	.global sub_0804DB34
sub_0804DB34: @ 0x0804DB34
	push {lr}
	movs r0, #0x30
	bl clear_battle_sprite_entry
	movs r0, #0x5a
	bl clear_battle_sprite_entry
	ldr r1, _0804DB5C @ =0x030057E0
	ldr r0, _0804DB60 @ =0x00000C76
	adds r2, r1, r0
	movs r0, #0
	strb r0, [r2]
	ldr r2, _0804DB64 @ =0x00000C5E
	adds r0, r1, r2
	ldrb r0, [r0]
	subs r2, #1
	adds r1, r1, r2
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0804DB5C: .4byte 0x030057E0
_0804DB60: .4byte 0x00000C76
_0804DB64: .4byte 0x00000C5E
	.syntax divided
