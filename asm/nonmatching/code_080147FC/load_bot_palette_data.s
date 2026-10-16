	.syntax unified

	thumb_func_start load_bot_palette_data
	.global load_bot_palette_data
load_bot_palette_data: @ 0x08015668
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	mov sb, r0
	mov r8, r1
	ldr r5, _080156C0 @ =0x03000590
	lsls r6, r0, #8
	adds r0, r6, r5
	ldrb r1, [r0, #1]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldr r1, _080156C4 @ =0x083B7E0C
	adds r0, r0, r1
	ldr r4, _080156C8 @ =0x0300052E
	adds r1, r4, #0
	movs r2, #3
	bl memcpy_bytes_08041D04
	add r4, r8
	ldrb r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _080156CC @ =0x083B7CD4
	adds r0, r0, r1
	adds r5, #0xa8
	adds r6, r6, r5
	adds r1, r6, #0
	movs r2, #6
	bl memcpy_bytes_08041D04
	movs r0, #4
	add r8, r0
	mov r0, sb
	mov r1, r8
	bl battle_bot_select_part
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080156C0: .4byte 0x03000590
_080156C4: .4byte 0x083B7E0C
_080156C8: .4byte 0x0300052E
_080156CC: .4byte 0x083B7CD4
	.syntax divided
