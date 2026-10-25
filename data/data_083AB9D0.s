	.section .rodata

	.global gData_083AB9D0
gData_083AB9D0:

	.global gUnk_083AB9D0
gUnk_083AB9D0:
	.incbin "baserom.gba", 0x3AB9D0, 0x92

	.global gUnk_083ABA62
gUnk_083ABA62:
	.incbin "baserom.gba", 0x3ABA62, 0x10

	.global gSoundOutputMasks
gSoundOutputMasks:
	.incbin "baserom.gba", 0x3ABA72, 0x4

	.global gSoundOutputBits
gSoundOutputBits:
	.incbin "baserom.gba", 0x3ABA76, 0x12

	.global gUnk_083ABA88
gUnk_083ABA88:
	.incbin "baserom.gba", 0x3ABA88, 0x4

	.global gUnk_083ABA8C
gUnk_083ABA8C:
	.incbin "baserom.gba", 0x3ABA8C, 0x20

	.global gSoundFifoResetBits
gSoundFifoResetBits:
	.incbin "baserom.gba", 0x3ABAAC, 0x2

	.global gSoundFifoEnableBits
gSoundFifoEnableBits:
	.incbin "baserom.gba", 0x3ABAAE, 0x4

	.global gUnk_083ABAB2
gUnk_083ABAB2:
	.incbin "baserom.gba", 0x3ABAB2, 0x10

	.global gUnk_083ABAC2
gUnk_083ABAC2:
	.incbin "baserom.gba", 0x3ABAC2, 0x4

	.global gSoundSemitoneRatios
gSoundSemitoneRatios:
	.incbin "baserom.gba", 0x3ABAC6, 0x18

	.global gSoundFinetuneRatios
gSoundFinetuneRatios:
	.incbin "baserom.gba", 0x3ABADE, 0x102

	.global gSoundTrackConfigs
gSoundTrackConfigs:
	.4byte sub_08074548
	.4byte sub_08072E7C
	.incbin "baserom.gba", 0x3ABBE8, 0x4
	.4byte process_tone_channel_if_idle
	.4byte sub_08072E7C
	.incbin "baserom.gba", 0x3ABBF4, 0x4
	.4byte sub_0807458C
	.4byte sub_08072E7C
	.incbin "baserom.gba", 0x3ABC00, 0x4
	.4byte sound_tick_channel_3a
	.4byte sub_08072E98
	.incbin "baserom.gba", 0x3ABC0C, 0x4
	.4byte sound_update_channel1_with_fallback
	.4byte sub_08072E7C
	.incbin "baserom.gba", 0x3ABC18, 0x4
	.4byte sound_update_channel2_with_fallback
	.4byte sub_08072E7C
	.incbin "baserom.gba", 0x3ABC24, 0x4
	.4byte update_wave_channels_pair
	.4byte sub_08072E7C
	.incbin "baserom.gba", 0x3ABC30, 0x4
	.4byte sound_update_wave_channels
	.4byte sub_08072E98
	.incbin "baserom.gba", 0x3ABC3C, 0x4
	.4byte reset_sound_channel_if_idle
	.4byte sub_08072ECC
	.incbin "baserom.gba", 0x3ABC48, 0x4
	.4byte sound_update_channel_finish
	.4byte sub_08072ECC
	.incbin "baserom.gba", 0x3ABC54, 0x4
	.4byte reset_sound_channel_at_690
	.4byte sub_08072ECC
	.incbin "baserom.gba", 0x3ABC60, 0x4
	.4byte sound_reset_channel_9_and_stop_12
	.4byte sub_08072ECC
	.incbin "baserom.gba", 0x3ABC6C, 0x4
	.4byte sound_tick_channel_3c
	.4byte sub_08072E98
	.incbin "baserom.gba", 0x3ABC78, 0x4

	.global gSoundEffectTracks
gSoundEffectTracks:
	.incbin "baserom.gba", 0x3ABC7C, 0x24

	.global gUnk_083ABCA0
gUnk_083ABCA0:
	.incbin "baserom.gba", 0x3ABCA0, 0xC

	.global gUnk_083ABCAC
gUnk_083ABCAC:
	.incbin "baserom.gba", 0x3ABCAC, 0xC

	.global gUnk_083ABCB8
gUnk_083ABCB8:
	.incbin "baserom.gba", 0x3ABCB8, 0x24
	.4byte sub_0807C784
	.incbin "baserom.gba", 0x3ABCE0, 0x138

	.global gUnk_083ABE18
gUnk_083ABE18:
	.4byte dispatch_game_state_handler_08002534
	.4byte sub_0804763C
	.4byte dispatch_game_state_handler_0805BA94
	.4byte dispatch_game_mode_handler
	.incbin "baserom.gba", 0x3ABE28, 0x8

	.global gUnk_083ABE30
gUnk_083ABE30:
	.incbin "baserom.gba", 0x3ABE30, 0x258

	.global gUnk_083AC088
gUnk_083AC088:
	.incbin "baserom.gba", 0x3AC088, 0x40

	.global gUnk_083AC0C8
gUnk_083AC0C8:
	.incbin "baserom.gba", 0x3AC0C8, 0x40

	.global gUnk_083AC108
gUnk_083AC108:
	.incbin "baserom.gba", 0x3AC108, 0x40

	.global gGameStateHandlers_083AC148
gGameStateHandlers_083AC148:
	.4byte dispatch_game_substate_handler_08002554
	.4byte field_menu_update
	.4byte medawatch_menu_update
	.4byte medabots_screen_update
	.4byte medals_screen_update
	.4byte medaparts_screen_update
	.4byte prebattle_screen_update
	.4byte robattle_update
	.4byte battle_action_state_update
	.4byte battle_run_action_script
	.4byte sub_0803D538
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte debug_menu_update

	.global gUnk_083AC248
gUnk_083AC248:
	.4byte sub_08002574
	.4byte sub_080025B4
	.4byte load_overworld_column_and_advance
	.4byte init_save_prompt_text
	.4byte sub_08002730
	.4byte sub_0800275C
	.4byte sub_0800277C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gFieldMenuHandlers
gFieldMenuHandlers:
	.4byte field_menu_load_gfx
	.4byte field_menu_open_anim
	.4byte field_menu_handle_input
	.4byte field_menu_close_anim
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte field_menu_select_start
	.4byte field_menu_select_collapse
	.4byte field_menu_select_slide
	.4byte field_menu_run_choice
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte field_menu_return_init
	.4byte field_menu_return_slide
	.4byte field_menu_return_expand
	.4byte nullsub_08000840

	.global gMedawatchMenuHandlers
gMedawatchMenuHandlers:
	.4byte medawatch_menu_load_gfx
	.4byte medawatch_menu_fade_in
	.4byte medawatch_menu_handle_input
	.4byte medawatch_menu_exit_start
	.4byte medawatch_menu_exit_fade
	.4byte medawatch_menu_return_to_field_menu
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte medawatch_menu_select_fade
	.4byte medawatch_menu_run_choice
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte medawatch_menu_return_init
	.4byte medawatch_menu_return_fade
	.4byte medawatch_menu_return_done

	.global gMedabotsScreenHandlers
gMedabotsScreenHandlers:
	.4byte medabots_screen_load_gfx
	.4byte medabots_screen_fade_in
	.4byte medabots_screen_handle_input
	.4byte medabots_screen_exit_start
	.4byte medabots_screen_exit_fade
	.4byte medabots_screen_return_to_medawatch
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_08003F28
	.4byte sub_08003F74
	.4byte nullsub_08000840
	.4byte sub_08003FE8
	.4byte sub_08004028
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte medabot_detail_load_gfx
	.4byte medabot_detail_fade_in
	.4byte medabot_detail_handle_input
	.4byte medabot_detail_exit_start
	.4byte medabot_detail_exit_fade
	.4byte medabot_detail_return_to_list
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte medabot_detail_open_info_start
	.4byte medabot_detail_open_info_fade
	.4byte medabot_detail_open_info
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_08004764
	.4byte sub_08004798
	.4byte sub_080047EC
	.4byte team_select_exit_battle
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_08004764
	.4byte sub_08004874
	.4byte sub_080048B0
	.4byte team_select_exit_race
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_080049C8
	.4byte sub_080049EC
	.4byte sub_08004A18
	.4byte sub_08004A40
	.4byte sub_08004A78
	.4byte sub_08004AF8
	.4byte sub_08004C58
	.4byte sub_08004A40
	.4byte sub_08004C58
	.4byte sub_08004CA4
	.4byte sub_08004DB4
	.4byte sub_08004DF0
	.4byte sub_08004E40
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AC420
gUnk_083AC420:
	.incbin "baserom.gba", 0x3AC420, 0x12

	.global gUnk_083AC432
gUnk_083AC432:
	.incbin "baserom.gba", 0x3AC432, 0x9

	.global gUnk_083AC43B
gUnk_083AC43B:
	.incbin "baserom.gba", 0x3AC43B, 0x12

	.global gUnk_083AC44D
gUnk_083AC44D:
	.incbin "baserom.gba", 0x3AC44D, 0x1B

	.global gUnk_083AC468
gUnk_083AC468:
	.incbin "baserom.gba", 0x3AC468, 0x1C

	.global gMedabotSlotDpadMoves
gMedabotSlotDpadMoves:
	.incbin "baserom.gba", 0x3AC484, 0x10

	.global gUnk_083AC494
gUnk_083AC494:
	.incbin "baserom.gba", 0x3AC494, 0x258

	.global gMedalsScreenHandlers
gMedalsScreenHandlers:
	.4byte medals_list_load_gfx
	.4byte medals_list_fade_in
	.4byte medals_list_handle_input
	.4byte medals_list_start_fade_out
	.4byte medals_list_wait_fade
	.4byte medals_list_exit
	.4byte nullsub_08000840
	.4byte medals_list_wait_fade
	.4byte medal_ability_load_gfx
	.4byte medal_page_wait_fade
	.4byte medal_page_open_text_window
	.4byte medal_ability_show_hint
	.4byte medal_ability_handle_input
	.4byte medal_page_start_fade_out
	.4byte medal_page_wait_fade
	.4byte medal_page_exit
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte medal_page_start_fade_out
	.4byte medal_page_wait_fade
	.4byte medal_page_switch
	.4byte nullsub_08000840
	.4byte medal_medaforce_load_gfx
	.4byte medal_medaforce_wait_fade
	.4byte medal_medaforce_open_text_window
	.4byte medal_medaforce_show_message
	.4byte medal_medaforce_handle_input
	.4byte medal_medaforce_show_message_back
	.4byte medal_medaforce_start_fade_out
	.4byte medal_medaforce_wait_fade
	.4byte medal_page_exit
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte medal_medaforce_start_fade_out
	.4byte medal_medaforce_wait_fade
	.4byte medal_page_switch
	.4byte nullsub_08000840
	.4byte medal_rotation_load_gfx
	.4byte medal_rotation_wait_fade
	.4byte medal_rotation_open_text_window
	.4byte medal_rotation_show_hint
	.4byte medal_rotation_handle_input
	.4byte medal_rotation_start_fade_out
	.4byte medal_rotation_wait_fade
	.4byte medal_page_exit
	.4byte medal_rotation_edit_init
	.4byte medal_rotation_edit_show_message
	.4byte medal_rotation_edit_input
	.4byte nullsub_08000840
	.4byte medal_rotation_start_fade_out
	.4byte medal_rotation_wait_fade
	.4byte medal_page_switch
	.4byte nullsub_08000840
	.4byte medal_skill_load_gfx
	.4byte medal_skill_wait_fade
	.4byte medal_skill_handle_input
	.4byte medal_skill_start_fade_out
	.4byte medal_skill_wait_fade
	.4byte medal_page_exit
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_08008A5C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte medal_skill_start_fade_out
	.4byte medal_skill_wait_fade
	.4byte medal_page_switch
	.4byte nullsub_08000840
	.4byte medals_help_load
	.4byte medals_help_show_intro
	.4byte medals_help_cursor_input
	.4byte medals_help_show_text
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte medals_help_exit
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_08009174
	.4byte sub_080091E0
	.4byte sub_08009248
	.4byte sub_08009274
	.4byte sub_080092D4
	.4byte sub_08009374
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte medals_list_start_fade_out
	.4byte medals_list_wait_fade
	.4byte sub_080093AC
	.4byte sub_080093E0
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AC8AC
gUnk_083AC8AC:
	.incbin "baserom.gba", 0x3AC8AC, 0x20

	.global gUnk_083AC8CC
gUnk_083AC8CC:
	.4byte update_sprite_blink_animation
	.4byte update_battle_sprite_scroll
	.4byte fill_bg0_rect_and_advance_sprite_state
	.4byte nullsub_08000840

	.global gDebugMenuHandlers
gDebugMenuHandlers:
	.4byte debug_menu_init
	.4byte debug_menu_select_input
	.4byte debug_menu_exit
	.4byte debug_menu_run_entry
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gDebugMenuEntryHandlers
gDebugMenuEntryHandlers:
	.4byte debug_process_update
	.4byte debug_medal_update
	.4byte debug_parts_update
	.4byte debug_tinpet_update
	.4byte debug_item_update
	.4byte debug_face_update
	.4byte debug_mdlpic_update
	.4byte debug_rndtk_update
	.4byte debug_battle_update
	.4byte debug_sound_update
	.4byte debug_motion_update
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gDebugProcessHandlers
gDebugProcessHandlers:
	.4byte debug_process_input
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gDebugMedalHandlers
gDebugMedalHandlers:
	.4byte debug_medal_input
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gDebugPartsHandlers
gDebugPartsHandlers:
	.4byte debug_parts_input
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gDebugTinpetHandlers
gDebugTinpetHandlers:
	.4byte debug_tinpet_input
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gDebugItemHandlers
gDebugItemHandlers:
	.4byte debug_item_input
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gDebugFaceHandlers
gDebugFaceHandlers:
	.4byte debug_face_input
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gDebugMdlpicHandlers
gDebugMdlpicHandlers:
	.4byte debug_mdlpic_input
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gDebugRndTkHandlers
gDebugRndTkHandlers:
	.4byte debug_rndtk_input
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gDebugBattleHandlers
gDebugBattleHandlers:
	.4byte debug_battle_input
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gDebugSoundHandlers
gDebugSoundHandlers:
	.4byte debug_sound_input
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gDebugMotionHandlers
gDebugMotionHandlers:
	.4byte debug_motion_init
	.4byte debug_motion_load
	.4byte debug_motion_input
	.4byte debug_motion_play
	.incbin "baserom.gba", 0x3AC9C8, 0x58

	.global gDebugMenuLabels
