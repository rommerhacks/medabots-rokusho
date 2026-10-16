	.syntax unified

	thumb_func_start sub_0805A258
	.global sub_0805A258
sub_0805A258: @ 0x0805A258
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r5, #0xd
	ldr r0, _0805A2D4 @ =0x03006F74
	ldr r0, [r0]
	ldrh r0, [r0, #0x36]
	adds r0, #0x16
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	lsls r1, r1, #1
	ldr r0, _0805A2D8 @ =0x0600F000
	adds r1, r1, r0
	lsls r2, r2, #6
	adds r4, r1, r2
	adds r0, r6, #0
	movs r1, #0x64
	bl sub_0807CBBC
	movs r1, #0xa
	bl sub_0807CC88
	cmp r0, #0
	beq _0805A28E
	adds r0, r7, r0
	movs r1, #0xd0
	lsls r1, r1, #8
	orrs r0, r1
_0805A28E:
	strh r0, [r4]
	ldrh r0, [r4]
	adds r4, #2
	adds r0, r6, #0
	movs r1, #0x64
	bl sub_0807CBBC
	movs r1, #0xa
	bl sub_0807CC88
	cmp r0, #0
	bne _0805A2B8
	adds r0, r6, #0
	movs r1, #0xa
	bl sub_0807CBBC
	movs r1, #0xa
	bl sub_0807CC88
	cmp r0, #0
	beq _0805A2DC
_0805A2B8:
	adds r0, r6, #0
	movs r1, #0xa
	bl sub_0807CBBC
	movs r1, #0xa
	bl sub_0807CC88
	adds r0, r7, r0
	lsls r1, r5, #0xc
	orrs r0, r1
	strh r0, [r4]
	adds r5, r1, #0
	b _0805A2E0
	.align 2, 0
_0805A2D4: .4byte 0x03006F74
_0805A2D8: .4byte 0x0600F000
_0805A2DC:
	strh r0, [r4]
	lsls r5, r5, #0xc
_0805A2E0:
	ldrh r0, [r4]
	adds r4, #2
	adds r0, r6, #0
	movs r1, #0xa
	bl sub_0807CC88
	adds r0, r7, r0
	orrs r0, r5
	strh r0, [r4]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
