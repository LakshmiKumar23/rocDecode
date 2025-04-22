/*
Copyright (c) 2023 - 2025 Advanced Micro Devices, Inc. All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include "vaapi_log.h"

static void PrintAv1PicParams(VADecPictureParameterBufferAV1 *p_pic_param) {
    int i, j;
    printf("=======================\n");
    printf("Picture parameter Info:\n");
    printf("=======================\n");
    printf("profile = %d\n", p_pic_param->profile);
    printf("order_hint_bits_minus_1 = %d\n", p_pic_param->order_hint_bits_minus_1);
    printf("bit_depth_idx = %d\n", p_pic_param->bit_depth_idx);
    printf("matrix_coefficients = %d\n", p_pic_param->matrix_coefficients);
    printf("still_picture = %d\n", p_pic_param->seq_info_fields.fields.still_picture);
    printf("use_128x128_superblock = %d\n", p_pic_param->seq_info_fields.fields.use_128x128_superblock);
    printf("enable_filter_intra = %d\n", p_pic_param->seq_info_fields.fields.enable_filter_intra);
    printf("enable_intra_edge_filter = %d\n", p_pic_param->seq_info_fields.fields.enable_intra_edge_filter);
    printf("enable_interintra_compound = %d\n", p_pic_param->seq_info_fields.fields.enable_interintra_compound);
    printf("enable_masked_compound = %d\n", p_pic_param->seq_info_fields.fields.enable_masked_compound);
    printf("enable_dual_filter = %d\n", p_pic_param->seq_info_fields.fields.enable_dual_filter);
    printf("enable_order_hint = %d\n", p_pic_param->seq_info_fields.fields.enable_order_hint);
    printf("enable_jnt_comp = %d\n", p_pic_param->seq_info_fields.fields.enable_jnt_comp);
    printf("enable_cdef = %d\n", p_pic_param->seq_info_fields.fields.enable_cdef);
    printf("mono_chrome = %d\n", p_pic_param->seq_info_fields.fields.mono_chrome);
    printf("color_range = %d\n", p_pic_param->seq_info_fields.fields.color_range);
    printf("subsampling_x = %d\n", p_pic_param->seq_info_fields.fields.subsampling_x);
    printf("subsampling_y = %d\n", p_pic_param->seq_info_fields.fields.subsampling_y);
    printf("chroma_sample_position = %d\n", p_pic_param->seq_info_fields.fields.chroma_sample_position);
    printf("film_grain_params_present = %d\n", p_pic_param->seq_info_fields.fields.film_grain_params_present);

    printf("current_frame = %d\n", p_pic_param->current_frame);
    printf("current_display_picture = %d\n", p_pic_param->current_display_picture);
    printf("anchor_frames_num = %d\n", p_pic_param->anchor_frames_num);
    printf("anchor_frames_list = %p\n", p_pic_param->anchor_frames_list);
    printf("frame_width_minus1 = %d\n", p_pic_param->frame_width_minus1);
    printf("frame_height_minus1 = %d\n", p_pic_param->frame_height_minus1);
    printf("output_frame_width_in_tiles_minus_1 = %d\n", p_pic_param->output_frame_width_in_tiles_minus_1);
    printf("output_frame_height_in_tiles_minus_1 = %d\n", p_pic_param->output_frame_height_in_tiles_minus_1);

    printf("ref_frame_map[]:");
    for (i = 0; i < AV1_NUM_REF_FRAMES; i++) {
        printf(" %d", p_pic_param->ref_frame_map[i]);
    }
    printf("\n");
    printf("ref_frame_idx[]:");
    for (i = 0; i < AV1_REFS_PER_FRAME; i++) {
        printf(" %d", p_pic_param->ref_frame_idx[i]);
    }
    printf("\n");
    printf("primary_ref_frame = %d\n", p_pic_param->primary_ref_frame);
    printf("order_hint = %d\n", p_pic_param->order_hint);

    printf("segmentation_enabled = %d\n", p_pic_param->seg_info.segment_info_fields.bits.enabled);
    printf("segmentation_update_map = %d\n", p_pic_param->seg_info.segment_info_fields.bits.update_map);
    printf("segmentation_temporal_update = %d\n", p_pic_param->seg_info.segment_info_fields.bits.temporal_update);
    printf("segmentation_update_data = %d\n", p_pic_param->seg_info.segment_info_fields.bits.update_data);
    for (i = 0; i < AV1_MAX_SEGMENTS; i++) {
        printf("Segment %d:\n", i);
        printf("feature_data[]:");
        for (j = 0; j < AV1_SEG_LVL_MAX; j++) {
            printf(" %d", p_pic_param->seg_info.feature_data[i][j]);
        }
        printf("\n");
        printf("feature_mask = 0x%x\n", p_pic_param->seg_info.feature_mask[i]);
    }

    printf("apply_grain = %d\n", p_pic_param->film_grain_info.film_grain_info_fields.bits.apply_grain);
    printf("chroma_scaling_from_luma = %d\n", p_pic_param->film_grain_info.film_grain_info_fields.bits.chroma_scaling_from_luma);
    printf("grain_scaling_minus_8 = %d\n", p_pic_param->film_grain_info.film_grain_info_fields.bits.grain_scaling_minus_8);
    printf("ar_coeff_lag = %d\n", p_pic_param->film_grain_info.film_grain_info_fields.bits.ar_coeff_lag);
    printf("ar_coeff_shift_minus_6 = %d\n", p_pic_param->film_grain_info.film_grain_info_fields.bits.ar_coeff_shift_minus_6);
    printf("grain_scale_shift = %d\n", p_pic_param->film_grain_info.film_grain_info_fields.bits.grain_scale_shift);
    printf("overlap_flag = %d\n", p_pic_param->film_grain_info.film_grain_info_fields.bits.overlap_flag);
    printf("clip_to_restricted_range = %d\n", p_pic_param->film_grain_info.film_grain_info_fields.bits.clip_to_restricted_range);
    printf("grain_seed = %d\n", p_pic_param->film_grain_info.grain_seed);
    printf("num_y_points = %d\n", p_pic_param->film_grain_info.num_y_points);
    printf("point_y_value[]:");
    for (i = 0; i < p_pic_param->film_grain_info.num_y_points; i++) {
        printf(" %d", p_pic_param->film_grain_info.point_y_value[i]);
    }
    printf("\n");
    printf("point_y_scaling[]:");
    for (i = 0; i < p_pic_param->film_grain_info.num_y_points; i++) {
        printf(" %d", p_pic_param->film_grain_info.point_y_scaling[i]);
    }
    printf("\n");
    printf("num_cb_points = %d\n", p_pic_param->film_grain_info.num_cb_points);
    printf("point_cb_value[]:");
    for (i = 0; i < p_pic_param->film_grain_info.num_cb_points; i++) {
        printf(" %d", p_pic_param->film_grain_info.point_cb_value[i]);
    }
    printf("\n");
    printf("point_cb_scaling[]:");
    for (i = 0; i < p_pic_param->film_grain_info.num_cb_points; i++) {
        printf(" %d", p_pic_param->film_grain_info.point_cb_scaling[i]);
    }
    printf("\n");
    printf("num_cr_points = %d\n", p_pic_param->film_grain_info.num_cr_points);
    printf("point_cr_value[]:");
    for (i = 0; i < p_pic_param->film_grain_info.num_cr_points; i++) {
        printf(" %d", p_pic_param->film_grain_info.point_cr_value[i]);
    }
    printf("\n");
    printf("point_cr_scaling[]:");
    for (i = 0; i < p_pic_param->film_grain_info.num_cr_points; i++) {
        printf(" %d", p_pic_param->film_grain_info.point_cr_scaling[i]);
    }
    printf("\n");

    printf("ar_coeffs_y[]:");
    for (i = 0; i < 24; i++) {
        printf(" %d", p_pic_param->film_grain_info.ar_coeffs_y[i]);
    }
    printf("\n");
    printf("ar_coeffs_cb[]:");
    for (i = 0; i < 25; i++) {
        printf(" %d", p_pic_param->film_grain_info.ar_coeffs_cb[i]);
    }
    printf("\n");
    printf("ar_coeffs_cr[]:");
    for (i = 0; i < 25; i++) {
        printf(" %d", p_pic_param->film_grain_info.ar_coeffs_cr[i]);
    }
    printf("\n");
    printf("cb_mult = %d\n", p_pic_param->film_grain_info.cb_mult);
    printf("cb_luma_mult = %d\n", p_pic_param->film_grain_info.cb_luma_mult);
    printf("cb_offset = %d\n", p_pic_param->film_grain_info.cb_offset);
    printf("cr_mult = %d\n", p_pic_param->film_grain_info.cr_mult);
    printf("cr_luma_mult = %d\n", p_pic_param->film_grain_info.cr_luma_mult);
    printf("cr_offset = %d\n", p_pic_param->film_grain_info.cr_offset);

    printf("tile_cols = %d\n", p_pic_param->tile_cols);
    printf("tile_rows = %d\n", p_pic_param->tile_rows);
    printf("width_in_sbs_minus_1[]:");
    for (i = 0; i < p_pic_param->tile_cols; i++) {
        printf(" %d", p_pic_param->width_in_sbs_minus_1[i]);
    }
    printf("\n");
    printf("height_in_sbs_minus_1[]:");
    for (i = 0; i < p_pic_param->tile_rows; i++) {
        printf(" %d", p_pic_param->height_in_sbs_minus_1[i]);
    }
    printf("\n");
    printf("tile_count_minus_1 = %d\n", p_pic_param->tile_count_minus_1);
    printf("context_update_tile_id = %d\n", p_pic_param->context_update_tile_id);

    printf("frame_type = %d\n", p_pic_param->pic_info_fields.bits.frame_type);
    printf("show_frame = %d\n", p_pic_param->pic_info_fields.bits.show_frame);
    printf("showable_frame = %d\n", p_pic_param->pic_info_fields.bits.showable_frame);
    printf("error_resilient_mode = %d\n", p_pic_param->pic_info_fields.bits.error_resilient_mode);
    printf("disable_cdf_update = %d\n", p_pic_param->pic_info_fields.bits.disable_cdf_update);
    printf("allow_screen_content_tools = %d\n", p_pic_param->pic_info_fields.bits.allow_screen_content_tools);
    printf("force_integer_mv = %d\n", p_pic_param->pic_info_fields.bits.force_integer_mv);
    printf("allow_intrabc = %d\n", p_pic_param->pic_info_fields.bits.allow_intrabc);
    printf("use_superres = %d\n", p_pic_param->pic_info_fields.bits.use_superres);
    printf("allow_high_precision_mv = %d\n", p_pic_param->pic_info_fields.bits.allow_high_precision_mv);
    printf("is_motion_mode_switchable = %d\n", p_pic_param->pic_info_fields.bits.is_motion_mode_switchable);
    printf("use_ref_frame_mvs = %d\n", p_pic_param->pic_info_fields.bits.use_ref_frame_mvs);
    printf("disable_frame_end_update_cdf = %d\n", p_pic_param->pic_info_fields.bits.disable_frame_end_update_cdf);
    printf("uniform_tile_spacing_flag = %d\n", p_pic_param->pic_info_fields.bits.uniform_tile_spacing_flag);
    printf("allow_warped_motion = %d\n", p_pic_param->pic_info_fields.bits.allow_warped_motion);
    printf("large_scale_tile = %d\n", p_pic_param->pic_info_fields.bits.large_scale_tile);

    printf("superres_scale_denominator = %d\n", p_pic_param->superres_scale_denominator);
    printf("interp_filter = %d\n", p_pic_param->interp_filter);
    printf("filter_level[] = %d, %d\n", p_pic_param->filter_level[0], p_pic_param->filter_level[1]);
    printf("filter_level_u = %d\n", p_pic_param->filter_level_u);
    printf("filter_level_v = %d\n", p_pic_param->filter_level_v);
    printf("sharpness_level = %d\n", p_pic_param->loop_filter_info_fields.bits.sharpness_level);
    printf("mode_ref_delta_enabled = %d\n", p_pic_param->loop_filter_info_fields.bits.mode_ref_delta_enabled);
    printf("mode_ref_delta_update = %d\n", p_pic_param->loop_filter_info_fields.bits.mode_ref_delta_update);
    printf("ref_deltas[]:");
    for (i = 0; i < AV1_TOTAL_REFS_PER_FRAME; i++) {
        printf(" %d", p_pic_param->ref_deltas[i]);
    }
    printf("\n");
    printf("mode_deltas[]:");
    for (i = 0; i < 2; i++) {
        printf(" %d", p_pic_param->mode_deltas[i]);
    }
    printf("\n");

    printf("base_qindex = %d\n", p_pic_param->base_qindex);
    printf("y_dc_delta_q = %d\n", p_pic_param->y_dc_delta_q);
    printf("u_dc_delta_q = %d\n", p_pic_param->u_dc_delta_q);
    printf("u_ac_delta_q = %d\n", p_pic_param->u_ac_delta_q);
    printf("v_dc_delta_q = %d\n", p_pic_param->v_dc_delta_q);
    printf("v_ac_delta_q = %d\n", p_pic_param->v_ac_delta_q);
    printf("using_qmatrix = %d\n", p_pic_param->qmatrix_fields.bits.using_qmatrix);
    printf("qm_y = %d\n", p_pic_param->qmatrix_fields.bits.qm_y);
    printf("qm_u = %d\n", p_pic_param->qmatrix_fields.bits.qm_u);
    printf("qm_v = %d\n", p_pic_param->qmatrix_fields.bits.qm_v);

    printf("delta_q_present_flag = %d\n", p_pic_param->mode_control_fields.bits.delta_q_present_flag);
    printf("log2_delta_q_res = %d\n", p_pic_param->mode_control_fields.bits.log2_delta_q_res);
    printf("delta_lf_present_flag = %d\n", p_pic_param->mode_control_fields.bits.delta_lf_present_flag);
    printf("log2_delta_lf_res = %d\n", p_pic_param->mode_control_fields.bits.log2_delta_lf_res);
    printf("delta_lf_multi = %d\n", p_pic_param->mode_control_fields.bits.delta_lf_multi);
    printf("tx_mode = %d\n", p_pic_param->mode_control_fields.bits.tx_mode);
    printf("reference_select = %d\n", p_pic_param->mode_control_fields.bits.reference_select);
    printf("reduced_tx_set_used = %d\n", p_pic_param->mode_control_fields.bits.reduced_tx_set_used);
    printf("skip_mode_present = %d\n", p_pic_param->mode_control_fields.bits.skip_mode_present);

    printf("cdef_damping_minus_3 = %d\n", p_pic_param->cdef_damping_minus_3);
    printf("cdef_bits = %d\n", p_pic_param->cdef_bits);
    printf("cdef_y_strengths[]:");
    for (int i = 0; i < 8; i++) {
        printf(" %d", p_pic_param->cdef_y_strengths[i]);
    }
    printf("\n");
    printf("cdef_uv_strengths[]:");
    for (int i = 0; i < 8; i++) {
        printf(" %d", p_pic_param->cdef_uv_strengths[i]);
    }
    printf("\n");

    printf("yframe_restoration_type = %d\n", p_pic_param->loop_restoration_fields.bits.yframe_restoration_type);
    printf("cbframe_restoration_type = %d\n", p_pic_param->loop_restoration_fields.bits.cbframe_restoration_type);
    printf("crframe_restoration_type = %d\n", p_pic_param->loop_restoration_fields.bits.crframe_restoration_type);
    printf("lr_unit_shift = %d\n", p_pic_param->loop_restoration_fields.bits.lr_unit_shift);
    printf("lr_uv_shift = %d\n", p_pic_param->loop_restoration_fields.bits.lr_uv_shift);

    for (i = AV1_REF_FRAME_LAST; i <= AV1_REF_FRAME_ALTREF; i++) {
        printf("wm[%d]:\n", i - 1);
        printf("invalid = %d, wmtype = %d\n", p_pic_param->wm[i - 1].invalid, p_pic_param->wm[i - 1].wmtype);
        printf("wmmat[]:");
        for (int j = 0; j < 6; j++) {
            printf(" %d", p_pic_param->wm[i - 1].wmmat[j]);
        }
        printf("\n");
    }
}

static void DumpAvcPicParams(VAPictureParameterBufferH264 *p_pic_params) {
    printf("================================\n");
    printf("VAPictureParameterBufferH264:\n");

    printf("CurrPic:\n");
    printf("    picture_id = %d, frame_idx = %d, flags = 0x%x, TopFieldOrderCnt = %d, BottomFieldOrderCnt = %d\n", p_pic_params->CurrPic.picture_id, p_pic_params->CurrPic.frame_idx, p_pic_params->CurrPic.flags, p_pic_params->CurrPic.TopFieldOrderCnt, p_pic_params->CurrPic.BottomFieldOrderCnt);
    printf("ReferenceFrames[16]:\n");
    for (int i = 0; i < 16; i++) {
        printf("    %d: picture_id = %d, frame_idx = %d, flags = 0x%x, TopFieldOrderCnt = %d, BottomFieldOrderCnt = %d\n", i, p_pic_params->ReferenceFrames[i].picture_id, p_pic_params->ReferenceFrames[i].frame_idx, p_pic_params->ReferenceFrames[i].flags, p_pic_params->ReferenceFrames[i].TopFieldOrderCnt, p_pic_params->ReferenceFrames[i].BottomFieldOrderCnt);
    }
    printf("picture_width_in_mbs_minus1 = %d\n", p_pic_params->picture_width_in_mbs_minus1);
    printf("picture_height_in_mbs_minus1 = %d\n", p_pic_params->picture_height_in_mbs_minus1);
    printf("bit_depth_luma_minus8 = %d\n", p_pic_params->bit_depth_luma_minus8);
    printf("bit_depth_chroma_minus8 = %d\n", p_pic_params->bit_depth_chroma_minus8);
    printf("num_ref_frames = %d\n", p_pic_params->num_ref_frames);
    printf("seq_fields:\n");
    printf("    chroma_format_idc = %d\n", p_pic_params->seq_fields.bits.chroma_format_idc);
    printf("    residual_colour_transform_flag = %d\n", p_pic_params->seq_fields.bits.residual_colour_transform_flag);
    printf("    gaps_in_frame_num_value_allowed_flag = %d\n", p_pic_params->seq_fields.bits.gaps_in_frame_num_value_allowed_flag);
    printf("    frame_mbs_only_flag = %d\n", p_pic_params->seq_fields.bits.frame_mbs_only_flag);
    printf("    mb_adaptive_frame_field_flag = %d\n", p_pic_params->seq_fields.bits.mb_adaptive_frame_field_flag);
    printf("    direct_8x8_inference_flag = %d\n", p_pic_params->seq_fields.bits.direct_8x8_inference_flag);
    printf("    MinLumaBiPredSize8x8 = %d\n", p_pic_params->seq_fields.bits.MinLumaBiPredSize8x8);
    printf("    log2_max_frame_num_minus4 = %d\n", p_pic_params->seq_fields.bits.log2_max_frame_num_minus4);
    printf("    pic_order_cnt_type = %d\n", p_pic_params->seq_fields.bits.pic_order_cnt_type);
    printf("    log2_max_pic_order_cnt_lsb_minus4 = %d\n", p_pic_params->seq_fields.bits.log2_max_pic_order_cnt_lsb_minus4);
    printf("    delta_pic_order_always_zero_flag = %d\n", p_pic_params->seq_fields.bits.delta_pic_order_always_zero_flag);
    printf("num_slice_groups_minus1 = %d\n", p_pic_params->num_slice_groups_minus1);
    printf("slice_group_map_type = %d\n", p_pic_params->slice_group_map_type);
    printf("slice_group_change_rate_minus1 = %d\n", p_pic_params->slice_group_change_rate_minus1);
    printf("pic_init_qp_minus26 = %d\n", p_pic_params->pic_init_qp_minus26);
    printf("pic_init_qs_minus26 = %d\n", p_pic_params->pic_init_qs_minus26);
    printf("chroma_qp_index_offset = %d\n", p_pic_params->chroma_qp_index_offset);
    printf("second_chroma_qp_index_offset = %d\n", p_pic_params->second_chroma_qp_index_offset);
    printf("pic_fields:\n");
    printf("    entropy_coding_mode_flag = %d\n", p_pic_params->pic_fields.bits.entropy_coding_mode_flag);
    printf("    weighted_pred_flag = %d\n", p_pic_params->pic_fields.bits.weighted_pred_flag);
    printf("    weighted_bipred_idc = %d\n", p_pic_params->pic_fields.bits.weighted_bipred_idc);
    printf("    transform_8x8_mode_flag = %d\n", p_pic_params->pic_fields.bits.transform_8x8_mode_flag);
    printf("    field_pic_flag = %d\n", p_pic_params->pic_fields.bits.field_pic_flag);
    printf("    constrained_intra_pred_flag = %d\n", p_pic_params->pic_fields.bits.constrained_intra_pred_flag);
    printf("    pic_order_present_flag = %d\n", p_pic_params->pic_fields.bits.pic_order_present_flag);
    printf("    deblocking_filter_control_present_flag = %d\n", p_pic_params->pic_fields.bits.deblocking_filter_control_present_flag);
    printf("    redundant_pic_cnt_present_flag = %d\n", p_pic_params->pic_fields.bits.redundant_pic_cnt_present_flag);
    printf("    reference_pic_flag = %d\n", p_pic_params->pic_fields.bits.reference_pic_flag);
    printf("frame_num = %d\n", p_pic_params->frame_num);
    printf("================================\n");
    printf("\n");
}

static void DumpAvcSliceParam(VASliceParameterBufferH264 *p_slice_param) {
    printf("================================\n");
    printf("VASliceParameterBufferH264:\n");
    printf("slice_data_size = %d\n", p_slice_param->slice_data_size);
    printf("slice_data_offset = %d\n", p_slice_param->slice_data_offset);
    printf("slice_data_flag = %d\n", p_slice_param->slice_data_flag);
    printf("slice_data_bit_offset = %d\n", p_slice_param->slice_data_bit_offset);
    printf("first_mb_in_slice = %d\n", p_slice_param->first_mb_in_slice);
    printf("slice_type = %d\n", p_slice_param->slice_type);
    printf("direct_spatial_mv_pred_flag = %d\n", p_slice_param->direct_spatial_mv_pred_flag);
    printf("num_ref_idx_l0_active_minus1 = %d\n", p_slice_param->num_ref_idx_l0_active_minus1);
    printf("num_ref_idx_l1_active_minus1 = %d\n", p_slice_param->num_ref_idx_l1_active_minus1);
    printf("cabac_init_idc = %d\n", p_slice_param->cabac_init_idc);
    printf("slice_qp_delta = %d\n", p_slice_param->slice_qp_delta);
    printf("disable_deblocking_filter_idc = %d\n", p_slice_param->disable_deblocking_filter_idc);
    printf("slice_alpha_c0_offset_div2 = %d\n", p_slice_param->slice_alpha_c0_offset_div2);
    printf("slice_beta_offset_div2 = %d\n", p_slice_param->slice_beta_offset_div2);
    printf("RefPicList0[32]:\n");
    for (int i = 0; i < 32; i++) {
        printf("    %d: picture_id = %d, frame_idx = %d, flags = 0x%x, TopFieldOrderCnt = %d, BottomFieldOrderCnt = %d\n", i, p_slice_param->RefPicList0[i].picture_id, p_slice_param->RefPicList0[i].frame_idx, p_slice_param->RefPicList0[i].flags, p_slice_param->RefPicList0[i].TopFieldOrderCnt, p_slice_param->RefPicList0[i].BottomFieldOrderCnt);
    }
    printf("RefPicList1[32]:\n");
    for (int i = 0; i < 32; i++) {
        printf("    %d: picture_id = %d, frame_idx = %d, flags = 0x%x, TopFieldOrderCnt = %d, BottomFieldOrderCnt = %d\n", i, p_slice_param->RefPicList1[i].picture_id, p_slice_param->RefPicList1[i].frame_idx, p_slice_param->RefPicList1[i].flags, p_slice_param->RefPicList1[i].TopFieldOrderCnt, p_slice_param->RefPicList1[i].BottomFieldOrderCnt);
    }
    printf("luma_log2_weight_denom = %d\n", p_slice_param->luma_log2_weight_denom);
    printf("chroma_log2_weight_denom = %d\n", p_slice_param->chroma_log2_weight_denom);
    printf("luma_weight_l0_flag = %d\n", p_slice_param->luma_weight_l0_flag);
    printf("luma_weight_l0[32]:\n    ");
    for (int i = 0; i < 32; i++) {
        printf("%d, ", p_slice_param->luma_weight_l0[i]);
    }
    printf("\n");
    printf("luma_offset_l0[32]:\n    ");
    for (int i = 0; i < 32; i++) {
        printf("%d, ", p_slice_param->luma_offset_l0[i]);
    }
    printf("\n");
    printf("chroma_weight_l0_flag = %d\n", p_slice_param->chroma_weight_l0_flag);
    printf("chroma_weight_l0[32][2]:\n    ");
    for (int i = 0; i < 32; i++) {
        printf("(%d %d), ", p_slice_param->chroma_weight_l0[i][0], p_slice_param->chroma_weight_l0[i][1]);
    }
    printf("\n");
    printf("chroma_offset_l0[32][2]:\n    ");
    for (int i = 0; i < 32; i++) {
        printf("(%d %d), ", p_slice_param->chroma_offset_l0[i][0], p_slice_param->chroma_offset_l0[i][1]);
    }
    printf("\n");

    printf("luma_weight_l1_flag = %d\n", p_slice_param->luma_weight_l1_flag);
    printf("luma_weight_l1[32]:\n    ");
    for (int i = 0; i < 32; i++) {
        printf("%d, ", p_slice_param->luma_weight_l1[i]);
    }
    printf("\n");
    printf("luma_offset_l1[32]:\n    ");
    for (int i = 0; i < 32; i++) {
        printf("%d, ", p_slice_param->luma_offset_l1[i]);
    }
    printf("\n");
    printf("chroma_weight_l1_flag = %d\n", p_slice_param->chroma_weight_l1_flag);
    printf("chroma_weight_l1[32][2]:\n    ");
    for (int i = 0; i < 32; i++) {
        printf("(%d %d), ", p_slice_param->chroma_weight_l1[i][0], p_slice_param->chroma_weight_l1[i][1]);
    }
    printf("\n");
    printf("chroma_offset_l1[32][2]:\n    ");
    for (int i = 0; i < 32; i++) {
        printf("(%d %d), ", p_slice_param->chroma_offset_l1[i][0], p_slice_param->chroma_offset_l1[i][1]);
    }
    printf("\n");
    printf("================================\n");
    printf("\n");
}

static void PrintVp9PicParams(VADecPictureParameterBufferVP9 *p_pic_param) {
    int i;

    printf("=======================\n");
    printf("Picture parameter Info:\n");
    printf("=======================\n");
    printf("frame_width = %d\n", p_pic_param->frame_width);
    printf("frame_height = %d\n", p_pic_param->frame_height);
    printf("reference_frames[]:");
    for (i = 0; i < 8; i++) {
        printf(" %d", p_pic_param->reference_frames[i]);
    }
    printf("\n");
    printf("subsampling_x = %d\n", p_pic_param->pic_fields.bits.subsampling_x);
    printf("subsampling_y = %d\n", p_pic_param->pic_fields.bits.subsampling_y);
    printf("frame_type = %d\n", p_pic_param->pic_fields.bits.frame_type);
    printf("show_frame = %d\n", p_pic_param->pic_fields.bits.show_frame);
    printf("error_resilient_mode = %d\n", p_pic_param->pic_fields.bits.error_resilient_mode);
    printf("intra_only = %d\n", p_pic_param->pic_fields.bits.intra_only);
    printf("allow_high_precision_mv = %d\n", p_pic_param->pic_fields.bits.allow_high_precision_mv);
    printf("mcomp_filter_type = %d\n", p_pic_param->pic_fields.bits.mcomp_filter_type);
    printf("frame_parallel_decoding_mode = %d\n", p_pic_param->pic_fields.bits.frame_parallel_decoding_mode);
    printf("reset_frame_context = %d\n", p_pic_param->pic_fields.bits.reset_frame_context);
    printf("refresh_frame_context = %d\n", p_pic_param->pic_fields.bits.refresh_frame_context);
    printf("frame_context_idx = %d\n", p_pic_param->pic_fields.bits.frame_context_idx);
    printf("segmentation_enabled = %d\n", p_pic_param->pic_fields.bits.segmentation_enabled);
    printf("segmentation_temporal_update = %d\n", p_pic_param->pic_fields.bits.segmentation_temporal_update);
    printf("segmentation_update_map = %d\n", p_pic_param->pic_fields.bits.segmentation_update_map);
    printf("last_ref_frame = %d\n", p_pic_param->pic_fields.bits.last_ref_frame);
    printf("last_ref_frame_sign_bias = %d\n", p_pic_param->pic_fields.bits.last_ref_frame_sign_bias);
    printf("golden_ref_frame = %d\n", p_pic_param->pic_fields.bits.golden_ref_frame);
    printf("golden_ref_frame_sign_bias = %d\n", p_pic_param->pic_fields.bits.golden_ref_frame_sign_bias);
    printf("alt_ref_frame = %d\n", p_pic_param->pic_fields.bits.alt_ref_frame);
    printf("alt_ref_frame_sign_bias = %d\n", p_pic_param->pic_fields.bits.alt_ref_frame_sign_bias);
    printf("lossless_flag = %d\n", p_pic_param->pic_fields.bits.lossless_flag);
    printf("filter_level = %d\n", (p_pic_param->filter_level));
    printf("sharpness_level = %d\n", (p_pic_param->sharpness_level));
    printf("log2_tile_rows = %d\n", (p_pic_param->log2_tile_rows));
    printf("log2_tile_columns = %d\n", (p_pic_param->log2_tile_columns));
    printf("frame_header_length_in_bytes = %d\n", (p_pic_param->frame_header_length_in_bytes));
    printf("first_partition_size = %d\n", p_pic_param->first_partition_size);
    printf("mb_segment_tree_probs[]:");
    for (i = 0; i < 7; i++) {
        printf(" %d", (p_pic_param->mb_segment_tree_probs[i]));
    }
    printf("\n");
    printf("segment_pred_probs[]:");
    for (i = 0; i < 3; i++) {
        printf(" %d", (p_pic_param->segment_pred_probs[i]));
    }
    printf("\n");
    printf("profile = %d\n", (p_pic_param->profile));
    printf("bit_depth = %d\n", (p_pic_param->bit_depth));
}

static void PrintVp9STileInfo(VASliceParameterBufferVP9 *p_tile_param) {
    printf("=======================\n");
    printf("Tile parameter Info: \n");
    printf("=======================\n");
    printf("slice_data_size = %d\n", p_tile_param->slice_data_size);
    printf("slice_data_offset = %d\n", p_tile_param->slice_data_offset);
    printf("slice_data_flag = %d\n", p_tile_param->slice_data_flag);

    for (int i = 0; i < 8; i++) {
        VASegmentParameterVP9 *p_seg_param = &p_tile_param->seg_param[i];
        printf("Segment %d:\n", i);
        printf("segment_reference_enabled = %d\n", p_seg_param->segment_flags.fields.segment_reference_enabled);
        printf("segment_reference = %d\n", p_seg_param->segment_flags.fields.segment_reference);
        printf("segment_reference_skipped = %d\n", p_seg_param->segment_flags.fields.segment_reference_skipped);
        printf("filter_level[4][2]: ");
        for (int j = 0; j < 4; j++) {
            printf("(%d %d) ", (p_seg_param->filter_level[j][0]), (p_seg_param->filter_level[j][1]));
        }
        printf("\n");
        printf("luma_ac_quant_scale = %d\n", p_seg_param->luma_ac_quant_scale);
        printf("luma_dc_quant_scale = %d\n", p_seg_param->luma_dc_quant_scale);
        printf("chroma_ac_quant_scale = %d\n", p_seg_param->chroma_ac_quant_scale);
        printf("chroma_dc_quant_scale = %d\n", p_seg_param->chroma_dc_quant_scale);
    }
}

static void DumpHevcPicParams(VAPictureParameterBufferHEVC *p_pic_params) {
    printf("================================\n");
    printf("VAPictureParameterBufferHEVC:\n");

    printf("CurrPic:\n");
    printf("    picture_id = %d, flags = 0x%x, pic_order_cnt = %d\n", p_pic_params->CurrPic.picture_id, p_pic_params->CurrPic.flags, p_pic_params->CurrPic.pic_order_cnt);
    printf("ReferenceFrames[15]:\n");
    for (int i = 0; i < 15; i++) {
        printf("    %d: picture_id = %d, flags = 0x%x, pic_order_cnt = %d\n", i, p_pic_params->ReferenceFrames[i].picture_id, p_pic_params->ReferenceFrames[i].flags, p_pic_params->ReferenceFrames[i].pic_order_cnt);
    }

    printf("pic_width_in_luma_samples = %d\n", p_pic_params->pic_width_in_luma_samples);
    printf("pic_height_in_luma_samples = %d\n", p_pic_params->pic_height_in_luma_samples);

    printf("sps_max_dec_pic_buffering_minus1 = %d\n", p_pic_params->sps_max_dec_pic_buffering_minus1);
    printf("bit_depth_luma_minus8 = %d\n", p_pic_params->bit_depth_luma_minus8);
    printf("bit_depth_chroma_minus8 = %d\n", p_pic_params->bit_depth_chroma_minus8);
    printf("pcm_sample_bit_depth_luma_minus1 = %d\n", p_pic_params->pcm_sample_bit_depth_luma_minus1);
    printf("pcm_sample_bit_depth_chroma_minus1 = %d\n", p_pic_params->pcm_sample_bit_depth_chroma_minus1);
    printf("log2_min_luma_coding_block_size_minus3 = %d\n", p_pic_params->log2_min_luma_coding_block_size_minus3);
    printf("log2_diff_max_min_luma_coding_block_size = %d\n", p_pic_params->log2_diff_max_min_luma_coding_block_size);
    printf("log2_min_transform_block_size_minus2 = %d\n", p_pic_params->log2_min_transform_block_size_minus2);
    printf("log2_diff_max_min_transform_block_size = %d\n", p_pic_params->log2_diff_max_min_transform_block_size);
    printf("log2_min_pcm_luma_coding_block_size_minus3 = %d\n", p_pic_params->log2_min_pcm_luma_coding_block_size_minus3);
    printf("log2_diff_max_min_pcm_luma_coding_block_size = %d\n", p_pic_params->log2_diff_max_min_pcm_luma_coding_block_size);
    printf("max_transform_hierarchy_depth_intra = %d\n", p_pic_params->max_transform_hierarchy_depth_intra);
    printf("max_transform_hierarchy_depth_inter = %d\n", p_pic_params->max_transform_hierarchy_depth_inter);
    printf("init_qp_minus26 = %d\n", p_pic_params->init_qp_minus26);
    printf("diff_cu_qp_delta_depth = %d\n", p_pic_params->diff_cu_qp_delta_depth);
    printf("pps_cb_qp_offset = %d\n", p_pic_params->pps_cb_qp_offset);
    printf("pps_cr_qp_offset = %d\n", p_pic_params->pps_cr_qp_offset);
    printf("log2_parallel_merge_level_minus2 = %d\n", p_pic_params->log2_parallel_merge_level_minus2);
    printf("num_tile_columns_minus1 = %d\n", p_pic_params->num_tile_columns_minus1);
    printf("num_tile_rows_minus1 = %d\n", p_pic_params->num_tile_rows_minus1);

    for (int i = 0; i < 19; i++) {
        printf("    %d: column_width_minus1 = %d\n", i, column_width_minus1[i]);
    }

    for (int i = 0; i < 21; i++) {
        printf("    %d: row_height_minus1 = %d\n", i, row_height_minus1[i]);
    }

    printf("log2_max_pic_order_cnt_lsb_minus4 = %d\n", p_pic_params->log2_max_pic_order_cnt_lsb_minus4);
    printf("num_short_term_ref_pic_sets = %d\n", p_pic_params->num_short_term_ref_pic_sets);
    printf("num_long_term_ref_pic_sps = %d\n", p_pic_params->num_long_term_ref_pic_sps);
    printf("num_ref_idx_l0_default_active_minus1 = %d\n", p_pic_params->num_ref_idx_l0_default_active_minus1);
    printf("num_ref_idx_l1_default_active_minus1 = %d\n", p_pic_params->num_ref_idx_l1_default_active_minus1);
    printf("pps_beta_offset_div2 = %d\n", p_pic_params->pps_beta_offset_div2);
    printf("pps_tc_offset_div2 = %d\n", p_pic_params->pps_tc_offset_div2);
    printf("num_extra_slice_header_bits = %d\n", p_pic_params->num_extra_slice_header_bits);

    printf("st_rps_bits = %d\n", p_pic_params->st_rps_bits);

    printf("pic_fields:\n");
    printf("    chroma_format_idc = %d\n", p_pic_params->pic_fields.bits.chroma_format_idc);
    printf("    separate_colour_plane_flag = %d\n", p_pic_params->pic_fields.bits.separate_colour_plane_flag);
    printf("    pcm_enabled_flag = %d\n", p_pic_params->pic_fields.bits.pcm_enabled_flag);
    printf("    scaling_list_enabled_flag = %d\n", p_pic_params->pic_fields.bits.scaling_list_enabled_flag);
    printf("    transform_skip_enabled_flag = %d\n", p_pic_params->pic_fields.bits.transform_skip_enabled_flag);
    printf("    amp_enabled_flag = %d\n", p_pic_params->pic_fields.bits.amp_enabled_flag);
    printf("    strong_intra_smoothing_enabled_flag = %d\n", p_pic_params->pic_fields.bits.strong_intra_smoothing_enabled_flag);
    printf("    sign_data_hiding_enabled_flag = %d\n", p_pic_params->pic_fields.bits.sign_data_hiding_enabled_flag);
    printf("    constrained_intra_pred_flag = %d\n", p_pic_params->pic_fields.bits.constrained_intra_pred_flag);
    printf("    cu_qp_delta_enabled_flag = %d\n", p_pic_params->pic_fields.bits.cu_qp_delta_enabled_flag);
    printf("    weighted_pred_flag = %d\n", p_pic_params->pic_fields.bits.weighted_pred_flag);
    printf("    transquant_bypass_enabled_flag = %d\n", p_pic_params->pic_fields.bits.transquant_bypass_enabled_flag);
    printf("    tiles_enabled_flag = %d\n", p_pic_params->pic_fields.bits.tiles_enabled_flag);
    printf("    entropy_coding_sync_enabled_flag = %d\n", p_pic_params->pic_fields.bits.entropy_coding_sync_enabled_flag);
    printf("    pps_loop_filter_across_slices_enabled_flag = %d\n", p_pic_params->pic_fields.bits.pps_loop_filter_across_slices_enabled_flag);
    printf("    loop_filter_across_tiles_enabled_flag = %d\n", p_pic_params->pic_fields.bits.loop_filter_across_tiles_enabled_flag);
    printf("    pcm_loop_filter_disabled_flag = %d\n", p_pic_params->pic_fields.bits.pcm_loop_filter_disabled_flag);
    printf("    NoPicReorderingFlag = %d\n", p_pic_params->pic_fields.bits.NoPicReorderingFlag);
    printf("    NoBiPredFlag = %d\n", p_pic_params->pic_fields.bits.NoBiPredFlag);
    printf("    value = %d\n", p_pic_params->pic_fields.value);

    printf("slice_parsing_fields:\n");
    printf("    lists_modification_present_flag = %d\n", p_pic_params->slice_parsing_fields.bits.lists_modification_present_flag);
    printf("    long_term_ref_pics_present_flag = %d\n", p_pic_params->slice_parsing_fields.bits.long_term_ref_pics_present_flag);
    printf("    sps_temporal_mvp_enabled_flag = %d\n", p_pic_params->slice_parsing_fields.bits.sps_temporal_mvp_enabled_flag);
    printf("    cabac_init_present_flag = %d\n", p_pic_params->slice_parsing_fields.bits.cabac_init_present_flag);
    printf("    output_flag_present_flag = %d\n", p_pic_params->slice_parsing_fields.bits.output_flag_present_flag);
    printf("    dependent_slice_segments_enabled_flag = %d\n", p_pic_params->slice_parsing_fields.bits.dependent_slice_segments_enabled_flag);
    printf("    pps_slice_chroma_qp_offsets_present_flag = %d\n", p_pic_params->slice_parsing_fields.bits.pps_slice_chroma_qp_offsets_present_flag);
    printf("    sample_adaptive_offset_enabled_flag = %d\n", p_pic_params->slice_parsing_fields.bits.sample_adaptive_offset_enabled_flag);
    printf("    deblocking_filter_override_enabled_flag = %d\n", p_pic_params->slice_parsing_fields.bits.deblocking_filter_override_enabled_flag);
    printf("    pps_disable_deblocking_filter_flag = %d\n", p_pic_params->slice_parsing_fields.bits.pps_disable_deblocking_filter_flag);
    printf("    slice_segment_header_extension_present_flag = %d\n", p_pic_params->slice_parsing_fields.bits.slice_segment_header_extension_present_flag);
    printf("    RapPicFlag = %d\n", p_pic_params->slice_parsing_fields.bits.RapPicFlag);
    printf("    IdrPicFlag = %d\n", p_pic_params->slice_parsing_fields.bits.IdrPicFlag);
    printf("    IntraPicFlag = %d\n", p_pic_params->slice_parsing_fields.bits.IntraPicFlag);
    printf("================================\n");
    printf("\n");
}

static void DumpHevcSliceParams(VASliceParameterBufferHEVC *p_slice_param) {
    printf("================================\n");
    printf("VASliceParameterBufferHEVC:\n");

    printf("slice_data_size = %d\n", p_slice_param->slice_data_size);
    printf("slice_data_offset = %d\n", p_slice_param->slice_data_offset);
    printf("slice_data_flag = %d\n", p_slice_param->slice_data_flag);
    printf("slice_data_byte_offset = %d\n", p_slice_param->slice_data_byte_offset);
    printf("slice_segment_address = %d\n", p_slice_param->slice_segment_address);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 15; j++) {
            printf("RefPicList[%d][%d] = %d\n", i ,j, p_slice_param->RefPicList[i][j]);
        }
    }

    printf("LongSliceFlags:\n");
    printf("    LastSliceOfPic = %d\n", p_slice_param->LongSliceFlags.fields.LastSliceOfPic);
    printf("    dependent_slice_segment_flag = %d\n", p_slice_param->LongSliceFlags.fields.dependent_slice_segment_flag);
    printf("    slice_type = %d\n", p_slice_param->LongSliceFlags.fields.slice_type);
    printf("    color_plane_id = %d\n", p_slice_param->LongSliceFlags.fields.color_plane_id);
    printf("    slice_sao_luma_flag = %d\n", p_slice_param->LongSliceFlags.fields.slice_sao_luma_flag);
    printf("    slice_sao_chroma_flag = %d\n", p_slice_param->LongSliceFlags.fields.slice_sao_chroma_flag);
    printf("    mvd_l1_zero_flag = %d\n", p_slice_param->LongSliceFlags.fields.mvd_l1_zero_flag);
    printf("    cabac_init_flag = %d\n", p_slice_param->LongSliceFlags.fields.cabac_init_flag);
    printf("    slice_temporal_mvp_enabled_flag = %d\n", p_slice_param->LongSliceFlags.fields.slice_temporal_mvp_enabled_flag);
    printf("    slice_deblocking_filter_disabled_flag = %d\n", p_slice_param->LongSliceFlags.fields.slice_deblocking_filter_disabled_flag);
    printf("    collocated_from_l0_flag = %d\n", p_slice_param->LongSliceFlags.fields.collocated_from_l0_flag);
    printf("    slice_loop_filter_across_slices_enabled_flag = %d\n", p_slice_param->LongSliceFlags.fields.slice_loop_filter_across_slices_enabled_flag);

    printf("collocated_ref_idx = %d\n", p_slice_param->collocated_ref_idx);
    printf("num_ref_idx_l0_active_minus1 = %d\n", p_slice_param->num_ref_idx_l0_active_minus1);
    printf("num_ref_idx_l1_active_minus1 = %d\n", p_slice_param->num_ref_idx_l1_active_minus1);
    printf("slice_qp_delta = %d\n", p_slice_param->slice_qp_delta);
    printf("slice_cb_qp_offset = %d\n", p_slice_param->slice_cb_qp_offset);
    printf("slice_cr_qp_offset = %d\n", p_slice_param->slice_cr_qp_offset);
    printf("slice_beta_offset_div2 = %d\n", p_slice_param->slice_beta_offset_div2);
    printf("slice_tc_offset_div2 = %d\n", p_slice_param->slice_tc_offset_div2);
    printf("luma_log2_weight_denom = %d\n", p_slice_param->luma_log2_weight_denom);
    printf("delta_chroma_log2_weight_denom = %d\n", p_slice_param->delta_chroma_log2_weight_denom);
    for (int i = 0; i < 15; i++) {
        printf("delta_luma_weight_l0[%d] = %d\n", i, p_slice_param->delta_luma_weight_l0);
    }
    for (int i = 0; i < 15; i++) {
        printf("luma_offset_l0[%d] = %d\n", i, p_slice_param->luma_offset_l0);
    }
    for (int i = 0; i < 15; i++) {
        printf("delta_luma_weight_l1[%d] = %d\n", i, p_slice_param->delta_luma_weight_l1);
    }
    for (int i = 0; i < 15; i++) {
        printf("luma_offset_l1[%d] = %d\n", i, p_slice_param->luma_offset_l1);
    }
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 2; j++) {
            printf("delta_chroma_weight_l0[%d][%d] = %d\n", i ,j, p_slice_param->delta_chroma_weight_l0[i][j]);
        }
    }
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 2; j++) {
            printf("ChromaOffsetL0[%d][%d] = %d\n", i ,j, p_slice_param->ChromaOffsetL0[i][j]);
        }
    }
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 2; j++) {
            printf("ChromaOffsetL1[%d][%d] = %d\n", i ,j, p_slice_param->ChromaOffsetL1[i][j]);
        }
    }
    printf("five_minus_max_num_merge_cand = %d\n", p_slice_param->five_minus_max_num_merge_cand);
    printf("num_entry_point_offsets = %d\n", p_slice_param->num_entry_point_offsets);
    printf("entry_offset_to_subset_array = %d\n", p_slice_param->entry_offset_to_subset_array);
    printf("slice_data_num_emu_prevn_bytes = %d\n", p_slice_param->slice_data_num_emu_prevn_bytes);
    printf("================================\n");
    printf("\n");
}