gDebugMenuLabels:
	.incbin "baserom.gba", 0x3ACA20, 0x44

	.global gDebugProcessLabels
gDebugProcessLabels:
	.incbin "baserom.gba", 0x3ACA64, 0x24

	.global gDebugMedalLabels
gDebugMedalLabels:
	.incbin "baserom.gba", 0x3ACA88, 0x24

	.global gDebugPartsLabels
gDebugPartsLabels:
	.incbin "baserom.gba", 0x3ACAAC, 0x14

	.global gDebugTinpetLabels
gDebugTinpetLabels:
	.incbin "baserom.gba", 0x3ACAC0, 0x1C

	.global gDebugItemLabels
gDebugItemLabels:
	.incbin "baserom.gba", 0x3ACADC, 0x1C

	.global gDebugFaceLabels
gDebugFaceLabels:
	.incbin "baserom.gba", 0x3ACAF8, 0x18

	.global gDebugMdlpicLabels
gDebugMdlpicLabels:
	.incbin "baserom.gba", 0x3ACB10, 0x10

	.global gDebugRndTkLabels
gDebugRndTkLabels:
	.incbin "baserom.gba", 0x3ACB20, 0xC

	.global gDebugBattleLabels
gDebugBattleLabels:
	.incbin "baserom.gba", 0x3ACB2C, 0x14

	.global gDebugSoundLabels
gDebugSoundLabels:
	.incbin "baserom.gba", 0x3ACB40, 0x10

	.global gDebugMotionLabels
gDebugMotionLabels:
	.incbin "baserom.gba", 0x3ACB50, 0x4

	.global gMedapartsScreenHandlers
gMedapartsScreenHandlers:
	.4byte medaparts_list_load_gfx
	.4byte medaparts_list_fade_in
	.4byte medaparts_list_open_text_window
	.4byte medaparts_list_show_hint
	.4byte medaparts_list_handle_input
	.4byte medaparts_list_start_fade_out
	.4byte medaparts_list_wait_fade
	.4byte medaparts_list_exit
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte medaparts_list_open_detail
	.4byte medaparts_list_detail_fade_out
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte medapart_detail_load_gfx
	.4byte medapart_detail_fade_in
	.4byte medapart_detail_open_text_window
	.4byte medapart_detail_show_hint
	.4byte medapart_detail_handle_input
	.4byte medapart_detail_start_fade_out
	.4byte medapart_detail_wait_fade
	.4byte medapart_detail_exit
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte medaparts_help_load
	.4byte medaparts_help_show_intro
	.4byte medaparts_help_cursor_input
	.4byte medaparts_help_show_text
	.4byte medaparts_help_exit
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_0800EA2C
	.4byte sub_0800EA98
	.4byte sub_0800EB34
	.4byte sub_0800EB60
	.4byte medaparts_list_start_fade_out
	.4byte medaparts_list_wait_fade
	.4byte sub_0800EBB8
	.4byte sub_0800EBE4
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083ACC94
gUnk_083ACC94:
	.4byte sub_08010170
	.4byte sub_080101E8
	.4byte sub_0801022C
	.4byte nullsub_08000840

	.global gPrebattleScreenHandlers
gPrebattleScreenHandlers:
	.4byte prebattle_mosaic_start
	.4byte prebattle_mosaic_grow_init
	.4byte prebattle_mosaic_grow
	.4byte prebattle_mosaic_shrink_init
	.4byte prebattle_mosaic_shrink
	.4byte prebattle_mosaic_repeat
	.4byte prebattle_wipe_init
	.4byte prebattle_wipe
	.4byte prebattle_load_encounter
	.4byte prebattle_load_gfx
	.4byte sub_08010794
	.4byte prebattle_open_text_window
	.4byte prebattle_show_opponent_line
	.4byte prebattle_wait_for_start_input
	.4byte sub_080108D0
	.4byte prebattle_rubberobo_ask
	.4byte prebattle_rubberobo_choice
	.4byte prebattle_rubberobo_use
	.4byte sub_080109A0
	.4byte sub_080109CC
	.4byte sub_08010A20
	.4byte sub_08010A7C
	.4byte sub_08010AC8
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_080109A0
	.4byte sub_080109CC
	.4byte sub_08010A20
	.4byte prebattle_open_team_select
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte prebattle_load_gfx
	.4byte afterbattle_count_battle
	.4byte sub_08010794
	.4byte prebattle_open_text_window
	.4byte afterbattle_check_won
	.4byte afterbattle_show_opponent_line
	.4byte sub_08010C28
	.4byte afterbattle_give_part
	.4byte afterbattle_load_part_name
	.4byte afterbattle_show_part_acquired
	.4byte sub_08010DAC
	.4byte sub_08010E50
	.4byte sub_08010E7C
	.4byte afterbattle_part_details_input
	.4byte sub_08010F6C
	.4byte sub_08010FA4
	.4byte afterbattle_load_experience
	.4byte afterbattle_show_experience
	.4byte afterbattle_start_medal_level_up
	.4byte sub_08011078
	.4byte sub_080110FC
	.4byte sub_0801112C
	.4byte nullsub_08000840
	.4byte sub_08011158
	.4byte sub_0801120C
	.4byte sub_0801123C
	.4byte nullsub_08000840
	.4byte sub_08011268
	.4byte sub_080112C4
	.4byte sub_080112F0
	.4byte sub_08011344
	.4byte nullsub_08000840
	.4byte sub_08011490
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_080114E0
	.4byte sub_080112C4
	.4byte sub_080112F0
	.4byte sub_08011500
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte afterbattle_part_detail_init_fade
	.4byte afterbattle_part_detail_fade_out
	.4byte afterbattle_part_detail_save_screen
	.4byte sub_080116C4
	.4byte nullsub_08000840
	.4byte afterbattle_part_detail_restore_screen
	.4byte afterbattle_part_detail_fade_in
	.4byte afterbattle_part_detail_return
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte afterbattle_show_lost_message
	.4byte sub_08011B18
	.4byte sub_080114E0
	.4byte sub_080112C4
	.4byte afterbattle_fade_to_white
	.4byte afterbattle_exit_to_field
	.4byte nullsub_08000840
	.4byte battle_loss_take_part
	.4byte afterbattle_load_part_name
	.4byte battle_loss_show_part_taken
	.4byte battle_loss_check_team
	.4byte battle_loss_show_no_medabots
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083ACEE4
gUnk_083ACEE4:
	.incbin "baserom.gba", 0x3ACEE4, 0x6

	.global gUnk_083ACEEA
gUnk_083ACEEA:
	.incbin "baserom.gba", 0x3ACEEA, 0x6

	.global gUnk_083ACEF0
gUnk_083ACEF0:
	.incbin "baserom.gba", 0x3ACEF0, 0x10

	.global gRobattleHandlers
gRobattleHandlers:
	.4byte battle_init_phase
	.4byte battle_scene_init_state_machine
	.4byte robattle_fade_in_from_white
	.4byte sub_08012B94
	.4byte sub_08012BC0
	.4byte sub_08012BE4
	.4byte sub_08012C0C
	.4byte robattle_command_input
	.4byte sub_08012D98
	.4byte sub_08012DF4
	.4byte nullsub_08000840
	.4byte sub_08012E40
	.4byte sub_08012EA8
	.4byte robattle_command_commit
	.4byte sub_08012FF8
	.4byte nullsub_08000840
	.4byte sub_0801303C
	.4byte sub_080130D8
	.4byte sub_08013164
	.4byte sub_08013228
	.4byte nullsub_08000840
	.4byte sub_08013288
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_08013330
	.4byte sub_080133B8
	.4byte sub_08013438
	.4byte sub_08013508
	.4byte nullsub_08000840
	.4byte sub_08013568
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_080136E8
	.4byte sub_0801372C
	.4byte sub_08013798
	.4byte sub_08013B8C
	.4byte sub_08013DE4
	.4byte sub_08013E30
	.4byte sub_08013FA8
	.4byte nullsub_08000840
	.4byte sub_08013614
	.4byte sub_08013650
	.4byte sub_080136B0
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_080136E8
	.4byte sub_0801372C
	.4byte sub_08013798
	.4byte sub_08013824
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_08013AE4
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte battle_phase_dispatch_0801387C
	.4byte sub_08013A74
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte robattle_start_banner_init
	.4byte robattle_start_banner
	.4byte sub_0801425C
	.4byte nullsub_08000840
	.4byte sub_0801427C
	.4byte sub_08014314
	.4byte sub_080143A0
	.4byte sub_08014404
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_08014548
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_080145BC
	.4byte sub_08014634
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_080146DC
	.4byte sub_08014754
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_080147FC
	.4byte sub_08014870
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_08014920
	.4byte sub_08014994
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_08014A44
	.4byte sub_08014A60
	.4byte sub_08014A84
	.4byte sub_08014AB4
	.4byte sub_08014ADC
	.4byte sub_08014B34
	.4byte sub_08014C30
	.4byte sub_08014C84
	.4byte sub_08014CC8
	.4byte sub_08014CE4
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_08014A44
	.4byte sub_08014A60
	.4byte sub_08014A84
	.4byte sub_08014AB4
	.4byte sub_08014ADC
	.4byte sub_08014CF0
	.4byte sub_08014AB4
	.4byte sub_08014A84
	.4byte sub_08014AB4
	.4byte sub_08014D84
	.4byte sub_08014D94
	.4byte sub_08014DC8
	.4byte sub_08014CC8
	.4byte sub_08014E20
	.4byte sub_08014E54
	.4byte sub_08014E08
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AD200
gUnk_083AD200:
	.incbin "baserom.gba", 0x3AD200, 0xF0

	.global gUnk_083AD2F0
gUnk_083AD2F0:
	.incbin "baserom.gba", 0x3AD2F0, 0x80

	.global gUnk_083AD370
gUnk_083AD370:
	.incbin "baserom.gba", 0x3AD370, 0x6

	.global gUnk_083AD376
gUnk_083AD376:
	.incbin "baserom.gba", 0x3AD376, 0x6

	.global gUnk_083AD37C
gUnk_083AD37C:
	.incbin "baserom.gba", 0x3AD37C, 0x6

	.global gUnk_083AD382
gUnk_083AD382:
	.incbin "baserom.gba", 0x3AD382, 0x18

	.global gUnk_083AD39A
gUnk_083AD39A:
	.incbin "baserom.gba", 0x3AD39A, 0x6

	.global gUnk_083AD3A0
gUnk_083AD3A0:
	.incbin "baserom.gba", 0x3AD3A0, 0x4

	.global gUnk_083AD3A4
gUnk_083AD3A4:
	.incbin "baserom.gba", 0x3AD3A4, 0xC

	.global gUnk_083AD3B0
gUnk_083AD3B0:
	.incbin "baserom.gba", 0x3AD3B0, 0x3

	.global gUnk_083AD3B3
gUnk_083AD3B3:
	.incbin "baserom.gba", 0x3AD3B3, 0x20

	.global gUnk_083AD3D3
gUnk_083AD3D3:
	.incbin "baserom.gba", 0x3AD3D3, 0x20

	.global gUnk_083AD3F3
gUnk_083AD3F3:
	.incbin "baserom.gba", 0x3AD3F3, 0x6

	.global gUnk_083AD3F9
gUnk_083AD3F9:
	.incbin "baserom.gba", 0x3AD3F9, 0x7

	.global gUnk_083AD400
gUnk_083AD400:
	.4byte sub_0801C0F8
	.4byte sub_0801C110
	.4byte sub_0801C138
	.4byte nullsub_08000840

	.global gUnk_083AD410
gUnk_083AD410:
	.4byte sub_0801C188
	.4byte sub_0801C1C0
	.4byte sub_0801C23C
	.4byte sub_0801C298
	.4byte nullsub_08000840

	.global gUnk_083AD424
gUnk_083AD424:
	.4byte sub_0801C32C
	.4byte sub_0801C360
	.4byte sub_0801C388
	.4byte sub_0801C3B0
	.4byte sub_0801C3F8
	.4byte sub_0801C40C
	.4byte sub_0801C444
	.4byte sub_0801C470
	.4byte sub_0801C4A4
	.4byte sub_0801C4E0

	.global gUnk_083AD44C
gUnk_083AD44C:
	.4byte sub_0801C524
	.4byte sub_080305E0
	.4byte sub_0801C660
	.4byte sub_0801C6C4
	.4byte sub_0801C774
	.4byte sub_0801C988
	.4byte sub_0801C9C8
	.4byte sub_0801CA2C
	.4byte sub_0801CA60
	.4byte sub_0801CAA8
	.4byte load_battle_script_data_d0
	.4byte sub_080305E0
	.4byte apply_battle_damage_tick
	.4byte battle_check_hit_and_set_timer
	.4byte sub_080305E0
	.4byte sub_0801CBE4
	.4byte sub_0801CC24
	.4byte sub_0801CC58
	.4byte sub_0801CCB8
	.4byte sub_0801CA2C
	.4byte sub_0801CD08
	.4byte sub_0801CD28
	.4byte sub_080305E0
	.4byte sub_0801CD40
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_0801CD50
	.4byte sub_0801CDB4
	.4byte sub_0801CDD4
	.4byte sub_0801CE94
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_0801CF78
	.4byte sub_0801CFFC
	.4byte sub_0801D06C
	.4byte sub_0801C988
	.4byte sub_0801D174
	.4byte sub_0801D1AC
	.4byte sub_0801D264
	.4byte sub_080305E0
	.4byte sub_0801D244
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_0801D2AC
	.4byte sub_0801D2C4
	.4byte sub_0801D2D8

	.global gUnk_083AD50C
gUnk_083AD50C:
	.4byte sub_0801D318
	.4byte sub_08030608
	.4byte sub_080305E0
	.4byte sub_0801D36C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AD530
