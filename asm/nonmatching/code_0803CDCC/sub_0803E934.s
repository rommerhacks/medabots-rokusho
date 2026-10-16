	.syntax unified

	thumb_func_start sub_0803E934
sub_0803E934: @ 0x0803E934
	push {lr}
	movs r0, #2
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r3, _0803E970 @ =0x03002C30
	adds r1, r3, #0
	adds r1, #0x80
	movs r2, #0
	movs r0, #0xc4
	lsls r0, r0, #8
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x68
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x78
	strh r0, [r1]
	adds r1, #2
	ldr r0, _0803E974 @ =0x00008506
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x9c
	strb r2, [r0]
	adds r1, #5
	movs r0, #0x82
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0803E970: .4byte 0x03002C30
_0803E974: .4byte 0x00008506
	.syntax divided
