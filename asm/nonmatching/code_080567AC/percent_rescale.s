	.syntax unified

	thumb_func_start percent_rescale
	.global percent_rescale
percent_rescale: @ 0x0805A2F8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	mov sb, r1
	mov sl, r2
	movs r1, #0x64
	bl sub_0807CC88
	adds r6, r0, #0
	ldr r0, _0805A36C @ =0x03006F74
	ldr r0, [r0]
	ldrh r4, [r0, #0x36]
	mov r1, sb
	lsls r0, r1, #1
	ldr r2, _0805A370 @ =0x0600F000
	adds r0, r0, r2
	mov r2, sl
	lsls r1, r2, #6
	adds r5, r0, r1
	adds r0, r6, #0
	movs r1, #0x64
	bl sub_0807CBBC
	movs r1, #0xa
	bl sub_0807CC88
	cmp r0, #0
	bne _0805A348
	adds r0, r6, #0
	movs r1, #0xa
	bl sub_0807CBBC
	movs r1, #0xa
	bl sub_0807CC88
	cmp r0, #0
	beq _0805A374
_0805A348:
	adds r0, r6, #0
	movs r1, #0xa
	bl sub_0807CBBC
	movs r1, #0xa
	bl sub_0807CC88
	lsls r2, r4, #0x10
	asrs r1, r2, #0x10
	adds r1, #1
	adds r0, r0, r1
	movs r1, #0xc0
	lsls r1, r1, #8
	orrs r0, r1
	strh r0, [r5]
	adds r7, r2, #0
	b _0805A378
	.align 2, 0
_0805A36C: .4byte 0x03006F74
_0805A370: .4byte 0x0600F000
_0805A374:
	strh r0, [r5]
	lsls r7, r4, #0x10
_0805A378:
	ldrh r0, [r5]
	adds r5, #2
	adds r0, r6, #0
	movs r1, #0xa
	bl sub_0807CC88
	asrs r1, r7, #0x10
	mov r8, r1
	adds r1, #1
	adds r0, r0, r1
	movs r4, #0xc
	lsls r4, r4, #0xc
	orrs r0, r4
	strh r0, [r5]
	movs r1, #0x1e
	lsls r1, r1, #0xb
	mov r2, sb
	lsls r0, r2, #1
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r0, r0, r2
	adds r1, r1, r0
	mov r0, sl
	adds r0, #1
	lsls r0, r0, #6
	adds r5, r1, r0
	adds r0, r6, #0
	movs r1, #0x64
	bl sub_0807CBBC
	movs r1, #0xa
	bl sub_0807CC88
	cmp r0, #0
	bne _0805A3D0
	adds r0, r6, #0
	movs r1, #0xa
	bl sub_0807CBBC
	movs r1, #0xa
	bl sub_0807CC88
	cmp r0, #0
	beq _0805A3E6
_0805A3D0:
	adds r0, r6, #0
	movs r1, #0xa
	bl sub_0807CBBC
	movs r1, #0xa
	bl sub_0807CC88
	mov r1, r8
	adds r1, #0xb
	adds r0, r0, r1
	orrs r0, r4
_0805A3E6:
	strh r0, [r5]
	ldrh r0, [r5]
	adds r5, #2
	adds r0, r6, #0
	movs r1, #0xa
	bl sub_0807CC88
	asrs r1, r7, #0x10
	adds r1, #0xb
	adds r0, r0, r1
	orrs r0, r4
	strh r0, [r5]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