gUnk_083AD530:
	.4byte sub_0801D3A8
	.4byte sub_08030608
	.4byte sub_080305E0
	.4byte sub_0801D3F8
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AD550
gUnk_083AD550:
	.4byte sub_0801D434
	.4byte sub_0801D45C
	.4byte sub_0801D524
	.4byte sub_0801D544
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AD570
gUnk_083AD570:
	.4byte sub_0801D5A8
	.4byte sub_0801D6A4
	.4byte sub_0801D738
	.4byte sub_0801D878
	.4byte sub_0801D95C
	.4byte sub_0801D9DC
	.4byte sub_0801DAEC
	.4byte sub_0801DC74
	.4byte sub_0801DD30
	.4byte sub_0801DD74
	.4byte sub_080305E0
	.4byte sub_0801DDDC
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AD5B0
gUnk_083AD5B0:
	.4byte sub_0801DE44
	.4byte sub_080305E0
	.4byte sub_0801DED4
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AD5D0
gUnk_083AD5D0:
	.4byte sub_0801DF0C
	.4byte sub_0801DF60
	.4byte sub_0801DFE0
	.4byte sub_0801E09C
	.4byte sub_0801E200
	.4byte sub_0801E248
	.4byte sub_0801E2B8
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AD610
gUnk_083AD610:
	.4byte sub_0801E300
	.4byte sub_0801E3C0
	.4byte sub_0801E43C
	.4byte sub_0801E474
	.4byte sub_0801E54C
	.4byte sub_08030624
	.4byte sub_0801E578
	.4byte sub_0801E5DC
	.4byte sub_0801E830
	.4byte sub_08030624
	.4byte sub_0801E864
	.4byte sub_0801E8DC
	.4byte sub_08030624
	.4byte sub_0801E918
	.4byte sub_0801E9B0
	.4byte sub_080306B8
	.4byte sub_0801E9E0
	.4byte sub_0801E9FC
	.4byte sub_08030624
	.4byte sub_0801EA5C
	.4byte sub_0801EA94
	.4byte sub_0801EAC4
	.4byte sub_0801EAD4
	.4byte sub_0801EB5C
	.4byte sub_0801EBB8
	.4byte sub_08030624
	.4byte sub_0801EBF8
	.4byte sub_0801EA94
	.4byte sub_0801EAC4
	.4byte sub_0801EC3C
	.4byte sub_0801EA94
	.4byte sub_0801EAC4
	.4byte sub_0801ECC0
	.4byte sub_0801ED50
	.4byte sub_0801E830
	.4byte sub_08030624
	.4byte sub_0801EED4
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_0801EEE4
	.4byte sub_0801EFC8
	.4byte sub_08030624
	.4byte sub_0801EA94
	.4byte sub_0801EAC4
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_0801F018
	.4byte sub_0801E54C
	.4byte sub_08030624
	.4byte sub_0801EA94
	.4byte sub_0801EAC4
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte decompress_sprite_tiles_to_vram_obj_0
	.4byte sub_0801E54C
	.4byte sub_08030624
	.4byte battle_resolve_action_target
	.4byte sub_0801EA94
	.4byte sub_0801EAC4
	.4byte decompress_sprite_tiles_to_vram_obj_800
	.4byte start_battle_transition_anim
	.4byte sub_08030624
	.4byte decompress_sprite_tiles_to_vram_obj_0_alt
	.4byte sub_0801E9B0
	.4byte sub_080306B8
	.4byte sub_0801F374
	.4byte sub_0801F390
	.4byte sub_08030624
	.4byte sub_0801F3F0
	.4byte sub_0801EA94
	.4byte sub_0801EAC4
	.4byte sub_0801ED50
	.4byte sub_0801E830
	.4byte sub_08030624
	.4byte sub_0801F474
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AD750
gUnk_083AD750:
	.4byte sub_0801F4AC
	.4byte sub_0801F5AC
	.4byte sub_0801F5BC
	.4byte sub_0801F780
	.4byte sub_0801F800
	.4byte sub_0801F9B0
	.4byte sub_080306B8
	.4byte sub_0801F9EC
	.4byte sub_0801F5AC
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AD794
gUnk_083AD794:
	.4byte sub_0801FA68
	.4byte sub_0801FADC
	.4byte sub_0801FBC4
	.4byte sub_0801FD88
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AD7D4
gUnk_083AD7D4:
	.4byte sub_0801FE14
	.4byte sub_0803080C
	.4byte sub_0801FE64
	.4byte sub_0801FEC8
	.4byte sub_0801FEE8
	.4byte sub_0801FF9C
	.4byte sub_08020004
	.4byte sub_080305E0
	.4byte sub_08020040
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AD814
gUnk_083AD814:
	.4byte sub_08020078
	.4byte sub_0803080C
	.4byte sub_080200A8
	.4byte sub_080201DC
	.4byte sub_08020248
	.4byte sub_0803080C
	.4byte sub_08020288
	.4byte sub_080202E0
	.4byte sub_08030624
	.4byte sub_08020340
	.4byte sub_0803080C
	.4byte sub_0802036C
	.4byte sub_08020428
	.4byte sub_08030624
	.4byte sub_0803080C
	.4byte sub_08020474
	.4byte sub_08020530
	.4byte sub_08030624
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AD878
gUnk_083AD878:
	.4byte sub_080205A4
	.4byte sub_08020608
	.4byte sub_08020628
	.4byte sub_080206E8
	.4byte sub_08020728
	.4byte sub_08020768
	.4byte sub_080305E0
	.4byte sub_0803080C

	.global gUnk_083AD898
gUnk_083AD898:
	.4byte sub_080207CC
	.4byte sub_0803080C
	.4byte sub_08030608
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AD8B8
gUnk_083AD8B8:
	.4byte sub_08020844
	.4byte sub_0803080C
	.4byte sub_08030608
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AD8D8
gUnk_083AD8D8:
	.4byte sub_0801E300
	.4byte sub_080208E8
	.4byte decompress_sprite_tiles_to_vram_obj_800
	.4byte start_battle_transition_anim
	.4byte sub_08030624
	.4byte decompress_sprite_tiles_to_vram_obj_0_alt
	.4byte sub_0801E9B0
	.4byte sub_080306B8
	.4byte sub_0801F374
	.4byte sub_0801F390
	.4byte sub_08030624
	.4byte sub_08020928
	.4byte sub_0801EA94
	.4byte sub_0803080C
	.4byte sub_0801ED50
	.4byte sub_0801E830
	.4byte sub_08030624
	.4byte sub_080209A0
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AD93C
gUnk_083AD93C:
	.4byte sub_080209D8
	.4byte sub_0803080C
	.4byte sub_08030608
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AD95C
gUnk_083AD95C:
	.4byte sub_0801E300
	.4byte sub_08020A90
	.4byte decompress_sprite_tiles_to_vram_obj_800
	.4byte start_battle_transition_anim
	.4byte sub_08030624
	.4byte decompress_sprite_tiles_to_vram_obj_0_alt
	.4byte sub_0801E9B0
	.4byte sub_080306B8
	.4byte sub_08020B4C
	.4byte sub_0801F374
	.4byte sub_0801F390
	.4byte sub_08030624
	.4byte sub_08020AD0
	.4byte sub_0801EA94
	.4byte sub_0803080C
	.4byte sub_0801ED50
	.4byte sub_0801E830
	.4byte sub_08030624
	.4byte sub_08020CEC
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AD9C0
gUnk_083AD9C0:
	.4byte sub_08020D24
	.4byte sub_08030608
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte sub_08020DF8
	.4byte sub_08020EDC
	.4byte sub_08020FB8
	.4byte sub_08021000
	.4byte sub_08021038
	.4byte sub_080211C8
	.4byte sub_0802121C
	.4byte sub_080212A0
	.4byte sub_08021300
	.4byte sub_08021370
	.4byte sub_080213E4
	.4byte sub_08021418
	.4byte sub_08021564
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte sub_080215C8
	.4byte sub_08021608
	.4byte sub_08021418
	.4byte sub_08021564
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_08021638
	.4byte sub_0802167C
	.4byte sub_08021734
	.4byte sub_08021774
	.4byte sub_080217D8
	.4byte sub_0802186C
	.4byte sub_08021418
	.4byte sub_08021564
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840

	.global gUnk_083ADA6C
gUnk_083ADA6C:
	.4byte sub_080218E4
	.4byte sub_08030608
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte sub_08020DF8
	.4byte sub_08020EDC
	.4byte sub_08020FB8
	.4byte sub_08021000
	.4byte sub_08021950
	.4byte sub_080219C0
	.4byte sub_08021A14
	.4byte sub_08021A6C
	.4byte sub_08021AFC
	.4byte sub_08021B78
	.4byte sub_08030674
	.4byte sub_08021BD8
	.4byte sub_08021C94
	.4byte sub_08021DAC
	.4byte sub_08021DEC
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083ADAEC
gUnk_083ADAEC:
	.4byte sub_08021E2C
	.4byte sub_08030608
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte sub_08020DF8
	.4byte sub_08020EDC
	.4byte sub_08020FB8
	.4byte sub_08021000
	.4byte sub_08021EA0
	.4byte sub_08030674
	.4byte sub_08021F90
	.4byte sub_08022010
	.4byte sub_080220A0
	.4byte sub_0802213C
	.4byte sub_080305E0
	.4byte sub_0803080C

	.global gUnk_083ADB2C
gUnk_083ADB2C:
	.4byte sub_0802217C
	.4byte sub_08030608
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte sub_080221C8
	.4byte sub_080222A8
	.4byte sub_08022380
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083ADB6C
gUnk_083ADB6C:
	.4byte sub_080223E4
	.4byte sub_08030608
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte sub_08022480
	.4byte sub_08022648
	.4byte sub_08022708
	.4byte sub_08022748
	.4byte sub_080227C0
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083ADBAC
gUnk_083ADBAC:
	.4byte sub_08022800
	.4byte sub_08030608
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte sub_08020DF8
	.4byte sub_08020EDC
	.4byte sub_08020FB8
	.4byte sub_08021000
	.4byte sub_08022870
	.4byte sub_08022938
	.4byte sub_08022990
	.4byte sub_080229C0
	.4byte sub_08022A04
	.4byte sub_08022B40
	.4byte sub_08022C28
	.4byte sub_08022C90
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083ADC0C
gUnk_083ADC0C:
	.4byte sub_08022CD0
	.4byte sub_08030608
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte sub_08020DF8
	.4byte sub_08020EDC
	.4byte sub_08020FB8
	.4byte sub_08021000
	.4byte sub_08022D4C
	.4byte sub_08022938
	.4byte sub_08022990
	.4byte sub_080229C0
	.4byte sub_08022E14
	.4byte sub_08022B40
	.4byte sub_08022F50
	.4byte sub_08022FB4
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083ADC6C
gUnk_083ADC6C:
	.4byte sub_08023018
	.4byte sub_08030608
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte sub_0802306C
	.4byte sub_080230A4
	.4byte sub_080230C8
	.4byte sub_08023118
	.4byte sub_080231D4
	.4byte sub_08023224
	.4byte sub_08023274
	.4byte sub_08023328
	.4byte sub_08030674
	.4byte sub_08023384
	.4byte sub_080233E0
	.4byte sub_08023414
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083ADCC0
gUnk_083ADCC0:
	.4byte sub_08023454
	.4byte sub_08030608
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte sub_080234A8
	.4byte sub_08023564
	.4byte sub_08030674
	.4byte sub_080235AC
	.4byte sub_080235E8
	.4byte sub_08023658
	.4byte sub_080236E0
	.4byte sub_08023718
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083ADD20
gUnk_083ADD20:
	.4byte sub_08023758
	.4byte sub_08030608
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte sub_08020DF8
	.4byte sub_08020EDC
	.4byte sub_08020FB8
	.4byte sub_08021000
	.4byte sub_080237C8
	.4byte sub_080238A0
	.4byte sub_08023900
	.4byte sub_08023988
	.4byte sub_080239C0
	.4byte sub_08023A04
	.4byte sub_08023A48
	.4byte sub_08023AB0
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083ADD80
gUnk_083ADD80:
	.4byte sub_08023AF0
	.4byte sub_08030608
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte sub_08020DF8
	.4byte sub_08020EDC
	.4byte sub_08020FB8
	.4byte sub_08021000
	.4byte sub_08023B44
	.4byte sub_080238A0
	.4byte sub_08023900
	.4byte sub_08023C18
	.4byte sub_080239C0
	.4byte sub_08023A04
	.4byte sub_08023C50
	.4byte sub_08023C78
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083ADDE0
gUnk_083ADDE0:
	.4byte sub_08023CB8
	.4byte sub_08030608
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte sub_08020DF8
	.4byte sub_08020EDC
	.4byte sub_08020FB8
	.4byte sub_08021000
	.4byte sub_08023D44
	.4byte sub_080238A0
	.4byte sub_08023900
	.4byte sub_08023E18
	.4byte sub_080239C0
	.4byte sub_08023E50
	.4byte sub_08023E94
	.4byte sub_08023F48
	.4byte sub_080238A0
	.4byte sub_08023900
	.4byte sub_08023F80
	.4byte sub_080239C0
	.4byte sub_08023A04
	.4byte sub_08023FB8
	.4byte sub_08024078
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083ADE60
gUnk_083ADE60:
	.4byte sub_080240B8
	.4byte sub_08030608
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte sub_08020DF8
	.4byte sub_08020EDC
	.4byte sub_08020FB8
	.4byte sub_08021000
	.4byte sub_0802410C
	.4byte sub_08030674
	.4byte sub_080241F0
	.4byte sub_08024210
	.4byte sub_080242F8
	.4byte sub_08024488
	.4byte sub_08024538
	.4byte sub_0802463C
	.4byte sub_080246C0
	.4byte battle_process_bot_defeat
	.4byte sub_0803080C
	.4byte sub_08024790
	.4byte sub_0803080C
	.4byte sub_080247C8
	.4byte sub_080247F4
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte sub_0802480C
	.4byte sub_08024870
	.4byte sub_08024890
	.4byte sub_0802494C
	.4byte sub_0803080C
	.4byte nullsub_08000840

	.global gUnk_083ADEE0
gUnk_083ADEE0:
	.incbin "baserom.gba", 0x3ADEE0, 0x4

	.global gUnk_083ADEE4
