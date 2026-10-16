	.syntax unified

	thumb_func_start sub_08035BFC
	.global sub_08035BFC
sub_08035BFC: @ 0x08035BFC
	push {r4, r5, lr}
	ldr r2, _08035C34 @ =0x03001800
	adds r5, r2, #0
	adds r5, #0xec
	movs r2, #0
	ldrsh r4, [r5, r2]
	ldr r3, _08035C38 @ =0x03000590
	lsls r2, r1, #1
	adds r2, r2, r1
	lsls r2, r2, #3
	lsls r0, r0, #8
	adds r2, r2, r0
	adds r2, r2, r3
	adds r2, #0x54
	ldrb r1, [r2]
	adds r0, r4, #0
	bl sub_0807CBBC
	strh r0, [r5]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08035C2C
	movs r0, #1
	strh r0, [r5]
_08035C2C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08035C34: .4byte 0x03001800
_08035C38: .4byte 0x03000590
	.syntax divided
