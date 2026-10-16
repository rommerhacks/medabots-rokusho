	.syntax unified

	thumb_func_start sub_0801053C
sub_0801053C: @ 0x0801053C
	push {r4, r5, lr}
	sub sp, #8
	bl load_encounter_into_battle_setup
	ldr r0, _0801057C @ =0x03000440
	movs r1, #0x99
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r4, #0
	strb r4, [r0]
	str r4, [sp]
	ldr r1, _08010580 @ =0x05000200
	ldr r5, _08010584 @ =0x01000080
	mov r0, sp
	adds r2, r5, #0
	bl CpuFastSet
	str r4, [sp, #4]
	add r0, sp, #4
	movs r1, #0xa0
	lsls r1, r1, #0x13
	adds r2, r5, #0
	bl CpuFastSet
	ldr r1, _08010588 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801057C: .4byte 0x03000440
_08010580: .4byte 0x05000200
_08010584: .4byte 0x01000080
_08010588: .4byte 0x0300137C
	.syntax divided