gUnk_083ADEE4:
	.4byte sub_080249C0
	.4byte sub_08030608
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte sub_08020DF8
	.4byte sub_08020EDC
	.4byte sub_08020FB8
	.4byte sub_08021000
	.4byte sub_08024A30
	.4byte sub_08030674
	.4byte sub_08021F90
	.4byte sub_08024AF4
	.4byte sub_08024BCC
	.4byte sub_08030674
	.4byte sub_08024BF8
	.4byte sub_08024C44
	.4byte sub_08024C94
	.4byte sub_08024D18
	.4byte sub_08024DA8
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083ADF44
gUnk_083ADF44:
	.4byte sub_08024E2C
	.4byte sub_08030608
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte sub_08020DF8
	.4byte sub_08020EDC
	.4byte sub_08020FB8
	.4byte sub_08021000
	.4byte sub_08024E9C
	.4byte sub_08030780
	.4byte sub_08021F90
	.4byte sub_08024F90
	.4byte sub_08024FC4
	.4byte sub_0802503C
	.4byte sub_0803081C
	.4byte sub_08025104
	.4byte sub_08025174
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083ADFA4
gUnk_083ADFA4:
	.4byte sub_080251B4
	.4byte sub_08030608
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte sub_08020DF8
	.4byte sub_08020EDC
	.4byte sub_08020FB8
	.4byte sub_08021000
	.4byte sub_08025230
	.4byte sub_08025308
	.4byte sub_08025354
	.4byte sub_08025378
	.4byte sub_0802549C
	.4byte sub_08025500
	.4byte sub_08025570
	.4byte sub_080255F8
	.4byte sub_08025674
	.4byte sub_080256EC
	.4byte battle_set_action_0x35
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AE004
gUnk_083AE004:
	.4byte process_battle_action_phase
	.4byte sub_08030608
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte sub_08020DF8
	.4byte sub_08020EDC
	.4byte sub_08020FB8
	.4byte sub_08021000
	.4byte battle_render_bot_status_icon
	.4byte sub_08030674
	.4byte sub_08021F90
	.4byte sub_08025974
	.4byte sub_08024BCC
	.4byte sub_08030674
	.4byte sub_08024BF8
	.4byte sub_08024C44
	.4byte sub_08024C94
	.4byte sub_08025A18
	.4byte sub_08025AAC
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AE064
gUnk_083AE064:
	.4byte sub_08025B20
	.4byte sub_08030608
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte sub_08020DF8
	.4byte sub_08020EDC
	.4byte sub_08020FB8
	.4byte sub_08021000
	.4byte sub_08025B9C
	.4byte sub_08030674
	.4byte sub_08021F90
	.4byte sub_08025C84
	.4byte sub_08025D2C
	.4byte sub_08025D4C
	.4byte sub_08025D6C
	.4byte sub_08025DD4
	.4byte sub_08021F90
	.4byte sub_08025D2C
	.4byte sub_08025D4C
	.4byte sub_08025E88
	.4byte sub_08025F14
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AE0E4
gUnk_083AE0E4:
	.4byte sub_08025F54
	.4byte sub_0803080C
	.4byte sub_08030608
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AE100
gUnk_083AE100:
	.4byte sub_08025FC8
	.4byte sub_08026080
	.4byte sub_08030674
	.4byte sub_080260EC
	.4byte sub_0803080C
	.4byte nullsub_08000840

	.global gUnk_083AE118
gUnk_083AE118:
	.4byte sub_08026130
	.4byte sub_08030608
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte sub_08026184
	.4byte sub_08026284
	.4byte sub_080262FC
	.4byte sub_08026340
	.4byte sub_08026378
	.4byte sub_08030674
	.4byte sub_080263BC
	.4byte sub_08026444
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AE16C
gUnk_083AE16C:
	.4byte sub_08026484
	.4byte sub_08030608
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte sub_080264E4
	.4byte sub_08026628
	.4byte sub_08026678
	.4byte sub_08026810
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AE1C0
gUnk_083AE1C0:
	.4byte sub_0801E300
	.4byte sub_080268AC
	.4byte sub_080268D4
	.4byte sub_08026924
	.4byte sub_08026A24
	.4byte sub_080306B8
	.4byte sub_0801E9E0
	.4byte sub_08026A74
	.4byte sub_08030624
	.4byte sub_08026AF4
	.4byte sub_0801EA94
	.4byte sub_0801EAC4
	.4byte nullsub_08000840
	.4byte sub_08026BF8
	.4byte sub_0801EBD4
	.4byte sub_08030624
	.4byte sub_08026CBC
	.4byte sub_0801EA94
	.4byte sub_0801EAC4
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AE240
gUnk_083AE240:
	.4byte sub_0801E300
	.4byte sub_08026D1C
	.4byte sub_0801E864
	.4byte sub_0801E8DC
	.4byte sub_08030624
	.4byte sub_0801E918
	.4byte sub_0801E9B0
	.4byte sub_080306B8
	.4byte sub_0801E9E0
	.4byte sub_0801E9FC
	.4byte sub_08030624
	.4byte sub_0801EA5C
	.4byte sub_0801EA94
	.4byte sub_0801EAC4
	.4byte sub_0801EAD4
	.4byte sub_0801EB5C
	.4byte sub_0801EBD4
	.4byte sub_08030624
	.4byte sub_0801EBF8
	.4byte sub_0801EA94
	.4byte sub_0801EAC4
	.4byte sub_08026D44
	.4byte sub_0801EA94
	.4byte sub_0801EAC4
	.4byte sub_08026D98
	.4byte sub_0801E830
	.4byte sub_08030624
	.4byte sub_08026EC0
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_0801F018
	.4byte sub_0801E54C
	.4byte sub_08030624
	.4byte sub_0801EA94
	.4byte sub_0801EAC4
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AE300
gUnk_083AE300:
	.4byte sub_08026EF8
	.4byte sub_0803080C
	.4byte sub_08026F34
	.4byte sub_0801E300
	.4byte decompress_sprite_tiles_to_vram_obj_800
	.4byte start_battle_transition_anim
	.4byte sub_08030624
	.4byte decompress_sprite_tiles_to_vram_obj_0_alt
	.4byte sub_0801E9B0
	.4byte sub_080306B8
	.4byte sub_0801F374
	.4byte sub_0801F390
	.4byte sub_08030624
	.4byte sub_08026F6C
	.4byte sub_0801EA94
	.4byte sub_0803080C
	.4byte sub_08026D98
	.4byte sub_0801E830
	.4byte sub_08030624
	.4byte sub_08026FC0
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AE380
gUnk_083AE380:
	.4byte sub_08026FF8
	.4byte sub_080270BC
	.4byte sub_080271C4
	.4byte sub_08030674
	.4byte sub_0802724C
	.4byte sub_080272EC
	.4byte sub_0802733C
	.4byte sub_08027378
	.4byte sub_080273DC
	.4byte sub_08027444
	.4byte sub_0802747C
	.4byte sub_080305E0
	.4byte sub_08027544
	.4byte sub_0802761C
	.4byte sub_08027494
	.4byte decompress_sprite_tiles_to_vram_obj_4800_alt
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte sub_08027798
	.4byte sub_080277DC
	.4byte sub_080278B8
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AE400
gUnk_083AE400:
	.4byte sub_08027964
	.4byte sub_080279E4
	.4byte sub_08027BA0
	.4byte sub_08027BEC
	.4byte sub_08027CB0
	.4byte sub_08027D24
	.4byte sub_08027D98
	.4byte sub_08027E1C
	.4byte sub_08027EDC
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AE440
gUnk_083AE440:
	.4byte sub_08020DF8
	.4byte sub_08020EDC
	.4byte sub_08020FB8
	.4byte sub_08021000
	.4byte sub_08027F84
	.4byte sub_08028034
	.4byte sub_080212A0
	.4byte sub_08028078
	.4byte sub_080280D4
	.4byte sub_080215C8
	.4byte sub_08021608
	.4byte sub_08028130
	.4byte sub_08028230
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840

	.global gUnk_083AE480
gUnk_083AE480:
	.4byte sub_08020DF8
	.4byte sub_08020EDC
	.4byte sub_08020FB8
	.4byte sub_08021000
	.4byte sub_08028270
	.4byte sub_08030674
	.4byte sub_080282E0
	.4byte sub_08028350
	.4byte sub_080283C0
	.4byte sub_080283EC
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AE4C0
gUnk_083AE4C0:
	.4byte sub_0802842C
	.4byte sub_08028504
	.4byte sub_080287C0
	.4byte sub_080287DC
	.4byte sub_08028A00
	.4byte sub_0803080C
	.4byte sub_08028A38
	.4byte sub_08028B58
	.4byte sub_08030674
	.4byte sub_08028BA8
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AE500
gUnk_083AE500:
	.4byte sub_08028C68
	.4byte sub_08028CC8
	.4byte sub_08028E84
	.4byte sub_08028F4C
	.4byte sub_08029004
	.4byte sub_08029178
	.4byte sub_08030674
	.4byte sub_080291E0
	.4byte sub_080292D4
	.4byte sub_08029354
	.4byte sub_08029464
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AE540
gUnk_083AE540:
	.4byte sub_080294DC
	.4byte sub_080287C0
	.4byte sub_08029600
	.4byte sub_0803080C
	.4byte sub_08029680
	.4byte sub_0802976C
	.4byte sub_080297EC
	.4byte sub_08029828
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AE580
gUnk_083AE580:
	.4byte sub_08029868
	.4byte sub_080287C0
	.4byte sub_08029984
	.4byte sub_0803080C
	.4byte sub_08029A14
	.4byte sub_08029B04
	.4byte sub_08029B84
	.4byte init_battle_bot_display_digits
	.4byte sub_08029D28
	.4byte sub_08029DF4
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AE5C0
gUnk_083AE5C0:
	.4byte sub_08029E34
	.4byte sub_080287C0
	.4byte sub_08029F50
	.4byte sub_0803080C
	.4byte sub_08029A14
	.4byte sub_08029B04
	.4byte sub_08029FE0
	.4byte init_battle_bot_display_digits
	.4byte sub_08029D28
	.4byte sub_0802A0D0
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AE600
gUnk_083AE600:
	.4byte sub_0802A110
	.4byte sub_0802A274
	.4byte sub_08030674
	.4byte sub_0802A2D4
	.4byte sub_0802A31C
	.4byte sub_0802A360
	.4byte sub_0802A440
	.4byte sub_0802A4C4
	.4byte sub_0802A534
	.4byte sub_0802A5C0
	.4byte sub_08029D28
	.4byte sub_0802A694
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AE640
gUnk_083AE640:
	.4byte sub_0802A6D4
	.4byte sub_0802A7E0
	.4byte sub_08030674
	.4byte sub_0802A824
	.4byte sub_0802A9B8
	.4byte sub_0802AAB8
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AE680
gUnk_083AE680:
	.4byte sub_0802AAF8
	.4byte sub_08022648
	.4byte sub_08022708
	.4byte sub_0802AC7C
	.4byte sub_0802ACB4
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AE6C0
gUnk_083AE6C0:
	.4byte sub_0802ACF4
	.4byte sub_08022648
	.4byte sub_0802AE88
	.4byte sub_0802AECC
	.4byte sub_0802AF6C
	.4byte sub_0802AFB0
	.4byte sub_0802AFE8
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AE700
gUnk_083AE700:
	.4byte sub_080230A4
	.4byte sub_080230C8
	.4byte sub_0802B028
	.4byte sub_080231D4
	.4byte sub_08023224
	.4byte sub_0802B184
	.4byte sub_0803080C
	.4byte sub_0802B258
	.4byte sub_0802B388
	.4byte sub_0802B3CC
	.4byte sub_0802B460
	.4byte sub_0802B4D8
	.4byte sub_08028B58
	.4byte sub_08030674
	.4byte sub_0802B5AC
	.4byte sub_0802B7AC
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AE750
gUnk_083AE750:
	.4byte sub_0802B810
	.4byte sub_0802B8BC
	.4byte sub_0802B980
	.4byte sub_0802BA2C
	.4byte sub_0802BAAC
	.4byte sub_0802BB24
	.4byte sub_0802BBA8
	.4byte sub_08030674
	.4byte sub_0802BC1C
	.4byte sub_0802A5C0
	.4byte sub_08029D28
	.4byte sub_0802BC60
	.4byte sub_0802BD1C
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840

	.global gUnk_083AE790
gUnk_083AE790:
	.4byte sub_0802306C
	.4byte sub_080230A4
	.4byte sub_080230C8
	.4byte sub_0802BD94
	.4byte sub_0802BE44
	.4byte sub_08023224
	.4byte sub_0802BEEC
	.4byte sub_0802BF9C
	.4byte sub_0802C0DC
	.4byte sub_08030674
	.4byte sub_0802C1A4
	.4byte sub_0802C24C
	.4byte sub_0802C294
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840

	.global gUnk_083AE7D0
gUnk_083AE7D0:
	.incbin "baserom.gba", 0x3AE7D0, 0x4

	.global gUnk_083AE7D4
gUnk_083AE7D4:
	.4byte sub_0802BEEC
	.4byte sub_0802C2D4
	.4byte sub_0802C440
	.4byte sub_0802C4F8
	.4byte sub_0802C588
	.4byte sub_0802C62C
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AE814
gUnk_083AE814:
	.4byte sub_0802C66C
	.4byte sub_0802C714
	.4byte sub_08030674
	.4byte sub_0802C758
	.4byte sub_0802C790
	.4byte sub_0802C820
	.4byte sub_0803080C
	.4byte sub_0802C864
	.4byte sub_0802C960
	.4byte sub_0802CA5C
	.4byte sub_0802CAD4
	.4byte sub_0802CB34
	.4byte sub_0802CBD0
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840

	.global gUnk_083AE854
gUnk_083AE854:
	.4byte sub_0802CC10
	.4byte sub_0802CC74
	.4byte sub_0802CD48
	.4byte sub_08030674
	.4byte sub_0802CE08
	.4byte sub_0802CE4C
	.4byte sub_0802CFAC
	.4byte sub_0802D198
	.4byte sub_0802D270
	.4byte apply_battle_damage_and_render
	.4byte sub_0802D4D8
	.4byte apply_battle_damage_to_team
	.4byte sub_0802D670
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte decompress_sprite_tiles_to_vram_obj_4800_alt
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte sub_08027798
	.4byte sub_080277DC
	.4byte sub_080278B8
	.4byte sub_0803080C

	.global gUnk_083AE8B0
