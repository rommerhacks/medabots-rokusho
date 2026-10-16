	.syntax unified

	thumb_func_start update_anim_counter
update_anim_counter: @ 0x08058A20
	push {r4, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	ldr r0, _08058A58 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _08058A60
	ldr r1, _08058A5C @ =0x083D6088
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r2, [r0]
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	bne _08058A7E
	subs r0, r4, #1
	strb r0, [r2]
	b _08058A7E
	.align 2, 0
_08058A58: .4byte 0x03001798
_08058A5C: .4byte 0x083D6088
_08058A60:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08058A7E
	ldr r1, _08058A84 @ =0x083D6088
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r2, [r0]
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	ldrb r0, [r2]
	cmp r0, r4
	blt _08058A7E
	strb r3, [r2]
_08058A7E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08058A84: .4byte 0x083D6088
	.syntax divided
