	.syntax unified

	thumb_func_start sub_0800B468
sub_0800B468: @ 0x0800B468
	push {lr}
	ldr r0, _0800B494 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x30
	ands r0, r1
	cmp r0, #0
	beq _0800B48E
	bl sub_08009EA0
	bl sub_08009EF4
	bl sub_08009F50
	bl sub_08009FC8
	bl render_medal_skill_stats
	bl draw_medal_skill_bars
_0800B48E:
	pop {r0}
	bx r0
	.align 2, 0
_0800B494: .4byte 0x03001798
	.syntax divided
