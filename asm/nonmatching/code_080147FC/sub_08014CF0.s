	.syntax unified

	thumb_func_start sub_08014CF0
sub_08014CF0: @ 0x08014CF0
	push {r4, lr}
	ldr r3, _08014D2C @ =0x03001800
	movs r0, #0x87
	adds r0, r0, r3
	mov ip, r0
	ldrb r0, [r0]
	cmp r0, #2
	bhi _08014D3C
	ldr r2, _08014D30 @ =0x03005010
	ldr r1, _08014D34 @ =0x03000590
	mov r4, ip
	ldrb r0, [r4]
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r0, #0xdd
	ldrb r0, [r0]
	movs r4, #0x80
	lsls r4, r4, #8
	adds r1, r4, #0
	adds r0, r0, r1
	strh r0, [r2, #6]
	ldr r0, _08014D38 @ =0x000001AF
	adds r1, r3, r0
	ldrb r0, [r1]
	cmp r0, #0
	bne _08014D66
	movs r0, #1
	strb r0, [r1]
	b _08014D6E
	.align 2, 0
_08014D2C: .4byte 0x03001800
_08014D30: .4byte 0x03005010
_08014D34: .4byte 0x03000590
_08014D38: .4byte 0x000001AF
_08014D3C:
	ldr r1, _08014D74 @ =0x03005010
	ldr r0, _08014D78 @ =0x03000B90
	ldrb r2, [r0]
	movs r0, #1
	eors r0, r2
	lsls r0, r0, #2
	adds r1, #0xa
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08014D6E
	ldr r1, _08014D7C @ =0x03000590
	mov r3, ip
	ldrb r0, [r3]
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r0, #0xdd
	strb r2, [r0]
_08014D66:
	ldr r1, _08014D80 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08014D6E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08014D74: .4byte 0x03005010
_08014D78: .4byte 0x03000B90
_08014D7C: .4byte 0x03000590
_08014D80: .4byte 0x0300137C
_08014D84:
	.byte 0x02, 0x49, 0x08, 0x68, 0x01, 0x30, 0x08, 0x60, 0x70, 0x47, 0x00, 0x00
	.byte 0x7C, 0x13, 0x00, 0x03
	.syntax divided
