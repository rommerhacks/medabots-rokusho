	.syntax unified

	thumb_func_start sub_08021F90
sub_08021F90: @ 0x08021F90
	push {lr}
	ldr r0, _08021FAC @ =0x03001800
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08021FB8
	ldr r0, _08021FB0 @ =0x03002C30
	ldr r1, _08021FB4 @ =0x00000858
	adds r0, r0, r1
	ldrh r1, [r0]
	subs r1, #0x40
	b _08021FC2
	.align 2, 0
_08021FAC: .4byte 0x03001800
_08021FB0: .4byte 0x03002C30
_08021FB4: .4byte 0x00000858
_08021FB8:
	ldr r0, _08021FFC @ =0x03002C30
	ldr r1, _08022000 @ =0x00000858
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #0x40
_08021FC2:
	ldr r3, _08022004 @ =0x000003FF
	adds r2, r3, #0
	ands r1, r2
	strh r1, [r0]
	movs r0, #0x21
	bl move_sprite_toward_target
	cmp r0, #0
	beq _08021FF6
	ldr r1, _08021FFC @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r3, r1, r0
	ldrh r2, [r3]
	ldr r0, _08022008 @ =0x0000FDFF
	ands r0, r2
	movs r2, #0
	strh r0, [r3]
	ldr r3, _08022000 @ =0x00000858
	adds r1, r1, r3
	strh r2, [r1]
	ldr r1, _0802200C @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08021FF6:
	pop {r0}
	bx r0
	.align 2, 0
_08021FFC: .4byte 0x03002C30
_08022000: .4byte 0x00000858
_08022004: .4byte 0x000003FF
_08022008: .4byte 0x0000FDFF
_0802200C: .4byte 0x03001800
	.syntax divided
