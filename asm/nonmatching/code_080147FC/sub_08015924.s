	.syntax unified

	thumb_func_start sub_08015924
	.global sub_08015924
sub_08015924: @ 0x08015924
	cmp r0, #2
	bhi _08015940
	ldr r1, _0801593C @ =0x03000590
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r0, #0xbd
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _08015952
	b _0801595C
	.align 2, 0
_0801593C: .4byte 0x03000590
_08015940:
	ldr r1, _08015958 @ =0x03000590
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r0, #0xbd
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _0801595C
_08015952:
	movs r0, #1
	b _0801595E
	.align 2, 0
_08015958: .4byte 0x03000590
_0801595C:
	movs r0, #0
_0801595E:
	bx lr
	.syntax divided
