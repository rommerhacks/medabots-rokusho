	.syntax unified

	thumb_func_start sub_0802BAAC
sub_0802BAAC: @ 0x0802BAAC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r7, #0
	movs r4, #0
	ldr r0, _0802BB10 @ =0x030018D2
	mov sb, r0
	ldr r1, _0802BB14 @ =0x083B6120
	mov r8, r1
	ldr r0, _0802BB18 @ =0x03002C30
	ldr r1, _0802BB1C @ =0x00000862
	adds r6, r0, r1
	movs r5, #0x84
	lsls r5, r5, #0x16
_0802BACA:
	mov r1, sb
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802BAE6
	mov r1, r8
	ldr r0, [r1]
	lsrs r1, r5, #0x18
	bl process_sprite_anim_commands
	ldrb r0, [r6]
	cmp r0, #0xff
	bne _0802BAE6
	movs r7, #1
_0802BAE6:
	adds r6, #0x40
	movs r0, #0x80
	lsls r0, r0, #0x11
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #2
	bls _0802BACA
	cmp r7, #0
	beq _0802BB02
	ldr r1, _0802BB20 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802BB02:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802BB10: .4byte 0x030018D2
_0802BB14: .4byte 0x083B6120
_0802BB18: .4byte 0x03002C30
_0802BB1C: .4byte 0x00000862
_0802BB20: .4byte 0x03001800
	.syntax divided
