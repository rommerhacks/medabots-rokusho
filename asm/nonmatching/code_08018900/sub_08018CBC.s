	.syntax unified

	thumb_func_start sub_08018CBC
sub_08018CBC: @ 0x08018CBC
	push {r4, r5, lr}
	ldr r0, _08018D04 @ =0x03001800
	adds r0, #0x55
	movs r1, #0
	strb r1, [r0]
	movs r5, #0
_08018CC8:
	ldr r1, _08018D08 @ =0x03000590
	lsls r0, r5, #8
	adds r4, r0, r1
	adds r0, r4, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08018CF8
	adds r0, r4, #0
	adds r0, #0xc4
	ldrb r0, [r0]
	cmp r0, #0
	beq _08018CE8
	adds r0, r5, #0
	bl sub_08018D0C
_08018CE8:
	adds r0, r4, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0
	beq _08018CF8
	adds r0, r5, #0
	bl sub_08018DF4
_08018CF8:
	adds r5, #1
	cmp r5, #5
	bls _08018CC8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08018D04: .4byte 0x03001800
_08018D08: .4byte 0x03000590
	.syntax divided
