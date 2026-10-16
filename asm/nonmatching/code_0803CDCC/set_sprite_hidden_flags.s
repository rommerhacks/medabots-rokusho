	.syntax unified

	thumb_func_start set_sprite_hidden_flags
	.global set_sprite_hidden_flags
set_sprite_hidden_flags: @ 0x08040D44
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x18
	movs r2, #0
	cmp r2, r3
	bhs _08040D6E
	ldr r1, _08040D74 @ =0x03002C30
	movs r5, #0x80
	lsls r5, r5, #8
	adds r4, r5, #0
	lsls r0, r0, #6
	adds r1, r0, r1
_08040D60:
	ldrh r0, [r1]
	orrs r0, r4
	strh r0, [r1]
	adds r1, #0x40
	adds r2, #1
	cmp r2, r3
	blo _08040D60
_08040D6E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08040D74: .4byte 0x03002C30
	.syntax divided
