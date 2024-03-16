#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_pressed();


    void on_pushButton_3_pressed();

    void on_pushButton_4_pressed();

    void on_pushButton_5_pressed();

    void on_pushButton_6_pressed();

    void on_pushButton_7_pressed();

    void on_pushButton_8_pressed();

    void on_pushButton_9_pressed();

    void on_pushButton_10_pressed();

    void on_pushButton_11_pressed();

    void on_pushButton_13_pressed();

    void on_pushButton_14_pressed();

    void on_pushButton_15_pressed();

    void on_pushButton_20_pressed();

    void on_pushButton_21_pressed();

    void on_pushButton_22_pressed();

    void on_pushButton_23_pressed();

    void on_pushButton_31_pressed();

    void on_pushButton_32_pressed();

    void on_pushButton_33_pressed();

    void on_pushButton_38_pressed();

    void on_pushButton_39_pressed();

    void on_pushButton_40_pressed();

    void on_pushButton_45_pressed();

    void on_pushButton_46_pressed();

    void on_pushButton_47_pressed();

    void on_pushButton_48_pressed();

    void on_pushButton_55_pressed();

    void on_pushButton_56_pressed();

    void on_pushButton_57_pressed();

    void on_pushButton_58_pressed();

    void on_pushButton_59_pressed();

    void on_pushButton_68_pressed();

    void on_pushButton_69_pressed();

    void on_pushButton_72_pressed();

    void on_pushButton_73_pressed();

    void on_pushButton_78_pressed();

    void on_pushButton_17_pressed();

    void on_pushButton_18_pressed();

    void on_pushButton_25_pressed();

    void on_pushButton_27_pressed();

    void on_pushButton_30_pressed();

    void on_pushButton_35_pressed();

    void on_pushButton_37_pressed();

    void on_pushButton_41_pressed();

    void on_pushButton_44_pressed();

    void on_pushButton_50_pressed();

    void on_pushButton_52_pressed();

    void on_pushButton_54_pressed();

    void on_pushButton_61_pressed();

    void on_pushButton_63_pressed();

    void on_pushButton_65_pressed();

    void on_pushButton_67_pressed();

    void on_pushButton_71_pressed();

    void on_pushButton_75_pressed();

    void on_pushButton_77_pressed();


    void on_pushButton_clicked(bool checked);

    void on_pushButton_released();

    void on_pushButton_16_pressed();

    void on_pushButton_19_pressed();

    void on_pushButton_34_pressed();

    void on_pushButton_36_pressed();

    void on_pushButton_79_pressed();

    void on_pushButton_80_pressed();

    void on_pushButton_24_pressed();

    void on_pushButton_26_pressed();

    void on_EliminarSala_pressed();

    void on_pushButton_clicked();

    void on_btNewCita_pressed();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
