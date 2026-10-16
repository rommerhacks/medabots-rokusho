	.syntax unified

	thumb_func_start sub_08028F4C
sub_08028F4C: @ 0x08028F4C
	push {r4, lr}
	ldr r1, _08028F88 @ =0x083B5F80
	ldr r4, _08028F8C @ =0x03002C30
	ldr r2, _08028F90 @ =0x0000086E
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x21
	bl process_sprite_anim_commands
	ldr r2, _08028F94 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08028F9C
	adds r0, r2, #0
	adds r0, #0x51
	ldrb r0, [r0]
	cmp r0, #3
	beq _08028FB6
	ldr r3, _08028F98 @ =0x00000858
	adds r0, r4, r3
	ldrh r1, [r0]
	subs r1, #0x10
	b _08028FAE
	.align 2, 0
_08028F88: .4byte 0x083B5F80
_08028F8C: .4byte 0x03002C30
_08028F90: .4byte 0x0000086E
_08028F94: .4byte 0x03001800
_08028F98: .4byte 0x00000858
_08028F9C:
	adds r0, r2, #0
	adds r0, #0x51
	ldrb r0, [r0]
	cmp r0, #3
	beq _08028FB6
	ldr r1, _08028FE0 @ =0x00000858
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r1, #0x10
_08028FAE:
	ldr r3, _08028FE4 @ =0x000003FF
	adds r2, r3, #0
	ands r1, r2
	strh r1, [r0]
_08028FB6:
	ldr r0, _08028FE8 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x89
	ldrb r1, [r1]
	adds r2, r0, #0
	cmp r1, #0
	bne _08028FD0
	ldr r0, _08028FEC @ =0x03001798
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08028FF0
_08028FD0:
	adds r1, r2, #0
	adds r1, #0x86
	ldrh r0, [r1]
	cmp r0, #0
	beq _08028FF0
	subs r0, #1
	strh r0, [r1]
	b _08028FFA
	.align 2, 0
_08028FE0: .4byte 0x00000858
_08028FE4: .4byte 0x000003FF
_08028FE8: .4byte 0x03000440
_08028FEC: .4byte 0x03001798
_08028FF0:
	ldr r1, _08029000 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08028FFA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08029000: .4byte 0x03001800
	.syntax divided
