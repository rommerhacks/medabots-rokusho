	.syntax unified

	thumb_func_start set_sprite_animation_state
	.global set_sprite_animation_state
set_sprite_animation_state: @ 0x08052D44
	push {r4, lr}
	lsls r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
	adds r4, r2, #0
	ldr r1, _08052D6C @ =0x03002C30
	lsrs r0, r0, #0x12
	adds r3, r0, r1
	adds r0, r3, #0
	adds r0, #0x20
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	cmp r2, #1
	beq _08052D88
	cmp r2, #1
	bgt _08052D70
	cmp r2, #0
	beq _08052D7A
	b _08052DB8
	.align 2, 0
_08052D6C: .4byte 0x03002C30
_08052D70:
	cmp r4, #2
	beq _08052D98
	cmp r4, #3
	beq _08052DA8
	b _08052DB8
_08052D7A:
	adds r0, r3, #0
	adds r0, #0x2b
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	b _08052DB6
_08052D88:
	adds r0, r3, #0
	adds r0, #0x2b
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, #3
	b _08052DB6
_08052D98:
	adds r0, r3, #0
	adds r0, #0x2b
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, #6
	b _08052DB6
_08052DA8:
	adds r0, r3, #0
	adds r0, #0x2b
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, #9
_08052DB6:
	strh r0, [r3, #6]
_08052DB8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
