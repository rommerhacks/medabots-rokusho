	.syntax unified

	thumb_func_start find_next_free_sprite_slot
	.global find_next_free_sprite_slot
find_next_free_sprite_slot: @ 0x08040D78
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r3, #0
	cmp r3, r1
	bhs _08040DAE
	ldr r5, _08040DA0 @ =0x03002C30
_08040D8A:
	adds r2, r4, r3
	cmp r2, #0x80
	beq _08040DAE
	lsls r0, r2, #6
	adds r0, r0, r5
	ldrh r0, [r0]
	cmp r0, #0
	bne _08040DA4
	adds r0, r2, #0
	b _08040DB0
	.align 2, 0
_08040DA0: .4byte 0x03002C30
_08040DA4:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, r1
	blo _08040D8A
_08040DAE:
	adds r0, r4, #0
_08040DB0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
