	.syntax unified

	thumb_func_start sub_08045A8C
sub_08045A8C: @ 0x08045A8C
	push {r4, lr}
	adds r4, r0, #0
	adds r0, r3, #0
	lsls r1, r1, #16
	lsrs r3, r1, #16
	lsls r2, r2, #16
	lsrs r2, r2, #16
	cmp r0, #0
	beq _08045AD4
	cmp r0, #1
	bne _08045ABA
	ldr r1, [r4, #0]
	ldrb r0, [r1, #0]
	adds r0, r0, r3
	lsls r0, r0, #16
	lsrs r3, r0, #16
	ldrh r0, [r1, #2]
	lsls r0, r0, #23
	lsrs r0, r0, #23
	adds r0, r0, r2
	lsls r0, r0, #16
	lsrs r2, r0, #16
	b _08045AD4
_08045ABA:
	ldr r0, [r4, #4]
	lsls r1, r3, #16
	asrs r1, r1, #16
	ldrh r3, [r0, #4]
	adds r1, r1, r3
	lsls r1, r1, #16
	lsrs r3, r1, #16
	lsls r1, r2, #16
	asrs r1, r1, #16
	ldrh r0, [r0, #2]
	adds r1, r1, r0
	lsls r1, r1, #16
	lsrs r2, r1, #16
_08045AD4:
	lsls r1, r3, #16
	asrs r1, r1, #16
	lsls r2, r2, #16
	asrs r2, r2, #16
	movs r0, #8
	ldrsh r3, [r4, r0]
	adds r0, r4, #0
	bl set_oam_sprite_tile_positions
	pop {r4}
	pop {r0}
	bx r0
	.syntax divided
