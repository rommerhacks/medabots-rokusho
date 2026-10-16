	.syntax unified

	thumb_func_start sub_0807118C
sub_0807118C: @ 0x0807118C
	push {r4, r5, lr}
	sub sp, #4
	ldr r4, _080711A8 @ =0x03001800
	ldr r0, [r4, #8]
	adds r5, r4, #0
	cmp r0, #0x19
	bls _0807119C
	b _080712C4
_0807119C:
	lsls r0, r0, #2
	ldr r1, _080711AC @ =_080711B0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080711A8: .4byte 0x03001800
_080711AC: .4byte _080711B0
_080711B0: @ jump table
	.4byte _08071218 @ case 0
	.4byte _0807122A @ case 1
	.4byte _0807126A @ case 2
	.4byte _080712AC @ case 3
	.4byte _08071224 @ case 4
	.4byte _0807122A @ case 5
	.4byte _0807126A @ case 6
	.4byte _080712AC @ case 7
	.4byte _08071224 @ case 8
	.4byte _0807122A @ case 9
	.4byte _0807126A @ case 10
	.4byte _080712AC @ case 11
	.4byte _08071224 @ case 12
	.4byte _0807122A @ case 13
	.4byte _0807126A @ case 14
	.4byte _080712AC @ case 15
	.4byte _08071224 @ case 16
	.4byte _0807122A @ case 17
	.4byte _0807126A @ case 18
	.4byte _080712AC @ case 19
	.4byte _08071224 @ case 20
	.4byte _0807122A @ case 21
	.4byte _08071278 @ case 22
	.4byte _080712AC @ case 23
	.4byte _08071224 @ case 24
	.4byte _08071254 @ case 25
_08071218:
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl text_window_init
	b _080712B4
_08071224:
	bl sub_0803FB0C
	b _080712B4
_0807122A:
	ldr r1, _0807124C @ =0x084872DC
	ldr r0, [r5, #8]
	asrs r0, r0, #2
	adds r0, #8
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl run_message
	cmp r0, #0
	beq _080712DC
	bl sub_0803FB0C
	ldr r0, _08071250 @ =0x08486114
	bl run_message
	b _0807126A
	.align 2, 0
_0807124C: .4byte 0x084872DC
_08071250: .4byte 0x08486114
_08071254:
	ldr r1, _08071274 @ =0x084872DC
	ldr r0, [r5, #8]
	asrs r0, r0, #2
	adds r0, #8
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl run_message
	cmp r0, #0
	beq _080712DC
_0807126A:
	ldr r0, [r5, #8]
	adds r0, #1
	str r0, [r5, #8]
	b _080712DC
	.align 2, 0
_08071274: .4byte 0x084872DC
_08071278:
	movs r1, #0xc8
	lsls r1, r1, #8
	ldr r2, _080712A0 @ =0x0000050F
	movs r0, #3
	str r0, [sp]
	movs r0, #0
	movs r3, #0
	bl init_battle_sprite_entry_08048818
	ldr r1, _080712A4 @ =0x03002C30
	movs r2, #0
	movs r0, #0x42
	strh r0, [r1, #2]
	ldr r0, _080712A8 @ =0x0000FFF8
	strh r0, [r1, #4]
	movs r0, #0x40
	strb r0, [r1, #0xb]
	strh r2, [r1, #0x1a]
	b _080712B4
	.align 2, 0
_080712A0: .4byte 0x0000050F
_080712A4: .4byte 0x03002C30
_080712A8: .4byte 0x0000FFF8
_080712AC:
	bl call_battle_handler_by_state_08071C64
	cmp r0, #0
	beq _080712DC
_080712B4:
	ldr r1, _080712C0 @ =0x03001800
	ldr r0, [r1, #8]
	adds r0, #1
	str r0, [r1, #8]
	b _080712DC
	.align 2, 0
_080712C0: .4byte 0x03001800
_080712C4:
	movs r0, #4
	movs r1, #2
	movs r2, #0
	bl setup_screen_transition_effect_080684F0
	movs r0, #0
	str r0, [r4, #8]
	movs r0, #0xe
	strh r0, [r4, #4]
	ldr r1, _080712E4 @ =0x0300137C
	movs r0, #2
	str r0, [r1]
_080712DC:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080712E4: .4byte 0x0300137C
	.syntax divided
