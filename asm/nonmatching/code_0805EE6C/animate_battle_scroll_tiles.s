	.syntax unified

	thumb_func_start animate_battle_scroll_tiles
	.global animate_battle_scroll_tiles
animate_battle_scroll_tiles: @ 0x08062BE8
	push {r4, r5, r6, lr}
	ldr r0, _08062C0C @ =0x03006F74
	ldr r2, [r0]
	movs r3, #0x3a
	ldrsh r1, [r2, r3]
	adds r3, r0, #0
	cmp r1, #0
	bge _08062BFA
	adds r1, #0x7f
_08062BFA:
	asrs r0, r1, #7
	cmp r0, #1
	beq _08062C22
	cmp r0, #1
	bgt _08062C10
	cmp r0, #0
	beq _08062C1A
	b _08062C3A
	.align 2, 0
_08062C0C: .4byte 0x03006F74
_08062C10:
	cmp r0, #2
	beq _08062C2A
	cmp r0, #3
	beq _08062C32
	b _08062C3A
_08062C1A:
	ldrh r0, [r2, #0x3a]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x11
	b _08062C42
_08062C22:
	ldrh r0, [r2, #0x3a]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x12
	b _08062C42
_08062C2A:
	ldrh r0, [r2, #0x3a]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x13
	b _08062C42
_08062C32:
	ldrh r0, [r2, #0x3a]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x14
	b _08062C42
_08062C3A:
	ldr r0, [r3]
	ldrh r0, [r0, #0x3a]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x15
_08062C42:
	movs r0, #3
	ands r1, r0
	ldr r2, [r3]
	ldrh r0, [r2, #0x3a]
	subs r0, #1
	strh r0, [r2, #0x3a]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _08062C58
	movs r0, #0x3f
	strh r0, [r2, #0x3a]
_08062C58:
	ldr r6, _08062C7C @ =0x0600E9E2
	lsls r1, r1, #9
	ldr r0, _08062C80 @ =0x0600D800
	adds r4, r1, r0
	movs r5, #7
_08062C62:
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0xc
	bl CpuSet
	adds r6, #0x40
	adds r4, #0x40
	subs r5, #1
	cmp r5, #0
	bge _08062C62
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08062C7C: .4byte 0x0600E9E2
_08062C80: .4byte 0x0600D800
	.syntax divided
