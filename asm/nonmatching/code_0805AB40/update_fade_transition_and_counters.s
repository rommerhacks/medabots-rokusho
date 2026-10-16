	.syntax unified

	thumb_func_start update_fade_transition_and_counters
update_fade_transition_and_counters: @ 0x0805C9E8
	push {lr}
	ldr r1, _0805CA18 @ =0x08483BA0
	ldr r0, _0805CA1C @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, _0805CA20 @ =0x03001780
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0805CA14
	ldr r0, _0805CA24 @ =0x03001C04
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	ldrh r1, [r0, #2]
	adds r1, #1
	strh r1, [r0, #2]
_0805CA14:
	pop {r0}
	bx r0
	.align 2, 0
_0805CA18: .4byte 0x08483BA0
_0805CA1C: .4byte 0x0300137C
_0805CA20: .4byte 0x03001780
_0805CA24: .4byte 0x03001C04
	.syntax divided
