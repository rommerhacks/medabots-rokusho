	.syntax unified

	thumb_func_start sub_080482C0
	.global sub_080482C0
sub_080482C0: @ 0x080482C0
	ldr r0, _080482E4 @ =0x083F9BF4
	ldr r1, _080482E8 @ =0x030057E0
	ldr r2, _080482EC @ =0x000007FE
	adds r1, r1, r2
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	cmp r0, #0
	beq _080482FC
	ldr r1, _080482F0 @ =0x040000D4
	str r0, [r1]
	ldr r0, _080482F4 @ =0x0202FA00
	str r0, [r1, #4]
	ldr r0, _080482F8 @ =0x84000068
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	b _08048366
	.align 2, 0
_080482E4: .4byte 0x083F9BF4
_080482E8: .4byte 0x030057E0
_080482EC: .4byte 0x000007FE
_080482F0: .4byte 0x040000D4
_080482F4: .4byte 0x0202FA00
_080482F8: .4byte 0x84000068
_080482FC:
	ldr r0, _08048368 @ =0x040000D4
	ldr r3, _0804836C @ =0x080AC5B4
	str r3, [r0]
	ldr r1, _08048370 @ =0x0202FA00
	str r1, [r0, #4]
	ldr r2, _08048374 @ =0x84000008
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _08048378 @ =0x080AC654
	str r1, [r0]
	ldr r1, _0804837C @ =0x0202FA20
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _08048380 @ =0x080AC6F4
	str r1, [r0]
	ldr r1, _08048384 @ =0x0202FA40
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _08048388 @ =0x080AC794
	str r1, [r0]
	ldr r1, _0804838C @ =0x0202FA60
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	str r3, [r0]
	ldr r1, _08048390 @ =0x0202FA80
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	str r3, [r0]
	ldr r1, _08048394 @ =0x0202FAA0
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	str r3, [r0]
	ldr r1, _08048398 @ =0x0202FAC0
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0804839C @ =0x080AC834
	str r1, [r0]
	ldr r1, _080483A0 @ =0x0202FAE0
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _080483A4 @ =0x080AC8D4
	str r1, [r0]
	ldr r1, _080483A8 @ =0x0202FB00
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r0, [r0, #8]
_08048366:
	bx lr
	.align 2, 0
_08048368: .4byte 0x040000D4
_0804836C: .4byte 0x080AC5B4
_08048370: .4byte 0x0202FA00
_08048374: .4byte 0x84000008
_08048378: .4byte 0x080AC654
_0804837C: .4byte 0x0202FA20
_08048380: .4byte 0x080AC6F4
_08048384: .4byte 0x0202FA40
_08048388: .4byte 0x080AC794
_0804838C: .4byte 0x0202FA60
_08048390: .4byte 0x0202FA80
_08048394: .4byte 0x0202FAA0
_08048398: .4byte 0x0202FAC0
_0804839C: .4byte 0x080AC834
_080483A0: .4byte 0x0202FAE0
_080483A4: .4byte 0x080AC8D4
_080483A8: .4byte 0x0202FB00
	.syntax divided
