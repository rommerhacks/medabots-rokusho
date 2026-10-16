	.syntax unified

	thumb_func_start sub_080376F4
	.global sub_080376F4
sub_080376F4: @ 0x080376F4
	ldr r2, _08037720 @ =0x03001800
	adds r1, r2, #0
	adds r1, #0xe8
	ldrh r1, [r1]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x13
	adds r3, r2, #0
	adds r3, #0xec
	strh r1, [r3]
	ldr r2, _08037724 @ =0x03000590
	lsls r0, r0, #8
	adds r0, r0, r2
	adds r0, #0xac
	ldrb r0, [r0]
	adds r1, r1, r0
	strh r1, [r3]
	cmp r1, #0
	bne _0803771C
	movs r0, #1
	strh r0, [r3]
_0803771C:
	bx lr
	.align 2, 0
_08037720: .4byte 0x03001800
_08037724: .4byte 0x03000590
	.syntax divided
