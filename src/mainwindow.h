#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/tracking.hpp>
#include <opencv2/objdetect/objdetect.hpp>

//////////////////////////////////////////////////////////////
namespace Ui {
class MainWindow;
}
//////////////////////////////////////////////////////////////
class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void processFrameAndUpdateGUI();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnPauseOrResume_clicked();

private:
    Ui::MainWindow *ui;

    QTimer* qtimer;

    cv::VideoCapture capWebcam;
    cv::Mat matPrevious;
    cv::Mat matOriginal;
    cv::Mat matProcessed;

    QImage imgOriginal;
    QImage imgProcessed;

    QImage matToQImage(cv::Mat mat);

    void exitProgram();
    void trackingMeanShift(cv::Mat& img, cv::Rect search_window);
};
//////////////////////////////////////////////////////////////



#endif // MAINWINDOW_H
