	.syntax unified

	thumb_func_start calc_fade_sprite_position
calc_fade_sprite_position: @ 0x0805AF64
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x54
	strh r0, [r4, #2]
	ldr r0, _0805AF88 @ =0x03006F74
	ldr r0, [r0]
	ldrb r0, [r0, #0xc]
	movs r1, #5
	bl sub_0807CDD0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x14
	adds r0, #0x1c
	strh r0, [r4, #4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805AF88: .4byte 0x03006F74
	.syntax divided
