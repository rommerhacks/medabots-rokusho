	.syntax unified

	thumb_func_start sub_08026628
sub_08026628: @ 0x08026628
	push {r4, lr}
	ldr r0, _08026644 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x86
	ldrh r0, [r1]
	cmp r0, #0x5a
	bne _0802664C
	ldr r1, _08026648 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0802666E
	.align 2, 0
_08026644: .4byte 0x03000440
_08026648: .4byte 0x03001800
_0802664C:
	adds r0, #1
	strh r0, [r1]
	ldr r4, _08026674 @ =0x083B5F80
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0x21
	bl process_sprite_anim_commands
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0x22
	bl process_sprite_anim_commands
_0802666E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08026674: .4byte 0x083B5F80
	.syntax divided
