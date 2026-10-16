	.syntax unified

	thumb_func_start sub_08022938
sub_08022938: @ 0x08022938
	push {lr}
	ldr r0, _08022970 @ =0x083B5F80
	adds r0, #0xf8
	ldr r0, [r0]
	movs r1, #0x21
	bl process_sprite_anim_commands
	ldr r0, _08022974 @ =0x03000440
	adds r0, #0x89
	ldrb r0, [r0]
	cmp r0, #0
	bne _0802295C
	ldr r0, _08022978 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0802297C
_0802295C:
	ldr r0, _08022974 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x86
	ldrh r0, [r1]
	cmp r0, #0
	beq _0802297C
	subs r0, #1
	strh r0, [r1]
	b _08022986
	.align 2, 0
_08022970: .4byte 0x083B5F80
_08022974: .4byte 0x03000440
_08022978: .4byte 0x03001798
_0802297C:
	ldr r1, _0802298C @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08022986:
	pop {r0}
	bx r0
	.align 2, 0
_0802298C: .4byte 0x03001800
	.syntax divided
