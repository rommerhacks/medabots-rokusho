	.syntax unified

	thumb_func_start sub_0803CDCC
sub_0803CDCC: @ 0x0803CDCC
	push {r4, r5, lr}
	ldr r2, _0803CE08 @ =0x083B5F80
	ldr r4, _0803CE0C @ =0x03002C30
	ldr r0, _0803CE10 @ =0x03000440
	ldr r1, _0803CE14 @ =0x0000012F
	adds r5, r0, r1
	ldrb r1, [r5]
	lsls r0, r1, #6
	adds r0, r0, r4
	adds r0, #0x2d
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl process_sprite_anim_commands
	ldrb r1, [r5]
	lsls r0, r1, #6
	adds r0, r0, r4
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _0803CE02
	adds r0, r1, #0
	movs r1, #1
	bl clear_battle_sprite_slot
_0803CE02:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803CE08: .4byte 0x083B5F80
_0803CE0C: .4byte 0x03002C30
_0803CE10: .4byte 0x03000440
_0803CE14: .4byte 0x0000012F
	.syntax divided
