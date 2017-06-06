/*#include "QtGuiApp_ObjPointVis.h"
#include <QtWidgets/QApplication>

#include <stdio.h>
#include <iostream>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtGuiApp_ObjPointVis w;

	std::cout << "here" << std::endl;
	w.show();
	return a.exec();
}*/


#include "src\mainwindow.h"

#include <QApplication>
#include <QSurfaceFormat>
#include <QDebug>

#include <iostream>
#include <stdio.h>

void debugFormatVersion()
{
    QSurfaceFormat form = QSurfaceFormat::defaultFormat();
    QSurfaceFormat::OpenGLContextProfile prof = form.profile();

    const char *profile =
        prof == QSurfaceFormat::CoreProfile ? "Core" :
        prof == QSurfaceFormat::CompatibilityProfile ? "Compatibility" :
        "None";

    printf("Requested format:\n");
    printf("  Version: %d.%d\n", form.majorVersion(), form.minorVersion());
    printf("  Profile: %s\n", profile);
}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    // Set OpenGL 3.2 and, optionally, 4-sample multisampling
    QSurfaceFormat format;
    format.setVersion(3, 2);
    format.setOption(QSurfaceFormat::DeprecatedFunctions, false);
    format.setProfile(QSurfaceFormat::CoreProfile);
    //format.setSamples(4);  // Uncomment for nice antialiasing. Not always supported.

    /*** AUTOMATIC TESTING: DO NOT MODIFY ***/
    /*** Check whether automatic testing is enabled */
    /***/

	if (qgetenv("CIS277_AUTOTESTING") != nullptr) format.setSamples(0);

	QSurfaceFormat::setDefaultFormat(format);
	debugFormatVersion();

	std::cout << "MADE IT HERE" << std::endl;

	MainWindow w;
	w.show();

	return a.exec();
	}
