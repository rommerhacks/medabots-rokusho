	.syntax unified

	thumb_func_start init_battle_medapart_sprites_all
	.global init_battle_medapart_sprites_all
init_battle_medapart_sprites_all: @ 0x08050670
	push {r4, r5, lr}
	movs r4, #0
_08050674:
	ldr r1, _080506B4 @ =0x030057E0
	lsls r0, r4, #2
	adds r3, r0, r1
	ldr r1, _080506B8 @ =0x000007DE
	adds r0, r3, r1
	ldrb r1, [r0]
	lsrs r0, r1, #7
	cmp r0, #0
	beq _080506A6
	lsls r0, r1, #0x19
	cmp r0, #0
	blt _080506A6
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _080506BC @ =0x000007DF
	adds r1, r3, r2
	ldrb r1, [r1]
	ldr r5, _080506C0 @ =0x000007DC
	adds r2, r3, r5
	ldrb r2, [r2]
	adds r5, #1
	adds r3, r3, r5
	ldrb r3, [r3]
	bl init_battle_medapart_sprite
_080506A6:
	adds r4, #1
	cmp r4, #5
	ble _08050674
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080506B4: .4byte 0x030057E0
_080506B8: .4byte 0x000007DE
_080506BC: .4byte 0x000007DF
_080506C0: .4byte 0x000007DC
	.syntax divided
