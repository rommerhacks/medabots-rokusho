	.syntax unified

	thumb_func_start sub_08018C78
	.global sub_08018C78
sub_08018C78: @ 0x08018C78
	push {r4, r5, r6, lr}
	ldr r5, _08018CB0 @ =0x03002C30
	ldr r4, _08018CB4 @ =0x03001800
	adds r4, #0x57
	ldrb r0, [r4]
	movs r1, #0xa
	bl sub_0807CD58
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08018CB8 @ =0x00000624
	adds r6, r1, #0
	adds r0, r0, r6
	adds r1, r5, #0
	adds r1, #0x46
	strh r0, [r1]
	ldrb r0, [r4]
	movs r1, #0xa
	bl sub_0807CDD0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, r0, r6
	adds r5, #0x86
	strh r0, [r5]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08018CB0: .4byte 0x03002C30
_08018CB4: .4byte 0x03001800
_08018CB8: .4byte 0x00000624
	.syntax divided
