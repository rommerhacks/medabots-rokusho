	.syntax unified

	thumb_func_start sub_08062AB0
	.global sub_08062AB0
sub_08062AB0: @ 0x08062AB0
	push {r4, lr}
	ldr r3, _08062B0C @ =0x083AC494
	lsls r2, r0, #2
	adds r2, r2, r0
	adds r2, r2, r1
	lsls r2, r2, #2
	adds r2, r2, r3
	ldr r0, [r2]
	ldr r1, _08062B10 @ =0x06010000
	bl lz_decompress_dispatch
	ldr r2, _08062B14 @ =0x03002C30
	movs r4, #0
	ldr r3, _08062B18 @ =0x00008A24
	strh r3, [r2]
	ldr r0, _08062B1C @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x7a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08062AEA
	movs r0, #0x80
	lsls r0, r0, #7
	adds r1, r0, #0
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
_08062AEA:
	movs r0, #0xb8
	strh r0, [r2, #2]
	movs r0, #0x38
	strh r0, [r2, #4]
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r2, #6]
	strb r4, [r2, #0xa]
	strb r4, [r2, #0x1c]
	movs r0, #0x40
	strb r0, [r2, #0xb]
	strb r0, [r2, #8]
	strb r0, [r2, #9]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08062B0C: .4byte 0x083AC494
_08062B10: .4byte 0x06010000
_08062B14: .4byte 0x03002C30
_08062B18: .4byte 0x00008A24
_08062B1C: .4byte 0x03006F74
	.syntax divided
