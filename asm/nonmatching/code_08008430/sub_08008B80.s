	.syntax unified

	thumb_func_start sub_08008B80
sub_08008B80: @ 0x08008B80
	push {lr}
	bl sub_080093F8
	movs r0, #1
	movs r1, #5
	bl clear_sprite_table_mask
	ldr r0, _08008BAC @ =0x084E2E78
	ldr r1, _08008BB0 @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	bl sub_0800AA1C
	bl sub_0803FB0C
	ldr r1, _08008BB4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08008BAC: .4byte 0x084E2E78
_08008BB0: .4byte 0x050003C0
_08008BB4: .4byte 0x0300137C
	.syntax divided
