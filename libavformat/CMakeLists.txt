get_library_version(avformat version.h LIBAVFORMAT_VERSION)

set(AVFORMAT_HEADERS avformat.h
    avio.h
    version.h
)

set(AVFORMAT_SOURCES allformats.c
    avio.c
    aviobuf.c
    cutils.c
    dump.c
    format.c
    id3v1.c
    id3v2.c
    metadata.c
    mux.c
    options.c
    os_support.c
    qtpalette.c
    protocols.c
    riff.c
    sdp.c
    url.c
    utils.c
)

if (NOT DISABLE_NETWORK)
    list(APPEND AVFORMAT_SOURCES network.c)
endif ()

if ((${CONFIG_RTSP_MUXER} EQUAL 1) OR (${CONFIG_RTSP_DEXMUER} EQUAL 1) OR (${CONFIG_SDP_DEMUXER} EQUAL 1))
    list(APPEND AVFORMAT_SOURCES rtsp.c)
endif ()

if (${CONFIG_RTP_PROTOCOL} EQUAL 1)
    list(APPEND AVFORMAT_SOURCES rtpproto.c ip.c)
endif ()

# generated from Makefile
if (${CONFIG_ISO_MEDIA})
    list(APPEND AVFORMAT_SOURCES isom.c)
endif ()
if (${CONFIG_NETWORK})
    list(APPEND AVFORMAT_SOURCES network.c)
endif ()
if (${CONFIG_RIFFDEC})
    list(APPEND AVFORMAT_SOURCES riffdec.c)
endif ()
if (${CONFIG_RIFFENC})
    list(APPEND AVFORMAT_SOURCES riffenc.c)
endif ()
if (${CONFIG_RTPDEC})
    list(APPEND AVFORMAT_SOURCES rdt.c
		rtp.c
		rtpdec.c
		rtpdec_ac3.c
		rtpdec_amr.c
		rtpdec_asf.c
		rtpdec_dv.c
		rtpdec_g726.c
		rtpdec_h261.c
		rtpdec_h263.c
		rtpdec_h263_rfc2190.c
		rtpdec_h264.c
		rtpdec_hevc.c
		rtpdec_ilbc.c
		rtpdec_jpeg.c
		rtpdec_latm.c
		rtpdec_mpa_robust.c
		rtpdec_mpeg12.c
		rtpdec_mpeg4.c
		rtpdec_mpegts.c
		rtpdec_qcelp.c
		rtpdec_qdm2.c
		rtpdec_qt.c
		rtpdec_rfc4175.c
		rtpdec_svq3.c
		rtpdec_vc2hq.c
		rtpdec_vp8.c
		rtpdec_vp9.c
		rtpdec_xiph.c
	)
endif ()
if (${CONFIG_RTPENC_CHAIN})
    list(APPEND AVFORMAT_SOURCES rtpenc_chain.c
		rtp.c
	)
endif ()
if (${CONFIG_SHARED})
    list(APPEND AVFORMAT_SOURCES log2_tab.c
		golomb_tab.c
	)
endif ()
if (${CONFIG_SRTP})
    list(APPEND AVFORMAT_SOURCES srtp.c)
endif ()
if (${CONFIG_A64_MUXER})
    list(APPEND AVFORMAT_SOURCES a64.c
		rawenc.c
	)
endif ()
if (${CONFIG_AA_DEMUXER})
    list(APPEND AVFORMAT_SOURCES aadec.c)
endif ()
if (${CONFIG_AAC_DEMUXER})
    list(APPEND AVFORMAT_SOURCES aacdec.c
		apetag.c
		img2.c
		rawdec.c
	)
endif ()
if (${CONFIG_AC3_DEMUXER})
    list(APPEND AVFORMAT_SOURCES ac3dec.c
		rawdec.c
	)
endif ()
if (${CONFIG_AC3_MUXER})
    list(APPEND AVFORMAT_SOURCES rawenc.c)
