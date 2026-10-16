	.syntax unified

	thumb_func_start sub_08037BF4
sub_08037BF4: @ 0x08037BF4
	push {r4, r5, lr}
	ldr r2, _08037C30 @ =0x083B5F80
	ldr r4, _08037C34 @ =0x03002C30
	ldr r0, _08037C38 @ =0x03000440
	ldr r1, _08037C3C @ =0x0000012F
	adds r5, r0, r1
	ldrb r1, [r5]
	lsls r0, r1, #6
	adds r0, r0, r4
	adds r0, #0x2e
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl process_sprite_anim_commands
	ldrb r0, [r5]
	lsls r0, r0, #6
	adds r2, r0, r4
	ldrh r1, [r2, #4]
	movs r3, #4
	ldrsh r0, [r2, r3]
	cmp r0, #0x14
	bne _08037C40
	adds r1, r2, #0
	adds r1, #0x29
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08037C48
	.align 2, 0
_08037C30: .4byte 0x083B5F80
_08037C34: .4byte 0x03002C30
_08037C38: .4byte 0x03000440
_08037C3C: .4byte 0x0000012F
_08037C40:
	adds r0, r1, #1
	movs r1, #0xff
	ands r0, r1
	strh r0, [r2, #4]
_08037C48:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
