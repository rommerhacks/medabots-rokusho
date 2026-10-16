	.syntax unified

	thumb_func_start sub_08027D24
sub_08027D24: @ 0x08027D24
	push {r4, lr}
	ldr r3, _08027D68 @ =0x03000440
	adds r1, r3, #0
	adds r1, #0x86
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _08027D6C @ =0x03002C30
	ldr r0, _08027D70 @ =0x00000858
	adds r2, r2, r0
	ldrh r0, [r2]
	adds r0, #0x40
	ldr r4, _08027D74 @ =0x000003FF
	adds r1, r4, #0
	ands r0, r1
	strh r0, [r2]
	adds r0, r3, #0
	adds r0, #0x89
	ldrb r0, [r0]
	cmp r0, #0
	bne _08027D5A
	ldr r0, _08027D78 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08027D7C
_08027D5A:
	adds r3, #0x84
	ldrb r0, [r3]
	cmp r0, #0
	beq _08027D7C
	subs r0, #1
	strb r0, [r3]
	b _08027D8C
	.align 2, 0
_08027D68: .4byte 0x03000440
_08027D6C: .4byte 0x03002C30
_08027D70: .4byte 0x00000858
_08027D74: .4byte 0x000003FF
_08027D78: .4byte 0x03001798
_08027D7C:
	movs r0, #0x2b
	bl play_sound_effect
	ldr r1, _08027D94 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08027D8C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08027D94: .4byte 0x03001800
	.syntax divided
