	.syntax unified

	thumb_func_start load_encounter_into_battle_setup
	.global load_encounter_into_battle_setup
load_encounter_into_battle_setup: @ 0x08011DB0
	push {lr}
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	ldr r1, _08011DD8 @ =0x040000D4
	mov r0, sp
	str r0, [r1]
	ldr r0, _08011DDC @ =0x03001800
	str r0, [r1, #4]
	ldr r0, _08011DE0 @ =0x85000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl sub_08011DE4
	bl setup_random_encounter_enemies
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_08011DD8: .4byte 0x040000D4
_08011DDC: .4byte 0x03001800
_08011DE0: .4byte 0x85000100
	.syntax divided
