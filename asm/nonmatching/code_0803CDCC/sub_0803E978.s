	.syntax unified

	thumb_func_start sub_0803E978
sub_0803E978: @ 0x0803E978
	push {lr}
	movs r0, #3
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r3, _0803E9B4 @ =0x03002C30
	adds r1, r3, #0
	adds r1, #0xc0
	movs r2, #0
	movs r0, #0xc4
	lsls r0, r0, #8
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x78
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x7c
	strh r0, [r1]
	adds r1, #2
	ldr r0, _0803E9B8 @ =0x00008504
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0xdc
	strb r2, [r0]
	adds r1, #5
	movs r0, #0x81
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0803E9B4: .4byte 0x03002C30
_0803E9B8: .4byte 0x00008504
	.syntax divided
