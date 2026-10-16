	.syntax unified

	thumb_func_start sub_08021638
sub_08021638: @ 0x08021638
	push {lr}
	ldr r0, _08021668 @ =0x083B5F80
	adds r0, #0xe0
	ldr r0, [r0]
	movs r1, #0x21
	bl process_sprite_anim_commands
	ldr r0, _0802166C @ =0x03002C30
	ldr r1, _08021670 @ =0x00000862
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _08021664
	ldr r0, _08021674 @ =0x03000440
	adds r0, #0x86
	movs r1, #0x3c
	strh r1, [r0]
	ldr r1, _08021678 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08021664:
	pop {r0}
	bx r0
	.align 2, 0
_08021668: .4byte 0x083B5F80
_0802166C: .4byte 0x03002C30
_08021670: .4byte 0x00000862
_08021674: .4byte 0x03000440
_08021678: .4byte 0x03001800
	.syntax divided
