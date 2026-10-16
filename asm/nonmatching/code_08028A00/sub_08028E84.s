	.syntax unified

	thumb_func_start sub_08028E84
sub_08028E84: @ 0x08028E84
	push {r4, lr}
	ldr r1, _08028EC0 @ =0x083B5F80
	ldr r4, _08028EC4 @ =0x03002C30
	ldr r2, _08028EC8 @ =0x0000086E
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x21
	bl process_sprite_anim_commands
	ldr r3, _08028ECC @ =0x00000844
	adds r2, r4, r3
	ldrh r1, [r2]
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r0, #0x40
	bne _08028ED8
	ldr r0, _08028ED0 @ =0x03000440
	adds r0, #0x86
	movs r1, #0x3c
	strh r1, [r0]
	ldr r1, _08028ED4 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08028F3A
	.align 2, 0
_08028EC0: .4byte 0x083B5F80
_08028EC4: .4byte 0x03002C30
_08028EC8: .4byte 0x0000086E
_08028ECC: .4byte 0x00000844
_08028ED0: .4byte 0x03000440
_08028ED4: .4byte 0x03001800
_08028ED8:
	adds r0, r1, #2
	movs r1, #0xff
	ands r0, r1
	strh r0, [r2]
	ldr r2, _08028F0C @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08028F18
	adds r0, r2, #0
	adds r0, #0x51
	ldrb r0, [r0]
	cmp r0, #3
	beq _08028F3A
	ldr r0, _08028F10 @ =0x03000440
	ldr r1, _08028F14 @ =0x0000012F
	adds r0, r0, r1
	ldrb r1, [r0]
	lsls r1, r1, #6
	adds r1, r1, r4
	ldrh r0, [r1, #0x18]
	subs r0, #0x10
	b _08028F32
	.align 2, 0
_08028F0C: .4byte 0x03001800
_08028F10: .4byte 0x03000440
_08028F14: .4byte 0x0000012F
_08028F18:
	adds r0, r2, #0
	adds r0, #0x51
	ldrb r0, [r0]
	cmp r0, #3
	beq _08028F3A
	ldr r0, _08028F40 @ =0x03000440
	ldr r1, _08028F44 @ =0x0000012F
	adds r0, r0, r1
	ldrb r1, [r0]
	lsls r1, r1, #6
	adds r1, r1, r4
	ldrh r0, [r1, #0x18]
	adds r0, #0x10
_08028F32:
	ldr r3, _08028F48 @ =0x000003FF
	adds r2, r3, #0
	ands r0, r2
	strh r0, [r1, #0x18]
_08028F3A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08028F40: .4byte 0x03000440
_08028F44: .4byte 0x0000012F
_08028F48: .4byte 0x000003FF
	.syntax divided
