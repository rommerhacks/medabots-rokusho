	.syntax unified

	thumb_func_start sub_0805F8F0
sub_0805F8F0: @ 0x0805F8F0
	push {r4, r5, lr}
	ldr r0, _0805F914 @ =0x03006F74
	ldr r2, [r0]
	ldrh r0, [r2, #2]
	adds r1, r0, #1
	strh r1, [r2, #2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r5, #0
	cmp r0, #0x1d
	bls _0805F966
	movs r0, #4
	bl is_sound_playing_with_lock
	cmp r0, #0
	bne _0805F966
	movs r0, #0
	b _0805F91E
	.align 2, 0
_0805F914: .4byte 0x03006F74
_0805F918:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_0805F91E:
	lsls r0, r0, #0x18
	asrs r4, r0, #0x18
	cmp r4, #3
	bgt _0805F934
	movs r0, #2
	bl save_dispatch
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne _0805F918
_0805F934:
	cmp r5, #0
	bne _0805F954
	bl sub_0803FB0C
	ldr r0, _0805F94C @ =0x03006F74
	ldr r0, [r0]
	strh r5, [r0, #2]
	ldr r1, _0805F950 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _0805F964
	.align 2, 0
_0805F94C: .4byte 0x03006F74
_0805F950: .4byte 0x0300137C
_0805F954:
	bl sub_0803FB0C
	ldr r0, _0805F96C @ =0x03006F74
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #2]
	ldr r1, _0805F970 @ =0x0300137C
	movs r0, #0xc
_0805F964:
	str r0, [r1]
_0805F966:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805F96C: .4byte 0x03006F74
_0805F970: .4byte 0x0300137C
	.syntax divided
