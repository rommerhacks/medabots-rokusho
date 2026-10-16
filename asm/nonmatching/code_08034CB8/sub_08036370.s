	.syntax unified

	thumb_func_start sub_08036370
	.global sub_08036370
sub_08036370: @ 0x08036370
	push {r4, r5, lr}
	sub sp, #4
	adds r2, r1, #0
	movs r5, #5
	cmp r0, #0
	bne _0803637E
	movs r5, #0x13
_0803637E:
	ldr r1, _080363E4 @ =0x03000590
	lsls r0, r2, #8
	adds r4, r0, r1
	adds r0, r4, #0
	adds r0, #0x4c
	ldrb r3, [r0]
	adds r0, #0xd
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #0x40
	bl sub_080363E8
	adds r0, r4, #0
	adds r0, #0x64
	ldrb r3, [r0]
	adds r0, #0xd
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #4
	movs r2, #0x40
	bl sub_080363E8
	adds r0, r4, #0
	adds r0, #0x7c
	ldrb r3, [r0]
	adds r0, #0xd
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #7
	movs r2, #0x40
	bl sub_080363E8
	adds r0, r4, #0
	adds r0, #0x94
	ldrb r3, [r0]
	adds r0, #0xd
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0xa
	movs r2, #0x40
	bl sub_080363E8
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080363E4: .4byte 0x03000590
	.syntax divided
