	.syntax unified

	thumb_func_start battle_sprite_set_palette_index
	.global battle_sprite_set_palette_index
battle_sprite_set_palette_index: @ 0x08043240
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r3, _0804329C @ =0x03002C30
	adds r0, r4, #1
	lsls r0, r0, #6
	adds r0, r0, r3
	ldrh r1, [r0]
	movs r6, #0x80
	lsls r6, r6, #2
	adds r2, r6, #0
	orrs r1, r2
	strh r1, [r0]
	adds r0, r4, #2
	lsls r0, r0, #6
	adds r0, r0, r3
	ldrh r1, [r0]
	orrs r2, r1
	strh r2, [r0]
	movs r0, #0
_08043268:
	adds r0, #1
	cmp r0, #0xf
	bls _08043268
	lsls r0, r4, #6
	adds r0, r0, r3
	adds r0, #0x24
	strb r5, [r0]
	adds r0, r4, #1
	lsls r0, r0, #6
	adds r0, r0, r3
	adds r0, #0x24
	strb r5, [r0]
	adds r0, r4, #2
	lsls r0, r0, #6
	adds r0, r0, r3
	adds r0, #0x24
	strb r5, [r0]
	adds r0, r4, #3
	lsls r0, r0, #6
	adds r0, r0, r3
	adds r0, #0x24
	strb r5, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804329C: .4byte 0x03002C30
	.syntax divided
