	.syntax unified

	thumb_func_start field_random
	.global field_random
field_random: @ 0x08049734
	push {r4, lr}
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r4, _08049764 @ =0x083F7FF4
	ldr r3, _08049768 @ =0x030057E0
	ldr r0, _0804976C @ =0x00000C37
	adds r3, r3, r0
	ldrb r0, [r3]
	ldr r2, _08049770 @ =0x03005310
	ldr r2, [r2, #4]
	adds r0, r0, r2
	movs r2, #0xff
	ands r0, r2
	adds r0, r0, r4
	ldrb r0, [r0]
	strb r0, [r3]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08049764: .4byte 0x083F7FF4
_08049768: .4byte 0x030057E0
_0804976C: .4byte 0x00000C37
_08049770: .4byte 0x03005310
	.syntax divided
