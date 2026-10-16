	.syntax unified

	thumb_func_start sub_0801C9C8
sub_0801C9C8: @ 0x0801C9C8
	push {r4, r5, lr}
	ldr r4, _0801CA18 @ =0x03001800
	adds r5, r4, #0
	adds r5, #0x87
	ldrb r0, [r5]
	ldr r1, _0801CA1C @ =0x03001780
	ldr r1, [r1]
	adds r2, r4, #0
	adds r2, #0x51
	ldrb r2, [r2]
	bl set_target_sprite_position
	ldr r1, _0801CA20 @ =0x083B5F80
	adds r0, r4, #0
	adds r0, #0x52
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x21
	bl process_sprite_anim_commands
	ldr r0, _0801CA24 @ =0x03002C30
	ldr r1, _0801CA28 @ =0x00000862
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _0801CA10
	ldrb r0, [r5]
	bl update_target_cursor_position
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0801CA10:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801CA18: .4byte 0x03001800
_0801CA1C: .4byte 0x03001780
_0801CA20: .4byte 0x083B5F80
_0801CA24: .4byte 0x03002C30
_0801CA28: .4byte 0x00000862
	.syntax divided
