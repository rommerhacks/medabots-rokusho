	.syntax unified

	thumb_func_start update_battle_sprite_and_check_done
update_battle_sprite_and_check_done: @ 0x0800B768
	push {r4, lr}
	ldr r1, _0800B788 @ =0x083AC8CC
	ldr r0, _0800B78C @ =0x03002C30
	ldr r2, _0800B790 @ =0x000001E9
	adds r4, r0, r2
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	ldrb r0, [r4]
	cmp r0, #3
	beq _0800B794
	movs r0, #0
	b _0800B796
	.align 2, 0
_0800B788: .4byte 0x083AC8CC
_0800B78C: .4byte 0x03002C30
_0800B790: .4byte 0x000001E9
_0800B794:
	movs r0, #1
_0800B796:
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
