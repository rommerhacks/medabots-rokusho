	.syntax unified

	thumb_func_start sub_080589B0
sub_080589B0: @ 0x080589B0
	push {r4, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	movs r3, #1
	ldr r0, _080589EC @ =0x03002B64
	ldrb r1, [r0, #1]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080589C6
	movs r3, #0x10
_080589C6:
	ldr r0, _080589F0 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080589F8
	ldr r0, _080589F4 @ =0x083D607C
	lsls r1, r2, #2
	adds r1, r1, r0
	ldr r1, [r1]
	ldrh r2, [r1]
	subs r2, r2, r3
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	bne _08058A12
	subs r2, r4, #1
	b _08058A12
	.align 2, 0
_080589EC: .4byte 0x03002B64
_080589F0: .4byte 0x03001798
_080589F4: .4byte 0x083D607C
_080589F8:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08058A14
	ldr r1, _08058A1C @ =0x083D607C
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldrh r2, [r1]
	adds r2, r2, r3
	cmp r2, r4
	blt _08058A12
	movs r2, #0
_08058A12:
	strh r2, [r1]
_08058A14:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08058A1C: .4byte 0x083D607C
	.syntax divided
