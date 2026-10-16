	.syntax unified

	thumb_func_start battle_check_hit_and_set_timer
battle_check_hit_and_set_timer: @ 0x0801CBA4
	push {r4, lr}
	ldr r4, _0801CBD0 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0xd1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0801CBD4
	movs r0, #0x3b
	bl play_sound_effect
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	bl sub_08035194
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0x13
	strb r0, [r1]
	adds r1, #4
	movs r0, #0x1a
	b _0801CBDA
	.align 2, 0
_0801CBD0: .4byte 0x03001800
_0801CBD4:
	adds r1, r4, #0
	adds r1, #0xaa
	movs r0, #0x20
_0801CBDA:
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
