	.syntax unified

	thumb_func_start sub_080255F8
sub_080255F8: @ 0x080255F8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r6, _0802566C @ =0x03001800
	adds r4, r6, #0
	adds r4, #0x88
	ldrb r0, [r4]
	adds r1, r6, #0
	adds r1, #0xec
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl sub_08037458
	adds r5, r6, #0
	adds r5, #0xc8
	ldrh r0, [r5]
	adds r7, r6, #0
	adds r7, #0x51
	strb r0, [r7]
	ldrb r0, [r4]
	lsls r0, r0, #8
	ldr r4, _08025670 @ =0x030005D8
	adds r0, r0, r4
	adds r0, #0x10
	ldrb r1, [r7]
	bl sub_0803572C
	movs r0, #0x87
	adds r0, r0, r6
	mov r8, r0
	ldrb r0, [r0]
	ldrb r1, [r7]
	bl sub_08037498
	ldrh r0, [r5]
	adds r1, r6, #0
	adds r1, #0x52
	strb r0, [r1]
	mov r0, r8
	ldrb r2, [r0]
	lsls r2, r2, #8
	adds r0, r2, r4
	adds r0, #0x10
	ldrb r1, [r1]
	adds r4, r4, r2
	ldrb r2, [r4, #8]
	bl sub_08035740
	adds r1, r6, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802566C: .4byte 0x03001800
_08025670: .4byte 0x030005D8
	.syntax divided
