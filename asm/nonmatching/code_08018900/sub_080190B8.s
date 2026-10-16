	.syntax unified

	thumb_func_start sub_080190B8
sub_080190B8: @ 0x080190B8
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08019104 @ =0x03000590
	lsls r0, r4, #8
	adds r0, r0, r1
	adds r0, #0xbb
	movs r1, #0
	strb r1, [r0]
	adds r0, r4, #0
	bl sub_08019108
	adds r0, r4, #0
	bl sub_080191C0
	adds r0, r4, #0
	bl sub_080191E4
	adds r0, r4, #0
	bl sub_0801922C
	adds r0, r4, #0
	bl sub_08019264
	adds r0, r4, #0
	bl sub_0801928C
	adds r0, r4, #0
	bl sub_080192B8
	adds r0, r4, #0
	bl sub_080192E8
	adds r0, r4, #0
	bl sub_0801932C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08019104: .4byte 0x03000590
	.syntax divided
