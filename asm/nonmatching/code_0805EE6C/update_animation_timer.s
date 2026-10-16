	.syntax unified

	thumb_func_start update_animation_timer
update_animation_timer: @ 0x080604B8
	push {r4, r5, lr}
	ldr r2, _08060510 @ =0x03006F74
	ldr r1, [r2]
	ldrh r0, [r1, #0x3a]
	adds r0, #1
	strh r0, [r1, #0x3a]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x6d
	bls _080604D0
	movs r0, #0
	strh r0, [r1, #0x3a]
_080604D0:
	ldr r0, [r2]
	movs r1, #0x3a
	ldrsh r5, [r0, r1]
	adds r0, r5, #0
	movs r1, #0xa
	bl sub_0807CC88
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0806050A
	ldr r4, _08060514 @ =0x08483E04
	adds r0, r5, #0
	movs r1, #0xa
	bl sub_0807CBBC
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r0, r0, r4
	ldrb r1, [r0]
	adds r1, #1
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #5
	ldr r1, _08060518 @ =0x02030000
	adds r0, r0, r1
	ldr r1, _0806051C @ =0x06004020
	movs r2, #0xf0
	bl CpuSet
_0806050A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08060510: .4byte 0x03006F74
_08060514: .4byte 0x08483E04
_08060518: .4byte 0x02030000
_0806051C: .4byte 0x06004020
	.syntax divided
