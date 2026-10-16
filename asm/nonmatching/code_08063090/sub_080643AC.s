	.syntax unified

	thumb_func_start sub_080643AC
sub_080643AC: @ 0x080643AC
	push {lr}
	ldr r2, _080643E4 @ =0x08485BD8
	ldr r0, _080643E8 @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x7a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0x6c
	cmp r0, #0
	beq _080643C4
	movs r1, #0x68
_080643C4:
	adds r0, r1, r2
	ldr r0, [r0]
	bl run_message
	cmp r0, #0
	beq _08064414
	ldr r0, _080643EC @ =0x03001798
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080643F0
	movs r0, #0xd
	bl play_sound_effect
	b _0806440C
	.align 2, 0
_080643E4: .4byte 0x08485BD8
_080643E8: .4byte 0x03006F74
_080643EC: .4byte 0x03001798
_080643F0:
	ldr r2, _08064418 @ =0x03005010
	ldr r0, _0806441C @ =0x03000B90
	ldrb r0, [r0]
	movs r1, #0
	cmp r0, #0
	bne _080643FE
	movs r1, #4
_080643FE:
	adds r0, r2, #0
	adds r0, #0xa
	adds r0, r1, r0
	ldrh r1, [r0]
	ldr r0, _08064420 @ =0x0000FEFF
	cmp r1, r0
	bne _08064414
_0806440C:
	ldr r1, _08064424 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08064414:
	pop {r0}
	bx r0
	.align 2, 0
_08064418: .4byte 0x03005010
_0806441C: .4byte 0x03000B90
_08064420: .4byte 0x0000FEFF
_08064424: .4byte 0x0300137C
	.syntax divided
