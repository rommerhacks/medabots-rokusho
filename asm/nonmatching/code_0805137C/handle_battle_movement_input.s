	.syntax unified

	thumb_func_start handle_battle_movement_input
handle_battle_movement_input: @ 0x08051C18
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r3, _08051C58 @ =0x0847E948
	ldr r1, _08051C5C @ =0x030057E0
	ldr r2, _08051C60 @ =0x00000C57
	adds r0, r1, r2
	ldrb r2, [r0]
	movs r5, #0x80
	lsls r5, r5, #4
	adds r0, r1, r5
	ldrh r0, [r0]
	lsrs r0, r0, #1
	ldr r5, _08051C64 @ =0x00000C56
	adds r1, r1, r5
	muls r0, r2, r0
	ldrb r1, [r1]
	adds r0, r0, r1
	adds r0, r0, r3
	ldrb r0, [r0]
	subs r0, #1
	cmp r0, #3
	bhi _08051C50
	ldr r1, _08051C68 @ =0x083D28C3
	lsls r0, r0, #4
	adds r0, r4, r0
	adds r0, r0, r1
	ldrb r4, [r0]
_08051C50:
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08051C58: .4byte 0x0847E948
_08051C5C: .4byte 0x030057E0
_08051C60: .4byte 0x00000C57
_08051C64: .4byte 0x00000C56
_08051C68: .4byte 0x083D28C3
	.syntax divided
