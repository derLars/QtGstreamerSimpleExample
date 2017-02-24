#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>

#include <glib.h>
#include <gst/gst.h>
#include <gst/video/videooverlay.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    gst_init(NULL,NULL);

    GstElement* pipeline = gst_pipeline_new("xvoverlay");
    GstElement* src = gst_element_factory_make("v4l2src", NULL);
    GstElement* sink = gst_element_factory_make("xvimagesink", NULL);

    gst_bin_add_many(GST_BIN (pipeline),src,sink,NULL);
    gst_element_link(src, sink);

    ui->widgetToOverlay->resize(320,240);
    WId xwinid = ui->widgetToOverlay->winId();

    gst_video_overlay_set_window_handle(GST_VIDEO_OVERLAY (sink), xwinid);

    GstStateChangeReturn stateReturn = gst_element_set_state(pipeline,GST_STATE_PLAYING);
    if(stateReturn == GST_STATE_CHANGE_FAILURE) {
        gst_element_set_state(pipeline,GST_STATE_NULL);
        gst_object_unref(pipeline);
        QTimer::singleShot(0,QApplication::activeWindow(), SLOT(quit()));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
