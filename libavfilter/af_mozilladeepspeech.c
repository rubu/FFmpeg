#include "libavutil/opt.h"
#include "avfilter.h"
#include "internal.h"

#include <deepspeech.h>

typedef struct MozillaDeepSpeechContext {
    const AVClass *class;

    char *model_path;
    ModelState *model;
} MozillaDeepSpeechContext;

#define OFFSET(x) offsetof(MozillaDeepSpeechContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM

static const AVOption mozilladeepspeech_options[] = {
    { "model", "path to model file", OFFSET(model_path), AV_OPT_TYPE_STRING, { .str = "" }, 0, 0, A },
    { NULL }
};

AVFILTER_DEFINE_CLASS(mozilladeepspeech);

static int config_output(AVFilterLink *outlink)
{
    return 0;
}

static int filter_frame(AVFilterLink *inlink, AVFrame *in)
{
    return 0;
}

static int query_formats(AVFilterContext *filter_context)
{
    static int64_t in_raw_channel_layouts[] = {
        AV_CH_LAYOUT_MONO,
        -1,
    };
    static const enum AVSampleFormat in_sample_fmts[] = {
        AV_SAMPLE_FMT_S16P,
        AV_SAMPLE_FMT_NONE
    };
    static int out_char_encs[] = {
        FF_SUB_CHARENC_MODE_IGNORE,
        -1
    };
    MozillaDeepSpeechContext *context = filter_context->priv;
    int in_sample_rates[] = { DS_GetModelSampleRate(context->model), -1 };
    AVFilterFormats *in_formats, *out_formats;
    AVFilterChannelLayouts *in_channel_layouts;
    int ret;

    in_formats = ff_make_format_list(in_sample_fmts);
    if (!in_formats)
        return AVERROR(ENOMEM);
    ret = ff_formats_ref(in_formats, &filter_context->inputs[0]->outcfg.formats);
    if (ret < 0)
        return ret;

    in_channel_layouts = ff_make_format64_list(in_raw_channel_layouts);
    if (!in_channel_layouts)
        return AVERROR(ENOMEM);
    ret = ff_channel_layouts_ref(in_channel_layouts, &filter_context->inputs[0]->outcfg.channel_layouts);
    if (ret < 0)
        return ret;

    in_formats = ff_make_format_list(in_sample_rates);
    if (!in_formats)
        return AVERROR(ENOMEM);
    ret = ff_formats_ref(in_formats, &filter_context->inputs[0]->outcfg.samplerates);
    if (ret < 0)
        return ret;

    out_formats = ff_make_format_list(out_char_encs);
    if (!out_formats)
        return AVERROR(ENOMEM);
    return ff_formats_ref(out_formats, &filter_context->outputs[0]->incfg.formats);
}

static int request_frame(AVFilterLink *outlink)
{
    return 0;
}

static int activate(AVFilterContext* ctx)
{
    return 0;
}

static av_cold int init(AVFilterContext *filter_context)
{
    MozillaDeepSpeechContext *context = filter_context->priv;

    if (context->model_path == NULL) {
        av_log(filter_context, AV_LOG_ERROR,
            "Model not specified.\n");
        return AVERROR(EINVAL);
    }
    if (DS_CreateModel(context->model_path, &context->model) != 0) {
        av_log(filter_context, AV_LOG_ERROR,
            "Failed to open model %s.\n", context->model_path);
        return AVERROR(EINVAL);
    }

    return 0;
}

static av_cold void uninit(AVFilterContext *filter_context)
{
    MozillaDeepSpeechContext* context = filter_context->priv;

    if (context->model)
        DS_FreeModel(context->model);
}

static const AVFilterPad mozilladeepspeech_inputs[] = {
    {
        .name           = "default",
        .type           = AVMEDIA_TYPE_AUDIO,
        .filter_frame   = filter_frame,
    },
    { NULL }
};

static const AVFilterPad mozilladeepspeech_outputs[] = {
    {
        .name          = "default",
        .type          = AVMEDIA_TYPE_SUBTITLE,
        .request_frame = request_frame,
        .config_props  = config_output,
    },
    { NULL }
};


AVFilter ff_af_mozilladeepspeech = {
    .name           = "mozilladeepspeech",
    .description    = NULL_IF_CONFIG_SMALL("Mozilla Deep Speech Speech-To-Text Engine"),
    .query_formats  = query_formats,
    .priv_size      = sizeof(MozillaDeepSpeechContext),
    .priv_class     = &mozilladeepspeech_class,
    .activate       = activate,
    .init           = init,
    .uninit         = uninit,
    .inputs         = mozilladeepspeech_inputs,
    .outputs        = mozilladeepspeech_outputs,
};
