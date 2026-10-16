	.syntax unified

	thumb_func_start sub_08063D90
sub_08063D90: @ 0x08063D90
	push {r4, lr}
	ldr r4, _08063DD0 @ =0x03006F74
	ldr r0, [r4]
	adds r0, #0x7a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08063DAA
	ldr r0, _08063DD4 @ =0x08485BD8
	ldr r0, [r0, #0x60]
	bl run_message
_08063DAA:
	ldr r0, _08063DD8 @ =0x03000B90
	ldrb r0, [r0]
	movs r1, #0
	ldr r2, _08063DDC @ =0x03005010
	cmp r0, #0
	bne _08063DB8
	movs r1, #4
_08063DB8:
	adds r0, r2, #0
	adds r0, #0xa
	adds r0, r1, r0
	ldrh r1, [r0]
	ldr r0, _08063DE0 @ =0x0000FEDF
	cmp r1, r0
	bne _08063DE8
	ldr r1, _08063DE4 @ =0x03002B8C
	movs r0, #0x1a
	str r0, [r1]
	b _08063E2C
	.align 2, 0
_08063DD0: .4byte 0x03006F74
_08063DD4: .4byte 0x08485BD8
_08063DD8: .4byte 0x03000B90
_08063DDC: .4byte 0x03005010
_08063DE0: .4byte 0x0000FEDF
_08063DE4: .4byte 0x03002B8C
_08063DE8:
	ldrh r1, [r2, #0xa]
	ldr r0, _08063E20 @ =0x0000FDEF
	cmp r1, r0
	bne _08063E28
	ldrh r0, [r2, #0xe]
	cmp r0, r1
	bne _08063E28
	ldr r1, _08063E24 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, [r4]
	adds r0, #0x48
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, #0x7a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08063E2C
	movs r0, #1
	movs r2, #1
	bl text_window_init
	b _08063E2C
	.align 2, 0
_08063E20: .4byte 0x0000FDEF
_08063E24: .4byte 0x0300137C
_08063E28:
	ldr r0, _08063E34 @ =0x0000FDEF
	strh r0, [r2, #6]
_08063E2C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08063E34: .4byte 0x0000FDEF
	.syntax divided
