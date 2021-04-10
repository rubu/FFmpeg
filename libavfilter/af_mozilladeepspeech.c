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
    { "model", "path to model file", OFFSET(model), AV_OPT_TYPE_STRING, { .str = "" }, 0, 0, A },
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
    static int64_t channel_layouts[] = {
        AV_CH_LAYOUT_MONO,
        -1,
    };
    static const enum AVSampleFormat sample_fmts[] = {
        AV_SAMPLE_FMT_S16P,
        AV_SAMPLE_FMT_NONE
    };
    MozillaDeepSpeechContext *context = filter_context->priv;
    int sample_rates[] = { DS_GetModelSampleRate(context->model), -1 };
    AVFilterFormats* formats;
    AVFilterChannelLayouts* layouts;
    int ret;

    formats = ff_make_format_list(sample_fmts);
    if (!formats)
        return AVERROR(ENOMEM);
    ret = ff_set_common_formats(filter_context, formats);
    if (ret < 0)
        return ret;
    layouts = ff_make_format64_list(channel_layouts);

    if (!layouts)
        return AVERROR(ENOMEM);
    ret = ff_set_common_channel_layouts(filter_context, layouts);
    if (ret < 0)
        return ret;

    formats = ff_make_format_list(sample_rates);
    if (!formats)
        return AVERROR(ENOMEM);
    return ff_set_common_samplerates(filter_context, formats);
}

static int request_frame(AVFilterLink *outlink)
{
    return 0;
}

static av_cold int init(AVFilterContext *filter_context)
{
    MozillaDeepSpeechContext *context = filter_context->priv;

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
        .type          = AVMEDIA_TYPE_AUDIO,
        .request_frame = request_frame,
        .config_props  = config_output,
    },
    {
        .name          = "text",
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
    .init           = init,
    .uninit         = uninit,
    .inputs         = mozilladeepspeech_inputs,
    .outputs        = mozilladeepspeech_outputs,
};
