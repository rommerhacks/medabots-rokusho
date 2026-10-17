	.syntax unified

	thumb_func_start sub_0805BA20
	.global sub_0805BA20
sub_0805BA20: @ 0x0805BA20
	push {lr}
	ldr r0, _0805BA40 @ =0x03005030
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0805BA5A
	ldr r0, _0805BA44 @ =0x03000B90
	ldrb r0, [r0]
	cmp r0, #0
	beq _0805BA4C
	ldr r0, _0805BA48 @ =0x03005010
	ldrh r0, [r0, #8]
	bl sub_0805B9EC
	b _0805BA5A
	.align 2, 0
_0805BA40: .4byte 0x03005030
_0805BA44: .4byte 0x03000B90
_0805BA48: .4byte 0x03005010
_0805BA4C:
	ldr r0, _0805BA60 @ =0x03005010
	ldr r1, _0805BA64 @ =0x03002B64
	ldrh r1, [r1]
	strh r1, [r0, #4]
	ldrh r0, [r0, #8]
	bl sub_0805B9EC
_0805BA5A:
	pop {r0}
	bx r0
	.align 2, 0
_0805BA60: .4byte 0x03005010
_0805BA64: .4byte 0x03002B64
	.syntax divided
