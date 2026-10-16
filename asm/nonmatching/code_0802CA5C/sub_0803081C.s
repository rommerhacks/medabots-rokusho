	.syntax unified

	thumb_func_start sub_0803081C
sub_0803081C: @ 0x0803081C
	push {lr}
	ldr r1, _0803084C @ =0x083B5F80
	ldr r0, _08030850 @ =0x03000440
	adds r0, #0x84
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x21
	bl process_sprite_anim_commands
	ldr r0, _08030854 @ =0x03002C30
	ldr r1, _08030858 @ =0x00000862
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _08030848
	ldr r1, _0803085C @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08030848:
	pop {r0}
	bx r0
	.align 2, 0
_0803084C: .4byte 0x083B5F80
_08030850: .4byte 0x03000440
_08030854: .4byte 0x03002C30
_08030858: .4byte 0x00000862
_0803085C: .4byte 0x03001800
	.syntax divided