gUnk_083AE8B0:
	.4byte sub_0802D6B0
	.4byte sub_0802C714
	.4byte sub_08030674
	.4byte sub_0802C758
	.4byte sub_0802D758
	.4byte sub_0802C820
	.4byte sub_0803080C
	.4byte sub_0802D7EC
	.4byte sub_0802D8D0
	.4byte sub_0802DA0C
	.4byte sub_08030674
	.4byte sub_0802DA60
	.4byte sub_0802DAD0
	.4byte sub_0802DB3C
	.4byte sub_0802DBD8
	.4byte sub_0802DC9C
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AE908
gUnk_083AE908:
	.4byte sub_0802DCDC
	.4byte sub_080230A4
	.4byte sub_080230C8
	.4byte sub_0802DD98
	.4byte sub_0802DE1C
	.4byte sub_0802DF18
	.4byte sub_0802DF48
	.4byte sub_0802DF98
	.4byte sub_0802DFE8
	.4byte nullsub_08000840
	.4byte sub_08023224
	.4byte sub_0802E010
	.4byte sub_0803080C
	.4byte sub_0802E098
	.4byte sub_0802E140
	.4byte sub_08030674
	.4byte sub_0802E1A4
	.4byte sub_080305E0
	.4byte sub_0802E1C8
	.4byte sub_0802E294
	.4byte sub_0802E358
	.4byte decompress_sprite_tiles_to_vram_obj_4800_alt
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte sub_08027798
	.4byte sub_080277DC
	.4byte sub_080278B8
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AE988
gUnk_083AE988:
	.incbin "baserom.gba", 0x3AE988, 0x14

	.global gUnk_083AE99C
gUnk_083AE99C:
	.4byte sub_0802E44C
	.4byte sub_0802E4C8
	.4byte sub_0802E5D4
	.4byte sub_08030674
	.4byte sub_0802E638
	.4byte sub_0802E70C
	.4byte sub_0802A5C0
	.4byte sub_08029D28
	.4byte sub_0802E7A0
	.4byte sub_0802E820
	.4byte sub_0802E8D4
	.4byte sub_0802E948
	.4byte sub_0802EAA4
	.4byte sub_0802EAC0
	.4byte sub_080305E0
	.4byte sub_0802EAD8
	.4byte sub_08027544
	.4byte sub_0802761C
	.4byte decompress_sprite_tiles_to_vram_obj_4800_alt
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte sub_08027798
	.4byte sub_080277DC
	.4byte sub_080278B8
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AEA08
gUnk_083AEA08:
	.4byte sub_0802EBE8
	.4byte sub_0802EC4C
	.4byte sub_0802ED34
	.4byte sub_0802ED90
	.4byte decrement_timer_and_decompress_sprite
	.4byte sub_0802EF0C
	.4byte sub_08030674
	.4byte sub_0802EF5C
	.4byte sub_0802EFD0
	.4byte sub_0802F018
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AEA44
gUnk_083AEA44:
	.4byte sub_0802F058
	.4byte sub_0802F13C
	.4byte sub_0802F214
	.4byte sub_0802F2F4
	.4byte sub_0802F3FC
	.4byte sub_0802F468
	.4byte sub_0802F48C
	.4byte sub_0802F4D0
	.4byte sub_0802F594
	.4byte sub_0802F5D8
	.4byte sub_0802F610
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AEA84
gUnk_083AEA84:
	.4byte sub_0802F650
	.4byte sub_0802F6CC
	.4byte sub_0802F7B8
	.4byte sub_08030674
	.4byte sub_0802F864
	.4byte sub_0802F880
	.4byte sub_0802F89C
	.4byte sub_0803080C
	.4byte sub_0802F8E4
	.4byte sub_08027544
	.4byte sub_0802761C
	.4byte decompress_sprite_tiles_to_vram_obj_4800_alt
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte sub_08027798
	.4byte sub_080277DC
	.4byte sub_080278B8
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AEAD8
gUnk_083AEAD8:
	.4byte sub_0802F9B8
	.4byte sub_0802FB74
	.4byte sub_0802FBF4
	.4byte sub_0802FC3C
	.4byte sub_0802FD08
	.4byte sub_0802FD4C
	.4byte sub_0802FD84
	.4byte sub_08030674
	.4byte sub_0802FDC8
	.4byte sub_0802FE0C
	.4byte sub_0802FE38
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AEB18
gUnk_083AEB18:
	.4byte sub_0802FE78
	.4byte sub_08030180
	.4byte sub_08030238
	.4byte sub_0803029C
	.4byte sub_08030354
	.4byte sub_080303A4
	.4byte sub_08030494
	.4byte sub_0803059C
	.4byte sub_080305C8
	.4byte sub_080305E0
	.4byte sub_0803080C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AEB58
gUnk_083AEB58:
	.4byte sub_08030890
	.4byte sub_08030910
	.4byte sub_08030990
	.4byte sub_080309C8
	.4byte resolve_battle_action_phase
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_08030CFC
	.4byte sub_08030D3C
	.4byte sub_08030D58
	.4byte sub_08030C94
	.4byte sub_08030D74
	.4byte sub_08030D90
	.4byte sub_08030DB4
	.4byte sub_08030E14
	.4byte sub_08030C94
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_08030D3C
	.4byte sub_08030E54
	.4byte sub_08030C94
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_08031614
	.4byte sub_08030D3C
	.4byte sub_08030E54
	.4byte sub_08030C94
	.4byte sub_08030D74
	.4byte sub_08031704
	.4byte sub_0803185C
	.4byte sub_080318CC
	.4byte sub_08030E54
	.4byte battle_start_transition_to_action
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_08030E78
	.4byte sub_08030F10
	.4byte sub_08030FB4
	.4byte sub_08030FEC
	.4byte sub_080310A0
	.4byte sub_08030CA0
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_08031120
	.4byte sub_08031174
	.4byte sub_08030FB4
	.4byte sub_08031048
	.4byte sub_08031218
	.4byte sub_08030CA0
	.4byte nullsub_08000840
	.4byte sub_08030CAC
	.4byte sub_08031298
	.4byte sub_080312CC
	.4byte sub_080312F0
	.4byte sub_0803133C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_08031978
	.4byte sub_08031994
	.4byte sub_080319B8
	.4byte sub_080319E0
	.4byte sub_08031A08
	.4byte sub_08031A24
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_08031390
	.4byte sub_08031438
	.4byte sub_08031458
	.4byte sub_08031518
	.4byte sub_08031538
	.4byte sub_080315B0
	.4byte sub_08031608
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AED18
gUnk_083AED18:
	.incbin "baserom.gba", 0x3AED18, 0x8

	.global gUnk_083AED20
gUnk_083AED20:
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte select_battle_targets_and_actions
	.4byte select_battle_targets_and_actions
	.4byte select_battle_targets_and_actions
	.4byte select_battle_targets_and_actions
	.4byte select_battle_targets_and_actions
	.4byte select_battle_targets_and_actions
	.4byte select_battle_targets_and_actions
	.4byte select_battle_targets_and_actions
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte ai_select_target_enemy_side_ability22_status
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte ai_pick_ally_most_damaged
	.4byte battle_ai_select_target_ability22_enemy
	.4byte ai_pick_ally_with_broken_part
	.4byte select_enemy_battle_target
	.4byte battle_ai_select_target_defend
	.4byte battle_ai_select_target_jump
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte battle_ai_select_target_ability22_enemy
	.4byte select_battle_target_for_bot
	.4byte nullsub_08000840
	.4byte battle_ai_select_target_ability22_ally
	.4byte select_battle_targets_and_actions
	.4byte ai_select_target_player_side_ability22
	.4byte battle_ai_select_target_ability22_ally
	.4byte battle_ai_select_target_status58
	.4byte battle_ai_select_target_ability22_ally
	.4byte battle_ai_select_target_ability22_ally
	.4byte nullsub_08000840
	.4byte select_battle_targets_and_actions
	.4byte select_player_battle_target
	.4byte nullsub_08000840
	.4byte select_battle_targets_and_actions
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AEE10
gUnk_083AEE10:
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_080332EC
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_080332EC
	.4byte nullsub_08000840
	.4byte sub_080332EC
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_080332EC
	.4byte sub_080332EC
	.4byte nullsub_08000840
	.4byte sub_080332EC
	.4byte sub_080332EC
	.4byte nullsub_08000840
	.4byte sub_080332EC
	.4byte nullsub_08000840
	.4byte sub_080332EC
	.4byte sub_080332EC
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_080332EC
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AEF00
gUnk_083AEF00:
	.incbin "baserom.gba", 0x3AEF00, 0x10

	.global gUnk_083AEF10
gUnk_083AEF10:
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_080336DC
	.4byte sub_08033754
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte check_battle_bot_defeated_set_flag
	.4byte sub_08033394
	.4byte nullsub_08000840
	.4byte sub_080333D4
	.4byte sub_080333D4
	.4byte sub_080333D4
	.4byte sub_080333E4
	.4byte sub_080333E4
	.4byte sub_080333E4
	.4byte sub_08033434
	.4byte sub_08033490
	.4byte sub_08033550
	.4byte sub_080335A0
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_08033490
	.4byte sub_080335E0
	.4byte sub_080333D4
	.4byte sub_080334E0
	.4byte nullsub_08000840
	.4byte sub_080334E0
	.4byte sub_080334E0
	.4byte sub_08033618
	.4byte sub_080334E0
	.4byte sub_080334E0
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_08033658
	.4byte sub_080337CC
	.4byte sub_08033698
	.4byte sub_080333D4
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AF000
gUnk_083AF000:
	.4byte nullsub_08000840
	.4byte sub_080338DC
	.4byte sub_080338F4
	.4byte sub_08033974
	.4byte sub_080339F4
	.4byte sub_08033A10
	.4byte sub_08033A2C
	.4byte sub_08033A78
	.4byte sub_08033A94
	.4byte sub_08033AB0
	.4byte sub_08033ACC
	.4byte sub_08033B7C
	.4byte sub_08033C00
	.4byte sub_08033C10
	.4byte sub_08033C20
	.4byte sub_08033CD0
	.4byte sub_08033CE0
	.4byte sub_08033CF0
	.4byte sub_08033D00
	.4byte sub_08033D10
	.4byte sub_08033D30
	.4byte sub_08033F04
	.4byte sub_08033F64
	.4byte sub_08033F9C
	.4byte sub_08034008
	.4byte sub_0803402C
	.4byte sub_08034048
	.4byte sub_08034074
	.4byte sub_08034120
	.4byte sub_08034170
	.4byte sub_080341C0
	.4byte sub_08034200
	.4byte sub_08034240
	.4byte sub_0803426C
	.4byte sub_08034288
	.4byte sub_080342C8
	.4byte sub_080342E4
	.4byte sub_08034300
	.4byte sub_0803431C
	.4byte sub_0803435C
	.4byte sub_08034378
	.4byte sub_080343B8
	.4byte sub_080343D4
	.4byte sub_080343F0
	.4byte sub_0803440C
	.4byte sub_08034428
	.4byte sub_08034444
	.4byte sub_08034460
	.4byte sub_0803447C
	.4byte sub_08034498
	.4byte sub_080344B4
	.4byte sub_080344D0
	.4byte sub_080344EC
	.4byte sub_08034508
	.4byte sub_08034524
	.4byte sub_08034540
	.4byte sub_0803455C
	.4byte sub_08034578
	.4byte sub_08034594
	.4byte sub_080345B0
	.4byte sub_080345CC
	.4byte sub_080345E8
	.4byte sub_08034628
	.4byte sub_08034644
	.4byte sub_08034684
	.4byte sub_080346C4
	.4byte sub_08034708
	.4byte sub_08034728
	.4byte sub_0803476C
	.4byte sub_080347AC
	.4byte sub_080347BC
	.4byte sub_080347F8
	.4byte sub_080348D0
	.4byte sub_08034910
	.4byte sub_0803496C
	.4byte sub_080349D8
	.4byte sub_08034A68
	.4byte sub_08034AA0
	.4byte sub_08034AF4
	.4byte sub_08034B68
	.4byte sub_08034BA0
	.4byte sub_08034BBC
	.4byte sub_08034BD8
	.4byte sub_08034BF4
	.4byte sub_08034C10
	.4byte sub_08034C2C
	.4byte sub_08034C48
	.4byte sub_08034C64
	.4byte sub_08034C80
	.4byte sub_08034C9C
	.4byte sub_08034CB8
	.4byte sub_08034CD4
	.4byte sub_08034CF0
	.4byte sub_08034D0C
	.4byte sub_08034D28
	.4byte sub_08034D44
	.4byte sub_08034D60
	.4byte sub_08034D7C
	.4byte sub_08034D98
	.4byte sub_08034DB4
	.4byte sub_08034DD0
	.4byte sub_08034DEC
	.4byte sub_08034E08
	.4byte sub_08034E24
	.4byte sub_08034E40
	.4byte sub_08034E5C
	.4byte sub_08034E78
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AF200
gUnk_083AF200:
	.incbin "baserom.gba", 0x3AF200, 0x10

	.global gUnk_083AF210
gUnk_083AF210:
	.incbin "baserom.gba", 0x3AF210, 0x100

	.global gUnk_083AF310
gUnk_083AF310:
	.incbin "baserom.gba", 0x3AF310, 0x20

	.global gUnk_083AF330
gUnk_083AF330:
	.incbin "baserom.gba", 0x3AF330, 0x50

	.global gUnk_083AF380
gUnk_083AF380:
	.incbin "baserom.gba", 0x3AF380, 0x40

	.global gUnk_083AF3C0
gUnk_083AF3C0:
	.incbin "baserom.gba", 0x3AF3C0, 0x40

	.global gUnk_083AF400
gUnk_083AF400:
	.incbin "baserom.gba", 0x3AF400, 0x40

	.global gUnk_083AF440
gUnk_083AF440:
	.incbin "baserom.gba", 0x3AF440, 0x40

	.global gUnk_083AF480
gUnk_083AF480:
	.incbin "baserom.gba", 0x3AF480, 0x10

	.global gUnk_083AF490
gUnk_083AF490:
	.incbin "baserom.gba", 0x3AF490, 0x10

	.global gUnk_083AF4A0
gUnk_083AF4A0:
	.incbin "baserom.gba", 0x3AF4A0, 0x10

	.global gUnk_083AF4B0
gUnk_083AF4B0:
	.incbin "baserom.gba", 0x3AF4B0, 0x10

	.global gUnk_083AF4C0
