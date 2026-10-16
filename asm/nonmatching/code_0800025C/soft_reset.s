	.syntax unified

	thumb_func_start soft_reset
soft_reset: @ 0x080008C0
	push {r4, lr}
	ldr r0, _08000938 @ =0x03005030
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _080008F6
	ldr r0, _0800093C @ =0x03005010
	ldr r1, _08000940 @ =0x0000FFFF
	strh r1, [r0, #4]
	movs r1, #1
	rsbs r1, r1, #0
	strh r1, [r0, #6]
	movs r4, #0
_080008DC:
	ldr r0, _08000944 @ =0x03005014
	bl serial_prepare_send_packet
	bl VBlankIntrWait
	adds r4, #1
	cmp r4, #7
	bls _080008DC
	ldr r1, _08000938 @ =0x03005030
	movs r0, #0
	strb r0, [r1]
	bl serial_multiplayer_init
_080008F6:
	bl VBlankIntrWait
	ldr r1, _08000948 @ =0x04000050
	movs r0, #0xff
	strh r0, [r1]
	adds r1, #4
	movs r0, #0x10
	strh r0, [r1]
	ldr r0, _0800094C @ =0x04000084
	movs r1, #0
	strh r1, [r0]
	ldr r0, _08000950 @ =0x04000208
	strh r1, [r0]
	bl hw_reset_init
	bl irq_init
	bl serial_link_init
	ldr r1, _08000954 @ =0x0300178C
	movs r0, #3
	str r0, [r1]
	ldr r0, _08000958 @ =0x03002B8C
	movs r1, #0
	str r1, [r0]
	ldr r0, _0800095C @ =0x0300137C
	str r1, [r0]
	ldr r0, _08000960 @ =0x040000BA
	strh r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08000938: .4byte 0x03005030
_0800093C: .4byte 0x03005010
_08000940: .4byte 0x0000FFFF
_08000944: .4byte 0x03005014
_08000948: .4byte 0x04000050
_0800094C: .4byte 0x04000084
_08000950: .4byte 0x04000208
_08000954: .4byte 0x0300178C
_08000958: .4byte 0x03002B8C
_0800095C: .4byte 0x0300137C
_08000960: .4byte 0x040000BA
	.syntax divided
