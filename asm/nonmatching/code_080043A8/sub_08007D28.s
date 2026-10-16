	.syntax unified

	thumb_func_start sub_08007D28
sub_08007D28: @ 0x08007D28
	push {r4, r5, lr}
	sub sp, #8
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	ldr r0, _08007D48 @ =0x03000440
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #4
	bhi _08007DCE
	lsls r0, r0, #2
	ldr r1, _08007D4C @ =_08007D50
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08007D48: .4byte 0x03000440
_08007D4C: .4byte _08007D50
_08007D50: @ jump table
	.4byte _08007DC8 @ case 0
	.4byte _08007D64 @ case 1
	.4byte _08007D88 @ case 2
	.4byte _08007DC8 @ case 3
	.4byte _08007DC8 @ case 4
_08007D64:
	ldr r0, _08007D7C @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x3d
	ldrb r1, [r1]
	adds r0, #0x97
	strb r1, [r0]
	ldr r1, _08007D80 @ =0x03002B8C
	movs r0, #3
	str r0, [r1]
	ldr r1, _08007D84 @ =0x0300137C
	movs r0, #0x10
	b _08007DCC
	.align 2, 0
_08007D7C: .4byte 0x03000440
_08007D80: .4byte 0x03002B8C
_08007D84: .4byte 0x0300137C
_08007D88:
	bl sub_0800B498
	movs r4, #0
	str r4, [sp]
	ldr r1, _08007DB8 @ =0x05000200
	ldr r5, _08007DBC @ =0x01000080
	mov r0, sp
	adds r2, r5, #0
	bl CpuFastSet
	str r4, [sp, #4]
	add r0, sp, #4
	movs r1, #0xa0
	lsls r1, r1, #0x13
	adds r2, r5, #0
	bl CpuFastSet
	ldr r1, _08007DC0 @ =0x03002B8C
	movs r0, #7
	str r0, [r1]
	ldr r1, _08007DC4 @ =0x0300137C
	movs r0, #0x3c
	b _08007DCC
	.align 2, 0
_08007DB8: .4byte 0x05000200
_08007DBC: .4byte 0x01000080
_08007DC0: .4byte 0x03002B8C
_08007DC4: .4byte 0x0300137C
_08007DC8:
	ldr r1, _08007DD8 @ =0x0300137C
	movs r0, #0
_08007DCC:
	str r0, [r1]
_08007DCE:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08007DD8: .4byte 0x0300137C
	.syntax divided
