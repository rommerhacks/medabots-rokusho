	.syntax unified

	thumb_func_start sub_08010170
sub_08010170: @ 0x08010170
	push {r4, lr}
	ldr r3, _08010198 @ =0x03002C30
	ldr r1, _0801019C @ =0x00000127
	adds r0, r3, r1
	ldrb r1, [r0]
	mov ip, r3
	cmp r1, #0x1e
	beq _080101C0
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080101A4
	movs r4, #0x80
	lsls r4, r4, #1
	adds r2, r3, r4
	ldrh r1, [r2]
	ldr r0, _080101A0 @ =0x0000BFFF
	ands r0, r1
	b _080101B4
	.align 2, 0
_08010198: .4byte 0x03002C30
_0801019C: .4byte 0x00000127
_080101A0: .4byte 0x0000BFFF
_080101A4:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r2, r3, r0
	ldrh r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r3, #0
	orrs r0, r1
_080101B4:
	strh r0, [r2]
	ldr r1, _080101BC @ =0x00000127
	add r1, ip
	b _080101D6
	.align 2, 0
_080101BC: .4byte 0x00000127
_080101C0:
	movs r4, #0x80
	lsls r4, r4, #1
	adds r2, r3, r4
	ldrh r1, [r2]
	movs r4, #0x80
	lsls r4, r4, #7
	adds r0, r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _080101E4 @ =0x00000129
	adds r1, r3, r0
_080101D6:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080101E4: .4byte 0x00000129
	.syntax divided