gUnk_083AF4C0:
	.incbin "baserom.gba", 0x3AF4C0, 0x20

	.global gUnk_083AF4E0
gUnk_083AF4E0:
	.incbin "baserom.gba", 0x3AF4E0, 0x40

	.global gUnk_083AF520
gUnk_083AF520:
	.incbin "baserom.gba", 0x3AF520, 0x10

	.global gUnk_083AF530
gUnk_083AF530:
	.4byte nullsub_08000840
	.4byte sub_08037BF4
	.4byte sub_08037C50
	.4byte sub_08037FE4
	.4byte sub_0803809C
	.4byte nullsub_08000840
	.4byte sub_08037BF4
	.4byte sub_08037E2C
	.4byte sub_08037FE4
	.4byte sub_0803809C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_08038024
	.4byte sub_0803805C
	.4byte sub_0803809C
	.4byte nullsub_08000840
	.4byte sub_080380B8
	.4byte sub_080380F0
	.4byte sub_0803805C
	.4byte sub_0803809C
	.4byte sub_080380B8
	.4byte sub_080380F0
	.4byte sub_0803805C
	.4byte sub_0803809C
	.4byte sub_08038178
	.4byte sub_0803805C
	.4byte sub_0803809C
	.4byte nullsub_08000840
	.4byte sub_080381E0
	.4byte sub_08038258
	.4byte sub_0803805C
	.4byte sub_0803809C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_080382F4
	.4byte sub_0803805C
	.4byte sub_0803809C
	.4byte nullsub_08000840
	.4byte sub_080380B8
	.4byte sub_080380F0
	.4byte sub_0803805C
	.4byte sub_0803809C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AF630
gUnk_083AF630:
	.incbin "baserom.gba", 0x3AF630, 0x40

	.global gUnk_083AF670
gUnk_083AF670:
	.incbin "baserom.gba", 0x3AF670, 0x20

	.global gUnk_083AF690
gUnk_083AF690:
	.4byte nullsub_08000840
	.4byte sub_08038428
	.4byte sub_0803858C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AF6D0
gUnk_083AF6D0:
	.incbin "baserom.gba", 0x3AF6D0, 0x10

	.global gUnk_083AF6E0
gUnk_083AF6E0:
	.4byte nullsub_08000840
	.4byte sub_08038650
	.4byte sub_08038700
	.4byte sub_08038804
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AF720
gUnk_083AF720:
	.4byte nullsub_08000840
	.4byte sub_080388A4
	.4byte sub_08038AC0
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AF740
gUnk_083AF740:
	.4byte nullsub_08000840
	.4byte sub_08039430
	.4byte sub_08039448
	.4byte sub_080394C4
	.4byte sub_08039540
	.4byte sub_08039568
	.4byte sub_08039598
	.4byte sub_080395C0
	.4byte sub_080395E8
	.4byte sub_080396C4
	.4byte sub_080396D4
	.4byte sub_080397B0
	.4byte battle_seq_cmd_wait_text
	.4byte sub_080398AC
	.4byte battle_seq_cmd_wait_frames
	.4byte sub_08039A2C
	.4byte sub_08039AC8
	.4byte sub_08039BFC
	.4byte sub_08039CB4
	.4byte sub_08039CF8
	.4byte sub_08039E00
	.4byte sub_08039FE4
	.4byte sub_0803A0B8
	.4byte sub_0803A0E0
	.4byte sub_0803A130
	.4byte sub_0803A264
	.4byte sub_0803A2E8
	.4byte sub_0803A310
	.4byte sub_0803A370
	.4byte sub_0803A444
	.4byte sub_0803A474
	.4byte sub_0803A5CC
	.4byte sub_0803A6FC
	.4byte sub_0803A760
	.4byte sub_0803A840
	.4byte sub_0803A920
	.4byte sub_0803A93C
	.4byte sub_0803AA00
	.4byte sub_0803AA90
	.4byte sub_0803AB00
	.4byte sub_0803AB9C
	.4byte sub_0803ACB4
	.4byte sub_0803AC4C
	.4byte sub_0803ADE8
	.4byte sub_0803ADFC
	.4byte sub_0803AF2C
	.4byte sub_0803B0C0
	.4byte sub_0803B19C
	.4byte sub_0803B1EC
	.4byte sub_0803B328
	.4byte sub_0803B374
	.4byte sub_0803B3C8
	.4byte sub_0803B428
	.4byte sub_0803B4F8
	.4byte sub_0803B5DC
	.4byte sub_0803B6D8
	.4byte sub_0803B700
	.4byte sub_0803B754
	.4byte sub_0803B884
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.incbin "baserom.gba", 0x3AF880, 0x8

	.global gUnk_083AF888
gUnk_083AF888:
	.incbin "baserom.gba", 0x3AF888, 0x4

	.global gUnk_083AF88C
gUnk_083AF88C:
	.incbin "baserom.gba", 0x3AF88C, 0xC0

	.global gUnk_083AF94C
gUnk_083AF94C:
	.incbin "baserom.gba", 0x3AF94C, 0x10

	.global gUnk_083AF95C
gUnk_083AF95C:
	.incbin "baserom.gba", 0x3AF95C, 0x10

	.global gUnk_083AF96C
gUnk_083AF96C:
	.4byte nullsub_08000840
	.4byte sub_0803B900
	.4byte sub_0803B9A4
	.4byte sub_0803BBE0
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_0803BE44
	.4byte sub_0803C044
	.4byte sub_0803C0CC
	.4byte sub_0803C5F8
	.4byte sub_0803C33C
	.4byte sub_0803C680
	.4byte sub_0803C738
	.4byte nullsub_08000840
	.4byte sub_0803C7DC
	.4byte sub_0803C8AC
	.4byte sub_0803C9E0
	.4byte sub_0803CAB0
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_0803CB54
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_0803CBD0
	.4byte sub_0803CC40
	.4byte sub_0803CC8C
	.4byte sub_0803CDCC
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_0803CE18
	.4byte sub_0803CECC
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_0803CF7C
	.4byte sub_0803CFC8
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_0803D0BC
	.4byte nullsub_08000840
	.4byte sub_0803D15C
	.4byte nullsub_08000840
	.4byte sub_0803D2A8
	.4byte nullsub_08000840
	.4byte sub_0803D3C0
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AFAAC
gUnk_083AFAAC:
	.incbin "baserom.gba", 0x3AFAAC, 0xC

	.global gUnk_083AFAB8
gUnk_083AFAB8:
	.incbin "baserom.gba", 0x3AFAB8, 0x40

	.global gUnk_083AFAF8
gUnk_083AFAF8:
	.4byte sub_0803D5A0
	.4byte sub_0803D5E0
	.4byte sub_0803D608
	.4byte sub_0803D634
	.4byte sub_0803D674
	.4byte sub_0803D6AC
	.4byte sub_0803D71C
	.4byte sub_0803D74C
	.4byte sub_0803D928
	.4byte sub_0803D980
	.4byte sub_0803D9A0
	.4byte sub_0803D9C8
	.4byte sub_0803D9F0
	.4byte sub_0803DA90
	.4byte sub_0803DAEC
	.4byte nullsub_08000840
	.4byte sub_0803E4B4
	.4byte sub_0803E4D8
	.4byte sub_0803E4F4
	.4byte sub_0803E4D8
	.4byte sub_0803E618
	.4byte sub_0803E634
	.4byte sub_0803E4B4
	.4byte sub_0803E4D8
	.4byte sub_0803E674
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_0803D74C
	.4byte sub_0803DB1C
	.4byte sub_0803D928
	.4byte sub_0803D980
	.4byte sub_0803DB4C
	.4byte sub_0803DB94
	.4byte sub_0803DBB8
	.4byte sub_0803DBE0
	.4byte sub_0803DC0C
	.4byte sub_0803DC3C
	.4byte sub_0803D9C8
	.4byte sub_0803DA40
	.4byte sub_0803DC58
	.4byte sub_0803DC8C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_0803DCDC
	.4byte sub_0803DE70
	.4byte sub_0803DE90
	.4byte sub_0803DEB0
	.4byte sub_0803DEF0
	.4byte sub_0803DF98
	.4byte sub_0803E018
	.4byte sub_0803E03C
	.4byte sub_0803E098
	.4byte sub_0803E0C0
	.4byte sub_0803E0F0
	.4byte sub_0803E120
	.4byte sub_0803E170
	.4byte sub_0803E1A4
	.4byte sub_0803E1FC
	.4byte sub_0803E234
	.4byte sub_0803E270
	.4byte sub_0803E2AC
	.4byte sub_0803E2DC
	.4byte sub_0803E314
	.4byte sub_0803DC8C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_0803E374
	.4byte sub_0803E170
	.4byte sub_0803E434
	.4byte sub_0803E48C
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte sub_0803E680
	.4byte sub_0803D608
	.4byte sub_0803D5E0
	.4byte sub_0803D608
	.4byte sub_0803E768
	.4byte sub_0803D608
	.4byte sub_0803E774
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083AFC78
gUnk_083AFC78:
	.incbin "baserom.gba", 0x3AFC78, 0x20

	.global gUnk_083AFC98
gUnk_083AFC98:
	.incbin "baserom.gba", 0x3AFC98, 0x60

	.global gUnk_083AFCF8
gUnk_083AFCF8:
	.incbin "baserom.gba", 0x3AFCF8, 0x10

	.global gUnk_083AFD08
gUnk_083AFD08:
	.incbin "baserom.gba", 0x3AFD08, 0x18C0

	.global gUnk_083B15C8
gUnk_083B15C8:
	.incbin "baserom.gba", 0x3B15C8, 0x2C0

	.global gUnk_083B1888
gUnk_083B1888:
	.incbin "baserom.gba", 0x3B1888, 0xB70

	.global gUnk_083B23F8
gUnk_083B23F8:
	.incbin "baserom.gba", 0x3B23F8, 0xB0

	.global gUnk_083B24A8
gUnk_083B24A8:
	.incbin "baserom.gba", 0x3B24A8, 0xDC

	.global gUnk_083B2584
gUnk_083B2584:
	.incbin "baserom.gba", 0x3B2584, 0x218

	.global gUnk_083B279C
gUnk_083B279C:
	.4byte message_open
	.4byte message_dim_palettes_step
	.4byte message_show_window
	.4byte message_open_window_frame
	.4byte message_clear_text_area
	.4byte message_print_step
	.4byte message_run_command
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gUnk_083B27C0
gUnk_083B27C0:
	.4byte sub_080408F4
	.4byte sub_08040914
	.4byte sub_08040934
	.4byte sub_08040954
	.4byte sub_08040974

	.global gUnk_083B27D4
gUnk_083B27D4:
	.4byte sub_08040994
	.4byte sub_08040A00
	.4byte sub_08040A40
	.4byte sub_08040AF0
	.4byte message_undim_palettes_step
	.4byte message_close

	.global gUnk_083B27EC
gUnk_083B27EC:
	.4byte sub_08040994
	.4byte sub_08040A00
	.4byte sub_08040A40
	.4byte sub_08040AF0
	.4byte message_undim_palettes_step
	.4byte message_close

	.global gUnk_083B2804
gUnk_083B2804:
	.4byte message_close

	.global gUnk_083B2808
gUnk_083B2808:
	.4byte sub_08040B5C
	.4byte message_close

	.global gUnk_083B2810
gUnk_083B2810:
	.4byte message_close

	.global gUnk_083B2814
gUnk_083B2814:
	.4byte decompress_bg_tilemap_to_vram
	.4byte clear_and_copy_tilemap_rows
	.4byte transition_draw_tile_strip
	.4byte copy_transition_tiles_to_bg2
	.4byte battle_sprite_setup_cursor
	.4byte advance_sprite_scroll_animation
	.4byte handle_battle_sprite_scroll_input
	.4byte update_sprite_hflip_by_animation_phase
	.4byte animate_battle_sprite_shrink
	.4byte transition_draw_tile_strip
	.4byte clear_and_copy_tilemap_rows
	.4byte clear_tilemap_and_advance_state
	.4byte sub_08041BF4
	.4byte nullsub_08000840

	.global gUnk_083B284C
gUnk_083B284C:
	.4byte sub_08040994
	.4byte sub_08040A00
	.4byte sub_08040A40
	.4byte sub_08040AF0
	.4byte message_undim_palettes_step
	.4byte message_close

	.global gUnk_083B2864
gUnk_083B2864:
	.4byte sub_08040994
	.4byte message_close

	.global gUnk_083B286C
gUnk_083B286C:
	.incbin "baserom.gba", 0x3B286C, 0x100

	.global gUnk_083B296C
gUnk_083B296C:
	.incbin "baserom.gba", 0x3B296C, 0x4

	.global gUnk_083B2970
gUnk_083B2970:
	.incbin "baserom.gba", 0x3B2970, 0x2170

	.global gUnk_083B4AE0
gUnk_083B4AE0:

	.global gUnk_083B4AE0_s
gUnk_083B4AE0_s:
	.incbin "baserom.gba", 0x3B4AE0, 0x1A8

	.global gUnk_083B4C88
gUnk_083B4C88:
	.incbin "baserom.gba", 0x3B4C88, 0x200

	.global gUnk_083B4E88
gUnk_083B4E88:
	.incbin "baserom.gba", 0x3B4E88, 0x570

	.global gUnk_083B53F8
gUnk_083B53F8:
	.incbin "baserom.gba", 0x3B53F8, 0xB88

	.global gUnk_083B5F80
gUnk_083B5F80:
	.incbin "baserom.gba", 0x3B5F80, 0x90

	.global gUnk_083B6010
gUnk_083B6010:
	.incbin "baserom.gba", 0x3B6010, 0x148

	.global gUnk_083B6158
gUnk_083B6158:
	.incbin "baserom.gba", 0x3B6158, 0x2B8

	.global gUnk_083B6410
gUnk_083B6410:
	.incbin "baserom.gba", 0x3B6410, 0x15C

	.global gUnk_083B656C
gUnk_083B656C:
	.incbin "baserom.gba", 0x3B656C, 0x45C

	.global gUnk_083B69C8
gUnk_083B69C8:
	.incbin "baserom.gba", 0x3B69C8, 0x45C

	.global gUnk_083B6E24
gUnk_083B6E24:
	.incbin "baserom.gba", 0x3B6E24, 0xA4

	.global gUnk_083B6EC8
