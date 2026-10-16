	.syntax unified

	thumb_func_start sub_0805FD60
sub_0805FD60: @ 0x0805FD60
	push {r4, r5, lr}
	ldr r0, _0805FD7C @ =0x03006F74
	ldr r2, [r0]
	ldrb r1, [r2]
	lsls r3, r1, #0x18
	lsrs r4, r3, #0x18
	cmp r4, #0
	beq _0805FD84
	ldr r0, _0805FD80 @ =0x04000054
	adds r1, #0xff
	strb r1, [r2]
	lsrs r1, r3, #0x19
	strh r1, [r0]
	b _0805FDA4
	.align 2, 0
_0805FD7C: .4byte 0x03006F74
_0805FD80: .4byte 0x04000054
_0805FD84:
	strh r4, [r2, #2]
	ldr r1, _0805FDAC @ =0x03002C30
	adds r3, r1, #0
	adds r3, #0x40
	ldrh r2, [r3]
	movs r5, #0x80
	lsls r5, r5, #7
	adds r0, r5, #0
	orrs r0, r2
	strh r0, [r3]
	adds r1, #0x5a
	strh r4, [r1]
	ldr r1, _0805FDB0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0805FDA4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805FDAC: .4byte 0x03002C30
_0805FDB0: .4byte 0x0300137C
	.syntax divided
