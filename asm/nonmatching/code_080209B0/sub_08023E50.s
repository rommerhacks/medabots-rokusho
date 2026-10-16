	.syntax unified

	thumb_func_start sub_08023E50
sub_08023E50: @ 0x08023E50
	push {lr}
	ldr r1, _08023E70 @ =0x03002C30
	ldr r0, _08023E74 @ =0x00000848
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, #8
	bne _08023E7C
	movs r0, #0x21
	movs r1, #1
	bl clear_sprite_table_mask
	ldr r1, _08023E78 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	b _08023E88
	.align 2, 0
_08023E70: .4byte 0x03002C30
_08023E74: .4byte 0x00000848
_08023E78: .4byte 0x03001800
_08023E7C:
	subs r0, #8
	strb r0, [r2]
	ldr r0, _08023E90 @ =0x00000849
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r0, #8
_08023E88:
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08023E90: .4byte 0x00000849
	.syntax divided
