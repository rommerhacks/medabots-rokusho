	.syntax unified

	thumb_func_start sound_volume_lookup
sound_volume_lookup: @ 0x080739F0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r6, _08073A14 @ =0x083ABAC6
	cmp r5, #0
	ble _08073A18
	movs r1, #0xc
	bl sub_0807CC88
	adds r4, r0, #0
	adds r0, r5, #0
	movs r1, #0xc
	bl sub_0807CBBC
	lsls r4, r4, #1
	adds r4, r4, r6
	ldrh r1, [r4]
	lsls r1, r0
	b _08073A48
	.align 2, 0
_08073A14: .4byte 0x083ABAC6
_08073A18:
	cmp r5, #0
	bge _08073A46
	rsbs r5, r5, #0
	adds r0, r5, #0
	movs r1, #0xc
	bl sub_0807CBBC
	adds r4, r0, #0
	adds r0, r5, #0
	movs r1, #0xc
	bl sub_0807CC88
	adds r1, r0, #0
	cmp r1, #0
	beq _08073A3C
	movs r0, #0xc
	subs r1, r0, r1
	adds r4, #1
_08073A3C:
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r1, [r0]
	asrs r1, r4
	b _08073A48
_08073A46:
	ldrh r1, [r6]
_08073A48:
	adds r0, r1, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.syntax divided
