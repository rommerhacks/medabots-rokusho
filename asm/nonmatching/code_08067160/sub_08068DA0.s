	.syntax unified

	thumb_func_start sub_08068DA0
sub_08068DA0: @ 0x08068DA0
	push {lr}
	ldr r1, _08068DB8 @ =0x04000050
	movs r0, #0xff
	strh r0, [r1]
	adds r1, #4
	movs r0, #0xf
	strh r0, [r1]
	bl race_enter_team_select
	pop {r0}
	bx r0
	.align 2, 0
_08068DB8: .4byte 0x04000050
	.syntax divided
