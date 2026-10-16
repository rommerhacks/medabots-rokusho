	.syntax unified

	thumb_func_start sub_080518F4
	.global sub_080518F4
sub_080518F4: @ 0x080518F4
	lsls r0, r0, #0x18
	ldr r2, _08051914 @ =0x083D28C0
	ldr r1, _08051918 @ =0x03002C30
	lsrs r0, r0, #0x12
	adds r0, r0, r1
	adds r0, #0x2a
	ldrb r0, [r0]
	adds r0, r0, r2
	ldrb r1, [r0]
	ldr r0, _0805191C @ =0x03006D38
	ldrb r0, [r0, #2]
	adds r0, r0, r2
	ldrb r0, [r0]
	muls r0, r1, r0
	bx lr
	.align 2, 0
_08051914: .4byte 0x083D28C0
_08051918: .4byte 0x03002C30
_0805191C: .4byte 0x03006D38
	.syntax divided
