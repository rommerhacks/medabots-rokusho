	.syntax unified

	thumb_func_start sub_08060118
sub_08060118: @ 0x08060118
	push {lr}
	ldr r1, _08060144 @ =0x08483CC4
	ldr r0, _08060148 @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, _0806014C @ =0x03001780
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0806013E
	ldr r1, _08060150 @ =0x03001C04
	ldrh r0, [r1, #2]
	subs r0, #1
	strh r0, [r1, #2]
_0806013E:
	pop {r0}
	bx r0
	.align 2, 0
_08060144: .4byte 0x08483CC4
_08060148: .4byte 0x0300137C
_0806014C: .4byte 0x03001780
_08060150: .4byte 0x03001C04
	.syntax divided
