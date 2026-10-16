	.syntax unified

	thumb_func_start sub_08027BA0
sub_08027BA0: @ 0x08027BA0
	push {r4, lr}
	ldr r0, _08027BD8 @ =0x03000440
	adds r0, #0x86
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	ldr r3, _08027BDC @ =0x03002C30
	ldr r0, _08027BE0 @ =0x00000858
	adds r3, r3, r0
	ldrh r0, [r3]
	adds r0, #0x40
	ldr r4, _08027BE4 @ =0x000003FF
	adds r2, r4, #0
	ands r0, r2
	strh r0, [r3]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0x3c
	bls _08027BD0
	ldr r1, _08027BE8 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08027BD0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08027BD8: .4byte 0x03000440
_08027BDC: .4byte 0x03002C30
_08027BE0: .4byte 0x00000858
_08027BE4: .4byte 0x000003FF
_08027BE8: .4byte 0x03001800
	.syntax divided
