	.syntax unified

	thumb_func_start sub_08030860
sub_08030860: @ 0x08030860
	push {lr}
	bl sub_0803EED8
	cmp r0, #0
	bne _08030882
	bl sub_0803E780
	bl update_all_battle_status_sprites
	ldr r1, _08030888 @ =0x083AEB58
	ldr r0, _0803088C @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
_08030882:
	pop {r0}
	bx r0
	.align 2, 0
_08030888: .4byte 0x083AEB58
_0803088C: .4byte 0x0300137C
	.syntax divided
