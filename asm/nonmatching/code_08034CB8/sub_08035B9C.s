	.syntax unified

	thumb_func_start sub_08035B9C
	.global sub_08035B9C
sub_08035B9C: @ 0x08035B9C
	push {r4, lr}
	movs r2, #0
	ldr r1, _08035BCC @ =0x03000590
	ldr r3, _08035BD0 @ =0x030018EC
	lsls r0, r0, #8
	adds r1, #0x49
	adds r1, r0, r1
_08035BAA:
	ldrb r0, [r1, #0x10]
	cmp r0, #0
	beq _08035BBE
	ldrb r0, [r1]
	cmp r0, #0x35
	bne _08035BBE
	ldrh r0, [r3]
	ldrb r4, [r1, #5]
	adds r0, r0, r4
	strh r0, [r3]
_08035BBE:
	adds r1, #0x18
	adds r2, #1
	cmp r2, #2
	bls _08035BAA
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08035BCC: .4byte 0x03000590
_08035BD0: .4byte 0x030018EC
	.syntax divided
