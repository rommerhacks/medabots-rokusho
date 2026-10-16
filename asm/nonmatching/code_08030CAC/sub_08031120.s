	.syntax unified

	thumb_func_start sub_08031120
sub_08031120: @ 0x08031120
	push {lr}
	ldr r1, _08031140 @ =0x03001800
	adds r0, r1, #0
	adds r0, #0x57
	ldrb r0, [r0]
	cmp r0, #0
	beq _08031158
	ldr r2, _08031144 @ =0x00000165
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803114C
	ldr r1, _08031148 @ =0x0300137C
	movs r0, #0x60
	b _08031168
	.align 2, 0
_08031140: .4byte 0x03001800
_08031144: .4byte 0x00000165
_08031148: .4byte 0x0300137C
_0803114C:
	ldr r1, _08031154 @ =0x0300137C
	movs r0, #0x4f
	b _08031168
	.align 2, 0
_08031154: .4byte 0x0300137C
_08031158:
	bl sub_0801B53C
	movs r0, #0x11
	bl play_song
	ldr r1, _08031170 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
_08031168:
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08031170: .4byte 0x0300137C
	.syntax divided
