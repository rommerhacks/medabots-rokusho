	.syntax unified

	thumb_func_start sub_0805DA1C
sub_0805DA1C: @ 0x0805DA1C
	push {lr}
	ldr r0, _0805DA50 @ =0x08485788
	ldr r0, [r0, #0x28]
	bl run_message
	cmp r0, #0
	beq _0805DA4A
	movs r0, #0
	bl play_song
	movs r0, #0
	bl play_sound_effect
	bl eeprom_setup_timer_irq
	ldr r0, _0805DA54 @ =0x03006F74
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #2]
	ldr r1, _0805DA58 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0805DA4A:
	pop {r0}
	bx r0
	.align 2, 0
_0805DA50: .4byte 0x08485788
_0805DA54: .4byte 0x03006F74
_0805DA58: .4byte 0x0300137C
	.syntax divided
