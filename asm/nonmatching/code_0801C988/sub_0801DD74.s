	.syntax unified

	thumb_func_start sub_0801DD74
sub_0801DD74: @ 0x0801DD74
	push {r4, lr}
	ldr r0, _0801DDC4 @ =0x083B5F80
	ldr r0, [r0, #0x70]
	movs r1, #0x21
	bl process_sprite_anim_commands
	ldr r0, _0801DDC8 @ =0x03002C30
	ldr r1, _0801DDCC @ =0x00000862
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _0801DDBC
	ldr r4, _0801DDD0 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0xde
	ldrb r0, [r0]
	lsls r0, r0, #8
	ldr r1, _0801DDD4 @ =0x0300049A
	adds r0, r0, r1
	ldr r1, _0801DDD8 @ =0x030004DE
	movs r2, #0xe
	bl memcpy_bytes_0803F63C
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0x16
	strb r0, [r1]
	movs r0, #0x21
	movs r1, #1
	bl clear_battle_sprite_slot
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0801DDBC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801DDC4: .4byte 0x083B5F80
_0801DDC8: .4byte 0x03002C30
_0801DDCC: .4byte 0x00000862
_0801DDD0: .4byte 0x03001800
_0801DDD4: .4byte 0x0300049A
_0801DDD8: .4byte 0x030004DE
	.syntax divided
