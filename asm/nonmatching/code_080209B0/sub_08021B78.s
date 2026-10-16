	.syntax unified

	thumb_func_start sub_08021B78
sub_08021B78: @ 0x08021B78
	push {r4, lr}
	ldr r4, _08021BC4 @ =0x083B5F80
	adds r4, #0xe8
	ldr r0, [r4]
	movs r1, #0x21
	bl process_sprite_anim_commands
	ldr r0, [r4]
	movs r1, #0x22
	bl process_sprite_anim_commands
	ldr r0, [r4]
	movs r1, #0x23
	bl process_sprite_anim_commands
	ldr r0, _08021BC8 @ =0x03002C30
	ldr r1, _08021BCC @ =0x00000862
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _08021BBC
	movs r0, #0x21
	movs r1, #3
	bl clear_sprite_table_mask
	ldr r0, _08021BD0 @ =0x03000440
	adds r0, #0x86
	movs r1, #0x3c
	strh r1, [r0]
	ldr r1, _08021BD4 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08021BBC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08021BC4: .4byte 0x083B5F80
_08021BC8: .4byte 0x03002C30
_08021BCC: .4byte 0x00000862
_08021BD0: .4byte 0x03000440
_08021BD4: .4byte 0x03001800
	.syntax divided
