	.syntax unified

	thumb_func_start sub_0803836C
	.global sub_0803836C
sub_0803836C: @ 0x0803836C
	push {r4, lr}
	movs r1, #0
	ldr r0, _08038390 @ =0x03001800
	adds r4, r0, #0
	adds r4, #0xd2
	movs r3, #0
	adds r2, r0, #0
	adds r2, #0xd6
_0803837C:
	adds r0, r1, r4
	strb r3, [r0]
	strh r3, [r2]
	adds r2, #2
	adds r1, #1
	cmp r1, #2
	bls _0803837C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08038390: .4byte 0x03001800
	.syntax divided
