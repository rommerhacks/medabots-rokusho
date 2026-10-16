	.syntax unified

	thumb_func_start race_enter_team_select
	.global race_enter_team_select
race_enter_team_select: @ 0x080441B8
	push {r4, r5, lr}
	sub sp, #8
	movs r4, #0
	str r4, [sp]
	ldr r1, _08044210 @ =0x05000200
	ldr r5, _08044214 @ =0x01000080
	mov r0, sp
	adds r2, r5, #0
	bl CpuFastSet
	str r4, [sp, #4]
	add r0, sp, #4
	movs r1, #0xa0
	lsls r1, r1, #0x13
	adds r2, r5, #0
	bl CpuFastSet
	ldr r5, _08044218 @ =0x03000490
	adds r0, r5, #0
	movs r1, #0x14
	movs r2, #0
	bl sub_0803F624
	movs r1, #3
	strb r1, [r5]
	ldr r0, _0804421C @ =0x03001800
	adds r2, r0, #0
	adds r2, #0x41
	strb r4, [r2]
	adds r2, #1
	strb r4, [r2]
	adds r0, #0x43
	strb r4, [r0]
	ldr r0, _08044220 @ =0x0300178C
	str r4, [r0]
	ldr r0, _08044224 @ =0x03002B8C
	str r1, [r0]
	ldr r0, _08044228 @ =0x0300137C
	str r4, [r0]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08044210: .4byte 0x05000200
_08044214: .4byte 0x01000080
_08044218: .4byte 0x03000490
_0804421C: .4byte 0x03001800
_08044220: .4byte 0x0300178C
_08044224: .4byte 0x03002B8C
_08044228: .4byte 0x0300137C
	.syntax divided
