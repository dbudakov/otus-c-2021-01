#include "filter.h"

G_DEFINE_TYPE (GstMyFilter, gst_my_filter, GST_TYPE_ELEMENT);
GST_ELEMENT_REGISTER_DEFINE(my_filter, "my-filter", GST_RANK_NONE, GST_TYPE_MY_FILTER);

static void
gst_my_filter_class_init (GstMyFilterClass * klass)
{
  GstElementClass *element_class = GST_ELEMENT_CLASS (klass);


  gst_element_class_set_static_metadata (element_klass,
    "An example plugin",
    "Example/FirstExample",
    "Shows the basic structure of a plugin",
    "your name <your.name@your.isp>");

}

static GstStaticPadTemplate sink_factory =
GST_STATIC_PAD_TEMPLATE (
  "sink",
  GST_PAD_SINK,
  GST_PAD_ALWAYS,
  GST_STATIC_CAPS ("ANY")
);

static GstStaticPadTemplate sink_factory = [..], src_factory = [..];

static void gst_my_filter_class_init (GstMyFilterClass * klass)
{
  
  GstElementClass *element_class = GST_ELEMENT_CLASS (klass);

  gst_element_class_add_pad_template (element_class,
    gst_static_pad_template_get (&src_factory));
  gst_element_class_add_pad_template (element_class, 
    gst_static_pad_template_get (&sink_factory));
}

static GstStaticPadTemplate sink_factory = GST_STATIC_PAD_TEMPLATE (
  "sink",
  GST_PAD_SINK,
  GST_PAD_ALWAYS,
  GST_STATIC_CAPS (
    "audio/x-raw, "
      "format = (string) " GST_AUDIO_NE (S16) ", "
      "channels = (int) { 1, 2 }, "
      "rate = (int) [ 8000, 96000 ]"
  )
);

static gboolean plugin_init (GstPlugin *plugin)
{
  return GST_ELEMENT_REGISTER (my_filter, plugin);
}

GST_PLUGIN_DEFINE (
  GST_VERSION_MAJOR,
  GST_VERSION_MINOR,
  my_filter,
  "My filter plugin",
  plugin_init,
  VERSION,
  "LGPL",
  "GStreamer",
  "http://gstreamer.net/"
)

/********** PAD **********/
static void gst_my_filter_init (GstMyFilter *filter)
{
  filter->sinkpad = gst_pad_new_from_static_template (&sink_template, "sink");
  gst_element_add_pad (GST_ELEMENT (filter), filter->sinkpad);

  filter->srcpad = gst_pad_new_from_static_template (&src_template, "src");
  gst_element_add_pad (GST_ELEMENT (filter), filter->srcpad);

  filter->silent = FALSE;
}

/********* CHAIN **********/
static GstFlowReturn gst_my_filter_chain  (GstPad   *pad, GstObject *parent, GstBuffer *buf);

static void gst_my_filter_init (GstMyFilter * filter)
{
  gst_pad_set_chain_function (filter->sinkpad, gst_my_filter_chain);
}

static GstFlowReturn gst_my_filter_chain (GstPad  *pad, GstObject *parent, GstBuffer *buf)
{
  GstMyFilter *filter = GST_MY_FILTER (parent);
  if (!filter->silent)
    g_print ("Have data of size %" G_GSIZE_FORMAT" bytes!\n",
        gst_buffer_get_size (buf));
  return gst_pad_push (filter->srcpad, buf);
}

static gboolean gst_my_filter_sink_event (GstPad    *pad, GstObject *parent, GstEvent  *event);

static void gst_my_filter_init (GstMyFilter * filter)
{
  gst_pad_set_event_function (filter->sinkpad, gst_my_filter_sink_event);
}

/********** EVENT **********/
static gboolean gst_my_filter_sink_event(GstPad *pad, GstObject *parent, GstEvent  *event)
{
  gboolean ret;
  GstMyFilter *filter = GST_MY_FILTER (parent);

  switch (GST_EVENT_TYPE (event)) {
    case GST_EVENT_CAPS:
    ret = gst_pad_push_event (filter->srcpad, event);
      break;
    case GST_EVENT_EOS:
      gst_my_filter_stop_processing (filter);
      ret = gst_pad_event_default (pad, parent, event);
      break;
    default:
      ret = gst_pad_event_default (pad, parent, event);
      break;
  }
  return ret;
}

/********** QUERY **********/
static gboolean gst_my_filter_src_query (GstPad    *pad, GstObject *parent, GstQuery  *query);

static void
gst_my_filter_init (GstMyFilter * filter)
{
  gst_pad_set_query_function (filter->srcpad, gst_my_filter_src_query);
}

static gboolean
gst_my_filter_src_query (GstPad    *pad, GstObject *parent, GstQuery  *query)
{
  gboolean ret;
  GstMyFilter *filter = GST_MY_FILTER (parent);

  switch (GST_QUERY_TYPE (query)) {
    case GST_QUERY_POSITION:
      break;
    case GST_QUERY_DURATION:
      break;
    case GST_QUERY_CAPS:
      break;
    default:
      ret = gst_pad_query_default (pad, parent, query);
      break;
  }
  return ret;
}

/********** STATE **********/
static GstStateChangeReturn gst_my_filter_change_state (GstElement *element, GstStateChange transition);

static void gst_my_filter_class_init (GstMyFilterClass *klass)
{
  GstElementClass *element_class = GST_ELEMENT_CLASS (klass);
  element_class->change_state = gst_my_filter_change_state;
}

static GstStateChangeReturn gst_my_filter_change_state (GstElement *element, GstStateChange transition)
{
  GstStateChangeReturn ret = GST_STATE_CHANGE_SUCCESS;
  GstMyFilter *filter = GST_MY_FILTER (element);
  switch (transition) {
	case GST_STATE_CHANGE_NULL_TO_READY:
	  if (!gst_my_filter_allocate_memory (filter))
		return GST_STATE_CHANGE_FAILURE;
	  break;
	default:
	  break;
  }
  ret = GST_ELEMENT_CLASS (parent_class)->change_state (element, transition);
  if (ret == GST_STATE_CHANGE_FAILURE)
	return ret;
  switch (transition) {
	case GST_STATE_CHANGE_READY_TO_NULL:
	  gst_my_filter_free_memory (filter);
	  break;
	default:
	  break;
  }
  return ret;
}

/********** Adding Properties **********/
/********** Signals **********/
