	.syntax unified

	thumb_func_start sub_08058908
sub_08058908: @ 0x08058908
	push {r4, r5, lr}
	adds r2, r0, #0
	adds r5, r1, #0
	movs r4, #1
	ldr r0, _0805895C @ =0x03002B64
	ldrb r1, [r0, #1]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _0805891E
	movs r4, #0x10
_0805891E:
	ldr r0, _08058960 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _08058970
	ldr r1, _08058964 @ =0x083D6070
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r2, [r0]
	ldrh r0, [r2]
	subs r0, r0, r4
	strh r0, [r2]
	lsls r0, r0, #0x10
	ldr r1, _08058968 @ =0xFFFF0000
	cmp r0, r1
	bne _08058948
	subs r0, r5, #1
	strh r0, [r2]
_08058948:
	ldr r1, _0805896C @ =0x030057A0
	ldrb r0, [r1, #0x14]
	adds r1, #0x16
	adds r1, r0, r1
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	bl sub_080581C0
	b _080589A0
	.align 2, 0
_0805895C: .4byte 0x03002B64
_08058960: .4byte 0x03001798
_08058964: .4byte 0x083D6070
_08058968: .4byte 0xFFFF0000
_0805896C: .4byte 0x030057A0
_08058970:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080589A0
	ldr r1, _080589A8 @ =0x083D6070
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r2, [r0]
	ldrh r0, [r2]
	adds r0, r0, r4
	strh r0, [r2]
	ldrh r0, [r2]
	cmp r0, r5
	blt _0805898E
	strh r3, [r2]
_0805898E:
	ldr r1, _080589AC @ =0x030057A0
	ldrb r0, [r1, #0x14]
	adds r1, #0x16
	adds r1, r0, r1
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	bl sub_080581C0
_080589A0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080589A8: .4byte 0x083D6070
_080589AC: .4byte 0x030057A0
	.syntax divided
