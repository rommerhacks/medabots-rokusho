	.syntax unified

	thumb_func_start sub_08033974
sub_08033974: @ 0x08033974
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	mov r1, sp
	movs r0, #0
	strb r0, [r1]
	bl battle_script_load_operands
	bl battle_script_advance
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #0
	bne _080339DA
	ldr r7, _080339C8 @ =0x083C6B28
	ldr r4, _080339CC @ =0x03001800
	adds r6, r4, #0
	adds r6, #0xbc
	mov r5, sp
_08033998:
	adds r0, r4, #0
	adds r0, #0xa8
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r2, [r0]
	adds r0, r4, #0
	adds r0, #0xab
	adds r1, r4, #0
	adds r1, #0xac
	ldrb r0, [r0]
	adds r1, r1, r0
	ldrh r0, [r6]
	adds r2, r2, r0
	ldrb r0, [r1]
	ldrb r2, [r2]
	cmp r0, r2
	bne _080339D0
	bl battle_script_advance
	movs r0, #1
	strb r0, [r5]
	b _080339D4
	.align 2, 0
_080339C8: .4byte 0x083C6B28
_080339CC: .4byte 0x03001800
_080339D0:
	bl battle_script_advance
_080339D4:
	ldrb r0, [r5]
	cmp r0, #0
	beq _08033998
_080339DA:
	ldr r0, _080339EC @ =0x03001800
	ldr r2, _080339F0 @ =0x00000163
	adds r1, r0, r2
	movs r0, #1
	strb r0, [r1]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080339EC: .4byte 0x03001800
_080339F0: .4byte 0x00000163
	.syntax divided
