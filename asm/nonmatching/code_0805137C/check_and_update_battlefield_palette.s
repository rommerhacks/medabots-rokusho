	.syntax unified

	thumb_func_start check_and_update_battlefield_palette
	.global check_and_update_battlefield_palette
check_and_update_battlefield_palette: @ 0x08052BE4
	push {r4, r5, lr}
	ldr r4, _08052C10 @ =0x030057E0
	ldr r0, _08052C14 @ =0x00000C5C
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #1
	bne _08052C0A
	movs r0, #0
	bl sub_0804803C
	cmp r0, #0
	bne _08052C0A
	ldr r1, _08052C18 @ =0x00000C69
	adds r0, r4, r1
	ldrb r0, [r0]
	strb r0, [r5]
	movs r0, #1
	bl load_battle_palette_via_dma
_08052C0A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08052C10: .4byte 0x030057E0
_08052C14: .4byte 0x00000C5C
_08052C18: .4byte 0x00000C69
	.syntax divided
