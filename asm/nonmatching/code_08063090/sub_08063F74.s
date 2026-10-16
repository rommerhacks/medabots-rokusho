	.syntax unified

	thumb_func_start sub_08063F74
sub_08063F74: @ 0x08063F74
	push {lr}
	ldr r0, _08063FA8 @ =0x08485BD8
	ldr r0, [r0, #0x64]
	bl run_message
	cmp r0, #0
	beq _08063FA2
	bl animate_battle_scroll_tiles
	ldr r0, _08063FAC @ =0x03006F74
	ldr r2, [r0]
	ldrh r0, [r2, #0x3c]
	subs r0, #1
	strh r0, [r2, #0x3c]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _08063FA2
	ldr r0, _08063FB0 @ =0x0300137C
	ldr r1, [r0]
	adds r1, #1
	str r1, [r0]
	movs r0, #0
	strh r0, [r2, #0x3c]
_08063FA2:
	pop {r0}
	bx r0
	.align 2, 0
_08063FA8: .4byte 0x08485BD8
_08063FAC: .4byte 0x03006F74
_08063FB0: .4byte 0x0300137C
	.syntax divided
