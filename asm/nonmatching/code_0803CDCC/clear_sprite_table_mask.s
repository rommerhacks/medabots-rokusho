	.syntax unified

	thumb_func_start clear_sprite_table_mask
	.global clear_sprite_table_mask
clear_sprite_table_mask: @ 0x08040D0C
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	movs r3, #0
	cmp r3, r4
	bhs _08040D34
	ldr r1, _08040D3C @ =0x03002C30
	ldr r5, _08040D40 @ =0x00007FFF
	lsls r0, r0, #6
	adds r2, r0, r1
_08040D24:
	ldrh r1, [r2]
	adds r0, r5, #0
	ands r0, r1
	strh r0, [r2]
	adds r2, #0x40
	adds r3, #1
	cmp r3, r4
	blo _08040D24
_08040D34:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08040D3C: .4byte 0x03002C30
_08040D40: .4byte 0x00007FFF
	.syntax divided