endif ()
if (${CONFIG_ACE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES acedec.c)
endif ()
if (${CONFIG_ACM_DEMUXER})
    list(APPEND AVFORMAT_SOURCES acm.c
		rawdec.c
	)
endif ()
if (${CONFIG_ACT_DEMUXER})
    list(APPEND AVFORMAT_SOURCES act.c)
endif ()
if (${CONFIG_ADF_DEMUXER})
    list(APPEND AVFORMAT_SOURCES bintext.c
		sauce.c
	)
endif ()
if (${CONFIG_ADP_DEMUXER})
    list(APPEND AVFORMAT_SOURCES adp.c)
endif ()
if (${CONFIG_ADS_DEMUXER})
    list(APPEND AVFORMAT_SOURCES ads.c)
endif ()
if (${CONFIG_ADTS_MUXER})
    list(APPEND AVFORMAT_SOURCES adtsenc.c
		apetag.c
		img2.c
        id3v2enc.c
	)
endif ()
if (${CONFIG_ADX_DEMUXER})
    list(APPEND AVFORMAT_SOURCES adxdec.c)
endif ()
if (${CONFIG_ADX_MUXER})
    list(APPEND AVFORMAT_SOURCES rawenc.c)
endif ()
if (${CONFIG_AEA_DEMUXER})
    list(APPEND AVFORMAT_SOURCES aea.c
		pcm.c
	)
endif ()
if (${CONFIG_AFC_DEMUXER})
    list(APPEND AVFORMAT_SOURCES afc.c)
endif ()
if (${CONFIG_AIFF_DEMUXER})
    list(APPEND AVFORMAT_SOURCES aiffdec.c
		pcm.c
		isom.c
        mov_chan.c
	)
endif ()
if (${CONFIG_AIFF_MUXER})
    list(APPEND AVFORMAT_SOURCES aiffenc.c
		id3v2enc.c
	)
endif ()
if (${CONFIG_AIX_DEMUXER})
    list(APPEND AVFORMAT_SOURCES aixdec.c)
endif ()
if (${CONFIG_ALP_DEMUXER})
    list(APPEND AVFORMAT_SOURCES alp.c)
endif ()
if (${CONFIG_AMR_DEMUXER})
    list(APPEND AVFORMAT_SOURCES amr.c)
endif ()
if (${CONFIG_AMR_MUXER})
    list(APPEND AVFORMAT_SOURCES amr.c)
endif ()
if (${CONFIG_AMRNB_DEMUXER})
    list(APPEND AVFORMAT_SOURCES amr.c)
endif ()
if (${CONFIG_AMRWB_DEMUXER})
    list(APPEND AVFORMAT_SOURCES amr.c)
endif ()
if (${CONFIG_AMV_MUXER})
    list(APPEND AVFORMAT_SOURCES amvenc.c)
endif ()
if (${CONFIG_ANM_DEMUXER})
    list(APPEND AVFORMAT_SOURCES anm.c)
endif ()
if (${CONFIG_APC_DEMUXER})
    list(APPEND AVFORMAT_SOURCES apc.c)
endif ()
if (${CONFIG_APE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES ape.c
		apetag.c
		img2.c
	)
endif ()
if (${CONFIG_APM_DEMUXER})
    list(APPEND AVFORMAT_SOURCES apm.c)
endif ()
if (${CONFIG_APNG_DEMUXER})
    list(APPEND AVFORMAT_SOURCES apngdec.c)
endif ()
if (${CONFIG_APNG_MUXER})
    list(APPEND AVFORMAT_SOURCES apngenc.c)
endif ()
if (${CONFIG_APTX_DEMUXER})
    list(APPEND AVFORMAT_SOURCES aptxdec.c
		rawdec.c
	)
endif ()
if (${CONFIG_APTX_MUXER})
    list(APPEND AVFORMAT_SOURCES rawenc.c)
endif ()
if (${CONFIG_AQTITLE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES aqtitledec.c
		subtitles.c
	)
endif ()
if (${CONFIG_ARGO_ASF_DEMUXER})
    list(APPEND AVFORMAT_SOURCES argo_asf.c)
endif ()
if (${CONFIG_ARGO_BRP_DEMUXER})
    list(APPEND AVFORMAT_SOURCES argo_brp.c argo_asf.c)
endif ()
if (${CONFIG_ASF_DEMUXER})
    list(APPEND AVFORMAT_SOURCES asfdec_f.c
		asf.c
		asfcrypt.c
        avlanguage.c
	)
endif ()
if (${CONFIG_ASF_O_DEMUXER})
    list(APPEND AVFORMAT_SOURCES asfdec_o.c
		asf.c
		asfcrypt.c
        avlanguage.c
	)
endif ()
if (${CONFIG_ASF_MUXER})
    list(APPEND AVFORMAT_SOURCES asfenc.c
		asf.c
		avlanguage.c
	)
endif ()
if (${CONFIG_ASS_DEMUXER})
    list(APPEND AVFORMAT_SOURCES assdec.c
		subtitles.c
	)
endif ()
if (${CONFIG_ASS_MUXER})
    list(APPEND AVFORMAT_SOURCES assenc.c)
endif ()
if (${CONFIG_AST_DEMUXER})
    list(APPEND AVFORMAT_SOURCES ast.c
		astdec.c
	)
endif ()
if (${CONFIG_AST_MUXER})
    list(APPEND AVFORMAT_SOURCES ast.c
		astenc.c
	)
endif ()
if (${CONFIG_AU_DEMUXER})
    list(APPEND AVFORMAT_SOURCES au.c
		pcm.c
	)
endif ()
if (${CONFIG_AU_MUXER})
    list(APPEND AVFORMAT_SOURCES au.c
		rawenc.c
	)
endif ()
if (${CONFIG_AVI_DEMUXER})
    list(APPEND AVFORMAT_SOURCES avidec.c)
endif ()
if (${CONFIG_AVI_MUXER})
    list(APPEND AVFORMAT_SOURCES avienc.c
		mpegtsenc.c
		avlanguage.c
		rawutils.c
	)
endif ()
if (${CONFIG_AVM2_MUXER})
    list(APPEND AVFORMAT_SOURCES swfenc.c
		swf.c
	)
endif ()
if (${CONFIG_AVR_DEMUXER})
    list(APPEND AVFORMAT_SOURCES avr.c
		pcm.c
	)
endif ()
if (${CONFIG_AVS_DEMUXER})
    list(APPEND AVFORMAT_SOURCES avs.c
		voc_packet.c
		vocdec.c
		voc.c
	)
endif ()
if (${CONFIG_AVS2_DEMUXER})
    list(APPEND AVFORMAT_SOURCES avs2dec.c rawdec.c)
endif ()
if (${CONFIG_AVS2_MUXER})
    list(APPEND AVFORMAT_SOURCES rawenc.c)
endif ()
if (${CONFIG_AVS3_DEMUXER})
    list(APPEND AVFORMAT_SOURCES avs3dec.c rawdec.c)
endif ()
if (${CONFIG_BETHSOFTVID_DEMUXER})
    list(APPEND AVFORMAT_SOURCES bethsoftvid.c)
endif ()
if (${CONFIG_BFI_DEMUXER})
    list(APPEND AVFORMAT_SOURCES bfi.c)
endif ()
if (${CONFIG_BINK_DEMUXER})
    list(APPEND AVFORMAT_SOURCES bink.c)
endif ()
if (${CONFIG_BINTEXT_DEMUXER})
    list(APPEND AVFORMAT_SOURCES bintext.c
		sauce.c
	)
endif ()
if (${CONFIG_BIT_DEMUXER})
    list(APPEND AVFORMAT_SOURCES bit.c)
endif ()
if (${CONFIG_BIT_MUXER})
    list(APPEND AVFORMAT_SOURCES bit.c)
endif ()
if (${CONFIG_BMV_DEMUXER})
    list(APPEND AVFORMAT_SOURCES bmv.c)
endif ()
if (${CONFIG_BOA_DEMUXER})
    list(APPEND AVFORMAT_SOURCES boadec.c)
endif ()
if (${CONFIG_BFSTM_DEMUXER})
    list(APPEND AVFORMAT_SOURCES brstm.c)
endif ()
if (${CONFIG_BRSTM_DEMUXER})
    list(APPEND AVFORMAT_SOURCES brstm.c)
endif ()
if (${CONFIG_C93_DEMUXER})
    list(APPEND AVFORMAT_SOURCES c93.c
		voc_packet.c
		vocdec.c
		voc.c
	)
endif ()
if (${CONFIG_CAF_DEMUXER})
    list(APPEND AVFORMAT_SOURCES cafdec.c
		caf.c
		mov_chan.c
		mov_esds.c
	)
endif ()
if (${CONFIG_CAF_MUXER})
    list(APPEND AVFORMAT_SOURCES cafenc.c
		caf.c
		riff.c
	)
endif ()
if (${CONFIG_CAVSVIDEO_DEMUXER})
    list(APPEND AVFORMAT_SOURCES cavsvideodec.c
		rawdec.c
	)
endif ()
if (${CONFIG_CAVSVIDEO_MUXER})
    list(APPEND AVFORMAT_SOURCES rawenc.c)
endif ()
if (${CONFIG_CDG_DEMUXER})
    list(APPEND AVFORMAT_SOURCES cdg.c)
endif ()
if (${CONFIG_CDXL_DEMUXER})
    list(APPEND AVFORMAT_SOURCES cdxl.c)
endif ()
if (${CONFIG_CINE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES cinedec.c)
endif ()
if (${CONFIG_CODEC2_DEMUXER})
    list(APPEND AVFORMAT_SOURCES codec2.c rawdec.c pcm.c)
endif ()
if (${CONFIG_CODEC2_MUXER})
    list(APPEND AVFORMAT_SOURCES codec2.c rawenc.c)
endif ()
if (${CONFIG_CODEC2RAW_DEMUXER})
    list(APPEND AVFORMAT_SOURCES codec2.c rawdec.c pcm.c)
endif ()
if (${CONFIG_CODEC2RAW_MUXER})
    list(APPEND AVFORMAT_SOURCES rawenc.c)
endif ()
if (${CONFIG_CONCAT_DEMUXER})
    list(APPEND AVFORMAT_SOURCES concatdec.c)
endif ()
if (${CONFIG_CRC_MUXER})
    list(APPEND AVFORMAT_SOURCES crcenc.c)
endif ()
if (${CONFIG_DATA_DEMUXER})
    list(APPEND AVFORMAT_SOURCES rawdec.c)
endif ()
if (${CONFIG_DATA_MUXER})
    list(APPEND AVFORMAT_SOURCES rawenc.c)
endif ()
if (${CONFIG_DASH_MUXER})
    list(APPEND AVFORMAT_SOURCES dash.c
		dashenc.c
		hlsplaylist.c
	)
endif ()
if (${CONFIG_DASH_DEMUXER})
    list(APPEND AVFORMAT_SOURCES dash.c
		dashdec.c
	)
endif ()
if (${CONFIG_DAUD_DEMUXER})
    list(APPEND AVFORMAT_SOURCES dauddec.c)
endif ()
if (${CONFIG_DAUD_MUXER})
    list(APPEND AVFORMAT_SOURCES daudenc.c)
endif ()
if (${CONFIG_DCSTR_DEMUXER})
    list(APPEND AVFORMAT_SOURCES dcstr.c)
endif ()
if (${CONFIG_DERF_DEMUXER})
    list(APPEND AVFORMAT_SOURCES derf.c pcm.c)
endif ()
if (${CONFIG_DFA_DEMUXER})
    list(APPEND AVFORMAT_SOURCES dfa.c)
endif ()
if (${CONFIG_DHAV_DEMUXER})
    list(APPEND AVFORMAT_SOURCES dhav.c)
endif ()
if (${CONFIG_DIRAC_DEMUXER})
    list(APPEND AVFORMAT_SOURCES diracdec.c
		rawdec.c
	)
endif ()
if (${CONFIG_DIRAC_MUXER})
    list(APPEND AVFORMAT_SOURCES rawenc.c)
endif ()
if (${CONFIG_DNXHD_DEMUXER})
    list(APPEND AVFORMAT_SOURCES dnxhddec.c
		rawdec.c
	)
endif ()
if (${CONFIG_DNXHD_MUXER})
    list(APPEND AVFORMAT_SOURCES rawenc.c)
endif ()
if (${CONFIG_DSF_DEMUXER})
    list(APPEND AVFORMAT_SOURCES dsfdec.c)
endif ()
if (${CONFIG_DSICIN_DEMUXER})
    list(APPEND AVFORMAT_SOURCES dsicin.c)
endif ()
if (${CONFIG_DSS_DEMUXER})
    list(APPEND AVFORMAT_SOURCES dss.c)
endif ()
if (${CONFIG_DTSHD_DEMUXER})
    list(APPEND AVFORMAT_SOURCES dtshddec.c)
endif ()
if (${CONFIG_DTS_DEMUXER})
    list(APPEND AVFORMAT_SOURCES dtsdec.c
		rawdec.c
	)
endif ()
if (${CONFIG_DTS_MUXER})
    list(APPEND AVFORMAT_SOURCES rawenc.c)
endif ()
if (${CONFIG_DV_DEMUXER})
    list(APPEND AVFORMAT_SOURCES dv.c)
endif ()
if (${CONFIG_DV_MUXER})
    list(APPEND AVFORMAT_SOURCES dvenc.c)
endif ()
if (${CONFIG_DVBSUB_DEMUXER})
    list(APPEND AVFORMAT_SOURCES dvbsub.c)
endif ()
if (${CONFIG_DVBTXT_DEMUXER})
    list(APPEND AVFORMAT_SOURCES dvbtxt.c)
endif ()
if (${CONFIG_DXA_DEMUXER})
    list(APPEND AVFORMAT_SOURCES dxa.c)
endif ()
if (${CONFIG_EA_CDATA_DEMUXER})
    list(APPEND AVFORMAT_SOURCES eacdata.c)
endif ()
if (${CONFIG_EA_DEMUXER})
    list(APPEND AVFORMAT_SOURCES electronicarts.c)
endif ()
if (${CONFIG_AAX_DEMUXER})
    list(APPEND AVFORMAT_SOURCES aaxdec.c)
endif ()
if (${CONFIG_EAC3_DEMUXER})
    list(APPEND AVFORMAT_SOURCES ac3dec.c
		rawdec.c
	)
endif ()
if (${CONFIG_EAC3_MUXER})
    list(APPEND AVFORMAT_SOURCES rawenc.c)
endif ()
if (${CONFIG_EPAF_DEMUXER})
    list(APPEND AVFORMAT_SOURCES epafdec.c
		pcm.c
	)
endif ()
if (${CONFIG_FFM_DEMUXER})
    list(APPEND AVFORMAT_SOURCES ffmdec.c)
endif ()
if (${CONFIG_FFM_MUXER})
    list(APPEND AVFORMAT_SOURCES ffmenc.c)
endif ()
if (${CONFIG_FFMETADATA_DEMUXER})
    list(APPEND AVFORMAT_SOURCES ffmetadec.c)
endif ()
if (${CONFIG_FFMETADATA_MUXER})
    list(APPEND AVFORMAT_SOURCES ffmetaenc.c)
endif ()
if (${CONFIG_FIFO_MUXER})
    list(APPEND AVFORMAT_SOURCES fifo.c)
endif ()
if (${CONFIG_FIFO_TEST_MUXER})
    list(APPEND AVFORMAT_SOURCES fifo_test.c)
endif ()
if (${CONFIG_FILMSTRIP_DEMUXER})
    list(APPEND AVFORMAT_SOURCES filmstripdec.c)
endif ()
if (${CONFIG_FILMSTRIP_MUXER})
    list(APPEND AVFORMAT_SOURCES filmstripenc.c)
endif ()
if (${CONFIG_FITS_DEMUXER})
    list(APPEND AVFORMAT_SOURCES fitsdec.c)
endif ()
if (${CONFIG_FITS_MUXER})
    list(APPEND AVFORMAT_SOURCES fitsenc.c)
endif ()
if (${CONFIG_FLAC_DEMUXER})
    list(APPEND AVFORMAT_SOURCES flacdec.c
		rawdec.c
		flac_picture.c
		oggparsevorbis.c
		replaygain.c
		vorbiscomment.c
	)
endif ()
if (${CONFIG_FLAC_MUXER})
    list(APPEND AVFORMAT_SOURCES flacenc.c
		flacenc_header.c
        vorbiscomment.c
	)
endif ()
if (${CONFIG_FLIC_DEMUXER})
    list(APPEND AVFORMAT_SOURCES flic.c)
endif ()
if (${CONFIG_FLV_DEMUXER})
    list(APPEND AVFORMAT_SOURCES flvdec.c)
endif ()
if (${CONFIG_LIVE_FLV_DEMUXER})
    list(APPEND AVFORMAT_SOURCES flvdec.c)
endif ()
if (${CONFIG_FLV_MUXER})
    list(APPEND AVFORMAT_SOURCES flvenc.c
		avc.c
	)
endif ()
if (${CONFIG_FOURXM_DEMUXER})
    list(APPEND AVFORMAT_SOURCES 4xm.c)
endif ()
if (${CONFIG_FRAMECRC_MUXER})
    list(APPEND AVFORMAT_SOURCES framecrcenc.c
		framehash.c
	)
endif ()
if (${CONFIG_FRAMEHASH_MUXER})
    list(APPEND AVFORMAT_SOURCES hashenc.c
		framehash.c
	)
endif ()
if (${CONFIG_FRAMEMD5_MUXER})
    list(APPEND AVFORMAT_SOURCES hashenc.c
		framehash.c
	)
endif ()
if (${CONFIG_FRM_DEMUXER})
    list(APPEND AVFORMAT_SOURCES frmdec.c)
endif ()
if (${CONFIG_FSB_DEMUXER})
    list(APPEND AVFORMAT_SOURCES fsb.c)
endif ()
if (${CONFIG_FSB_DEMUXER})
    list(APPEND AVFORMAT_SOURCES fwse.c pcm.c)
endif ()
if (${CONFIG_GIF_MUXER})
    list(APPEND AVFORMAT_SOURCES gif.c)
endif ()
if (${CONFIG_GIF_DEMUXER})
    list(APPEND AVFORMAT_SOURCES gifdec.c)
endif ()
if (${CONFIG_GSM_DEMUXER})
    list(APPEND AVFORMAT_SOURCES gsmdec.c)
endif ()
if (${CONFIG_GSM_MUXER})
    list(APPEND AVFORMAT_SOURCES rawenc.c)
endif ()
if (${CONFIG_GXF_DEMUXER})
    list(APPEND AVFORMAT_SOURCES gxf.c)
endif ()
if (${CONFIG_GXF_MUXER})
    list(APPEND AVFORMAT_SOURCES gxfenc.c)
endif ()
if (${CONFIG_G722_DEMUXER})
    list(APPEND AVFORMAT_SOURCES g722.c
		rawdec.c
	)
endif ()
if (${CONFIG_G722_MUXER})
    list(APPEND AVFORMAT_SOURCES rawenc.c)
endif ()
if (${CONFIG_G723_1_DEMUXER})
    list(APPEND AVFORMAT_SOURCES g723_1.c)
endif ()
if (${CONFIG_G723_1_MUXER})
    list(APPEND AVFORMAT_SOURCES rawenc.c)
endif ()
if (${CONFIG_G726_DEMUXER})
    list(APPEND AVFORMAT_SOURCES g726.c)
endif ()
if (${CONFIG_G726_MUXER})
    list(APPEND AVFORMAT_SOURCES rawenc.c)
endif ()
if (${CONFIG_G726LE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES g726.c)
endif ()
if (${CONFIG_G726LE_MUXER})
    list(APPEND AVFORMAT_SOURCES rawenc.c)
endif ()
if (${CONFIG_G729_DEMUXER})
    list(APPEND AVFORMAT_SOURCES g729dec.c)
endif ()
if (${CONFIG_GDV_DEMUXER})
    list(APPEND AVFORMAT_SOURCES gdv.c)
endif ()
if (${CONFIG_GENH_DEMUXER})
    list(APPEND AVFORMAT_SOURCES genh.c)
endif ()
if (${CONFIG_H261_DEMUXER})
    list(APPEND AVFORMAT_SOURCES h261dec.c
		rawdec.c
	)
endif ()
if (${CONFIG_H261_MUXER})
    list(APPEND AVFORMAT_SOURCES rawenc.c)
endif ()
if (${CONFIG_H263_DEMUXER})
    list(APPEND AVFORMAT_SOURCES h263dec.c
		rawdec.c
	)
endif ()
if (${CONFIG_H263_MUXER})
    list(APPEND AVFORMAT_SOURCES rawenc.c)
endif ()
if (${CONFIG_H264_DEMUXER})
    list(APPEND AVFORMAT_SOURCES h264dec.c
		rawdec.c
	)
endif ()
if (${CONFIG_H264_MUXER})
    list(APPEND AVFORMAT_SOURCES rawenc.c)
endif ()
if (${CONFIG_HASH_MUXER})
    list(APPEND AVFORMAT_SOURCES hashenc.c)
endif ()
if (${CONFIG_HCA_DEMUXER})
    list(APPEND AVFORMAT_SOURCES hca.c)
endif ()
if (${CONFIG_HCOM_DEMUXER})
    list(APPEND AVFORMAT_SOURCES hcom.c pcm.c)
endif ()
if (${CONFIG_HDS_MUXER})
    list(APPEND AVFORMAT_SOURCES hdsenc.c)
endif ()
if (${CONFIG_HEVC_DEMUXER})
    list(APPEND AVFORMAT_SOURCES hevcdec.c
		rawdec.c
	)
endif ()
if (${CONFIG_HEVC_MUXER})
    list(APPEND AVFORMAT_SOURCES rawenc.c)
endif ()
if (${CONFIG_HLS_DEMUXER})
    list(APPEND AVFORMAT_SOURCES hls.c)
endif ()
if (${CONFIG_HLS_MUXER})
    list(APPEND AVFORMAT_SOURCES hlsenc.c
		hlsplaylist.c
	)
endif ()
if (${CONFIG_HNM_DEMUXER})
    list(APPEND AVFORMAT_SOURCES hnm.c)
endif ()
if (${CONFIG_ICO_DEMUXER})
    list(APPEND AVFORMAT_SOURCES icodec.c)
endif ()
if (${CONFIG_ICO_MUXER})
    list(APPEND AVFORMAT_SOURCES icoenc.c)
endif ()
if (${CONFIG_IDCIN_DEMUXER})
    list(APPEND AVFORMAT_SOURCES idcin.c)
endif ()
if (${CONFIG_IDF_DEMUXER})
    list(APPEND AVFORMAT_SOURCES bintext.c
		sauce.c
	)
endif ()
if (${CONFIG_IFF_DEMUXER})
    list(APPEND AVFORMAT_SOURCES iff.c)
endif ()
if (${CONFIG_IFV_DEMUXER})
    list(APPEND AVFORMAT_SOURCES ifv.c)
endif ()
if (${CONFIG_ILBC_DEMUXER})
    list(APPEND AVFORMAT_SOURCES ilbc.c)
endif ()
if (${CONFIG_ILBC_MUXER})
    list(APPEND AVFORMAT_SOURCES ilbc.c)
endif ()
if (${CONFIG_IMAGE2_DEMUXER})
    list(APPEND AVFORMAT_SOURCES img2dec.c
		img2.c
	)
endif ()
if (${CONFIG_IMAGE2_MUXER})
    list(APPEND AVFORMAT_SOURCES img2enc.c
		img2.c
	)
endif ()
if (${CONFIG_IMAGE2PIPE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES img2dec.c
		img2.c
	)
endif ()
if (${CONFIG_IMAGE2PIPE_MUXER})
    list(APPEND AVFORMAT_SOURCES img2enc.c
		img2.c
	)
endif ()
if (${CONFIG_IMAGE2_ALIAS_PIX_DEMUXER})
    list(APPEND AVFORMAT_SOURCES img2_alias_pix.c)
endif ()
if (${CONFIG_IMAGE2_BRENDER_PIX_DEMUXER})
    list(APPEND AVFORMAT_SOURCES img2_brender_pix.c)
endif ()
if (${CONFIG_IMAGE_BMP_PIPE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES img2dec.c
		img2.c
	)
endif ()
if (${CONFIG_IMAGE_DDS_PIPE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES img2dec.c
		img2.c
	)
endif ()
if (${CONFIG_IMAGE_DPX_PIPE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES img2dec.c
		img2.c
	)
endif ()
if (${CONFIG_IMAGE_EXR_PIPE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES img2dec.c
		img2.c
	)
endif ()
if (${CONFIG_IMAGE_J2K_PIPE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES img2dec.c
		img2.c
	)
endif ()
if (${CONFIG_IMAGE_JPEG_PIPE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES img2dec.c
		img2.c
	)
endif ()
if (${CONFIG_IMAGE_JPEGLS_PIPE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES img2dec.c
		img2.c
	)
endif ()
if (${CONFIG_IMAGE_PAM_PIPE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES img2dec.c
		img2.c
	)
endif ()
if (${CONFIG_IMAGE_PBM_PIPE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES img2dec.c
		img2.c
	)
endif ()
if (${CONFIG_IMAGE_PCX_PIPE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES img2dec.c
		img2.c
	)
endif ()
if (${CONFIG_IMAGE_PGMYUV_PIPE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES img2dec.c
		img2.c
	)
endif ()
if (${CONFIG_IMAGE_PGM_PIPE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES img2dec.c
		img2.c
	)
endif ()
if (${CONFIG_IMAGE_PICTOR_PIPE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES img2dec.c
		img2.c
	)
endif ()
if (${CONFIG_IMAGE_PNG_PIPE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES img2dec.c
		img2.c
	)
endif ()
if (${CONFIG_IMAGE_PPM_PIPE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES img2dec.c
		img2.c
	)
endif ()
if (${CONFIG_IMAGE_PSD_PIPE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES img2dec.c
        img2.c
    )
endif ()
if (${CONFIG_IMAGE_QDRAW_PIPE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES img2dec.c
        img2.c
    )
endif ()
if (${CONFIG_IMAGE_SGI_PIPE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES img2dec.c
        img2.c
    )
endif ()
if (${CONFIG_IMAGE_SVG_PIPE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES img2dec.c
        img2.c
    )
endif ()
if (${CONFIG_IMAGE_SUNRAST_PIPE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES img2dec.c
        img2.c
    )
endif ()
if (${CONFIG_IMAGE_TIFF_PIPE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES img2dec.c
        img2.c
    )
endif ()
if (${CONFIG_IMAGE_WEBP_PIPE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES img2dec.c
        img2.c
    )
endif ()
if (${CONFIG_IMAGE_XPM_PIPE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES img2dec.c
        img2.c
    )
endif ()
if (${CONFIG_INGENIENT_DEMUXER})
    list(APPEND AVFORMAT_SOURCES ingenientdec.c
		rawdec.c
	)
endif ()
if (${CONFIG_IPMOVIE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES ipmovie.c)
endif ()
if (${CONFIG_IPU_DEMUXER})
    list(APPEND AVFORMAT_SOURCES ipudec.c)
endif ()
if (${CONFIG_IRCAM_DEMUXER})
    list(APPEND AVFORMAT_SOURCES ircamdec.c
		ircam.c
		pcm.c
	)
endif ()
if (${CONFIG_IRCAM_MUXER})
    list(APPEND AVFORMAT_SOURCES ircamenc.c
		ircam.c
		rawenc.c
	)
endif ()
if (${CONFIG_ISS_DEMUXER})
    list(APPEND AVFORMAT_SOURCES iss.c)
endif ()
if (${CONFIG_IV8_DEMUXER})
    list(APPEND AVFORMAT_SOURCES iv8.c)
endif ()
if (${CONFIG_IVF_DEMUXER})
    list(APPEND AVFORMAT_SOURCES ivfdec.c)
endif ()
if (${CONFIG_IVF_MUXER})
    list(APPEND AVFORMAT_SOURCES ivfenc.c)
endif ()
if (${CONFIG_IVR_DEMUXER})
    list(APPEND AVFORMAT_SOURCES rmdec.c
		rm.c
		rmsipr.c
	)
endif ()
if (${CONFIG_JACOSUB_DEMUXER})
    list(APPEND AVFORMAT_SOURCES jacosubdec.c
		subtitles.c
	)
endif ()
if (${CONFIG_JACOSUB_MUXER})
    list(APPEND AVFORMAT_SOURCES jacosubenc.c
		rawenc.c
	)
endif ()
if (${CONFIG_JV_DEMUXER})
    list(APPEND AVFORMAT_SOURCES jvdec.c)
endif ()
if (${CONFIG_KVAG_DEMUXER})
    list(APPEND AVFORMAT_SOURCES kvag.c)
endif ()
if (${CONFIG_LATM_MUXER})
    list(APPEND AVFORMAT_SOURCES latmenc.c
		rawenc.c
	)
endif ()
if (${CONFIG_LMLM4_DEMUXER})
    list(APPEND AVFORMAT_SOURCES lmlm4.c)
endif ()
if (${CONFIG_LOAS_DEMUXER})
    list(APPEND AVFORMAT_SOURCES loasdec.c
		rawdec.c
	)
endif ()
if (${CONFIG_LUODAT_DEMUXER})
    list(APPEND AVFORMAT_SOURCES luodatdec.c)
endif ()
if (${CONFIG_LRC_DEMUXER})
    list(APPEND AVFORMAT_SOURCES lrcdec.c
		lrc.c
		subtitles.c
	)
endif ()
if (${CONFIG_LRC_MUXER})
    list(APPEND AVFORMAT_SOURCES lrcenc.c
		lrc.c
	)
endif ()
if (${CONFIG_LVF_DEMUXER})
    list(APPEND AVFORMAT_SOURCES lvfdec.c)
endif ()
if (${CONFIG_LXF_DEMUXER})
    list(APPEND AVFORMAT_SOURCES lxfdec.c)
endif ()
if (${CONFIG_M4V_DEMUXER})
    list(APPEND AVFORMAT_SOURCES m4vdec.c
		rawdec.c
	)
endif ()
if (${CONFIG_M4V_MUXER})
    list(APPEND AVFORMAT_SOURCES rawenc.c)
endif ()
if (${CONFIG_MATROSKA_DEMUXER})
    list(APPEND AVFORMAT_SOURCES matroskadec.c
		matroska.c
		rmsipr.c
		flac_picture.c
		oggparsevorbis.c
		vorbiscomment.c
		flac_picture.c
		replaygain.c
	)
endif ()
if (${CONFIG_MATROSKA_MUXER})
    list(APPEND AVFORMAT_SOURCES matroskaenc.c
		matroska.c
		av1.c
        avc.c
		hevc.c
        flacenc_header.c
		avlanguage.c
		vorbiscomment.c
		wv.c
        webmdashenc.c
		webm_chunk.c
	)
endif ()
if (${CONFIG_MCA_DEMUXER})
    list(APPEND AVFORMAT_SOURCES mca.c)
endif ()
if (${CONFIG_MCC_DEMUXER})
    list(APPEND AVFORMAT_SOURCES mccdec.c subtitles.c)
endif ()
if (${CONFIG_MD5_MUXER})
    list(APPEND AVFORMAT_SOURCES hashenc.c)
endif ()
if (${CONFIG_MGSTS_DEMUXER})
    list(APPEND AVFORMAT_SOURCES mgsts.c)
endif ()
if (${CONFIG_MICRODVD_DEMUXER})
    list(APPEND AVFORMAT_SOURCES microdvddec.c
		subtitles.c
	)
endif ()
if (${CONFIG_MICRODVD_MUXER})
    list(APPEND AVFORMAT_SOURCES microdvdenc.c)
endif ()
if (${CONFIG_MJPEG_2000_DEMUXER})
    list(APPEND AVFORMAT_SOURCES rawdec.c
		mj2kdec.c
	)
endif ()
if (${CONFIG_MJPEG_DEMUXER})
    list(APPEND AVFORMAT_SOURCES rawdec.c)
endif ()
if (${CONFIG_MJPEG_MUXER})
    list(APPEND AVFORMAT_SOURCES rawenc.c)
endif ()
if (${CONFIG_MLP_DEMUXER})
    list(APPEND AVFORMAT_SOURCES rawdec.c
		mlpdec.c
	)
endif ()
if (${CONFIG_MLP_MUXER})
    list(APPEND AVFORMAT_SOURCES rawenc.c)
endif ()
if (${CONFIG_MLV_DEMUXER})
    list(APPEND AVFORMAT_SOURCES mlvdec.c
		riffdec.c
	)
endif ()
if (${CONFIG_MM_DEMUXER})
    list(APPEND AVFORMAT_SOURCES mm.c)
endif ()
if (${CONFIG_MMF_DEMUXER})
    list(APPEND AVFORMAT_SOURCES mmf.c)
endif ()
if (${CONFIG_MMF_MUXER})
    list(APPEND AVFORMAT_SOURCES mmf.c
		rawenc.c
	)
endif ()
if (${CONFIG_MODS_DEMUXER})
    list(APPEND AVFORMAT_SOURCES mods.c)
endif ()
if (${CONFIG_MOFLEX_DEMUXER})
    list(APPEND AVFORMAT_SOURCES moflex.c)
endif ()
if (${CONFIG_MOV_DEMUXER})
    list(APPEND AVFORMAT_SOURCES mov.c
		mov_chan.c
		mov_esds.c
		replaygain.c
	)
endif ()
if (${CONFIG_MOV_MUXER})
	list(APPEND AVFORMAT_SOURCES movenc.c
		av1.c
		avc.c
		hevc.c
		vpcc.c
        movenchint.c
		mov_chan.c
		rtp.c
        movenccenc.c
		rawutils.c
	)
endif ()
if (${CONFIG_MP2_MUXER})
    list(APPEND AVFORMAT_SOURCES rawenc.c)
endif ()
if (${CONFIG_MP3_DEMUXER})
    list(APPEND AVFORMAT_SOURCES mp3dec.c
		replaygain.c
	)
endif ()
if (${CONFIG_MP3_MUXER})
    list(APPEND AVFORMAT_SOURCES mp3enc.c
		rawenc.c
		id3v2enc.c
	)
endif ()
if (${CONFIG_MPC_DEMUXER})
    list(APPEND AVFORMAT_SOURCES mpc.c
		apetag.c
        img2.c
    )
endif ()
if (${CONFIG_MPC8_DEMUXER})
    list(APPEND AVFORMAT_SOURCES mpc8.c
		apetag.c
        img2.c
    )
endif ()
if (${CONFIG_MPEG1SYSTEM_MUXER})
    list(APPEND AVFORMAT_SOURCES mpegenc.c)
endif ()
if (${CONFIG_MPEG1VCD_MUXER})
    list(APPEND AVFORMAT_SOURCES mpegenc.c)
endif ()
if (${CONFIG_MPEG1VIDEO_MUXER})
    list(APPEND AVFORMAT_SOURCES rawenc.c)
endif ()
if (${CONFIG_MPEG2DVD_MUXER})
    list(APPEND AVFORMAT_SOURCES mpegenc.c)
endif ()
if (${CONFIG_MPEG2SVCD_MUXER})
    list(APPEND AVFORMAT_SOURCES mpegenc.c)
endif ()
if (${CONFIG_MPEG2VIDEO_MUXER})
    list(APPEND AVFORMAT_SOURCES rawenc.c)
endif ()
if (${CONFIG_MPEG2VOB_MUXER})
    list(APPEND AVFORMAT_SOURCES mpegenc.c)
endif ()
if (${CONFIG_MPEGPS_DEMUXER})
    list(APPEND AVFORMAT_SOURCES mpeg.c)
endif ()
if (${CONFIG_MPEGTS_DEMUXER})
    list(APPEND AVFORMAT_SOURCES mpegts.c)
endif ()
if (${CONFIG_MPEGTS_MUXER})
    list(APPEND AVFORMAT_SOURCES mpegtsenc.c)
endif ()
if (${CONFIG_MPEGVIDEO_DEMUXER})
    list(APPEND AVFORMAT_SOURCES mpegvideodec.c
		rawdec.c
	)
endif ()
if (${CONFIG_MPJPEG_DEMUXER})
    list(APPEND AVFORMAT_SOURCES mpjpegdec.c)
endif ()
if (${CONFIG_MPJPEG_MUXER})
    list(APPEND AVFORMAT_SOURCES mpjpeg.c)
endif ()
if (${CONFIG_MPL2_DEMUXER})
    list(APPEND AVFORMAT_SOURCES mpl2dec.c
		subtitles.c
	)
endif ()
if (${CONFIG_MSF_DEMUXER})
    list(APPEND AVFORMAT_SOURCES msf.c)
endif ()
if (${CONFIG_MPSUB_DEMUXER})
    list(APPEND AVFORMAT_SOURCES mpsubdec.c
		subtitles.c
	)
endif ()
if (${CONFIG_MSNWC_TCP_DEMUXER})
    list(APPEND AVFORMAT_SOURCES msnwc_tcp.c)
endif ()
if (${CONFIG_MSP_DEMUXER})
    list(APPEND AVFORMAT_SOURCES mspdec.c)
endif ()
if (${CONFIG_MTAF_DEMUXER})
    list(APPEND AVFORMAT_SOURCES mtaf.c)
endif ()
if (${CONFIG_MTV_DEMUXER})
    list(APPEND AVFORMAT_SOURCES mtv.c)
endif ()
if (${CONFIG_MUSX_DEMUXER})
    list(APPEND AVFORMAT_SOURCES musx.c)
endif ()
if (${CONFIG_MV_DEMUXER})
    list(APPEND AVFORMAT_SOURCES mvdec.c)
endif ()
if (${CONFIG_MVI_DEMUXER})
    list(APPEND AVFORMAT_SOURCES mvi.c)
endif ()
if (${CONFIG_MXF_DEMUXER})
    list(APPEND AVFORMAT_SOURCES mxfdec.c
		mxf.c
	)
endif ()
if (${CONFIG_MXF_MUXER})
    list(APPEND AVFORMAT_SOURCES mxfenc.c
		mxf.c
		avc.c
	)
endif ()
if (${CONFIG_MXG_DEMUXER})
    list(APPEND AVFORMAT_SOURCES mxg.c)
endif ()
if (${CONFIG_NC_DEMUXER})
    list(APPEND AVFORMAT_SOURCES ncdec.c)
endif ()
if (${CONFIG_NISTSPHERE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES nistspheredec.c
		pcm.c
	)
endif ()
if (${CONFIG_NSP_DEMUXER})
    list(APPEND AVFORMAT_SOURCES nspdec.c)
endif ()
if (${CONFIG_NSV_DEMUXER})
    list(APPEND AVFORMAT_SOURCES nsvdec.c)
endif ()
if (${CONFIG_NULL_MUXER})
    list(APPEND AVFORMAT_SOURCES nullenc.c)
endif ()
if (${CONFIG_NUT_DEMUXER})
    list(APPEND AVFORMAT_SOURCES nutdec.c
		nut.c
		isom.c
	)
endif ()
if (${CONFIG_NUT_MUXER})
    list(APPEND AVFORMAT_SOURCES nutenc.c
		nut.c
	)
endif ()
if (${CONFIG_NUV_DEMUXER})
    list(APPEND AVFORMAT_SOURCES nuv.c)
endif ()
if (${CONFIG_AV1_DEMUXER})
    list(APPEND AVFORMAT_SOURCES av1dec.c)
endif ()
if (${CONFIG_OGG_DEMUXER})
    list(APPEND AVFORMAT_SOURCES oggdec.c
		oggparsecelt.c
		oggparsedirac.c
		oggparseflac.c
		oggparseogm.c
		oggparseopus.c
		oggparseskeleton.c
		oggparsespeex.c
		oggparsetheora.c
		oggparsevorbis.c
		oggparsevp8.c
		replaygain.c
		vorbiscomment.c
		flac_picture.c
    )
endif ()
if (${CONFIG_OGA_MUXER})
    list(APPEND AVFORMAT_SOURCES oggenc.c
        vorbiscomment.c
	)
endif ()
if (${CONFIG_OGG_MUXER})
    list(APPEND AVFORMAT_SOURCES oggenc.c
		vorbiscomment.c
	)
endif ()
if (${CONFIG_OGV_MUXER})
    list(APPEND AVFORMAT_SOURCES oggenc.c
        vorbiscomment.c
	)
endif ()
if (${CONFIG_OMA_DEMUXER})
    list(APPEND AVFORMAT_SOURCES omadec.c
		pcm.c
		oma.c
	)
endif ()
if (${CONFIG_OMA_MUXER})
    list(APPEND AVFORMAT_SOURCES omaenc.c
		rawenc.c
		oma.c
		id3v2enc.c
	)
endif ()
if (${CONFIG_OPUS_MUXER})
    list(APPEND AVFORMAT_SOURCES oggenc.c
        vorbiscomment.c
	)
endif ()
if (${CONFIG_PAF_DEMUXER})
    list(APPEND AVFORMAT_SOURCES paf.c)
endif ()
if (${CONFIG_PCM_ALAW_DEMUXER})
    list(APPEND AVFORMAT_SOURCES pcmdec.c
		pcm.c
	)
endif ()
if (${CONFIG_PCM_ALAW_MUXER})
    list(APPEND AVFORMAT_SOURCES pcmenc.c
		rawenc.c
	)
endif ()
if (${CONFIG_PCM_F32BE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES pcmdec.c
		pcm.c
	)
endif ()
if (${CONFIG_PCM_F32BE_MUXER})
    list(APPEND AVFORMAT_SOURCES pcmenc.c
		rawenc.c
	)
endif ()
if (${CONFIG_PCM_F32LE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES pcmdec.c
		pcm.c
	)
endif ()
if (${CONFIG_PCM_F32LE_MUXER})
    list(APPEND AVFORMAT_SOURCES pcmenc.c
		rawenc.c
	)
endif ()
if (${CONFIG_PCM_F64BE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES pcmdec.c
		pcm.c
	)
endif ()
if (${CONFIG_PCM_F64BE_MUXER})
    list(APPEND AVFORMAT_SOURCES pcmenc.c
		rawenc.c
	)
endif ()
if (${CONFIG_PCM_F64LE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES pcmdec.c
		pcm.c
	)
endif ()
if (${CONFIG_PCM_F64LE_MUXER})
    list(APPEND AVFORMAT_SOURCES pcmenc.c
		rawenc.c
	)
endif ()
if (${CONFIG_PCM_MULAW_DEMUXER})
    list(APPEND AVFORMAT_SOURCES pcmdec.c
		pcm.c
	)
endif ()
if (${CONFIG_PCM_MULAW_MUXER})
    list(APPEND AVFORMAT_SOURCES pcmenc.c
		rawenc.c
	)
endif ()
if (${CONFIG_PCM_S16BE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES pcmdec.c
		pcm.c
	)
endif ()
if (${CONFIG_PCM_S16BE_MUXER})
    list(APPEND AVFORMAT_SOURCES pcmenc.c
		rawenc.c
	)
endif ()
if (${CONFIG_PCM_S16LE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES pcmdec.c
		pcm.c
	)
endif ()
if (${CONFIG_PCM_S16LE_MUXER})
    list(APPEND AVFORMAT_SOURCES pcmenc.c
		rawenc.c
	)
endif ()
if (${CONFIG_PCM_S24BE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES pcmdec.c
		pcm.c
	)
endif ()
if (${CONFIG_PCM_S24BE_MUXER})
    list(APPEND AVFORMAT_SOURCES pcmenc.c
		rawenc.c
	)
endif ()
if (${CONFIG_PCM_S24LE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES pcmdec.c
		pcm.c
	)
endif ()
if (${CONFIG_PCM_S24LE_MUXER})
    list(APPEND AVFORMAT_SOURCES pcmenc.c
		rawenc.c
	)
endif ()
if (${CONFIG_PCM_S32BE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES pcmdec.c
		pcm.c
	)
endif ()
if (${CONFIG_PCM_S32BE_MUXER})
    list(APPEND AVFORMAT_SOURCES pcmenc.c
		rawenc.c
	)
endif ()
if (${CONFIG_PCM_S32LE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES pcmdec.c
		pcm.c
	)
endif ()
if (${CONFIG_PCM_S32LE_MUXER})
    list(APPEND AVFORMAT_SOURCES pcmenc.c
		rawenc.c
	)
endif ()
if (${CONFIG_PCM_S8_DEMUXER})
    list(APPEND AVFORMAT_SOURCES pcmdec.c
		pcm.c
	)
endif ()
if (${CONFIG_PCM_S8_MUXER})
    list(APPEND AVFORMAT_SOURCES pcmenc.c
		rawenc.c
	)
endif ()
if (${CONFIG_PCM_U16BE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES pcmdec.c
		pcm.c
	)
endif ()
if (${CONFIG_PCM_U16BE_MUXER})
    list(APPEND AVFORMAT_SOURCES pcmenc.c
		rawenc.c
	)
endif ()
if (${CONFIG_PCM_U16LE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES pcmdec.c
		pcm.c
	)
endif ()
if (${CONFIG_PCM_U16LE_MUXER})
    list(APPEND AVFORMAT_SOURCES pcmenc.c
		rawenc.c
	)
endif ()
if (${CONFIG_PCM_U24BE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES pcmdec.c
		pcm.c
	)
endif ()
if (${CONFIG_PCM_U24BE_MUXER})
    list(APPEND AVFORMAT_SOURCES pcmenc.c
		rawenc.c
	)
endif ()
if (${CONFIG_PCM_U24LE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES pcmdec.c
		pcm.c
	)
endif ()
if (${CONFIG_PCM_U24LE_MUXER})
    list(APPEND AVFORMAT_SOURCES pcmenc.c
		rawenc.c
	)
endif ()
if (${CONFIG_PCM_U32BE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES pcmdec.c
		pcm.c
	)
endif ()
if (${CONFIG_PCM_U32BE_MUXER})
    list(APPEND AVFORMAT_SOURCES pcmenc.c
		rawenc.c
	)
endif ()
if (${CONFIG_PCM_U32LE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES pcmdec.c
		pcm.c
	)
endif ()
if (${CONFIG_PCM_U32LE_MUXER})
    list(APPEND AVFORMAT_SOURCES pcmenc.c
		rawenc.c
	)
endif ()
if (${CONFIG_PCM_U8_DEMUXER})
    list(APPEND AVFORMAT_SOURCES pcmdec.c
		pcm.c
	)
endif ()
if (${CONFIG_PCM_U8_MUXER})
    list(APPEND AVFORMAT_SOURCES pcmenc.c
		rawenc.c
	)
endif ()
if (${CONFIG_PJS_DEMUXER})
    list(APPEND AVFORMAT_SOURCES pjsdec.c
		subtitles.c
	)
endif ()
if (${CONFIG_PMP_DEMUXER})
    list(APPEND AVFORMAT_SOURCES pmpdec.c)
endif ()
if (${CONFIG_PP_BNK_DEMUXER})
    list(APPEND AVFORMAT_SOURCES pp_bnk.c)
endif ()
if (${CONFIG_PVA_DEMUXER})
    list(APPEND AVFORMAT_SOURCES pva.c)
endif ()
if (${CONFIG_PVF_DEMUXER})
    list(APPEND AVFORMAT_SOURCES pvfdec.c
		pcm.c
	)
endif ()
if (${CONFIG_QCP_DEMUXER})
    list(APPEND AVFORMAT_SOURCES qcp.c)
endif ()
if (${CONFIG_R3D_DEMUXER})
    list(APPEND AVFORMAT_SOURCES r3d.c)
endif ()
if (${CONFIG_RAWVIDEO_DEMUXER})
    list(APPEND AVFORMAT_SOURCES rawvideodec.c)
endif ()
if (${CONFIG_RAWVIDEO_MUXER})
    list(APPEND AVFORMAT_SOURCES rawenc.c)
endif ()
if (${CONFIG_REALTEXT_DEMUXER})
    list(APPEND AVFORMAT_SOURCES realtextdec.c
		subtitles.c
	)
endif ()
if (${CONFIG_REDSPARK_DEMUXER})
    list(APPEND AVFORMAT_SOURCES redspark.c)
endif ()
if (${CONFIG_RL2_DEMUXER})
    list(APPEND AVFORMAT_SOURCES rl2.c)
endif ()
if (${CONFIG_RM_DEMUXER})
    list(APPEND AVFORMAT_SOURCES rmdec.c
		rm.c
		rmsipr.c
	)
endif ()
if (${CONFIG_RM_MUXER})
    list(APPEND AVFORMAT_SOURCES rmenc.c
		rm.c
	)
endif ()
if (${CONFIG_ROQ_DEMUXER})
    list(APPEND AVFORMAT_SOURCES idroqdec.c)
endif ()
if (${CONFIG_ROQ_MUXER})
    list(APPEND AVFORMAT_SOURCES idroqenc.c
		rawenc.c
	)
endif ()
if (${CONFIG_RSD_DEMUXER})
    list(APPEND AVFORMAT_SOURCES rsd.c)
endif ()
if (${CONFIG_RPL_DEMUXER})
    list(APPEND AVFORMAT_SOURCES rpl.c)
endif ()
if (${CONFIG_RSO_DEMUXER})
    list(APPEND AVFORMAT_SOURCES rsodec.c
		rso.c
		pcm.c
	)
endif ()
if (${CONFIG_RSO_MUXER})
    list(APPEND AVFORMAT_SOURCES rsoenc.c
		rso.c
	)
endif ()
if (${CONFIG_RTP_MPEGTS_MUXER})
    list(APPEND AVFORMAT_SOURCES rtpenc_mpegts.c)
endif ()
if (${CONFIG_RTP_MUXER})
    list(APPEND AVFORMAT_SOURCES rtp.c
		rtpenc_aac.c
		rtpenc_latm.c
		rtpenc_amr.c
		rtpenc_h261.c
		rtpenc_h263.c
		rtpenc_h263_rfc2190.c
		rtpenc_h264_hevc.c
		rtpenc_jpeg.c
		rtpenc_mpv.c
		rtpenc.c
		rtpenc_vc2hq.c
		rtpenc_vp8.c
		rtpenc_vp9.c
		rtpenc_xiph.c
		avc.c
		hevc.c
	)
endif ()
if (${CONFIG_RTSP_DEMUXER})
    list(APPEND AVFORMAT_SOURCES rtsp.c
		rtspdec.c
		httpauth.c
        urldecode.c
	)
endif ()
if (${CONFIG_RTSP_MUXER})
    list(APPEND AVFORMAT_SOURCES rtsp.c
		rtspenc.c
		httpauth.c
        urldecode.c
	)
endif ()
if (${CONFIG_S337M_DEMUXER})
    list(APPEND AVFORMAT_SOURCES s337m.c
		spdif.c
	)
endif ()
if (${CONFIG_SAMI_DEMUXER})
    list(APPEND AVFORMAT_SOURCES samidec.c
		subtitles.c
	)
endif ()
if (${CONFIG_SAP_DEMUXER})
    list(APPEND AVFORMAT_SOURCES sapdec.c)
endif ()
if (${CONFIG_SAP_MUXER})
    list(APPEND AVFORMAT_SOURCES sapenc.c)
endif ()
if (${CONFIG_SBC_DEMUXER})
    list(APPEND AVFORMAT_SOURCES sbcdec.c rawdec.c)
endif ()
if (${CONFIG_SBC_MUXER})
    list(APPEND AVFORMAT_SOURCES rawenc.c)
endif ()
if (${CONFIG_SBG_DEMUXER})
    list(APPEND AVFORMAT_SOURCES sbgdec.c)
endif ()
if (${CONFIG_SCC_DEMUXER})
    list(APPEND AVFORMAT_SOURCES sccdec.c
		subtitles.c
	)
endif ()
if (${CONFIG_SCC_MUXER})
    list(APPEND AVFORMAT_SOURCES sccenc.c
		subtitles.c
	)
endif ()
if (${CONFIG_SDP_DEMUXER})
    list(APPEND AVFORMAT_SOURCES rtsp.c)
endif ()
if (${CONFIG_SDR2_DEMUXER})
    list(APPEND AVFORMAT_SOURCES sdr2.c)
endif ()
if (${CONFIG_SDS_DEMUXER})
    list(APPEND AVFORMAT_SOURCES sdsdec.c)
endif ()
if (${CONFIG_SDX_DEMUXER})
    list(APPEND AVFORMAT_SOURCES sdxdec.c)
endif ()
if (${CONFIG_SEGAFILM_DEMUXER})
    list(APPEND AVFORMAT_SOURCES segafilm.c)
endif ()
if (${CONFIG_SEGAFILM_MUXER})
    list(APPEND AVFORMAT_SOURCES segafilmenc.c)
endif ()
if (${CONFIG_SEGMENT_MUXER})
    list(APPEND AVFORMAT_SOURCES segment.c)
endif ()
if (${CONFIG_SER_DEMUXER})
    list(APPEND AVFORMAT_SOURCES serdec.c)
endif ()
if (${CONFIG_SHORTEN_DEMUXER})
    list(APPEND AVFORMAT_SOURCES shortendec.c
		rawdec.c
	)
endif ()
if (${CONFIG_SIFF_DEMUXER})
    list(APPEND AVFORMAT_SOURCES siff.c)
endif ()
if (${CONFIG_SINGLEJPEG_MUXER})
    list(APPEND AVFORMAT_SOURCES rawenc.c)
endif ()
if (${CONFIG_SMACKER_DEMUXER})
    list(APPEND AVFORMAT_SOURCES smacker.c)
endif ()
if (${CONFIG_SMJPEG_DEMUXER})
    list(APPEND AVFORMAT_SOURCES smjpegdec.c
		smjpeg.c
	)
endif ()
if (${CONFIG_SMJPEG_MUXER})
    list(APPEND AVFORMAT_SOURCES smjpegenc.c
		smjpeg.c
	)
endif ()
if (${CONFIG_SMOOTHSTREAMING_MUXER})
    list(APPEND AVFORMAT_SOURCES smoothstreamingenc.c)
endif ()
if (${CONFIG_SMUSH_DEMUXER})
    list(APPEND AVFORMAT_SOURCES smush.c)
endif ()
if (${CONFIG_SOL_DEMUXER})
    list(APPEND AVFORMAT_SOURCES sol.c
		pcm.c
	)
endif ()
if (${CONFIG_SOX_DEMUXER})
    list(APPEND AVFORMAT_SOURCES soxdec.c
		pcm.c
	)
endif ()
if (${CONFIG_SOX_MUXER})
    list(APPEND AVFORMAT_SOURCES soxenc.c
		rawenc.c
	)
endif ()
if (${CONFIG_SPDIF_DEMUXER})
    list(APPEND AVFORMAT_SOURCES spdif.c
		spdifdec.c
	)
endif ()
if (${CONFIG_SPDIF_MUXER})
    list(APPEND AVFORMAT_SOURCES spdif.c
		spdifenc.c
	)
endif ()
if (${CONFIG_SPEEX_MUXER})
    list(APPEND AVFORMAT_SOURCES oggenc.c
		vorbiscomment.c
	)
endif ()
if (${CONFIG_SRT_DEMUXER})
    list(APPEND AVFORMAT_SOURCES srtdec.c
		subtitles.c
	)
endif ()
if (${CONFIG_SRT_MUXER})
    list(APPEND AVFORMAT_SOURCES srtenc.c)
endif ()
if (${CONFIG_STL_DEMUXER})
    list(APPEND AVFORMAT_SOURCES stldec.c
		subtitles.c
	)
endif ()
if (${CONFIG_STR_DEMUXER})
    list(APPEND AVFORMAT_SOURCES psxstr.c)
endif ()
if (${CONFIG_SUBVIEWER1_DEMUXER})
    list(APPEND AVFORMAT_SOURCES subviewer1dec.c
		subtitles.c
	)
endif ()
if (${CONFIG_SUBVIEWER_DEMUXER})
    list(APPEND AVFORMAT_SOURCES subviewerdec.c
		subtitles.c
	)
endif ()
if (${CONFIG_SUP_DEMUXER})
    list(APPEND AVFORMAT_SOURCES supdec.c)
endif ()
if (${CONFIG_SUP_MUXER})
    list(APPEND AVFORMAT_SOURCES supenc.c)
endif ()
if (${CONFIG_SVAG_DEMUXER})
    list(APPEND AVFORMAT_SOURCES svag.c)
endif ()
if (${CONFIG_SVS_DEMUXER})
    list(APPEND AVFORMAT_SOURCES svs.c)
endif ()
if (${CONFIG_SWF_DEMUXER})
    list(APPEND AVFORMAT_SOURCES swfdec.c
		swf.c
	)
endif ()
if (${CONFIG_SWF_MUXER})
    list(APPEND AVFORMAT_SOURCES swfenc.c
		swf.c
	)
endif ()
if (${CONFIG_TAK_DEMUXER})
    list(APPEND AVFORMAT_SOURCES takdec.c
		apetag.c
		img2.c
		rawdec.c
	)
endif ()
if (${CONFIG_TEDCAPTIONS_DEMUXER})
    list(APPEND AVFORMAT_SOURCES tedcaptionsdec.c
		subtitles.c
	)
endif ()
if (${CONFIG_TEE_MUXER})
    list(APPEND AVFORMAT_SOURCES tee.c
		tee_common.c
	)
endif ()
if (${CONFIG_THP_DEMUXER})
    list(APPEND AVFORMAT_SOURCES thp.c)
endif ()
if (${CONFIG_THREEDOSTR_DEMUXER})
    list(APPEND AVFORMAT_SOURCES 3dostr.c)
endif ()
if (${CONFIG_TIERTEXSEQ_DEMUXER})
    list(APPEND AVFORMAT_SOURCES tiertexseq.c)
endif ()
if (${CONFIG_MKVTIMESTAMP_V2_MUXER})
    list(APPEND AVFORMAT_SOURCES mkvtimestamp_v2.c)
endif ()
if (${CONFIG_TMV_DEMUXER})
    list(APPEND AVFORMAT_SOURCES tmv.c)
endif ()
if (${CONFIG_TRUEHD_DEMUXER})
    list(APPEND AVFORMAT_SOURCES rawdec.c
		mlpdec.c
	)
endif ()
if (${CONFIG_TRUEHD_MUXER})
    list(APPEND AVFORMAT_SOURCES rawenc.c)
endif ()
if (${CONFIG_TTA_DEMUXER})
    list(APPEND AVFORMAT_SOURCES tta.c
		apetag.c
        img2.c
    )
endif ()
if (${CONFIG_TTA_MUXER})
    list(APPEND AVFORMAT_SOURCES ttaenc.c
		apetag.c
        img2.c
    )
endif ()
if (${CONFIG_TTY_DEMUXER})
    list(APPEND AVFORMAT_SOURCES tty.c
		sauce.c
	)
endif ()
if (${CONFIG_TY_DEMUXER})
    list(APPEND AVFORMAT_SOURCES ty.c)
endif ()
if (${CONFIG_TXD_DEMUXER})
    list(APPEND AVFORMAT_SOURCES txd.c)
endif ()
if (${CONFIG_UNCODEDFRAMECRC_MUXER})
    list(APPEND AVFORMAT_SOURCES uncodedframecrcenc.c
		framehash.c
	)
endif ()
if (${CONFIG_V210_DEMUXER})
    list(APPEND AVFORMAT_SOURCES v210.c)
endif ()
if (${CONFIG_V210X_DEMUXER})
    list(APPEND AVFORMAT_SOURCES v210.c)
endif ()
if (${CONFIG_VAG_DEMUXER})
    list(APPEND AVFORMAT_SOURCES vag.c)
endif ()
if (${CONFIG_VC1_DEMUXER})
    list(APPEND AVFORMAT_SOURCES rawdec.c
		vc1dec.c
	)
endif ()
if (${CONFIG_VC1_MUXER})
    list(APPEND AVFORMAT_SOURCES rawenc.c)
endif ()
if (${CONFIG_VC1T_DEMUXER})
    list(APPEND AVFORMAT_SOURCES vc1test.c)
endif ()
if (${CONFIG_VC1T_MUXER})
    list(APPEND AVFORMAT_SOURCES vc1testenc.c)
endif ()
if (${CONFIG_VIVIDAS_DEMUXER})
    list(APPEND AVFORMAT_SOURCES vividas.c)
endif ()
if (${CONFIG_VIVO_DEMUXER})
    list(APPEND AVFORMAT_SOURCES vivo.c)
endif ()
if (${CONFIG_VMD_DEMUXER})
    list(APPEND AVFORMAT_SOURCES sierravmd.c)
endif ()
if (${CONFIG_VOBSUB_DEMUXER})
    list(APPEND AVFORMAT_SOURCES subtitles.c)
endif ()
if (${CONFIG_VOC_DEMUXER})
    list(APPEND AVFORMAT_SOURCES vocdec.c
		voc_packet.c
		voc.c
	)
endif ()
if (${CONFIG_VOC_MUXER})
    list(APPEND AVFORMAT_SOURCES vocenc.c
		voc.c
	)
endif ()
if (${CONFIG_VPK_DEMUXER})
    list(APPEND AVFORMAT_SOURCES vpk.c)
endif ()
if (${CONFIG_VPLAYER_DEMUXER})
    list(APPEND AVFORMAT_SOURCES vplayerdec.c
		subtitles.c
	)
endif ()
if (${CONFIG_VQF_DEMUXER})
    list(APPEND AVFORMAT_SOURCES vqf.c)
endif ()
if (${CONFIG_W64_DEMUXER})
    list(APPEND AVFORMAT_SOURCES wavdec.c
		w64.c
		pcm.c
	)
endif ()
if (${CONFIG_W64_MUXER})
    list(APPEND AVFORMAT_SOURCES wavenc.c
		w64.c
	)
endif ()
if (${CONFIG_WAV_DEMUXER})
    list(APPEND AVFORMAT_SOURCES wavdec.c
		pcm.c
	)
endif ()
if (${CONFIG_WAV_MUXER})
    list(APPEND AVFORMAT_SOURCES wavenc.c)
endif ()
if (${CONFIG_WC3_DEMUXER})
    list(APPEND AVFORMAT_SOURCES wc3movie.c)
endif ()
if (${CONFIG_WEBM_MUXER})
    list(APPEND AVFORMAT_SOURCES matroskaenc.c
		matroska.c
		av1.c avc.c hevc.c
		flacenc_header.c
		avlanguage.c
		wv.c
		vorbiscomment.c
		webmdashenc.c
		webm_chunk.c
	)
endif ()
if (${CONFIG_WEBM_DASH_MANIFEST_MUXER})
    list(APPEND AVFORMAT_SOURCES webmdashenc.c
		matroska.c
	)
endif ()
if (${CONFIG_WEBM_CHUNK_MUXER})
    list(APPEND AVFORMAT_SOURCES webm_chunk.c
		matroska.c
	)
endif ()
if (${CONFIG_WEBP_MUXER})
    list(APPEND AVFORMAT_SOURCES webpenc.c)
endif ()
if (${CONFIG_WEBVTT_DEMUXER})
    list(APPEND AVFORMAT_SOURCES webvttdec.c
		subtitles.c
	)
endif ()
if (${CONFIG_WEBVTT_MUXER})
    list(APPEND AVFORMAT_SOURCES webvttenc.c)
endif ()
if (${CONFIG_WSAUD_DEMUXER})
    list(APPEND AVFORMAT_SOURCES westwood_aud.c)
endif ()
if (${CONFIG_WSD_DEMUXER})
    list(APPEND AVFORMAT_SOURCES wsddec.c
		rawdec.c
	)
endif ()
if (${CONFIG_WSVQA_DEMUXER})
    list(APPEND AVFORMAT_SOURCES westwood_vqa.c)
endif ()
if (${CONFIG_WTV_DEMUXER})
    list(APPEND AVFORMAT_SOURCES wtvdec.c
		wtv_common.c
        asf.c
	)
endif ()
if (${CONFIG_WTV_MUXER})
    list(APPEND AVFORMAT_SOURCES wtvenc.c
		wtv_common.c
        asf.c
	)
endif ()
if (${CONFIG_WV_DEMUXER})
    list(APPEND AVFORMAT_SOURCES wvdec.c
		wv.c apetag.c
        img2.c
    )
endif ()
if (${CONFIG_WVE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES wvedec.c
		pcm.c
	)
endif ()
if (${CONFIG_WV_MUXER})
    list(APPEND AVFORMAT_SOURCES wvenc.c
		wv.c apetag.c
        img2.c
    )
endif ()
if (${CONFIG_XA_DEMUXER})
    list(APPEND AVFORMAT_SOURCES xa.c)
endif ()
if (${CONFIG_XBIN_DEMUXER})
    list(APPEND AVFORMAT_SOURCES bintext.c
		sauce.c
	)
endif ()
if (${CONFIG_XMV_DEMUXER})
    list(APPEND AVFORMAT_SOURCES xmv.c)
endif ()
if (${CONFIG_XVAG_DEMUXER})
    list(APPEND AVFORMAT_SOURCES xvag.c)
endif ()
if (${CONFIG_XWMA_DEMUXER})
    list(APPEND AVFORMAT_SOURCES xwma.c)
endif ()
if (${CONFIG_YOP_DEMUXER})
    list(APPEND AVFORMAT_SOURCES yop.c)
endif ()
if (${CONFIG_YUV4MPEGPIPE_DEMUXER})
    list(APPEND AVFORMAT_SOURCES yuv4mpegdec.c)
endif ()
if (${CONFIG_YUV4MPEGPIPE_MUXER})
    list(APPEND AVFORMAT_SOURCES yuv4mpegenc.c)
endif ()
if (${CONFIG_AVISYNTH_DEMUXER})
    list(APPEND AVFORMAT_SOURCES avisynth.c)
endif ()
if (${CONFIG_CHROMAPRINT_MUXER})
    list(APPEND AVFORMAT_SOURCES chromaprint.c)
endif ()
if (${CONFIG_LIBGME_DEMUXER})
    list(APPEND AVFORMAT_SOURCES libgme.c)
endif ()
if (${CONFIG_LIBMODPLUG_DEMUXER})
    list(APPEND AVFORMAT_SOURCES libmodplug.c)
endif ()
if (${CONFIG_LIBOPENMPT_DEMUXER})
    list(APPEND AVFORMAT_SOURCES libopenmpt.c)
endif ()
if (${CONFIG_VAPOURSYNTH_DEMUXER})
    list(APPEND AVFORMAT_SOURCES vapoursynth.c)
endif ()
if (${CONFIG_LIBAMQP_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES libamqp.c)
endif ()
if (${CONFIG_LIBRTMP})
    list(APPEND AVFORMAT_SOURCES librtmp.c)
endif ()
if (${CONFIG_LIBSRT_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES libsrt.c)
endif ()
if (${CONFIG_LIBSSH_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES libssh.c)
endif ()
if (${CONFIG_LIBZMQ_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES libzmq.c)
endif ()
if (${CONFIG_LIBSMBCLIENT_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES libsmbclient.c)
endif ()
if (${CONFIG_ASYNC_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES async.c)
endif ()
if (${CONFIG_APPLEHTTP_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES hlsproto.c)
endif ()
if (${CONFIG_BLURAY_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES bluray.c)
endif ()
if (${CONFIG_CACHE_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES cache.c)
endif ()
if (${CONFIG_CONCAT_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES concat.c)
endif ()
if (${CONFIG_CRYPTO_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES crypto.c)
endif ()
if (${CONFIG_DATA_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES data_uri.c)
endif ()
if (${CONFIG_FFRTMPCRYPT_PROTOCOL} AND CONFIG_OPENSSL)
    list(APPEND AVFORMAT_SOURCES rtmpcrypt.c
		rtmpdigest.c
		rtmpdh.c
	)
endif ()
if (${CONFIG_FFRTMPHTTP_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES rtmphttp.c)
endif ()
if (${CONFIG_FILE_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES file.c)
endif ()
if (${CONFIG_FTP_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES ftp.c)
endif ()
if (${CONFIG_GOPHER_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES gopher.c)
endif ()
if (${CONFIG_HLS_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES hlsproto.c)
endif ()
if (${CONFIG_HTTP_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES http.c
		httpauth.c
		urldecode.c
	)
endif ()
if (${CONFIG_HTTPPROXY_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES http.c
		httpauth.c
		urldecode.c
	)
endif ()
if (${CONFIG_HTTPS_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES http.c
		httpauth.c
		urldecode.c
	)
endif ()
if (${CONFIG_ICECAST_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES icecast.c)
endif ()
if (${CONFIG_MD5_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES md5proto.c)
endif ()
if (${CONFIG_MMSH_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES mmsh.c
		mms.c
		asf.c
	)
endif ()
if (${CONFIG_MMST_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES mmst.c
		mms.c
		asf.c
	)
endif ()
if (${CONFIG_PIPE_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES file.c)
endif ()
if (${CONFIG_PROMPEG_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES prompeg.c)
endif ()
if (${CONFIG_RTMP_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES rtmpproto.c
		rtmpdigest.c
		rtmppkt.c
	)
endif ()
if (${CONFIG_RTMPE_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES rtmpproto.c
		rtmpdigest.c
		rtmppkt.c
	)
endif ()
if (${CONFIG_RTMPS_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES rtmpproto.c
		rtmpdigest.c
		rtmppkt.c
	)
endif ()
if (${CONFIG_RTMPT_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES rtmpproto.c
		rtmpdigest.c
		rtmppkt.c
	)
endif ()
if (${CONFIG_RTMPTE_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES rtmpproto.c
		rtmpdigest.c
		rtmppkt.c
	)
endif ()
if (${CONFIG_RTMPTS_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES rtmpproto.c
		rtmpdigest.c
		rtmppkt.c
	)
endif ()
if (${CONFIG_RTP_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES rtpproto.c)
endif ()
if (${CONFIG_SCTP_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES sctp.c)
endif ()
if (${CONFIG_SRTP_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES srtpproto.c
		srtp.c
	)
endif ()
if (${CONFIG_SUBFILE_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES subfile.c)
endif ()
if (${CONFIG_TEE_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES teeproto.c
		tee_common.c
	)
endif ()
if (${CONFIG_TCP_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES tcp.c)
endif ()
if (${CONFIG_GNUTLS})
    list(APPEND AVFORMAT_SOURCES tls_gnutls.c)
endif ()
if (${CONFIG_LIBTLS})
    list(APPEND AVFORMAT_SOURCES tls_libtls.c)
endif ()
if (${CONFIG_OPENSSL})
    list(APPEND AVFORMAT_SOURCES tls_openssl.c)
endif ()
if (${CONFIG_SECURETRANSPORT})
    list(APPEND AVFORMAT_SOURCES tls_securetransport.c)
endif ()
if (${CONFIG_SCHANNEL})
    list(APPEND AVFORMAT_SOURCES tls_schannel.c)
endif ()
if (${CONFIG_TLS_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES tls.c)
endif ()
if (${CONFIG_UDP_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES udp.c ip.c)
endif ()
if (${CONFIG_UDPLITE_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES udp.c ip.c)
endif ()
if (${CONFIG_UNIX_PROTOCOL})
    list(APPEND AVFORMAT_SOURCES unix.c)
endif ()
if (${CONFIG_IEC61883_INDEV})
    list(APPEND AVFORMAT_SOURCES dv.c)
endif ()

add_library(avformat ${LIBRARY_TYPE} ${AVFORMAT_SOURCES} ${AVFORMAT_HEADERS} ${GENERATED_CONFIG_HEADERS} ${GENERATED_VERSION_HEADERS})
target_link_libraries(avformat PUBLIC avutil avcodec)
if (CONFIG_OPENSSL)
    target_link_libraties(avformat PUBLIC OpenSSL::SSL OpenSSL::Crypto)
endif ()
if (HAS_LIBXML)
    target_link_libraries(avformat PUBLIC LibXml2::LibXml2)
endif ()
target_include_directories(avformat PRIVATE ${CMAKE_SOURCE_DIR} ${OPENSSL_INCLUDE_DIR})
target_compile_definitions(avformat PUBLIC HAVE_AV_CONFIG_H)
if (WIN32)
	target_link_libraries(avformat PUBLIC ws2_32 crypt32)
endif (WIN32)

set_target_properties(avformat PROPERTIES PUBLIC_HEADER "${AVFORMAT_HEADERS}")
set_target_properties(avformat PROPERTIES RUNTIME_OUTPUT_NAME "avformat-${LIBAVFORMAT_VERSION}")
install(TARGETS avformat
    ARCHIVE
    LIBRARY
    PUBLIC_HEADER
		DESTINATION include/libavformat
	RUNTIME
)
if (WIN32)
    install(FILES $<TARGET_PDB_FILE:avformat> DESTINATION bin OPTIONAL)
endif ()