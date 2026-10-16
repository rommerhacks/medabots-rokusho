	.syntax unified

	thumb_func_start sub_0803EC04
sub_0803EC04: @ 0x0803EC04
	push {lr}
	ldr r1, _0803EC44 @ =0x03002C30
	ldr r0, _0803EC48 @ =0x03001800
	mov ip, r0
	movs r0, #0xd0
	lsls r0, r0, #1
	add r0, ip
	ldrb r0, [r0]
	lsrs r0, r0, #2
	adds r0, #4
	adds r2, r1, #0
	adds r2, #0xa4
	movs r3, #0
	strb r0, [r2]
	adds r1, #0xa5
	strb r3, [r1]
	ldr r2, _0803EC4C @ =0x083B5F80
	movs r0, #0xd1
	lsls r0, r0, #1
	add r0, ip
	ldrb r1, [r0]
	movs r0, #0x75
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	movs r1, #4
	bl init_battle_sprite_entry_08040B90
	pop {r0}
	bx r0
	.align 2, 0
_0803EC44: .4byte 0x03002C30
_0803EC48: .4byte 0x03001800
_0803EC4C: .4byte 0x083B5F80
	.syntax divided
