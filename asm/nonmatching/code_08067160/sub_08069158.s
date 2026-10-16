	.syntax unified

	thumb_func_start sub_08069158
sub_08069158: @ 0x08069158
	push {lr}
	bl sub_0806918C
	movs r0, #0
	bl play_song
	ldr r2, _08069184 @ =0x03005310
	ldr r0, _08069188 @ =0x03006F94
	ldrb r0, [r0]
	movs r1, #2
	cmp r0, #1
	bne _08069172
	movs r1, #1
_08069172:
	adds r0, r2, #0
	adds r0, #0x39
	strb r1, [r0]
	movs r0, #0
	bl sub_08047850
	pop {r0}
	bx r0
	.align 2, 0
_08069184: .4byte 0x03005310
_08069188: .4byte 0x03006F94
	.syntax divided
