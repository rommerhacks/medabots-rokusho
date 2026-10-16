	.syntax unified

	thumb_func_start sub_08061180
sub_08061180: @ 0x08061180
	push {r4, lr}
	ldr r0, _080611C0 @ =0x03006F74
	ldr r4, [r0]
	movs r0, #0x9c
	lsls r0, r0, #2
	adds r4, r4, r0
	ldr r1, _080611C4 @ =0x0848552C
	adds r0, r4, #0
	bl copy_text_with_lookup
	adds r0, r4, #0
	bl run_message
	cmp r0, #0
	beq _080611BA
	ldr r1, _080611C8 @ =0x03002C30
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r1, r3
	ldrh r2, [r1]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r3, #0
	orrs r0, r2
	strh r0, [r1]
	ldr r1, _080611CC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080611BA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080611C0: .4byte 0x03006F74
_080611C4: .4byte 0x0848552C
_080611C8: .4byte 0x03002C30
_080611CC: .4byte 0x0300137C
	.syntax divided