gUnk_083B6EC8:
	.incbin "baserom.gba", 0x3B6EC8, 0x1E4

	.global gUnk_083B70AC
gUnk_083B70AC:
	.incbin "baserom.gba", 0x3B70AC, 0x28C

	.global gUnk_083B7338
gUnk_083B7338:
	.incbin "baserom.gba", 0x3B7338, 0x8C8

	.global gUnk_083B7C00
gUnk_083B7C00:
	.incbin "baserom.gba", 0x3B7C00, 0xD4

	.global gUnk_083B7CD4
gUnk_083B7CD4:
	.incbin "baserom.gba", 0x3B7CD4, 0x138

	.global gUnk_083B7E0C
gUnk_083B7E0C:
	.incbin "baserom.gba", 0x3B7E0C, 0xB0

	.global gUnk_083B7EBC
gUnk_083B7EBC:
	.incbin "baserom.gba", 0x3B7EBC, 0x84

	.global gUnk_083B7F40
gUnk_083B7F40:
	.incbin "baserom.gba", 0x3B7F40, 0x230

	.global gUnk_083B8170
gUnk_083B8170:
	.incbin "baserom.gba", 0x3B8170, 0xEC

	.global gUnk_083B825C
gUnk_083B825C:
	.incbin "baserom.gba", 0x3B825C, 0x20

	.global gUnk_083B827C
gUnk_083B827C:
	.incbin "baserom.gba", 0x3B827C, 0x225C

	.global gUnk_083BA4D8
gUnk_083BA4D8:
	.incbin "baserom.gba", 0x3BA4D8, 0x14F4

	.global gUnk_083BB9CC
gUnk_083BB9CC:
	.incbin "baserom.gba", 0x3BB9CC, 0x1EB8

	.global gUnk_083BD884
gUnk_083BD884:
	.incbin "baserom.gba", 0x3BD884, 0xB60

	.global gUnk_083BE3E4
gUnk_083BE3E4:
	.incbin "baserom.gba", 0x3BE3E4, 0x304

	.global gUnk_083BE6E8
gUnk_083BE6E8:
	.incbin "baserom.gba", 0x3BE6E8, 0x244

	.global gUnk_083BE92C
gUnk_083BE92C:
	.incbin "baserom.gba", 0x3BE92C, 0x50

	.global gUnk_083BE97C
gUnk_083BE97C:
	.incbin "baserom.gba", 0x3BE97C, 0x6C

	.global gUnk_083BE9E8
gUnk_083BE9E8:
	.incbin "baserom.gba", 0x3BE9E8, 0x2C

	.global gUnk_083BEA14
gUnk_083BEA14:
	.incbin "baserom.gba", 0x3BEA14, 0x7C

	.global gUnk_083BEA90
gUnk_083BEA90:
	.incbin "baserom.gba", 0x3BEA90, 0x600

	.global gUnk_083BF090
gUnk_083BF090:
	.incbin "baserom.gba", 0x3BF090, 0x2970

	.global gUnk_083C1A00
gUnk_083C1A00:
	.incbin "baserom.gba", 0x3C1A00, 0x11BC

	.global gUnk_083C2BBC
gUnk_083C2BBC:
	.incbin "baserom.gba", 0x3C2BBC, 0xDC8

	.global gUnk_083C3984
gUnk_083C3984:
	.incbin "baserom.gba", 0x3C3984, 0x180

	.global gUnk_083C3B04
gUnk_083C3B04:
	.incbin "baserom.gba", 0x3C3B04, 0x58

	.global gUnk_083C3B5C
gUnk_083C3B5C:
	.incbin "baserom.gba", 0x3C3B5C, 0x3DC

	.global gUnk_083C3F38
gUnk_083C3F38:
	.incbin "baserom.gba", 0x3C3F38, 0x180

	.global gUnk_083C40B8
gUnk_083C40B8:
	.incbin "baserom.gba", 0x3C40B8, 0xB

	.global gUnk_083C40C3
gUnk_083C40C3:
	.incbin "baserom.gba", 0x3C40C3, 0x5A9

	.global gUnk_083C466C
gUnk_083C466C:
	.incbin "baserom.gba", 0x3C466C, 0x3A4

	.global gUnk_083C4A10
gUnk_083C4A10:
	.incbin "baserom.gba", 0x3C4A10, 0x200

	.global gUnk_083C4C10
gUnk_083C4C10:
	.incbin "baserom.gba", 0x3C4C10, 0x50

	.global gUnk_083C4C60
gUnk_083C4C60:
	.incbin "baserom.gba", 0x3C4C60, 0x28

	.global gUnk_083C4C88
gUnk_083C4C88:
	.incbin "baserom.gba", 0x3C4C88, 0x193C

	.global gUnk_083C65C4
gUnk_083C65C4:
	.incbin "baserom.gba", 0x3C65C4, 0x564

	.global gUnk_083C6B28
gUnk_083C6B28:
	.incbin "baserom.gba", 0x3C6B28, 0x210

	.global gUnk_083C6D38
gUnk_083C6D38:
	.incbin "baserom.gba", 0x3C6D38, 0xB0

	.global gUnk_083C6DE8
gUnk_083C6DE8:
	.incbin "baserom.gba", 0x3C6DE8, 0x10

	.global gUnk_083C6DF8
gUnk_083C6DF8:
	.incbin "baserom.gba", 0x3C6DF8, 0x3E00

	.global gUnk_083CABF8
gUnk_083CABF8:
	.incbin "baserom.gba", 0x3CABF8, 0x33EC

	.global gUnk_083CDFE4
gUnk_083CDFE4:
	.incbin "baserom.gba", 0x3CDFE4, 0x210

	.global gUnk_083CE1F4
gUnk_083CE1F4:
	.incbin "baserom.gba", 0x3CE1F4, 0x28C

	.global gUnk_083CE480
gUnk_083CE480:
	.incbin "baserom.gba", 0x3CE480, 0x7F4

	.global gUnk_083CEC74
gUnk_083CEC74:
	.incbin "baserom.gba", 0x3CEC74, 0x94

	.global gUnk_083CED08
gUnk_083CED08:
	.incbin "baserom.gba", 0x3CED08, 0x80

	.global gUnk_083CED88
gUnk_083CED88:
	.incbin "baserom.gba", 0x3CED88, 0x80

	.global gUnk_083CEE08
gUnk_083CEE08:
	.incbin "baserom.gba", 0x3CEE08, 0x80

	.global gUnk_083CEE88
gUnk_083CEE88:
	.incbin "baserom.gba", 0x3CEE88, 0x40

	.global gUnk_083CEEC8
gUnk_083CEEC8:
	.incbin "baserom.gba", 0x3CEEC8, 0x40

	.global gUnk_083CEF08
gUnk_083CEF08:
	.incbin "baserom.gba", 0x3CEF08, 0x40

	.global gUnk_083CEF48
gUnk_083CEF48:
	.incbin "baserom.gba", 0x3CEF48, 0x40

	.global gUnk_083CEF88
gUnk_083CEF88:
	.incbin "baserom.gba", 0x3CEF88, 0x40

	.global gUnk_083CEFC8
gUnk_083CEFC8:
	.incbin "baserom.gba", 0x3CEFC8, 0x40

	.global gUnk_083CF008
gUnk_083CF008:
	.incbin "baserom.gba", 0x3CF008, 0x40

	.global gUnk_083CF048
gUnk_083CF048:
	.incbin "baserom.gba", 0x3CF048, 0x40

	.global gUnk_083CF088
gUnk_083CF088:
	.incbin "baserom.gba", 0x3CF088, 0x40

	.global gUnk_083CF0C8
gUnk_083CF0C8:
	.incbin "baserom.gba", 0x3CF0C8, 0x40

	.global gUnk_083CF108
gUnk_083CF108:
	.incbin "baserom.gba", 0x3CF108, 0x40

	.global gUnk_083CF148
gUnk_083CF148:
	.incbin "baserom.gba", 0x3CF148, 0x268

	.global gUnk_083CF3B0
gUnk_083CF3B0:
	.incbin "baserom.gba", 0x3CF3B0, 0x2848

	.global gUnk_083D1BF8
gUnk_083D1BF8:
	.incbin "baserom.gba", 0x3D1BF8, 0xC8

	.global gUnk_083D1CC0
gUnk_083D1CC0:
	.incbin "baserom.gba", 0x3D1CC0, 0xEC

	.global gUnk_083D1DAC
gUnk_083D1DAC:
	.incbin "baserom.gba", 0x3D1DAC, 0xEC

	.global gUnk_083D1E98
gUnk_083D1E98:
	.incbin "baserom.gba", 0x3D1E98, 0xEC

	.global gUnk_083D1F84
gUnk_083D1F84:
	.4byte nullsub_08000840
	.4byte field_update
	.4byte sub_08057024
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gFieldSubStates
gFieldSubStates:
	.4byte new_game_init
	.4byte sub_0804A5C0
	.4byte sub_0804A654
	.4byte sub_0804A670
	.4byte sub_0804A67C
	.4byte sub_0804A694
	.4byte sub_0804A6A0
	.4byte sub_0804A6AC
	.4byte sub_0804A6D8
	.4byte sub_0804A6E8
	.4byte sub_0804A718
	.4byte sub_0804A8B4
	.4byte nullsub_0804B110
	.4byte sub_0804A8F8
	.4byte sub_0804A9B8
	.4byte nullsub_0804B110
	.4byte sub_0804A9F8
	.4byte sub_0804AA28
	.4byte sub_0804AAB8
	.4byte sub_0804AACC
	.4byte sub_0804AAD8
	.4byte nullsub_0804B110
	.4byte nullsub_0804B110
	.4byte nullsub_0804B110
	.4byte sub_0804AAF0
	.4byte sub_0804AB14
	.4byte sub_0804AB5C
	.4byte nullsub_0804B110
	.4byte sub_0804AB74
	.4byte sub_0804AB80
	.4byte sub_0804ABC8
	.4byte nullsub_0804B110
	.4byte sub_0804AC7C
	.4byte sub_0804AC88
	.4byte sub_0804AD1C
	.4byte sub_0804AD68
	.4byte nullsub_0804B110
	.4byte nullsub_0804B110
	.4byte nullsub_0804B110
	.4byte nullsub_0804B110
	.4byte sub_0804AE34
	.4byte sub_0804AE7C
	.4byte nullsub_0804B110
	.4byte nullsub_0804B110
	.4byte nullsub_0804B110
	.4byte nullsub_0804B110
	.4byte nullsub_0804B110
	.4byte nullsub_0804B110
	.4byte sub_0804AF4C
	.4byte sub_0804AF6C
	.4byte sub_0804AF80
	.4byte sub_0804AF94
	.4byte sub_0804AFBC
	.incbin "baserom.gba", 0x3D2080, 0x2C

	.global gMapScriptCommands
gMapScriptCommands:
	.4byte nullsub_0804B6F0
	.4byte sub_0804B6F4
	.4byte sub_0804B700
	.4byte sub_0804B72C
	.4byte sub_0804B740
	.4byte sub_0804B768
	.4byte map_script_cmd_end
	.4byte sub_0804B80C
	.4byte sub_0804B860
	.4byte sub_0804B8B4
	.4byte sub_0804B90C
	.4byte sub_0804B964
	.4byte sub_0804B980
	.4byte sub_0804BA10
	.4byte sub_0804BA50
	.4byte sub_0804BAA0
	.4byte sub_0804BAC8
	.4byte sub_0804BB54
	.4byte sub_0804BB7C
	.4byte sub_0804BBA8
	.4byte sub_0804BBD4
	.4byte sub_0804BC20
	.4byte sub_0804BC88
	.4byte sub_0804BCBC
	.4byte sub_0804BCF8
	.4byte sub_0804BD24
	.4byte sub_0804BD8C
	.4byte sub_0804BE04
	.4byte sub_0804BE78
	.4byte sub_0804BEE8
	.4byte sub_0804BF68
	.4byte sub_0804BFE0
	.4byte sub_0804C02C
	.4byte sub_0804C078
	.4byte sub_0804C0B4
	.4byte sub_0804C0E4
	.4byte sub_0804C11C
	.4byte sub_0804C154
	.4byte sub_0804C174
	.4byte sub_0804C1C4
	.4byte sub_0804C220
	.4byte sub_0804C27C
	.4byte sub_0804C2A4
	.4byte sub_0804C2CC
	.4byte sub_0804C318
	.4byte sub_0804C360
	.4byte sub_0804C398
	.4byte sub_0804C3F8
	.4byte sub_0804C42C
	.4byte sub_0804C468
	.4byte sub_0804C4AC
	.4byte sub_0804C4F0
	.4byte sub_0804C53C
	.4byte sub_0804C598
	.4byte sub_0804C5FC
	.4byte sub_0804C62C
	.4byte sub_0804C65C
	.4byte sub_0804C67C
	.4byte sub_0804C69C
	.4byte sub_0804C6BC
	.4byte sub_0804C6DC
	.4byte sub_0804C704
	.4byte sub_0804C72C
	.4byte sub_0804C790
	.4byte sub_0804C7F4
	.4byte sub_0804C81C
	.4byte nullsub_0804C8DC
	.4byte sub_0804C8E0
	.4byte sub_0804C900
	.4byte sub_0804C914
	.4byte sub_0804C938
	.4byte sub_0804C948
	.4byte sub_0804C954
	.4byte sub_0804C978
	.4byte sub_0804C988
	.4byte sub_0804C9DC
	.4byte sub_0804CA38
	.4byte sub_0804CA9C
	.4byte sub_0804CAE8
	.4byte sub_0804CB48
	.4byte sub_0804CB90
	.4byte sub_0804CC10
	.4byte sub_0804CC60
	.4byte sub_0804CCA8
	.4byte nullsub_0804CD14
	.4byte nullsub_0804CD18
	.4byte sub_0804CD1C
	.4byte nullsub_0804CD30
	.4byte nullsub_0804CD34
	.4byte sub_0804CD38
	.4byte sub_0804CD58
	.4byte sub_0804CDB8
	.4byte sub_0804CDF8
	.4byte map_script_cmd_set_medawatch_flag
	.4byte sub_0804CEAC
	.4byte sub_0804CEF4
	.4byte sub_0804CF10
	.4byte sub_0804CFC0
	.4byte sub_0804CFCC
	.4byte sub_0804CFD8
	.4byte sub_0804D038
	.4byte nullsub_0804D044
	.4byte sub_0804D048
	.4byte sub_0804D094
	.4byte sub_0804D0B4
	.4byte sub_0804D10C
	.4byte nullsub_0804D1B8
	.4byte sub_0804D1BC
	.4byte sub_0804D1D8
	.4byte sub_0804D224
	.4byte sub_0804D25C
	.4byte sub_0804D2A8
	.4byte sub_0804D2E0
	.4byte sub_0804D2F4
	.4byte sub_0804D308
	.4byte sub_0804D31C
	.4byte nullsub_0804D330
	.4byte nullsub_0804D334
	.4byte sub_0804D338
	.4byte nullsub_0804D34C
	.4byte sub_0804D350
	.4byte sub_0804D3B4
	.4byte sub_0804D3D8
	.4byte sub_0804D3EC
	.4byte nullsub_0804D440
	.4byte sub_0804D444
	.4byte sub_0804D460
	.4byte sub_0804D488
	.4byte sub_0804D4B0
	.4byte sub_0804D534
	.4byte sub_0804D590
	.4byte sub_0804D5A4
	.4byte sub_0804D70C
	.4byte sub_0804D72C
	.4byte sub_0804D760
	.4byte sub_0804D798
	.4byte sub_0804D7AC
	.incbin "baserom.gba", 0x3D22D0, 0x1DC

	.global gUnk_083D24AC
