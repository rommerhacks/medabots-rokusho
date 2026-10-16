	.syntax unified

	thumb_func_start sub_0801013C
sub_0801013C: @ 0x0801013C
	push {r4, lr}
	ldr r1, _0801015C @ =0x083ACC94
	ldr r0, _08010160 @ =0x03002C30
	ldr r2, _08010164 @ =0x00000129
	adds r4, r0, r2
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	ldrb r0, [r4]
	cmp r0, #3
	beq _08010168
	movs r0, #0
	b _0801016A
	.align 2, 0
_0801015C: .4byte 0x083ACC94
_08010160: .4byte 0x03002C30
_08010164: .4byte 0x00000129
_08010168:
	movs r0, #1
_0801016A:
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
