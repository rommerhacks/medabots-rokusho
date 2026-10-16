	.syntax unified

	thumb_func_start sub_08021A14
sub_08021A14: @ 0x08021A14
	push {lr}
	ldr r0, _08021A5C @ =0x083B5F80
	adds r0, #0xec
	ldr r0, [r0]
	movs r1, #0x21
	bl process_sprite_anim_commands
	ldr r1, _08021A60 @ =0x03000440
	adds r3, r1, #0
	adds r3, #0x86
	ldrh r0, [r3]
	subs r0, #1
	strh r0, [r3]
	adds r1, #0x89
	ldrb r2, [r1]
	cmp r2, #0
	bne _08021A44
	ldr r0, _08021A64 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08021A44
	strh r2, [r3]
_08021A44:
	ldr r0, _08021A60 @ =0x03000440
	adds r0, #0x86
	ldrh r0, [r0]
	cmp r0, #0
	bne _08021A58
	ldr r1, _08021A68 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08021A58:
	pop {r0}
	bx r0
	.align 2, 0
_08021A5C: .4byte 0x083B5F80
_08021A60: .4byte 0x03000440
_08021A64: .4byte 0x03001798
_08021A68: .4byte 0x03001800
	.syntax divided
