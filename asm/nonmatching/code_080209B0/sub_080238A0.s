	.syntax unified

	thumb_func_start sub_080238A0
sub_080238A0: @ 0x080238A0
	push {r4, lr}
	ldr r1, _080238E0 @ =0x083B5F80
	ldr r4, _080238E4 @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x84
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x21
	bl process_sprite_anim_commands
	adds r4, #0x89
	ldrb r0, [r4]
	cmp r0, #0
	bne _080238CC
	ldr r0, _080238E8 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080238EC
_080238CC:
	ldr r0, _080238E4 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x86
	ldrh r0, [r1]
	cmp r0, #0
	beq _080238EC
	subs r0, #1
	strh r0, [r1]
	b _080238F6
	.align 2, 0
_080238E0: .4byte 0x083B5F80
_080238E4: .4byte 0x03000440
_080238E8: .4byte 0x03001798
_080238EC:
	ldr r1, _080238FC @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_080238F6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080238FC: .4byte 0x03001800
	.syntax divided
