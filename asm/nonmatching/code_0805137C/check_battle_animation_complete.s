	.syntax unified

	thumb_func_start check_battle_animation_complete
check_battle_animation_complete: @ 0x08052C74
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	movs r4, #0
	cmp r3, #1
	beq _08052CAC
	cmp r3, #1
	bgt _08052C8A
	cmp r3, #0
	beq _08052C94
	b _08052D26
_08052C8A:
	cmp r3, #2
	beq _08052CE0
	cmp r3, #3
	beq _08052D04
	b _08052D26
_08052C94:
	ldr r0, _08052CA0 @ =0x030057E0
	ldr r2, _08052CA4 @ =0x00000C54
	adds r1, r0, r2
	ldrh r1, [r1]
	ldr r5, _08052CA8 @ =0x00000C4A
	b _08052CEA
	.align 2, 0
_08052CA0: .4byte 0x030057E0
_08052CA4: .4byte 0x00000C54
_08052CA8: .4byte 0x00000C4A
_08052CAC:
	ldr r1, _08052CD0 @ =0x030057E0
	ldr r2, _08052CD4 @ =0x00000C54
	adds r0, r1, r2
	ldrh r2, [r0]
	ldr r5, _08052CD8 @ =0x00000C4A
	adds r0, r1, r5
	ldrh r0, [r0]
	subs r2, r2, r0
	adds r2, #0x10
	ldr r0, _08052CDC @ =0x00000802
	adds r1, r1, r0
	ldrh r0, [r1]
	lsls r0, r0, #3
	cmp r2, r0
	bne _08052D26
	movs r4, #1
	b _08052D2A
	.align 2, 0
_08052CD0: .4byte 0x030057E0
_08052CD4: .4byte 0x00000C54
_08052CD8: .4byte 0x00000C4A
_08052CDC: .4byte 0x00000802
_08052CE0:
	ldr r0, _08052CF8 @ =0x030057E0
	ldr r2, _08052CFC @ =0x00000C52
	adds r1, r0, r2
	ldrh r1, [r1]
	ldr r5, _08052D00 @ =0x00000C48
_08052CEA:
	adds r0, r0, r5
	ldrh r0, [r0]
	cmp r1, r0
	bne _08052D26
	movs r4, #1
	b _08052D2A
	.align 2, 0
_08052CF8: .4byte 0x030057E0
_08052CFC: .4byte 0x00000C52
_08052D00: .4byte 0x00000C48
_08052D04:
	ldr r1, _08052D38 @ =0x030057E0
	ldr r2, _08052D3C @ =0x00000C52
	adds r0, r1, r2
	ldrh r2, [r0]
	ldr r5, _08052D40 @ =0x00000C48
	adds r0, r1, r5
	ldrh r0, [r0]
	subs r2, r2, r0
	adds r2, #0x10
	movs r0, #0x80
	lsls r0, r0, #4
	adds r1, r1, r0
	ldrh r0, [r1]
	lsls r0, r0, #3
	cmp r2, r0
	bne _08052D26
	movs r4, #1
_08052D26:
	cmp r4, #0
	beq _08052D30
_08052D2A:
	adds r0, r3, #0
	bl set_battle_entity_animation_attack
_08052D30:
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08052D38: .4byte 0x030057E0
_08052D3C: .4byte 0x00000C52
_08052D40: .4byte 0x00000C48
	.syntax divided
