	.syntax unified

	thumb_func_start sub_08043AE0
sub_08043AE0: @ 0x08043AE0
	push {r4, lr}
	ldr r4, _08043B3C @ =0x040000B0
	ldr r0, _08043B40 @ =0x03001780
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	ldr r3, _08043B44 @ =0x02023C00
	cmp r0, #0
	bne _08043AF4
	ldr r3, _08043B48 @ =0x02023200
_08043AF4:
	ldr r2, _08043B4C @ =0x04000010
	ldrh r0, [r3]
	strh r0, [r2]
	ldr r1, _08043B50 @ =0x04000012
	ldrh r0, [r3, #2]
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r3, #4]
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r3, #6]
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r3, #8]
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r3, #0xa]
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r3, #0xc]
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r3, #0xe]
	strh r0, [r1]
	adds r1, #0x9c
	movs r0, #0
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x10
	str r0, [r4]
	str r2, [r4, #4]
	ldr r0, _08043B54 @ =0xA6600004
	str r0, [r4, #8]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08043B3C: .4byte 0x040000B0
_08043B40: .4byte 0x03001780
_08043B44: .4byte 0x02023C00
_08043B48: .4byte 0x02023200
_08043B4C: .4byte 0x04000010
_08043B50: .4byte 0x04000012
_08043B54: .4byte 0xA6600004
_08043B58:
	.byte 0x00, 0xB5, 0x39, 0xF0, 0x0D, 0xF8, 0x04, 0x49
	.byte 0x00, 0x20, 0x08, 0x80, 0x03, 0x49, 0x04, 0x48, 0x08, 0x60, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
	.byte 0xBA, 0x00, 0x00, 0x04, 0x98, 0x0B, 0x00, 0x03, 0x41, 0x08, 0x00, 0x08
	.syntax divided
