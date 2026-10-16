	.syntax unified

	thumb_func_start update_animated_tilemap
	.global update_animated_tilemap
update_animated_tilemap: @ 0x08062B20
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _08062B48 @ =0x03006F74
	ldr r2, [r0]
	movs r3, #0x3a
	ldrsh r1, [r2, r3]
	adds r3, r0, #0
	cmp r1, #0
	bge _08062B36
	adds r1, #0x7f
_08062B36:
	asrs r0, r1, #7
	cmp r0, #1
	beq _08062B5E
	cmp r0, #1
	bgt _08062B4C
	cmp r0, #0
	beq _08062B56
	b _08062B76
	.align 2, 0
_08062B48: .4byte 0x03006F74
_08062B4C:
	cmp r0, #2
	beq _08062B66
	cmp r0, #3
	beq _08062B6E
	b _08062B76
_08062B56:
	ldrh r0, [r2, #0x3a]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x11
	b _08062B7E
_08062B5E:
	ldrh r0, [r2, #0x3a]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x12
	b _08062B7E
_08062B66:
	ldrh r0, [r2, #0x3a]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x13
	b _08062B7E
_08062B6E:
	ldrh r0, [r2, #0x3a]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x14
	b _08062B7E
_08062B76:
	ldr r0, [r3]
	ldrh r0, [r0, #0x3a]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x15
_08062B7E:
	movs r0, #3
	ands r1, r0
	ldr r2, [r3]
	ldrh r0, [r2, #0x3a]
	subs r0, #1
	strh r0, [r2, #0x3a]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _08062B94
	movs r0, #0x3f
	strh r0, [r2, #0x3a]
_08062B94:
	movs r6, #0
	adds r0, r1, #2
	mov r8, r0
	ldr r7, _08062BDC @ =0x0600D800
	movs r5, #0xe0
	lsls r5, r5, #1
	lsls r4, r1, #9
_08062BA2:
	adds r0, r4, r7
	ldr r2, _08062BE0 @ =0x0600E804
	adds r1, r5, r2
	movs r2, #0xc
	bl CpuSet
	movs r0, #3
	mov r3, r8
	ands r0, r3
	lsls r0, r0, #3
	adds r0, r0, r6
	lsls r0, r0, #6
	adds r0, r0, r7
	ldr r2, _08062BE4 @ =0x0600E820
	adds r1, r5, r2
	movs r2, #0xc
	bl CpuSet
	adds r5, #0x40
	adds r4, #0x40
	adds r6, #1
	cmp r6, #7
	ble _08062BA2
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08062BDC: .4byte 0x0600D800
_08062BE0: .4byte 0x0600E804
_08062BE4: .4byte 0x0600E820
	.syntax divided