gUnk_083D24AC:
	.incbin "baserom.gba", 0x3D24AC, 0x4

	.global gMapScriptUpdates
gMapScriptUpdates:
	.4byte nullsub_0804DBE8
	.4byte map_script_update_message
	.4byte sub_0804DCAC
	.4byte sub_0804DCB8
	.4byte sub_0804DCCC
	.4byte sub_0804DCF0
	.4byte nullsub_0804DBE8
	.4byte sub_0804DD10
	.4byte sub_0804DD24
	.4byte sub_0804DD38
	.4byte sub_0804DD50
	.4byte sub_0804DD68
	.4byte sub_0804DD74
	.4byte nullsub_0804DBE8
	.4byte sub_0804DE28
	.4byte sub_0804DEF4
	.4byte sub_0804E0E8
	.4byte sub_0804E324
	.4byte nullsub_0804DBE8
	.4byte nullsub_0804DBE8
	.4byte nullsub_0804DBE8
	.4byte nullsub_0804DBE8
	.4byte nullsub_0804DBE8
	.4byte nullsub_0804DBE8
	.4byte nullsub_0804DBE8
	.4byte nullsub_0804DBE8
	.4byte sub_0804E3F0
	.4byte nullsub_0804DBE8
	.4byte nullsub_0804DBE8
	.4byte sub_0804E404
	.4byte sub_0804E418
	.4byte sub_0804E434
	.4byte sub_0804E440
	.4byte nullsub_0804DBE8
	.4byte nullsub_0804DBE8
	.4byte sub_0804E4D0
	.4byte sub_0804E4DC
	.4byte nullsub_0804DBE8
	.4byte sub_0804E540
	.4byte sub_0804E55C
	.4byte sub_0804E570
	.4byte sub_0804E584
	.4byte sub_0804E594
	.4byte sub_0804E6B4
	.4byte nullsub_0804DBE8
	.4byte sub_0804E738
	.4byte nullsub_0804E790
	.4byte nullsub_0804E794
	.4byte nullsub_0804E798
	.4byte sub_0804E79C
	.4byte sub_0804E814
	.4byte sub_0804E878
	.4byte nullsub_0804DBE8
	.4byte nullsub_0804DBE8
	.4byte sub_0804E8DC
	.4byte sub_0804E9CC
	.4byte map_script_update_give_medapart
	.4byte sub_0804EBEC
	.4byte map_script_update_give_money
	.4byte map_script_update_take_money
	.4byte map_script_update_give_medal
	.4byte sub_0804EF10
	.4byte nullsub_0804DBE8
	.4byte nullsub_0804DBE8
	.4byte sub_0804EFB0
	.4byte sub_0804F058
	.4byte sub_0804F0C4
	.4byte sub_0804F3AC
	.4byte nullsub_0804DBE8
	.4byte nullsub_0804DBE8
	.4byte nullsub_0804DBE8
	.4byte nullsub_0804DBE8
	.4byte nullsub_0804DBE8
	.4byte nullsub_0804DBE8
	.4byte nullsub_0804DBE8
	.4byte nullsub_0804DBE8
	.4byte nullsub_0804DBE8
	.4byte nullsub_0804DBE8
	.4byte nullsub_0804DBE8
	.4byte nullsub_0804DBE8
	.4byte nullsub_0804DBE8
	.4byte nullsub_0804F57C
	.4byte nullsub_0804F580
	.4byte nullsub_0804F584
	.4byte nullsub_0804F588
	.4byte nullsub_0804F58C
	.4byte sub_0804F590
	.4byte nullsub_0804F628
	.4byte nullsub_0804F62C
	.4byte sub_0804F630
	.4byte nullsub_0804F678
	.4byte nullsub_0804F67C
	.4byte nullsub_0804F680
	.4byte nullsub_0804F684
	.4byte nullsub_0804F688
	.4byte nullsub_0804F68C
	.4byte nullsub_0804DBE8
	.4byte nullsub_0804DBE8
	.4byte nullsub_0804F690
	.4byte sub_0804F694
	.4byte nullsub_0804DBE8
	.4byte nullsub_0804DBE8
	.4byte sub_0804F7F0
	.4byte sub_0804F804
	.4byte nullsub_0804DBE8
	.4byte nullsub_0804DBE8
	.4byte nullsub_0804F814
	.4byte nullsub_0804DBE8
	.4byte sub_0804F818
	.4byte sub_0804F89C
	.4byte sub_0804F8F4
	.4byte sub_0804F978
	.4byte sub_0804F9D0
	.4byte sub_0804FA10
	.4byte sub_0804FA50
	.4byte sub_0804FA90
	.4byte nullsub_0804DBE8
	.4byte nullsub_0804DBE8
	.4byte sub_0804FAD0
	.4byte nullsub_0804DBE8
	.4byte sub_0804FB40
	.4byte sub_0804FB90
	.4byte sub_0804FBD0
	.4byte nullsub_0804DBE8
	.4byte nullsub_0804DBE8
	.4byte nullsub_0804DBE8
	.4byte sub_0804FC20
	.4byte sub_0804FC30
	.4byte nullsub_0804DBE8
	.4byte nullsub_0804DBE8
	.4byte sub_0804FCC4
	.4byte nullsub_0804DBE8
	.4byte sub_0804FE20
	.4byte nullsub_0804DBE8
	.4byte nullsub_0804DBE8
	.4byte sub_0804FE50
	.4byte nullsub_0804DBE8
	.incbin "baserom.gba", 0x3D26D4, 0x1DC

	.global gUnk_083D28B0
gUnk_083D28B0:
	.incbin "baserom.gba", 0x3D28B0, 0x10

	.global gUnk_083D28C0
gUnk_083D28C0:
	.incbin "baserom.gba", 0x3D28C0, 0x3

	.global gUnk_083D28C3
gUnk_083D28C3:
	.incbin "baserom.gba", 0x3D28C3, 0x40

	.global gUnk_083D2903
gUnk_083D2903:
	.incbin "baserom.gba", 0x3D2903, 0x5

	.global gUnk_083D2908
gUnk_083D2908:
	.incbin "baserom.gba", 0x3D2908, 0x10

	.global gUnk_083D2918
gUnk_083D2918:
	.incbin "baserom.gba", 0x3D2918, 0x80

	.global gUnk_083D2998
gUnk_083D2998:
	.incbin "baserom.gba", 0x3D2998, 0xE

	.global gUnk_083D29A6
gUnk_083D29A6:
	.incbin "baserom.gba", 0x3D29A6, 0x10

	.global gUnk_083D29B6
gUnk_083D29B6:
	.incbin "baserom.gba", 0x3D29B6, 0x30

	.global gUnk_083D29E6
gUnk_083D29E6:
	.incbin "baserom.gba", 0x3D29E6, 0x5

	.global gUnk_083D29EB
gUnk_083D29EB:
	.incbin "baserom.gba", 0x3D29EB, 0xC0

	.global gUnk_083D2AAB
gUnk_083D2AAB:
	.incbin "baserom.gba", 0x3D2AAB, 0x9

	.global gUnk_083D2AB4
gUnk_083D2AB4:
	.incbin "baserom.gba", 0x3D2AB4, 0x24

	.global gUnk_083D2AD8
gUnk_083D2AD8:
	.incbin "baserom.gba", 0x3D2AD8, 0x1

	.global gUnk_083D2AD9
gUnk_083D2AD9:
	.incbin "baserom.gba", 0x3D2AD9, 0x4

	.global gUnk_083D2ADD
gUnk_083D2ADD:
	.incbin "baserom.gba", 0x3D2ADD, 0xB0

	.global gUnk_083D2B8D
gUnk_083D2B8D:
	.incbin "baserom.gba", 0x3D2B8D, 0xB0

	.global gUnk_083D2C3D
gUnk_083D2C3D:
	.incbin "baserom.gba", 0x3D2C3D, 0x173

	.global gUnk_083D2DB0
gUnk_083D2DB0:
	.incbin "baserom.gba", 0x3D2DB0, 0x2FD4

	.global gUnk_083D5D84
gUnk_083D5D84:
	.incbin "baserom.gba", 0x3D5D84, 0x84

	.global gUnk_083D5E08
gUnk_083D5E08:
	.4byte sub_08057044
	.4byte sub_080572F8
	.4byte sub_0805738C
	.4byte sub_08057494
	.4byte sub_08057540
	.4byte sub_08057550
	.4byte sub_08057574
	.4byte sub_08057588
	.4byte sub_08057598
	.4byte sub_08057988
	.4byte sub_080579C4
	.4byte sub_08057A24
	.4byte sub_08057B68
	.4byte sub_08057BBC
	.4byte sub_08057BCC
	.4byte sub_08057BF8
	.4byte sub_08057C08
	.incbin "baserom.gba", 0x3D5E4C, 0xE0

	.global gUnk_083D5F2C
gUnk_083D5F2C:
	.incbin "baserom.gba", 0x3D5F2C, 0x4

	.global gUnk_083D5F30
gUnk_083D5F30:
	.incbin "baserom.gba", 0x3D5F30, 0x140

	.global gUnk_083D6070
gUnk_083D6070:
	.incbin "baserom.gba", 0x3D6070, 0xC

	.global gUnk_083D607C
gUnk_083D607C:
	.incbin "baserom.gba", 0x3D607C, 0xC

	.global gUnk_083D6088
gUnk_083D6088:
	.incbin "baserom.gba", 0x3D6088, 0x54

	.global gUnk_083D60DC
gUnk_083D60DC:
	.incbin "baserom.gba", 0x3D60DC, 0x8C4

	.global gUnk_083D69A0
gUnk_083D69A0:
	.incbin "baserom.gba", 0x3D69A0, 0x200

	.global gUnk_083D6BA0
gUnk_083D6BA0:
	.incbin "baserom.gba", 0x3D6BA0, 0x300

	.global gUnk_083D6EA0
gUnk_083D6EA0:
	.incbin "baserom.gba", 0x3D6EA0, 0x400

	.global gUnk_083D72A0
gUnk_083D72A0:
	.incbin "baserom.gba", 0x3D72A0, 0x20954

	.global gUnk_083F7BF4
gUnk_083F7BF4:
	.incbin "baserom.gba", 0x3F7BF4, 0x400

	.global gUnk_083F7FF4
gUnk_083F7FF4:
	.incbin "baserom.gba", 0x3F7FF4, 0x100

	.global gUnk_083F80F4
gUnk_083F80F4:
	.incbin "baserom.gba", 0x3F80F4, 0x540

	.global gUnk_083F8634
gUnk_083F8634:
	.incbin "baserom.gba", 0x3F8634, 0x540

	.global gUnk_083F8B74
gUnk_083F8B74:
	.incbin "baserom.gba", 0x3F8B74, 0x180

	.global gUnk_083F8CF4
gUnk_083F8CF4:
	.incbin "baserom.gba", 0x3F8CF4, 0x300

	.global gUnk_083F8FF4
gUnk_083F8FF4:
	.incbin "baserom.gba", 0x3F8FF4, 0x300

	.global gUnk_083F92F4
gUnk_083F92F4:
	.incbin "baserom.gba", 0x3F92F4, 0x900

	.global gUnk_083F9BF4
gUnk_083F9BF4:
	.incbin "baserom.gba", 0x3F9BF4, 0xA9B4

	.global gUnk_084045A8
gUnk_084045A8:
	.incbin "baserom.gba", 0x4045A8, 0x514C

	.global gUnk_084096F4
gUnk_084096F4:
	.incbin "baserom.gba", 0x4096F4, 0x6400

	.global gUnk_0840FAF4
gUnk_0840FAF4:
	.incbin "baserom.gba", 0x40FAF4, 0x2260

	.global gUnk_08411D54
gUnk_08411D54:
	.incbin "baserom.gba", 0x411D54, 0x13C0

	.global gUnk_08413114
gUnk_08413114:
	.incbin "baserom.gba", 0x413114, 0x400

	.global gUnk_08413514
gUnk_08413514:
	.incbin "baserom.gba", 0x413514, 0xE80

	.global gUnk_08414394
gUnk_08414394:
	.incbin "baserom.gba", 0x414394, 0x5D4

	.global gTextTable
gTextTable:
	.incbin "baserom.gba", 0x414968, 0x69AF4

	.global gTextBankTables
gTextBankTables:
	.incbin "baserom.gba", 0x47E45C, 0x468

	.global gUnk_0847E8C4
gUnk_0847E8C4:
	.incbin "baserom.gba", 0x47E8C4, 0x84

	.global gUnk_0847E948
gUnk_0847E948:
	.incbin "baserom.gba", 0x47E948, 0x238

	.global gUnk_0847EB80
gUnk_0847EB80:
	.incbin "baserom.gba", 0x47EB80, 0xC0

	.global gUnk_0847EC40
gUnk_0847EC40:
	.incbin "baserom.gba", 0x47EC40, 0x80

	.global gUnk_0847ECC0
gUnk_0847ECC0:
	.incbin "baserom.gba", 0x47ECC0, 0x1340
