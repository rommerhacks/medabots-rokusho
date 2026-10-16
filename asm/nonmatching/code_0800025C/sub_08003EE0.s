	.syntax unified

	thumb_func_start sub_08003EE0
sub_08003EE0: @ 0x08003EE0
	push {lr}
	ldr r0, _08003F10 @ =0x084E2E38
	ldr r1, _08003F14 @ =0x050003E0
	movs r2, #8
	bl CpuFastSet
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	ldr r0, _08003F18 @ =0x03000440
	adds r0, #0x96
	movs r1, #0
	strb r1, [r0]
	ldr r0, _08003F1C @ =0x03000430
	str r1, [r0]
	ldr r1, _08003F20 @ =0x03002B8C
	movs r0, #2
	str r0, [r1]
	ldr r1, _08003F24 @ =0x0300137C
	movs r0, #0x10
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08003F10: .4byte 0x084E2E38
_08003F14: .4byte 0x050003E0
_08003F18: .4byte 0x03000440
_08003F1C: .4byte 0x03000430
_08003F20: .4byte 0x03002B8C
_08003F24: .4byte 0x0300137C
	.syntax divided
